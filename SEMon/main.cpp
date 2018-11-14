//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
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
void __fastcall TfrmMain::bitbtnSolarEdgeClick(TObject *Sender)
{
	ShellExecute(NULL, L"open", L"https://www.solaredge.com", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
	InitStatusGrid ();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::InitStatusGrid ()
{
	gridStatus->Cells[0][0] = "Property";
	gridStatus->Cells[1][0] = "Value";
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnStatusClick(TObject *Sender)
{
	PurgeGrid (gridStatus);
    RESTRequest1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnReadClick(TObject *Sender)
{
	String str, sj;
	TJSONObject *jobj = NULL;
	TJSONArray *ja = NULL;
	TJSONValue *jv;
	TJSONPair* jpair;
	TJSONString *jstring;

	int nCode = RESTResponse1->StatusCode;
	if (nCode == 0) {
		nCode = 200;
		str = mmoJSON->Lines->Text;
	}
	if (nCode == 200) {
		str = RESTResponse1->Content;
		try {
			jobj = new TJSONObject;
			ja = new TJSONArray;
			try {
				jobj->ParseJSONValue(str);
				str += "";
				ja = (TJSONArray *) TJSONObject::ParseJSONValue(str);
				for (int n=0 ; n < jobj->Size() ; n++) {
					jpair = jobj->Get(n);
					jstring = jpair->JsonString;
				}
			} catch (Exception &e) {
				ShowMessage (e.Message);
			}
		}
		__finally {
			if (jobj)
				delete jobj;
			if (ja)
				delete ja;
		}
	}
	str += String (nCode);
}
//---------------------------------------------------------------------------
