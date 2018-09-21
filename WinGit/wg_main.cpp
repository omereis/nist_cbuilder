//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "wg_main.h"
#include "FileCtrl.hpp"
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
void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
	TCHAR szDir[MAX_PATH];
	BROWSEINFO bInfo;
	String strDir, strTitle ("Please, select a folder");

	bInfo.hwndOwner = Handle;
	bInfo.pidlRoot = NULL;
	bInfo.pszDisplayName = szDir; // Address of a buffer to receive the display name of the folder selected by the user
	bInfo.lpszTitle = strTitle.c_str();
	bInfo.ulFlags = BIF_USENEWUI;
	bInfo.lpfn = NULL;
	bInfo.lParam = 0;
	bInfo.iImage = -1;

	LPITEMIDLIST lpItem = SHBrowseForFolder( &bInfo);
	if( lpItem != NULL )
	{
		SHGetPathFromIDList(lpItem, szDir );
		strDir = String (szDir);
  //......
	}
	if (strDir.Length()) {
		ShowMessage (strDir);
	}
	else {
        ShowMessage ("No Dir Selected");
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnSelDirTestClick(TObject *Sender)
{
	String dir = "d:\\Users\\one4\\Documents\\Embarcadero\\Studio\\Projects\\WinGit";

	if (SelectDirectory(dir, TSelectDirOpts()  << sdAllowCreate << sdPerformCreate << sdPrompt, 0))
		ShowMessage ("Selected directory:\n" + dir);
}
//---------------------------------------------------------------------------


