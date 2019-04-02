//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	m_rowChannels = 25;
	m_rowHeadings = 28;
	m_rowDataStart = 29;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnLoadFileClick(TObject *Sender)
{
	TStringList *lstr = NULL;
	TCursor crOld;

	if (dlgOpenTxt->Execute()) {
		try {
			try {
				crOld = Screen->Cursor;
				Screen->Cursor = crHourGlass;
				lstr = new TStringList;
				lstr->LoadFromFile(dlgOpenTxt->FileName);
				memoFileData->Clear();
				int nLines = edtLines->Text.ToIntDef(1000);
				int digits = (int) log10((double) nLines);
				String strFmt, strLine;
				memoFileData->Lines->BeginUpdate ();
				for (int n=0 ; n < nLines ; n++) {
					strFmt = String().sprintf (L"%%%dd: %%s", digits);
					strLine = String().sprintf (strFmt.c_str(), n + 1, lstr->Strings[n]);
					memoFileData->Lines->Add(strLine);
				}
				memoFileData->Lines->EndUpdate ();
				MessageDlg (String(lstr->Count) + " lines read", mtInformation, TMsgDlgButtons() << mbOK, 0);
			} catch (Exception &e)
			{
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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    memoFileData->Anchors << akRight << akBottom;
}
//---------------------------------------------------------------------------

