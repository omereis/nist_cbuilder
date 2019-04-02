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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	TStringList *lstr = NULL;

	if (dlgOpenTxt->Execute()) {
		try {
			try {
				lstr = new TStringList;
				lstr->LoadFromFile(dlgOpenTxt->FileName);
				MessageDlg (String(lstr->Count) + " lines read", mtInformation, TMsgDlgButtons() << mbOK, 0);
			} catch (Exception &e)
			{
				MessageDlg ("Button1Click: " + e.Message, mtInformation, TMsgDlgButtons() << mbOK, 0);
			}
		}
		__finally {
			if (lstr) {
				delete lstr;
			}
		}
	}
}
//---------------------------------------------------------------------------

