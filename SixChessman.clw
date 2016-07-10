; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSixChessmanDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SixChessman.h"

ClassCount=4
Class1=CSixChessmanApp
Class2=CSixChessmanDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_SIXCHESSMAN_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_rule
Resource4=IDD_ABOUTBOX
Class4=RuleDialog
Resource5=IDR_MENU_control

[CLS:CSixChessmanApp]
Type=0
HeaderFile=SixChessman.h
ImplementationFile=SixChessman.cpp
Filter=N

[CLS:CSixChessmanDlg]
Type=0
HeaderFile=SixChessmanDlg.h
ImplementationFile=SixChessmanDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CSixChessmanDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=SixChessmanDlg.h
ImplementationFile=SixChessmanDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SIXCHESSMAN_DIALOG]
Type=1
Class=CSixChessmanDlg
ControlCount=0

[MNU:IDR_MENU_control]
Type=1
Class=?
Command1=ID_MENUITEM_computerModel
Command2=ID_MENUITEM_humanModel
Command3=ID_MENUITEM_finishGame
Command4=ID_MENUITEM_exit
Command5=ID_MENUITEM_rule
Command6=ID_MENUITEM_about
CommandCount=6

[DLG:IDD_DIALOG_rule]
Type=1
Class=RuleDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:RuleDialog]
Type=0
HeaderFile=RuleDialog.h
ImplementationFile=RuleDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENUITEM_about

