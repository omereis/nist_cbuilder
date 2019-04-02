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
TJSONObject *__fastcall ReadJSonString (const String &strJSON)
{
	TJSONObject *jobj = NULL;

	try {
		jobj = (TJSONObject *) TJSONObject::ParseJSONValue(strJSON, true);
	}
	catch (...) {
		jobj = NULL;
	}
	return (jobj);
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
		ReadJSonString (lstr->Text);
//		jobj = (TJSONObject *) TJSONObject::ParseJSONValue(lstr->Text, true);
	}
	__finally {
		delete lstr;
	}
	return (jobj);
}
//---------------------------------------------------------------------------
bool __fastcall IsJsonArray (const String &str)
{
	bool fArray = false;

	if (str[1] == '[')
		if (str[str.Length()] == ']')
			fArray = true;
	return (fArray);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::JSonToStringGrid (const String &strText, int nRow, int nLevel)
{
	String strJson = RemoveCRLF (strText);
	TJSONObject *jObj;
	TJSONPair *jPair;
	TJSONString *jstr;
	TJSONValue *jval;
	String str, strVal;
	TJSONArray *jarray;
	int nCol;
	jObj = ReadJSonString (strJson);
	for (int n=0 ; n < jObj->Count ; n++) {
		try {
			jPair = jObj->Get(n);
			jstr = jPair->JsonString;
			jval = jPair->JsonValue;

			str = jstr->Value();
			if (gridStatus->RowCount <= nRow + n) {
				gridStatus->RowCount = nRow + n;
			}
			gridStatus->Cells[nLevel][nRow + n] = jstr->Value();
			gridStatus->Cells[nLevel + 1][nRow + n] = jval->Value();
			str = jval->Value();
			if (str.Length() == 0) {
				strVal = jval->ToString ();
				if (IsJsonArray (strVal)) {
					jarray = (TJSONArray *) jval;//->Value();
					str = jarray->Size();
					for (int i=0 ; i < jarray->Size() ; i++) {
						nCol = nLevel + i;
						jval = jarray->Items[i];
						if (gridStatus->ColCount <= nCol)
							gridStatus->ColCount >= nCol + 1;
						gridStatus->Cells[nCol][nRow] = jval->Value();
					}
				}
				else if (strVal.Length())
					JSonToStringGrid (strVal, nRow + n, nLevel + 1);
		}
		} catch (Exception &e) {
            ShowMessage (e.Message);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnReadClick(TObject *Sender)
{
	System::UnicodeString str, sj, strJson;
	TStringList *lstr = new TStringList;
	TJSONObject *jobj;
	TJSONPair *jPair;
	TJSONString *jstr, *jstr1;
	TJSONValue *jval;

	int nCode = RESTResponse1->StatusCode;
	if (nCode == 0) {
		nCode = 200;
		str = mmoJSON->Lines->Text;
	}
	if (nCode == 200) {
		PurgeGrid (gridStatus);
		JSonToStringGrid (mmoJSON->Lines->Text, 1, 0);
/*
		String str1, str2;
		int nPos;
//		str = RESTResponse1->Content;
		str = mmoJSON->Lines->Text;
		str1 = StringReplace (str, "\n","", TReplaceFlags () << rfReplaceAll);
		nPos = str1.Pos("\n");
		str2 = StringReplace (str1, "\r","", TReplaceFlags () << rfReplaceAll);
		nPos = str1.Pos("\r");
		Memo2->Lines->Text = str2;
		jobj = ReadJSonString (str2);
		if (jobj) {
			PurgeGrid (gridStatus);
			gridStatus->RowCount = gridStatus->FixedRows + std::max (1, jobj->Count);
			str = StringReplace (jobj->ToString(), "\r","", TReplaceFlags () << rfReplaceAll);
			str1 = StringReplace (jobj->ToString(), "\n","", TReplaceFlags () << rfReplaceAll);
			Memo1->Lines->Text = str1;//jobj->ToString();
			for (int n=0 ; n < jobj->Count ; n++) {
				jPair = jobj->Get(n);
				jstr = jPair->JsonString;
				jval = jPair->JsonValue;

				gridStatus->Cells[0][n+1] = jstr->Value();
				gridStatus->Cells[1][n+1] = jval->Value();
				jstr = (TJSONString *) jval;
			}
		}
*/
/*
		try {
		}
		__finally {
			if (jobj)
				delete jobj;
			if (ja)
				delete ja;
			delete lstr;
		}
*/
	}
	str += String (nCode);
}
//---------------------------------------------------------------------------
