//---------------------------------------------------------------------------

#ifndef MiscH
#define MiscH
//---------------------------------------------------------------------------
#include <Grids.hpp>
#include <stdio.h>
#include <inifiles.hpp>
#include <cwchar>
#include <iostream>
//---------------------------------------------------------------------------
void __fastcall EnableEdit  (TEdit *edt, bool fEnabled);
void __fastcall ClearGrid (TStringGrid *grid);
void __fastcall PurgeGrid (TStringGrid *grid);
String __fastcall Reverse (const String &strSrc);
void __fastcall WriteH (FILE *fileInclude, const String &strPrototype);
void __fastcall WriteSepLine (FILE *file);
String __fastcall Reverse (const String &strSrc);
void __fastcall SaveIni (const String &strFile, const String &strSec, const String &Ident, const String &strValue);
String __fastcall LoadIniString  (const String &strFile, const String &strSec, const String &Ident);
void __fastcall SetComboText (TComboBox *combo, const String &str);
void __fastcall ClearGridRow (TStringGrid *grid, int nRow);
void __fastcall DeleteLine (TStringGrid *grid, int nRow);
String __fastcall RemoveCRLF (const String &strSrc);
int __fastcall Tokenize (const String &strLine, TStringList *lstr, const String &strDelimiter = ",");

//---------------------------------------------------------------------------
#endif
