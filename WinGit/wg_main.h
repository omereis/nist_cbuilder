//---------------------------------------------------------------------------

#ifndef wg_mainH
#define wg_mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Outline.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <IPPeerClient.hpp>
#include <REST.Client.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <REST.Types.hpp>
//---------------------------------------------------------------------------
#ifndef _MSC_VER
#define  _MSC_VER
#endif
//---------------------------------------------------------------------------
#ifdef	__amigaos4__
#undef   __amigaos4__
#endif
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *dlgSelectDir;
	TButton *Button1;
	TButton *Button2;
	TDirectoryListBox *DirectoryListBox1;
	TDriveComboBox *DriveComboBox1;
	TFileListBox *FileListBox1;
	TButton *btnSelDirTest;
	TButton *btnConnect;
	TButton *btnRepo;
	TOpenDialog *OpenDialog1;
	TButton *Button4;
	TPanel *Panel1;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TMemo *Memo1;
	TBindingsList *BindingsList1;
	TLinkControlToField *LinkControlToField1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall btnSelDirTestClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
