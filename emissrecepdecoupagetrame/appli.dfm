object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 589
  ClientWidth = 1011
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object latitude: TLabel
    Left = 49
    Top = 328
    Width = 36
    Height = 13
    Caption = 'latitude'
  end
  object longitude: TLabel
    Left = 528
    Top = 400
    Width = 44
    Height = 13
    Caption = 'longitude'
  end
  object ButtonSend: TButton
    Left = 32
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Envoyer'
    TabOrder = 0
    OnClick = ButtonSendClick
  end
  object ButtonReceive: TButton
    Left = 176
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Recevoir'
    TabOrder = 1
    OnClick = ButtonReceiveClick
  end
  object Memo1: TMemo
    Left = 144
    Top = 142
    Width = 737
    Height = 177
    TabOrder = 2
  end
  object Edit1: TEdit
    Left = 208
    Top = 104
    Width = 585
    Height = 21
    TabOrder = 3
  end
  object Memo2: TMemo
    Left = 104
    Top = 368
    Width = 385
    Height = 181
    TabOrder = 4
  end
  object Memo3: TMemo
    Left = 610
    Top = 368
    Width = 351
    Height = 176
    TabOrder = 5
  end
end