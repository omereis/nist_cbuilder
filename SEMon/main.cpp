//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "Misc.h"
#include <System.JSON.hpp>
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
TJSONObject *__fastcall ReadJSon (const String &strFileName)
{
//	String strJSon;
	TJSONObject *jobj = NULL;
	TStringList *lstr = new TStringList;

	try {
		lstr->LoadFromFile(strFileName);
//		str = lstr->Text;
		jobj = (TJSONObject *) TJSONObject::ParseJSONValue(lstr->Text, true);
	}
	__finally {
		delete lstr;
	}
	return (jobj);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnReadClick(TObject *Sender)
{
	System::UnicodeString str, sj, strJson;
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
//		str = RESTResponse1->Content;
		str = mmoJSON->Lines->Text;
		try {
			jobj = ReadJSon ("d:\\Users\\one4\\Documents\\Embarcadero\\Studio\\Projects\\SEMon\\j1.json");
			if (jobj)
				ShowMessage (String(jobj->Size()));
			jobj = (TJSONObject *) TJSONObject::ParseJSONValue(mmoJSON->Lines->Text);
			if (jobj)
				ShowMessage (String(jobj->Size()));
			jobj = (TJSONObject *) TJSONObject::ParseJSONValue(mmoJSON->Lines->Text, true);
			if (jobj)
				ShowMessage (String(jobj->Size()));
/*
			try {
				ja = (TJSONArray *) TJSONObject::ParseJSONValue(str);
				for (int n=0 ; n < jobj->Size() ; n++) {
					jpair = jobj->Get(n);
					jstring = jpair->JsonString;
				}
			} catch (Exception &e) {
				ShowMessage (e.Message);
			}
*/
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
