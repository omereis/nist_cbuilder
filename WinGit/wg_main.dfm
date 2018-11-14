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
    Left = 400
    Top = 32
    Width = 75
    Height = 25
    Caption = 'Shutdown'
    TabOrder = 1
    OnClick = Button2Click
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
    Caption = 'Init'
    TabOrder = 8
    OnClick = Button4Click
  end
  object Panel1: TPanel
    Left = 40
    Top = 19
    Width = 521
    Height = 294
    TabOrder = 9
    object Memo1: TMemo
      Left = 152
      Top = 24
      Width = 281
      Height = 249
      Lines.Strings = (
        '[{"internalId":"5ba651504ad8714da424660c","ticker":"'
        'CCEUSP01JPA651N","date":"1999-01-'
        '01T00:00:00Z","value":0.973425484279178},'
        '{"internalId":"5ba651504ad8714da4246626","ticker":"C'
        'CEUSP01JPA651N","date":"2000-01-'
        '01T00:00:00Z","value":0.935278713056491},'
        '{"internalId":"5ba651504ad8714da424662f","ticker":"C'
        'CEUSP01JPA651N","date":"2001-01-'
        '01T00:00:00Z","value":0.867077083152692},'
        '{"internalId":"5ba651504ad8714da4246638","ticker":"C'
        'CEUSP01JPA651N","date":"2002-01-'
        '01T00:00:00Z","value":0.803923144947343},'
        '{"internalId":"5ba651504ad8714da4246677","ticker":"C'
        'CEUSP01JPA651N","date":"2003-01-'
        '01T00:00:00Z","value":0.740466493891151},'
        '{"internalId":"5ba651504ad8714da424667f","ticker":"C'
        'CEUSP01JPA651N","date":"2004-01-'
        '01T00:00:00Z","value":0.716075904045829},'
        '{"internalId":"5ba651504ad8714da424668d","ticker":"C'
        'CEUSP01JPA651N","date":"2005-01-'
        '01T00:00:00Z","value":0.719942404607631},'
        '{"internalId":"5ba651504ad8714da4246696","ticker":"C'
        'CEUSP01JPA651N","date":"2006-01-'
        '01T00:00:00Z","value":0.63722678901421},'
        '{"internalId":"5ba651504ad8714da42466a4","ticker":"C'
        'CEUSP01JPA651N","date":"2007-01-'
        '01T00:00:00Z","value":0.606317831807433},'
        '{"internalId":"5ba651504ad8714da42466b2","ticker":"C'
        'CEUSP01JPA651N","date":"2008-01-'
        '01T00:00:00Z","value":0.792769938163945},'
        '{"internalId":"5ba651504ad8714da42466c6","ticker":"C'
        'CEUSP01JPA651N","date":"2009-01-'
        '01T00:00:00Z","value":0.750976269149895},'
        '{"internalId":"5ba651504ad8714da42466d5","ticker":"C'
        'CEUSP01JPA651N","date":"2010-01-'
        '01T00:00:00Z","value":0.92038656235619},'
        '{"internalId":"5ba651504ad8714da42466e2","ticker":"C'
        'CEUSP01JPA651N","date":"2011-01-'
        '01T00:00:00Z","value":0.998003992015968},'
        '{"internalId":"5ba651504ad8714da42466ec","ticker":"C'
        'CEUSP01JPA651N","date":"2012-01-'
        '01T00:00:00Z","value":0.880204207376111},'
        '{"internalId":"5ba651504ad8714da42466ff","ticker":"C'
        'CEUSP01JPA651N","date":"2013-01-'
        '01T00:00:00Z","value":0.690989496959646},'
        '{"internalId":"5ba651504ad8714da424670f","ticker":"C'
        'CEUSP01JPA651N","date":"2014-01-'
        '01T00:00:00Z","value":0.688562969083523},'
        '{"internalId":"5ba651504ad8714da4246721","ticker":"C'
        'CEUSP01JPA651N","date":"2015-01-'
        '01T00:00:00Z","value":0.762951094834821},'
        '{"internalId":"5ba651504ad8714da424672b","ticker":"C'
        'CEUSP01JPA651N","date":"2016-01-'
        '01T00:00:00Z","value":0.810372771474878},'
        '{"internalId":"5ba651504ad8714da4246748","ticker":"C'
        'CEUSP01JPA651N","date":"2017-01-'
        '01T00:00:00Z","value":0.740685875120362}]')
      TabOrder = 0
    end
  end
  object dlgSelectDir: TOpenDialog
    InitialDir = 'd:\omer'
    Options = [ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 592
    Top = 64
  end
  object OpenDialog1: TOpenDialog
    Options = [ofEnableSizing]
    Left = 584
    Top = 16
  end
  object RESTClient1: TRESTClient
    Accept = 'application/json, text/plain; q=0.9, text/html;q=0.8,'
    AcceptCharset = 'UTF-8, *;q=0.8'
    BaseURL = 'http://www.webservicex.net:500/Prices'
    Params = <>
    HandleRedirects = True
    Left = 48
    Top = 32
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <
      item
        name = 'ticker'
        Value = 'CCEUSP01JPA651N'
      end>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 48
    Top = 96
  end
  object RESTResponse1: TRESTResponse
    ContentType = 'application/json'
    Left = 40
    Top = 184
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    Left = 20
    Top = 5
    object LinkControlToField1: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTResponse1
      FieldName = 'Content'
      Control = Memo1
      Track = False
    end
  end
end
