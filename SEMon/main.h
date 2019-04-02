//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.Bind.EngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TBindingsList *BindingsList1;
	TLinkControlToField *LinkControlToField1;
	TButton *btnStatus;
	TBitBtn *bitbtnSolarEdge;
	TStatusBar *StatusBar1;
	TStatusBar *StatusBar2;
	TToolBar *ToolBar1;
	TBitBtn *BitBtn1;
	TStringGrid *gridStatus;
	TButton *btnRead;
	TMemo *mmoJSON;
	TMemo *Memo2;
	void __fastcall bitbtnSolarEdgeClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnStatusClick(TObject *Sender);
	void __fastcall btnReadClick(TObject *Sender);
private:	// User declarations
	void __fastcall TfrmMain::InitStatusGrid ();
	void __fastcall JSonToStringGrid (const String &strText, int nRow, int nLevel);
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
