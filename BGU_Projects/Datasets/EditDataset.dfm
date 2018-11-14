object dlgEditDataset: TdlgEditDataset
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Datasets'
  ClientHeight = 326
  ClientWidth = 635
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 38
    Top = 22
    Width = 27
    Height = 13
    Caption = 'Name'
  end
  object Label2: TLabel
    Left = 46
    Top = 49
    Width = 19
    Height = 13
    Caption = 'URL'
  end
  object Label3: TLabel
    Left = 12
    Top = 107
    Width = 53
    Height = 13
    Caption = 'Description'
  end
  object Label4: TLabel
    Left = 20
    Top = 187
    Width = 45
    Height = 13
    Caption = 'Structure'
  end
  object Label5: TLabel
    Left = 17
    Top = 137
    Width = 48
    Height = 13
    Caption = 'Username'
  end
  object Label6: TLabel
    Left = 19
    Top = 164
    Width = 46
    Height = 13
    Caption = 'Password'
  end
  object Label7: TLabel
    Left = 4
    Top = 76
    Width = 61
    Height = 13
    Caption = 'Organization'
  end
  object bitbtnOK: TBitBtn
    Left = 212
    Top = 295
    Width = 75
    Height = 25
    TabOrder = 8
    Kind = bkOK
  end
  object bitbtnCancel: TBitBtn
    Left = 293
    Top = 295
    Width = 75
    Height = 25
    TabOrder = 9
    Kind = bkCancel
  end
  object edtName: TEdit
    Left = 71
    Top = 18
    Width = 465
    Height = 21
    TabOrder = 0
    Text = 'edtName'
  end
  object edtURL: TEdit
    Left = 71
    Top = 45
    Width = 465
    Height = 21
    TabOrder = 1
    Text = 'edtURL'
  end
  object edtUsername: TEdit
    Left = 71
    Top = 133
    Width = 151
    Height = 21
    TabOrder = 4
    Text = 'edtUsername'
  end
  object edtPasswors: TEdit
    Left = 74
    Top = 160
    Width = 151
    Height = 21
    TabOrder = 5
    Text = 'edtPasswors'
  end
  object memoStructure: TMemo
    Left = 74
    Top = 187
    Width = 303
    Height = 89
    Lines.Strings = (
      'memoStructure')
    TabOrder = 6
  end
  object edtDescription: TEdit
    Left = 71
    Top = 103
    Width = 465
    Height = 21
    TabOrder = 3
    Text = 'edtDescription'
  end
  object GroupBox1: TGroupBox
    Left = 383
    Top = 130
    Width = 247
    Height = 158
    Caption = 'Contacts'
    TabOrder = 7
    object lboxContacts: TListBox
      Left = 3
      Top = 17
      Width = 153
      Height = 125
      ItemHeight = 13
      TabOrder = 0
    end
    object bitbtnAdd: TBitBtn
      Left = 162
      Top = 17
      Width = 75
      Height = 25
      Caption = 'bitbtnAdd'
      TabOrder = 1
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        04000000000080000000C40E0000C40E00001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2222FFFFFFFFFFFF2222FF
        FFFFFFFFFF2222FFFFFFFFFFFF2222FFFFFFFF222222222222FFFF2222222222
        226FFF2222222222226FFFF666222266666FFFFFFF22226FFFFFFFFFFF22226F
        FFFFFFFFFF22226FFFFFFFFFFFF6666FFFFFFFFFFFFFFFFFFFFF}
    end
    object bitbtnEdit: TBitBtn
      Left = 160
      Top = 48
      Width = 75
      Height = 25
      Caption = 'bitbtnEdit'
      TabOrder = 2
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        04000000000080000000C40E0000C40E00001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        888888000000000000088803330DDD0EEE088803330DDD0EEE088803330DDD0E
        EE0888000000000000088805550BBB0AAA088805550BBB0AAA088805550BBB0A
        AA08880000000000000888044409990222088804440999022208880444099902
        2208880000000000000888888888888888888888888888888888}
    end
    object bitbtnDel: TBitBtn
      Left = 161
      Top = 87
      Width = 75
      Height = 25
      TabOrder = 3
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        04000000000080000000C40E0000C40E00001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF999999999999FFFF9999999999
        991FFF9999999999991FFFF111111111111FFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
    end
  end
  object panelID: TPanel
    Left = 542
    Top = 8
    Width = 57
    Height = 25
    Caption = 'panelID'
    TabOrder = 10
  end
  object edtOrg: TEdit
    Left = 71
    Top = 72
    Width = 465
    Height = 21
    TabOrder = 2
    Text = 'edtOrg'
  end
  object btnURLTest: TButton
    Left = 542
    Top = 43
    Width = 75
    Height = 25
    Caption = '&Test...'
    TabOrder = 11
    OnClick = btnURLTestClick
  end
  object panelChars: TPanel
    Left = 8
    Top = 208
    Width = 65
    Height = 25
    Caption = 'panelChars'
    TabOrder = 12
  end
  object ApplicationEvents1: TApplicationEvents
    OnIdle = OnIdle
    Left = 568
    Top = 104
  end
end
