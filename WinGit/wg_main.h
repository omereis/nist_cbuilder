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
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall btnSelDirTestClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
