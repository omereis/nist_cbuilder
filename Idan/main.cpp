//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
	m_rowChannels = 25;
	m_rowHeadings = 28;
	m_rowDataStart = 29;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnLoadFileClick(TObject *Sender)
{
	LoadData ();
}
//---------------------------------------------------------------------------
String __fastcall TfrmMain::LoadData ()
{
	TStringList *lstr = NULL;
	TCursor crOld;
	String strFmt, strLine;

	if (dlgOpenTxt->Execute()) {
		try {
			try {
				crOld = Screen->Cursor;
				Screen->Cursor = crHourGlass;
				lstr = new TStringList;
				lstr->LoadFromFile(dlgOpenTxt->FileName);
				m_strFile = dlgOpenTxt->FileName;
				memoFileData->Clear();
				int nLines = edtLines->Text.ToIntDef(1000);
				int digits = (int) log10((double) nLines);
				memoFileData->Lines->BeginUpdate ();
				for (int n=0 ; n < nLines ; n++) {
					strFmt = String().sprintf (L"%%%dd: %%s", digits);
					strLine = String().sprintf (strFmt.c_str(), n + 1, lstr->Strings[n]);
					memoFileData->Lines->Add(strLine);
				}
				memoFileData->Lines->EndUpdate ();
//				MessageDlg (String(lstr->Count) + " lines read", mtInformation, TMsgDlgButtons() << mbOK, 0);
			} catch (Exception &e)
			{
				m_strFile = "";
				MessageDlg ("Button1Click: " + e.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
			}
		}
		__finally {
            Screen->Cursor = crOld;
			if (lstr) {
				delete lstr;
			}
		}
	}
    return (m_strFile);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
    memoFileData->Anchors << akRight << akBottom;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Exit1Click(TObject *Sender)
{
	Close ();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::LoadData1Click(TObject *Sender)
{
	LoadData ();
}
//---------------------------------------------------------------------------
bool __fastcall GetFileData (const String &strFile, TStringList *lstr)
{
	TFileStream *fstrm;
	bool f;

	try {
		try {
			fstrm = new TFileStream (strFile, fmOpenRead | fmShareDenyWrite);
            lstr->LoadFromStream (fstrm);
			f = true;
		}
		catch (...) {
			f = false;
		}
	}
	__finally {
		if (fstrm)
			delete fstrm;
	}
	return (f);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnParseDataClick(TObject *Sender)
{
	TChannelInfoVec vChannels;
	TStringList *lstr = NULL;

	try {
		try {
			lstr = new TStringList;
			GetFileData (m_strFile, lstr);
			vChannels.ParseChannels (lstr->Strings[ChannelsLine]);
			vChannels.ParseChannels (lstr->Strings[ChannelsLine]);
		}
		catch (Exception &e) {
			MessageDlg (e.Message, mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
	__finally {
		if (lstr)
			delete lstr;
	}
}
//---------------------------------------------------------------------------
int __fastcall TfrmMain::GetChannelsLine ()
{
	return (edtChannels->Text.ToIntDef(0) - 1);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::SetChannelsLine (int nLine)
{
    udChannels->Position = nLine;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::OnIdle(TObject *Sender, bool &Done)
{
	btnParseData->Enabled = m_strFile.Trim().Length() > 0;
}
//---------------------------------------------------------------------------

