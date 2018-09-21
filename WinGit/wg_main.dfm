object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'Git for Windows'
  ClientHeight = 336
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 112
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 344
    Top = 176
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 1
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 257
    Top = 207
    Width = 145
    Height = 97
    TabOrder = 2
  end
  object DriveComboBox1: TDriveComboBox
    Left = 96
    Top = 200
    Width = 145
    Height = 19
    TabOrder = 3
  end
  object FileListBox1: TFileListBox
    Left = 408
    Top = 200
    Width = 145
    Height = 97
    ItemHeight = 13
    TabOrder = 4
  end
  object btnSelDirTest: TButton
    Left = 479
    Top = 120
    Width = 116
    Height = 25
    Caption = 'Select Directory Test'
    TabOrder = 5
    OnClick = btnSelDirTestClick
  end
  object btnConnect: TButton
    Left = 8
    Top = 40
    Width = 89
    Height = 25
    Caption = 'Connect...'
    TabOrder = 6
  end
  object btnRepo: TButton
    Left = 8
    Top = 9
    Width = 89
    Height = 25
    Caption = 'Select Repo...'
    TabOrder = 7
  end
  object Button4: TButton
    Left = 304
    Top = 32
    Width = 75
    Height = 25
    Caption = 'Button4'
    TabOrder = 8
  end
  object dlgSelectDir: TOpenDialog
    InitialDir = 'd:\omer'
    Options = [ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 248
    Top = 128
  end
  object OpenDialog1: TOpenDialog
    Options = [ofEnableSizing]
    Left = 152
    Top = 48
  end
end
