// SixChessmanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SixChessman.h"
#include "SixChessmanDlg.h"
#include "RuleDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSixChessmanDlg dialog

CSixChessmanDlg::CSixChessmanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSixChessmanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSixChessmanDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//this->widthPerGrid=WIDTH;
	//this->heightPerGrid=HEIGHT;
	isLeftBtnDown=false;
	isStart=false;
}

void CSixChessmanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSixChessmanDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSixChessmanDlg, CDialog)
	//{{AFX_MSG_MAP(CSixChessmanDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENUITEM_humanModel, OnMenuHumanModel)
	ON_COMMAND(ID_MENUITEM_computerModel, OnMenuComputerModel)
	ON_COMMAND(ID_MENUITEM_about, OnMenuAbout)
	ON_COMMAND(ID_MENUITEM_exit, OnMenuExit)
	ON_COMMAND(ID_MENUITEM_finishGame, OnMenuFinishGame)
	ON_COMMAND(ID_MENUITEM_rule, OnMenuLookRule)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSixChessmanDlg message handlers

BOOL CSixChessmanDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSixChessmanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSixChessmanDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	Repaint();
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSixChessmanDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
//��ʼ��Ϸ
void CSixChessmanDlg::StartChess()
{
	for(int i=0;i<COL_COUNT;i++)
	{
		map[0][i]=WHITE;
		map[1][i]=WHITE;
		map[2][i]=BLACK;
		map[3][i]=BLACK;
	}
	map[1][1]=map[1][2]=BLANK;
	map[2][1]=map[2][2]=BLANK;
	winCountOfWhite=0;
	winCountOfBlack=0;
	isStart=true;
	isLeftBtnDown=false;
	isFirst=true;
	Repaint();
}
/********************************************************************************/
//�ػ�������Ϣ
void CSixChessmanDlg::Repaint()
{
	if(!isStart)
		return;
	int x,y;	
	CDC *pDC=GetDC();
	CBrush blackBrush(RGB(0,0,0));
	CBrush whiteBrush(RGB(255,240,225));
	CBrush moveStateBrush(RGB(215,200,205));
	CBrush *pOldBrush;
	pDC->Rectangle(0,0,width,height);
	/*
	//������
	for(int i=0;i<ROW_COUNT-1;i++)
	{
		for(int j=0;j<COL_COUNT-1;j++)
		{
			x=baseX+j*widthPerGrid;
			y=baseY+i*heightPerGrid;
			pDC->Rectangle(x,y,x+widthPerGrid,y+heightPerGrid);
		}
	}
	//*/
	//������
	int i;
	//��
	for(i=0;i<COL_COUNT;i++)
	{
		x=baseX+i*widthPerGrid;
		y=baseY;
		pDC->MoveTo(x,y);
		pDC->LineTo(x,y+(ROW_COUNT-1)*heightPerGrid);			
	}
	//����
	for(i=0;i<ROW_COUNT;i++)
	{
		x=baseX;
		y=baseY+i*heightPerGrid;
		pDC->MoveTo(x,y);
		pDC->LineTo(x+(COL_COUNT-1)*widthPerGrid,y);	
	}
	//��������Ϣ
	for(i=0;i<ROW_COUNT;i++)
	{
		for(int j=0;j<COL_COUNT;j++)
		{
			x=baseX+j*widthPerGrid;
			y=baseY+i*heightPerGrid;
			/*//������
			if(i<ROW_COUNT-1 && j<ROW_COUNT-1)
				pDC->Rectangle(x,y,x+widthPerGrid,y+heightPerGrid);
			//*/
			//������
			if(map[i][j]==BLACK)
			{				
				pOldBrush=pDC->SelectObject(&blackBrush);
				pDC->Ellipse(x-radius,y-radius,x+radius,y+radius);
				pDC->SelectObject(pOldBrush);
			}
			else if(map[i][j]==WHITE)
			{
				pOldBrush=pDC->SelectObject(&whiteBrush);
				pDC->Ellipse(x-radius,y-radius,x+radius,y+radius);
				pDC->SelectObject(pOldBrush);
			}
			else if(map[i][j]==TEMP_MOVE_STATE)
			{
				pOldBrush=pDC->SelectObject(&moveStateBrush);
				pDC->Ellipse(endPosX-radius,endPosY-radius,endPosX+radius,endPosY+radius);
				pDC->SelectObject(pOldBrush);
			}
		}
	}
}
//��¼�ͻ�����С
void CSixChessmanDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	this->width=cx;
	this->height=cy;
	baseX=width/10;
	baseY=height/10;
	widthPerGrid=(width*8/10)/(COL_COUNT-1);
	heightPerGrid=(height*8/10)/(ROW_COUNT-1);
	int tmp=(widthPerGrid<heightPerGrid) ? widthPerGrid:heightPerGrid;
	radius=tmp/4;
}
//��ʼ�˵�
void CSixChessmanDlg::OnMenuStart() 
{
	// TODO: Add your command handler code here
	StartChess();
}
//�������
void CSixChessmanDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{	
	if(!IsSuit(point.x,point.y,startX,startY))
		return;							//CString str;str.Format("startX:%d,startY:%d",startX,startY);AfxMessageBox(str);
	if(map[startX][startY]==BLANK)
		return;	
	if(isFirst)
	{
		if(map[startX][startY]==WHITE)
			isWhiteDone=false;
		else if(map[startX][startY]==BLACK)
			isWhiteDone=true;	//GetDC()->TextOut(endPosX,0,"isFirst");
	}
	else if((isWhiteDone && map[startX][startY]==WHITE) || (!isWhiteDone && map[startX][startY]==BLACK))
		return;
	map[startX][startY]=MOVE_STATE*map[startX][startY];
	endX=startX;
	endY=startY;
	isLeftBtnDown=true;
	Repaint();
	CDialog::OnLButtonDown(nFlags, point);
}
//�϶�����
void CSixChessmanDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!isLeftBtnDown)
		return;		
	SetEndPosition(point);	//GetDC()->TextOut(point.x,point.y,"�϶�");
	Repaint();
	CDialog::OnMouseMove(nFlags, point);
}
//����ͷ�
void CSixChessmanDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!isLeftBtnDown)
		return;
	isLeftBtnDown=false;
	bool isSuccss;
	CString msg;
	if(SetEndPosition(point))
	{		
		map[endX][endY]=map[startX][startY]/MOVE_STATE;
		map[startX][startY]=BLANK;
		isFirst=false;
		isSuccss=IsWin(endX,endY);
		if(isSuccss)
			msg="��ϲ��Ӯ��!";
		if(isWithComputer && !isSuccss)
		{
			Repaint();
			Sleep(1000);
			isSuccss=this->ComputerDo();
			if(isSuccss)
				msg="��Ϸ����,������!";			
		}
		if(isSuccss)
		{
			if(AfxMessageBox(msg+" �Ƿ������һ��?",MB_YESNO)==IDYES)
			{
				this->StartChess();
			}
			else
				isStart=false;
			return;
		}
	}
	else
	{
		map[startX][startY]=map[startX][startY]/MOVE_STATE;		
	}
	Repaint();
	CDialog::OnLButtonUp(nFlags, point);
}
//�����յ�
bool CSixChessmanDlg::SetEndPosition(CPoint &point)
{	
	int tmpX,tmpY;
	endPosX=point.x;
	endPosY=point.y;
	if(!IsSuit(endPosX,endPosY,tmpX,tmpY))
		return false;	
	if(map[tmpX][tmpY]==BLACK || map[tmpX][tmpY]==WHITE)
		return false;
	bool isNotCoincide=!(startX==endX && startY==endY);
	if(isNotCoincide)
		map[endX][endY]=BLANK;
	endX=tmpX;
	endY=tmpY;
	if(isNotCoincide)
		map[endX][endY]=TEMP_MOVE_STATE;
	return isNotCoincide;
}
//�ж��Ƿ�Ϸ�,����i,jΪת������
bool CSixChessmanDlg::IsSuit(int x,int y,int&i,int&j)
{
	if(x<baseX-radius || y<baseY-radius || x>width-baseX+radius || y>height-baseY+radius)
		return false;;
	int offsetX=(x-baseX)%widthPerGrid;
	int offsetY=(y-baseY)%heightPerGrid;
	if( (offsetX<radius||offsetX>widthPerGrid-radius) && (offsetY<radius||offsetY>heightPerGrid-radius))
	{
		j=(x-baseX+radius)/widthPerGrid;
		i=(y-baseY+radius)/heightPerGrid;					
		return true;
	}
	return false;
}
//�ж��Ƿ�ʤ��
bool CSixChessmanDlg::IsWin(int row,int col)
{	
	int winCount;
	bool isSuccss=false;
	winCount=IsEatOppositeside(row,col);
	for(int i=0;i<winCount;i++)
	{
		if(AddWinCount(map[row][col]))
		{
			isSuccss=true;
			Repaint();
		}
	}				
	isWhiteDone=!isWhiteDone;
	return isSuccss;
}
//�ж��Ƿ��ܳ�
int CSixChessmanDlg::IsEatOppositeside(int row,int col,bool isTry)
{
	int state;
	int i,winCount=0;
	bool rowAble=false,colAble=false;
	int (*pMap)[COL_COUNT];
	if(isTry)
		pMap=mapForComputerDo;
	else
		pMap=map;
	state=pMap[row][col];
	for(i=0;i<COL_COUNT;i++)
	{
		if(pMap[row][i]==BLANK)
		{
			rowAble=true;
			break;
		}
	}
	for(i=0;i<ROW_COUNT;i++)
	{
		if(pMap[i][col]==BLANK)
		{
			colAble=true;
			break;
		}
	}
	//��
	if(rowAble)
	{
		if(col>0 && pMap[row][col-1]==state)
		{
			if(col>1 && pMap[row][col-2]==-state)
			{
				pMap[row][col-2]=BLANK;
				winCount++;
			}
			else if(col<COL_COUNT-1 && pMap[row][col+1]==-state)
			{
				pMap[row][col+1]=BLANK;
				winCount++;
			}
		}
		//�ҷ�
		if(col<COL_COUNT-2 && pMap[row][col+1]==state)
		{
			if(col<COL_COUNT-2 && pMap[row][col+2]==-state)
			{
				pMap[row][col+2]=BLANK;
				winCount++;
			}
			else if(col>0 && pMap[row][col-1]==-state)
			{
				pMap[row][col-1]=BLANK;
				winCount++;
			}
		}
	}
	if(colAble)
	{
		//�Ϸ�
		if(row>0 && pMap[row-1][col]==state)
		{
			if(row>1 && pMap[row-2][col]==-state)
			{
				pMap[row-2][col]=BLANK;
				winCount++;
			}
			else if(row<ROW_COUNT-1 && pMap[row+1][col]==-state)
			{
				pMap[row+1][col]=BLANK;
				winCount++;
			}
		}
		//�·�
		if(row<ROW_COUNT && pMap[row+1][col]==state)
		{
			if(row<ROW_COUNT-2 && pMap[row+2][col]==-state)
			{
				pMap[row+2][col]=BLANK;
				winCount++;
			}
			else if(row>0 && pMap[row-1][col]==-state)
			{
				pMap[row-1][col]=BLANK;
				winCount++;
			}
		}
	}
	return winCount;
}
//���Ӵ���
bool CSixChessmanDlg::AddWinCount(int state)
{
	if(state==WHITE)
	{
		winCountOfWhite++;
		if(winCountOfWhite>=5)
			return true;
	}
	else if(state==BLACK)
	{
		winCountOfBlack++;	
		if(winCountOfBlack>=5)
			return true;
	}
	return false;
}

