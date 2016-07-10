// SixChessman.h : main header file for the SIXCHESSMAN application
//

#if !defined(AFX_SIXCHESSMAN_H__1E2AE858_C80D_4CAA_A3C2_7785B34E1480__INCLUDED_)
#define AFX_SIXCHESSMAN_H__1E2AE858_C80D_4CAA_A3C2_7785B34E1480__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSixChessmanApp:
// See SixChessman.cpp for the implementation of this class
//

class CSixChessmanApp : public CWinApp
{
public:
	CSixChessmanApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSixChessmanApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSixChessmanApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIXCHESSMAN_H__1E2AE858_C80D_4CAA_A3C2_7785B34E1480__INCLUDED_)
