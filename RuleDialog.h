#if !defined(AFX_RULEDIALOG_H__3F0A92E1_9BB7_4C4D_AFBF_661BC0ACA604__INCLUDED_)
#define AFX_RULEDIALOG_H__3F0A92E1_9BB7_4C4D_AFBF_661BC0ACA604__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RuleDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RuleDialog dialog

class RuleDialog : public CDialog
{
// Construction
public:
	RuleDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RuleDialog)
	enum { IDD = IDD_DIALOG_rule };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RuleDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RuleDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULEDIALOG_H__3F0A92E1_9BB7_4C4D_AFBF_661BC0ACA604__INCLUDED_)
