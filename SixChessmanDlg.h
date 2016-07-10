// SixChessmanDlg.h : header file
//

#if !defined(AFX_SIXCHESSMANDLG_H__2D5E0D80_1054_4308_A148_7FBC527BB4BA__INCLUDED_)
#define AFX_SIXCHESSMANDLG_H__2D5E0D80_1054_4308_A148_7FBC527BB4BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"GoAbleChesman.h"

/////////////////////////////////////////////////////////////////////////////
// CSixChessmanDlg dialog
#define ROW_COUNT 4
#define COL_COUNT 4
#define WHITE -1
#define BLACK 1
#define BLANK 0
#define MOVE_STATE 2
#define TEMP_MOVE_STATE 3

#define WIDTH 20
#define HEIGHT 20

class CSixChessmanDlg : public CDialog
{
// Construction
public:
	CSixChessmanDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSixChessmanDlg)
	enum { IDD = IDD_SIXCHESSMAN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSixChessmanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSixChessmanDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMenuStart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMenuHumanModel();
	afx_msg void OnMenuComputerModel();
	afx_msg void OnMenuAbout();
	afx_msg void OnMenuExit();
	afx_msg void OnMenuFinishGame();
	afx_msg void OnMenuLookRule();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
	void Repaint();
private:
	int width,height,baseX,baseY;
	int widthPerGrid,heightPerGrid,radius;
	int map[ROW_COUNT][COL_COUNT],mapForComputerDo[ROW_COUNT][COL_COUNT];
	int winCountOfWhite,winCountOfBlack;
	int computerColor;
	//RGB blackColor(0,0,0),white(0,0,0);
	int startX,startY,endX,endY,endPosX,endPosY;
	bool isLeftBtnDown,isStart,isWhiteDone,isFirst,isWithComputer;
	GoAbleChesman goAbleChessmanMap[6*4];
private:
	void StartChess();
	bool SetEndPosition(CPoint &point);
	bool IsSuit(int x,int y,int&i,int&j);
	bool IsWin(int row,int col);
	int IsEatOppositeside(int row,int col,bool isTry=false);
	bool AddWinCount(int state);

	bool ComputerDo();
	bool WillNotSelfBeenEat(int x,int y);
	int GetSelfBeenEatCount(int x,int y);
	//bool WillOppositesideBeenEat(int x,int y);
	//int GetOppositesideBeenEatCount(int x,int y);
	//void ChooseBest(int x,int y);
	bool ChooseBest(bool willBeenEat,int length);
	void SetComputerMap();
	bool MoveChessman(GoAbleChesman*pChessman);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIXCHESSMANDLG_H__2D5E0D80_1054_4308_A148_7FBC527BB4BA__INCLUDED_)
