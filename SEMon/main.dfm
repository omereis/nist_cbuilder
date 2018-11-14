object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'SolarEdge Site Monitor'
  ClientHeight = 336
  ClientWidth = 803
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 312
    Top = 35
    Width = 289
    Height = 249
    TabOrder = 0
  end
  object btnStatus: TButton
    Left = 64
    Top = 35
    Width = 75
    Height = 25
    Caption = 'Status'
    TabOrder = 1
    OnClick = btnStatusClick
  end
  object bitbtnSolarEdge: TBitBtn
    Left = 616
    Top = 24
    Width = 179
    Height = 73
    Cursor = crHandPoint
    Glyph.Data = {
      C60A0000424DC60A00000000000076000000280000009E000000210000000100
      040000000000500A0000C40E0000C40E00001000000000000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FF89999999999999999999999999999999999999999998FFFFFFFFFFF8999999
      9999997FFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF999999999999999999999999999999
      9999999999997FFFFFFFFFFFFF79999999999999FFFFFFFFFF00FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FF799999999999999999999999999999999999999999FFFFF88888FFFFF99999
      999999998FFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF899999999999999999999999999999
      999999999999FFFF7999998FFFF99999999999999FFFFFFFFF00FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFF99999999999999999999999999999999999999997FFFF9999999FFFF79999
      9999999998FFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF79999999999999999999999999999
      999999999999888799999998FFF899999999999998FFFFFFFF00FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFF89999999999999999999999999999999999999999999999999998FFF89999
      9999999999FFFFFFFF00FF870000000778FFFFFFF87700000077FFFFFF87777F
      FFFF875000077F77778FFF77778FFFFFFFFF9999988FFFFFFF88999999978FFF
      FF897FFF8999998FFFFF8798FFF8999998FFFFFFFFFFFFFFFF00F70000000000
      007FFFFF70000000000008FFFF80000FFFF8000000000770007FFF70007FFFFF
      FFFF99998FFFFFFFFFFFF999998FFFFFFFF87FFFF9999FFFFFFFFF78FFF89998
      FFFFFFFFFFFFFFFFFF008000000150000007FFF800000000000000FFFF80001F
      FFF0000000700000007FFF70007FFFFFFFFF8998FFFFFFFFFFFFFF9998FFFFFF
      FFFF8FFFF999FFFFFFFFFFFFFFF8997FFFFFFFFFFFFFFFFFFF00700008FFFFF7
      0000FFF7000078887700007FFF80001FFF800007FFFF8700007FFF70007FFFFF
      FFFFF99FFFFF88888FFFFF999FFFFF88888FFFFFF997FFFFF88888FFFFF8998F
      FFF888888FFFFFFFFF0000008FFFFFFF00008FF00007FFFFFF70007FFF80001F
      FF70007FFFFFFF00007FFF70007FFFFFFFFFF98FFFF9999999FFFF899FFFF899
      9999FFFFF998FFFF9999998FFFF899FFFF89999998FFFFFFFF0050008FFFFFFF
      00008F80000FFFFFFF80000FFF80001FFF70007FFFFFFF70007FFF70007FFFFF
      FFFFF88FFF899999998FFF897FFFF99999998FFFF998FFF89999999FFFF897FF
      FF99999997FFFFFFFF00FFFFFFFFFFF800008F80000FFFFFFF80000FFF80001F
      FF70007FFFFFFF70007FFF70007FFFFFFFFFFF8FFF899999999999997FFFF999
      99998FFFF99FFFF89999999FFFF897FFFF9999999999FFFFFF00FFFFF8888870
      0000FF80000FFFFFFFF0000FFF80001FFF700008FFFFF700007FFF70007FFFFF
      FFFFFFFFFF799999999999998FFFF99999998FFFF99FFFF899999998FFF898FF
      FF99999999997FFFFF00FF71000000000007FF80000FFFFFFFF0000FFF80001F
      FF80000077777000007FFF70007FFFFFFFFFFFFFFF888888888888798FFFF999
      99998FFFF99FFFF899999998FFF898FFFF88888888888FFFFF00800000000000
      007FFF80000FFFFFFFF0000FFF80001FFFF7000000000770007FFF70007FFFFF
      FFFFFFFFFFFFFFFFFFFFFF898FFFF99999998FFFF99FFFF899999998FFF898FF
      FFFFFFFFFFFFFFFFFF0070000000000178FFFF80000FFFFFFFF0000FFF80001F
      FFFF870000007F70007FFF70007FFFFFFFFFFFFFFFFFFFFFFFFFFF898FFFF999
      99998FFFF99FFFF899999998FFF898FFFFFFFFFFFFFFFFFFFF00700078888FFF
      FFFFFF80000FFFFFFF80000FFF80001FFFFFFFF88888FF70007FFF70007FFFFF
      7777FFFFFF87777777FFFF898FFFF99999998FFFF99FFFF89999999FFFF897FF
      FF77777778FFFFFFFF0000008FFFFFFFFFFFFF80000FFFFFFF80000FFF80001F
      FFFFFFFFFFFFFF70007FFF70007FFFF80007FFFFFF799999998FFF797FFFF999
      99998FFFF998FFF89999999FFFF897FFFF99999997FFF88FFF0000008FFFFFF7
      7778FF800008FFFFFF70007FFF80001FFFF00008FFFFFF70008FFF70007FFFF8
      0007FFFFFF89999999FFFF997FFFF7999999FFFFF998FFFF9999997FFFF899FF
      FF99999998FFF87FFF0000007FFFFFF00007FFF000008FFFF800007FFF80001F
      FFF00007FFFFF800008FFF700007FFF70007FFFFFFF8999998FFFF999FFFFF79
      9978FFFFF998FFFF899998FFFFF899FFFF8799997FFFF79FFF00700007777770
      0008FFF7000000000000008FFF80001FFFF700007777700000FFFF7000000000
      0007FFFFFFFFFFFFFFFFF89998FFFFFFFFFFFFFFF999FFFFFFFFFFFFFFF8998F
      FFFFFFFFFFFFF998FF00800000000000007FFFFF70000000000007FFFF80001F
      FFFF00000000000008FFFF7000700000000FFFFFFFFFFFFFFFFFF99999FFFFFF
      FFFF8FFFF9998FFFFFFFFF88FFF89998FFFFFFFFFFFF8998FF00F87000000000
      07FFFFFFF700000000077FFFFF80001FFFFFF700000000078FFFFF70008F7000
      008FFFFFFFFFFFFFFFF899999998FFFFFFF77FFFF99998FFFFFFF898FFF89999
      8FFFFFFFFF879999FF00FFFF88777788FFFFFFFFFFF8887788FFFFFFFF80001F
      FFFFFFF8877788FFFFFFFFF888FFF8778FFFFFFFFF9788887799999999999788
      87998FFFF9999997888799977779999999978888799999998F00FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFF80001FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFF799999999999999999999999998FFFF99999999999999999999999
      99999999999999998F00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF80001F
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8999999999999999999999
      99998FFFF9999999999999999999999999999999999999999F00FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFF80001FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFF99999999999999999999999998FFFF99999999999999999999999
      99999999999999999F00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF80001F
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF799999999999999999999
      99998FFFF9999999999999999999999999999999999999999800FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFF80001FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFF89999999999999999999999998FFFF99999999999999999999999
      99999999999999999900FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF80000F
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF79999999999999999999
      99997FFFF9999999999999999999999999999999999999999900FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFF80007FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFF879999999999999999999998FFFF99999999999999999999999
      99999999999999999800}
    TabOrder = 2
    OnClick = bitbtnSolarEdgeClick
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 317
    Width = 803
    Height = 19
    Panels = <>
  end
  object StatusBar2: TStatusBar
    Left = 0
    Top = 298
    Width = 803
    Height = 19
    Panels = <>
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 803
    Height = 29
    ButtonHeight = 25
    Caption = 'ToolBar1'
    EdgeBorders = [ebBottom]
    TabOrder = 5
    object BitBtn1: TBitBtn
      Left = 0
      Top = 0
      Width = 57
      Height = 25
      Caption = 'BitBtn1'
      ModalResult = 3
      TabOrder = 0
    end
  end
  object gridStatus: TStringGrid
    Left = 120
    Top = 128
    Width = 320
    Height = 120
    ColCount = 2
    DefaultColWidth = 100
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
    TabOrder = 6
    ColWidths = (
      100
      174)
  end
  object btnRead: TButton
    Left = 145
    Top = 35
    Width = 75
    Height = 25
    Caption = 'Read'
    TabOrder = 7
    OnClick = btnReadClick
  end
  object mmoJSON: TMemo
    Left = 560
    Top = 120
    Width = 185
    Height = 89
    Lines.Strings = (
      '{"sites":{"count":1,"site":'
      '[{"id":714303,"name":"Idan '
      'Cohen '
      'Gvaot","accountId":53508,"status":'
      '"Active","peakPower"'
      ':7.47,"lastUpdateTime":"2018-11-'
      '14","installationDate":"2018-05-'
      '08","ptoDate":null,"notes":"","type"'
      ':"Optimizers & '
      'Inverters","location":'
      '{"country":"Israel","city":"Giv'#39'ot '
      'Bar","address":"Yakinton Street, '
      'Yakinton '
      'Street","address2":"","zip":"123456'
      '","timeZone":"Asia/Je'
      'rusalem","countryCode":"IL"},"prim'
      'aryModule":'
      '{"manufacturerName":"Suntech","m'
      'odelName":"STP325-'
      '24/vfm","maximumPower":325.0,"t'
      'emperatureCoef":-'
      '0.8},"uris":'
      '{"DETAILS":"/site/714303/details","'
      'DATA_PERIOD":"/site'
      '/714303/dataPeriod","OVERVIEW":"'
      '/site/714303/overvie'
      'w"},"publicSettings":'
      '{"isPublic":false}}]}}')
    TabOrder = 8
  end
  object RESTClient1: TRESTClient
    Accept = 'application/json, text/plain; q=0.9, text/html;q=0.8,'
    AcceptCharset = 'UTF-8, *;q=0.8'
    BaseURL = 'https://monitoringapi.solaredge.com/sites/list'
    Params = <>
    HandleRedirects = True
    Left = 56
    Top = 96
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <
      item
        name = 'id'
        Value = '714303'
      end
      item
        name = 'api_key'
        Value = 'K5FAMYTKQC619FBG8K09JMOZGZ1B18QJ'
      end>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 56
    Top = 144
  end
  object RESTResponse1: TRESTResponse
    ContentType = 'application/json'
    Left = 56
    Top = 200
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    Left = 28
    Top = 37
    object LinkControlToField1: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTResponse1
      FieldName = 'Content'
      Control = Memo1
      Track = False
    end
  end
end
