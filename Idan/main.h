//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.SqlExpr.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include "ChannelInfo.h"
#include <Vcl.AppEvnts.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TFDConnection *WatertemperaturesConnection;
	TButton *btnLoadFile;
	TOpenDialog *dlgOpenTxt;
	TMemo *memoFileData;
	TLabel *Label1;
	TEdit *edtLines;
	TButton *btnUpdate;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *edtChannels;
	TEdit *edtDataStart;
	TEdit *edtHeadings;
	TUpDown *udChannels;
	TUpDown *udHeading;
	TUpDown *udDataStart;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *LoadData1;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TButton *btnParseData;
	TStringGrid *gridData;
	TApplicationEvents *ApplicationEvents1;
	void __fastcall btnLoadFileClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall LoadData1Click(TObject *Sender);
	void __fastcall btnParseDataClick(TObject *Sender);
	int __fastcall GetChannelsLine ();
	void __fastcall SetChannelsLine (int nLine);
	void __fastcall OnIdle(TObject *Sender, bool &Done);
private:	// User declarations
	int m_rowChannels;
	int m_rowHeadings;
	int m_rowDataStart;
	TChannelInfoVec m_vChannels;
	String m_strFile;
protected:	// User declarations
	String __fastcall LoadData ();
public:		// User declarations
	__property int ChannelsLine = {read=GetChannelsLine, write=SetChannelsLine};
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