//��������
bool CSixChessmanDlg::ComputerDo()
{
	int row,col;
	int length=0;
	int i,j;
	for(i=0;i<ROW_COUNT;i++)
	{
		for(j=0;j<COL_COUNT;j++)
		{			//�Ƿ���һ��������������������forѭ����?

			//�ж��Ƿ�Ϊ�ҷ���ɫ
			if(map[i][j]==computerColor)
			{
				//MoveAble(i,j);
				if(i-1>=0 && map[i-1][j]==BLANK)//��
				{
					goAbleChessmanMap[length].position.row=i;
					goAbleChessmanMap[length].position.col=j;
					goAbleChessmanMap[length].direction.row=-1;
					goAbleChessmanMap[length].direction.col=0;
					length++;
				}
				if(i+1<ROW_COUNT && map[i+1][j]==BLANK)//��
				{
					goAbleChessmanMap[length].position.row=i;
					goAbleChessmanMap[length].position.col=j;
					goAbleChessmanMap[length].direction.row=1;
					goAbleChessmanMap[length].direction.col=0;
					length++;
				}
				if(j-1>=0 && map[i][j-1]==BLANK)//��
				{
					goAbleChessmanMap[length].position.row=i;
					goAbleChessmanMap[length].position.col=j;
					goAbleChessmanMap[length].direction.row=0;
					goAbleChessmanMap[length].direction.col=-1;
					length++;
				}
				if(j+1<COL_COUNT && map[i][j+1]==BLANK)//��
				{
					goAbleChessmanMap[length].position.row=i;
					goAbleChessmanMap[length].position.col=j;
					goAbleChessmanMap[length].direction.row=0;
					goAbleChessmanMap[length].direction.col=1;
					length++;
				}				
			}
		}
	}	
	//������ѡ������һ�ֽϺ��߷�
	bool willBeenEat=true;
	for(int k=0;k<length;k++)
	{
		SetComputerMap();
		row=goAbleChessmanMap[k].position.row+goAbleChessmanMap[k].direction.row;
		col=goAbleChessmanMap[k].position.col+goAbleChessmanMap[k].direction.col;
		mapForComputerDo[row][col]=computerColor;
		mapForComputerDo[goAbleChessmanMap[k].position.row][goAbleChessmanMap[k].position.col]=BLANK;
		//�����Ƿ�ᱻ��
		if(WillNotSelfBeenEat(row,col))
		{	
			goAbleChessmanMap[k].willBeenEat=false;
			willBeenEat=false;			
		}
		else
			goAbleChessmanMap[k].willBeenEat=true;
		mapForComputerDo[row][col]=BLANK;
		mapForComputerDo[goAbleChessmanMap[k].position.row][goAbleChessmanMap[k].position.col]=computerColor;
	}
	/*
	//ѡ��ᱻ������õ��߷�
	if(willBeenEat)
		ChooseBest(true);
	*/

	//ѡ��(��)�ᱻ���нϺõ��߷�
	return ChooseBest(willBeenEat,length);//lengthΪ����λ�õĸ���
}
//�����Ƿ�ᱻ��
bool CSixChessmanDlg::WillNotSelfBeenEat(int row,int col)
{
	bool isWillNotBeenEat=true;
	//SetComputerMap();
	//�ж϶Է��Ƿ�Ҫ����
	int i,j;
	for(i=0;i<ROW_COUNT;i++)
	{
		for(j=0;j<COL_COUNT;j++)
		{		
			if(mapForComputerDo[i][j]==-computerColor)//�Է�����
			{
				if(GetSelfBeenEatCount(i,j)>0)//�Է�����,���Լ��Ƿ񱻳�
				{
					isWillNotBeenEat=false;
					break;
				}
			}
		}
	}
	return isWillNotBeenEat;
}
//�жϳԶԷ��ӵĸ���,û����Ϊ0
int CSixChessmanDlg::GetSelfBeenEatCount(int row,int col)
{
	int selfBeenEatCount=0;
	//��
	if(col>0 && mapForComputerDo[row][col-1]==BLANK)
	{
		mapForComputerDo[row][col-1]=-computerColor;
		mapForComputerDo[row][col]=BLANK;
		selfBeenEatCount+=IsEatOppositeside(row,col-1,true);
		mapForComputerDo[row][col-1]=BLANK;
		mapForComputerDo[row][col]=-computerColor;
	}
	//��
	if(col<COL_COUNT-1 && mapForComputerDo[row][col+1]==BLANK)
	{
		mapForComputerDo[row][col+1]=-computerColor;
		mapForComputerDo[row][col]=BLANK;
		selfBeenEatCount+=IsEatOppositeside(row,col+1,true);
		mapForComputerDo[row][col+1]=BLANK;
		mapForComputerDo[row][col]=-computerColor;
	}
	//��
	if(row>0 && mapForComputerDo[row-1][col]==BLANK)
	{
		mapForComputerDo[row-1][col]=-computerColor;
		mapForComputerDo[row][col]=BLANK;
		selfBeenEatCount+=IsEatOppositeside(row-1,col,true);
		mapForComputerDo[row-1][col]=BLANK;
		mapForComputerDo[row][col]=-computerColor;
	}
	//��
	if(row<ROW_COUNT-1 && mapForComputerDo[row+1][col]==BLANK)
	{
		mapForComputerDo[row+1][col]=-computerColor;
		mapForComputerDo[row][col]=BLANK;
		selfBeenEatCount+=IsEatOppositeside(row+1,col,true);
		mapForComputerDo[row+1][col]=BLANK;
		mapForComputerDo[row][col]=-computerColor;
	}
	return selfBeenEatCount;
}
//ѡ��Ϻ��߷�
bool CSixChessmanDlg::ChooseBest(bool willBeenEat,int length)
{
	//bool haveEat=false;
	int row,col;
	int k;
	for(k=0;k<length;k++)
	{
		row=goAbleChessmanMap[k].position.row+goAbleChessmanMap[k].direction.row;
		col=goAbleChessmanMap[k].position.col+goAbleChessmanMap[k].direction.col;
		if(goAbleChessmanMap[k].willBeenEat==willBeenEat)
		{
			mapForComputerDo[row][col]=computerColor;
			mapForComputerDo[goAbleChessmanMap[k].position.row][goAbleChessmanMap[k].position.col]=BLANK;			
			
			goAbleChessmanMap[k].eatAbleCount=this->IsEatOppositeside(row,col,true);

			mapForComputerDo[row][col]=BLANK;
			mapForComputerDo[goAbleChessmanMap[k].position.row][goAbleChessmanMap[k].position.col]=computerColor;
			/*
			if(GetOppositesideBeenEatCount(row,col)>0)
			{
				;
			}			
			if(!haveEat)
			{
				;//ѡ��û�г�����õ��߷�
			}*/
		}
	}
	//ѡ��(û)�г�����õ��߷�
	for(k=0;k<length;k++)
	{
		if(goAbleChessmanMap[k].willBeenEat==willBeenEat && goAbleChessmanMap[k].eatAbleCount==2)
		{
			return MoveChessman(&goAbleChessmanMap[k]);
		}
	}
	int count=0,tmpCount=0;
	for(k=0;k<length;k++)
	{
		if(goAbleChessmanMap[k].willBeenEat==willBeenEat)
		{
			if(goAbleChessmanMap[k].eatAbleCount==1)
			{
				return MoveChessman(&goAbleChessmanMap[k]);
			}
			count++;
		}
	}
	bool isSiut;
	count=rand()%count;
	for(k=0;k<length;k++)
	{
		if(goAbleChessmanMap[k].willBeenEat==willBeenEat)
		{
			isSiut=false;
			row=goAbleChessmanMap[k].position.row+goAbleChessmanMap[k].direction.row;
			col=goAbleChessmanMap[k].position.col+goAbleChessmanMap[k].direction.col;
			//��������...
			if(row!=0 && row!=ROW_COUNT-1 && col!=0 && col!=COL_COUNT-1)
			{
				isSiut=true;
			}
			if(tmpCount==count)
			{
				isSiut=true;				
			}
			tmpCount++;

			if(isSiut)
			{
				return MoveChessman(&goAbleChessmanMap[k]);
			}
		}		
	}
	return false;
}
//����
bool CSixChessmanDlg::MoveChessman(GoAbleChesman*pChessman)
{
	int row,col,newRow,newCol;
	row=pChessman->position.row;
	newRow=row+pChessman->direction.row;
	col=pChessman->position.col;
	newCol=col+pChessman->direction.col;
	map[row][col]=BLANK;
	map[newRow][newCol]=computerColor;
	return this->IsWin(newRow,newCol);
}
//��λ��������map
void CSixChessmanDlg::SetComputerMap()
{
	int i,j;
	for(i=0;i<ROW_COUNT;i++)
	{
		for(j=0;j<COL_COUNT;j++)
		{			
			mapForComputerDo[i][j]=map[i][j];
		}
	}
}
//*/

//����ģʽ
void CSixChessmanDlg::OnMenuHumanModel() 
{
	// TODO: Add your command handler code here
	this->isWithComputer=false;	
	StartChess();
}
//�˻�ģʽ
void CSixChessmanDlg::OnMenuComputerModel() 
{
	this->isWithComputer=true;
	computerColor=WHITE;
	StartChess();
}
//���ڲ˵�
void CSixChessmanDlg::OnMenuAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

void CSixChessmanDlg::OnMenuExit() 
{
	// TODO: Add your command handler code here
	this->OnCancel();
}

void CSixChessmanDlg::OnMenuFinishGame() 
{
	if(!isStart)
		return;
	if(AfxMessageBox("���Ƿ�Ҫ��������?",MB_YESNO)==IDYES)
	{
		this->StartChess();
	}
}

void CSixChessmanDlg::OnMenuLookRule() 
{
	// TODO: Add your command handler code here
	RuleDialog dlg;
	dlg.DoModal();
}
