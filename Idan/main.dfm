object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'DAD Data Viewer'
  ClientHeight = 377
  ClientWidth = 1067
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 248
    Top = 8
    Width = 28
    Height = 13
    Caption = 'Lines:'
  end
  object Label2: TLabel
    Left = 8
    Top = 176
    Width = 44
    Height = 13
    Caption = 'Channels'
  end
  object Label3: TLabel
    Left = 8
    Top = 232
    Width = 39
    Height = 13
    Caption = 'Heading'
  end
  object Label4: TLabel
    Left = 8
    Top = 288
    Width = 50
    Height = 13
    Caption = 'Data Start'
  end
  object btnLoadFile: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = '&Load File...'
    TabOrder = 0
    OnClick = btnLoadFileClick
  end
  object memoFileData: TMemo
    Left = 168
    Top = 32
    Width = 395
    Height = 337
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object edtLines: TEdit
    Left = 296
    Top = 5
    Width = 57
    Height = 21
    Alignment = taCenter
    TabOrder = 2
    Text = '1000'
  end
  object btnUpdate: TButton
    Left = 376
    Top = 3
    Width = 75
    Height = 25
    Caption = 'Update'
    TabOrder = 3
  end
  object Button1: TButton
    Left = 32
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Load Params'
    TabOrder = 4
  end
  object Button2: TButton
    Left = 16
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Save Params'
    TabOrder = 5
  end
  object edtChannels: TEdit
    Left = 12
    Top = 195
    Width = 46
    Height = 21
    TabOrder = 6
    Text = '25'
  end
  object edtDataStart: TEdit
    Left = 12
    Top = 304
    Width = 46
    Height = 21
    TabOrder = 7
    Text = '29'
  end
  object edtHeadings: TEdit
    Left = 12
    Top = 251
    Width = 46
    Height = 21
    TabOrder = 8
    Text = '28'
  end
  object udChannels: TUpDown
    Left = 58
    Top = 195
    Width = 16
    Height = 21
    Associate = edtChannels
    Min = 1
    Max = 1000
    Position = 25
    TabOrder = 9
  end
  object udHeading: TUpDown
    Left = 58
    Top = 251
    Width = 16
    Height = 21
    Associate = edtHeadings
    Min = 1
    Max = 1000
    Position = 28
    TabOrder = 10
  end
  object udDataStart: TUpDown
    Left = 58
    Top = 304
    Width = 16
    Height = 21
    Associate = edtDataStart
    Min = 1
    Max = 1000
    Position = 29
    TabOrder = 11
  end
  object btnParseData: TButton
    Left = 96
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Parse Data'
    TabOrder = 12
    OnClick = btnParseDataClick
  end
  object gridData: TStringGrid
    Left = 584
    Top = 32
    Width = 449
    Height = 337
    ColCount = 2
    FixedCols = 0
    RowCount = 3
    FixedRows = 2
    GradientStartColor = 14079702
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
    TabOrder = 13
    RowHeights = (
      24
      24
      24)
  end
  object WatertemperaturesConnection: TFDConnection
    Params.Strings = (
      'ConnectionDef=WaterTemperatures')
    LoginPrompt = False
    Left = 483
    Top = 12
  end
  object dlgOpenTxt: TOpenDialog
    Filter = 'Text Files|*.txt|Data Files|*.dat|All Files|*.*'
    Left = 520
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 80
    Top = 256
    object File1: TMenuItem
      Caption = '&File'
      object LoadData1: TMenuItem
        Caption = '&Load Data...'
        OnClick = LoadData1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'E&xit'
        OnClick = Exit1Click
      end
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnIdle = OnIdle
    Left = 568
    Top = 8
  end
end
