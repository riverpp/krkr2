object LabelDetailForm: TLabelDetailForm
  Left = 151
  Top = 185
  ActiveControl = EditLabelAttribFrame.LabelNameEdit
  BorderStyle = bsDialog
  BorderWidth = 8
  Caption = '���x���̕ҏW'
  ClientHeight = 66
  ClientWidth = 380
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = '�l�r �o�S�V�b�N'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 12
  inline EditLabelAttribFrame: TEditLabelAttribFrame
    Width = 380
    Align = alTop
  end
  object OKButton: TButton
    Left = 202
    Top = 40
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 1
    OnClick = OKButtonClick
  end
  object CancelButton: TButton
    Left = 290
    Top = 40
    Width = 75
    Height = 25
    Cancel = True
    Caption = '�L�����Z��'
    TabOrder = 2
    OnClick = CancelButtonClick
  end
end
