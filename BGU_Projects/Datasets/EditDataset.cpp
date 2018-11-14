//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "EditDataset.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TdlgEditDataset *dlgEditDataset;
//---------------------------------------------------------------------
__fastcall TdlgEditDataset::TdlgEditDataset(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
bool __fastcall TdlgEditDataset::Execute (TDatasetInfo &dataset)
{
	bool f;

	Download (dataset);
	ShowModal ();
	f = ModalResult == mrOk;
	if (f) {
		Upload (dataset);
	}
	return (f);
}
//---------------------------------------------------------------------
void  __fastcall TdlgEditDataset::Download (TDatasetInfo &dataset)
{
	Tag = dataset.DatasetID;
	panelID->Caption = String (Tag);
	edtName->Text = dataset.Name;
	edtURL->Text = dataset.URL;
	edtOrg->Text = dataset.Organization;
	memoStructure->Lines->Text = dataset.Structure;
//	dataset.Contacts = ;
//	dataset.Points = ;
	edtUsername->Text = dataset.Username;
	edtPasswors->Text = dataset.Password;
	edtDescription->Text = dataset.Description;
}
//---------------------------------------------------------------------
void __fastcall TdlgEditDataset::Upload (TDatasetInfo &dataset)
{
//	dataset.Contacts = ;
//	dataset.Points;
	dataset.DatasetID = Tag;
	dataset.Name = edtName->Text;
	dataset.URL = edtURL->Text;
	dataset.Structure = memoStructure->Lines->Text;
	dataset.Username = edtUsername->Text;
	dataset.Password = edtPasswors->Text;
	dataset.Description = edtDescription->Text;
	dataset.Organization = edtOrg->Text;
}
//---------------------------------------------------------------------
void __fastcall TdlgEditDataset::btnURLTestClick(TObject *Sender)
{
	String str = edtURL->Text.Trim();

	if (str.Length() > 0) {
		ShellExecute(Handle, "open", str.c_str(), NULL, NULL,SW_SHOWNORMAL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TdlgEditDataset::OnIdle(TObject *Sender, bool &Done)
{
	panelChars->Caption = String (memoStructure->Lines->Text.Length());	
}
//---------------------------------------------------------------------------

