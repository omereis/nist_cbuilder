//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "EditDataset.h"
#include "Misc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
	m_strCaption = Caption;
	InitDatasetsGrid ();
	ConnectToDB ();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::actExitExecute(TObject *Sender)
{
	Close ();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::ConnectToDB ()
{
	TCursor cr = Screen->Cursor;
	Screen->Cursor = crHourGlass;
	try {
		try {
			dbMain->Connected = true;
			DownloadDatasete ();
		} catch (Exception &e) {
			ShowMessage ("Error connecting to database:\n" + e.Message);
		}
	}
	__finally {
		Screen->Cursor = cr;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::actConnectExecute(TObject *Sender)
{
	ConnectToDB ();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::actDisconnectExecute(TObject *Sender)
{
	Disconect ();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::OnIdle(TObject *Sender, bool &Done)
{
	UpdateActions ();
	UpdateStatusBar ();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::UpdateActions ()
{
	bool fConnected = dbMain->Connected;

	actConnect->Enabled = fConnected == false;
	actDisconnect->Enabled = fConnected == true;
	actDSAdd->Enabled = fConnected;
	actDSEdit->Enabled = fConnected;
	actDSDel->Enabled = fConnected;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Disconect ()
{
	dbMain->Connected = false;
	PurgeGrid (gridDatasets);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (dbMain->Connected)
		Disconect ();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::UpdateStatusBar ()
{
	String strConnect;

	strConnect = dbMain->Connected ? "Conected" : "Disconnected";
	StatusBar1->Panels[0].Items[0]->Text = strConnect;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::InitDatasetsGrid ()
{
	gridDatasets->Cells[0][0] = "Name";
	gridDatasets->Cells[1][0] = "Description";
	gridDatasets->Cells[2][0] = "URL";
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::actDSAddExecute(TObject *Sender)
{
	TDatasetInfo dataset;
	bool fNew = false;

	if (dataset.InsertAsNew (dbMain, m_strErr)) {
		if (EditDataset (dataset)) {
			if (dataset.UpdateInDB (dbMain, m_strErr)) {
				fNew = true;
			}
		}
	}
	if (fNew) {
		DownloadNewDataset (dataset);
	}
	else
		dataset.DeleteInDB (dbMain, m_strErr);
	if (m_strErr.Length() > 0) {
		ShowMessage (m_strErr);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::actDSEditExecute(TObject *Sender)
{
	TDatasetInfo dataset;

	dataset.DatasetID = UploadDatasetID ();
	if (dataset.LoadByID (dbMain, m_strErr))
		if (EditDataset (dataset))
			if (dataset.UpdateInDB (dbMain, m_strErr))
				Download (dataset, gridDatasets->Row);
}
//---------------------------------------------------------------------------
int __fastcall TfrmMain::UploadDatasetID ()
{
	int id;

	id = (int) gridDatasets->Objects[0][gridDatasets->Row];
	return (id);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::actDSDelExecute(TObject *Sender)
{
	TDatasetInfo dataset;

	dataset.DatasetID = UploadDatasetID ();
	if (dataset.LoadByID (dbMain, m_strErr))
		if (dataset.ConfirmDeletion ()) {
			if (dataset.DeleteInDB (dbMain, m_strErr))
				DeleteLine (gridDatasets, gridDatasets->Row);
		}
}
//---------------------------------------------------------------------------
int __fastcall GetNextEmptyRow (TStringGrid *grid)
{
	bool fNew = true;

	if (grid->RowCount == 2) {
		if (grid->Objects[0][1] == NULL) {
			fNew = false;
		}
	}
	if (fNew) {
		grid->RowCount++;
	}
	return (grid->RowCount - 1);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::DownloadNewDataset (TDatasetInfo &dataset)
{
	int nRow;

	nRow = GetNextEmptyRow (gridDatasets);
	Download (dataset, nRow);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Download (TDatasetInfo &dataset, int nRow)
{
	gridDatasets->Cells[0][nRow] = dataset.Name;
	gridDatasets->Cells[1][nRow] = dataset.Description;
	gridDatasets->Cells[2][nRow] = dataset.URL;
	gridDatasets->Objects[0][nRow] = (TObject*) dataset.DatasetID;
}
//---------------------------------------------------------------------------
bool __fastcall TfrmMain::EditDataset (TDatasetInfo &dataset)
{
	TdlgEditDataset *dlg = new TdlgEditDataset (this);
	bool f;

	f = dlg->Execute (dataset);
	delete dlg;
	return (f);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::DownloadDatasete ()
{
	TDatases vSet;

	if (vSet.LoadFromDB (dbMain, m_strErr))
		DownloadDatasets (vSet);
	else
		ShowMessage ("Error loading datasets:\n" + m_strErr);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::DownloadDatasets (TDatases &vSet)
{
	TDatases::iterator iSet;
	int nRow;

	PurgeGrid (gridDatasets);
	if (vSet.size() > 0) {
		gridDatasets->RowCount = vSet.size() + 1;
		for (iSet=vSet.begin(), nRow=1 ; iSet != vSet.end() ; iSet++, nRow++) {
			Download (*iSet, nRow);
		}

	}

}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::gridDatasetsDblClick(TObject *Sender)
{
	if (actDSEdit->Enabled) {
        actDSEdit->OnExecute (Sender);
	}
}
//---------------------------------------------------------------------------
#include <FileCtrl.hpp>
void __fastcall TfrmMain::bitbtnImportClick(TObject *Sender)
{
	String strDir;

	if (SelectDirectory("Select Dataset Source", ".", strDir, TSelectDirExtOpts () << sdShowEdit))
    	ShowMessage ("Selected folder:\n" + strDir);
}
//---------------------------------------------------------------------------

