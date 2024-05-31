object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1055#1088#1080#1083#1086#1078#1077#1085#1080#1077
  ClientHeight = 372
  ClientWidth = 906
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object LVThead: TLabel
    Left = 248
    Top = 276
    Width = 78
    Height = 15
    Caption = 'Last visit time: '
  end
  object LastVisitTimeLabel: TLabel
    Left = 332
    Top = 276
    Width = 3
    Height = 15
  end
  object VirtualStringTreeTable: TVirtualStringTree
    Left = 8
    Top = 8
    Width = 890
    Height = 257
    Colors.BorderColor = 15987699
    Colors.DisabledColor = clGray
    Colors.DropMarkColor = 15385233
    Colors.DropTargetColor = 15385233
    Colors.DropTargetBorderColor = 15385233
    Colors.FocusedSelectionColor = 15385233
    Colors.FocusedSelectionBorderColor = 15385233
    Colors.GridLineColor = 15987699
    Colors.HeaderHotColor = clBlack
    Colors.HotColor = clBlack
    Colors.SelectionRectangleBlendColor = 15385233
    Colors.SelectionRectangleBorderColor = 15385233
    Colors.SelectionTextColor = clBlack
    Colors.TreeLineColor = 9471874
    Colors.UnfocusedColor = clGray
    Colors.UnfocusedSelectionColor = clWhite
    Colors.UnfocusedSelectionBorderColor = clWhite
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 0
    OnAddToSelection = VSTAddToSelection
    OnGetText = VSTGetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = #1047#1072#1075#1086#1083#1086#1074#1086#1082
        Width = 375
      end
      item
        Position = 1
        Text = 'URL'
        Width = 506
      end>
  end
  object OpenFileButton: TButton
    Left = 16
    Top = 272
    Width = 201
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1080#1089#1090#1086#1088#1080#1080' '#1073#1088#1072#1091#1079#1077#1088#1072
    TabOrder = 1
    OnClick = OpenFileButtonClick
  end
  object DeleteNodeButton: TButton
    Left = 16
    Top = 303
    Width = 201
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
    TabOrder = 2
    OnClick = DeleteNodeButtonClick
  end
  object FileOpenDialog: TOpenDialog
    Left = 768
    Top = 312
  end
end
