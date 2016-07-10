// RuleDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SixChessman.h"
#include "RuleDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RuleDialog dialog


RuleDialog::RuleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(RuleDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(RuleDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void RuleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RuleDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RuleDialog, CDialog)
	//{{AFX_MSG_MAP(RuleDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RuleDialog message handlers
