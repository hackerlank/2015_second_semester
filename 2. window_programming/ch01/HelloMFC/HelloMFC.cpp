// MFC
#include	<afxwin.h>

class	CHelloApp : public CWinApp
{
public:
	virtual BOOL	InitInstance(); //override
};

//
CHelloApp	myApp;
//CHelloApp	myApp1;

class	CMainFrame: public	CFrameWnd
{
public:
	CMainFrame();


protected:
	afx_msg	void	OnPaint();
	afx_msg	void	OnLButtonDown(UINT nFlags, CPoint point);
	//���콺 R��ư �����1
	afx_msg void	OnRButtonDown(UINT nFalgs, CPoint point);
	DECLARE_MESSAGE_MAP()
};

CWnd *x, *y;

BOOL	CHelloApp::InitInstance ()
{
	x = m_pMainWnd = new CMainFrame();
	m_pMainWnd->ShowWindow (this->m_nCmdShow);

	y = m_pMainWnd = new CMainFrame();
	m_pMainWnd->ShowWindow(SW_SHOWMINIMIZED);
	
	return true;
}


CMainFrame::CMainFrame()
{
	Create(NULL,"HelloMFC Application");
}



void	CMainFrame::OnPaint()
{
	char	*str1="Hello, MFC";
	char	*str2 = "Hello, jmlee";
	if(this == x) {
		CPaintDC dc(this);
		dc.TextOutA(100, 100, str1, strlen(str1));
	} else {
		CPaintDC dc(this);
		dc.TextOutA(100, 100, str2, strlen(str2));
	}

}

void	CMainFrame::OnLButtonDown (UINT nFlags, CPoint point)
{
	MessageBox("���콺�� Ŭ���Ͽ����ϴ�", "���콺 �޽���");
}

//���콺 R��ư �����2
void	CMainFrame::OnRButtonDown (UINT nFlags, CPoint point) {
	MessageBox("���繮 ����", "���繮 ����");
}

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	//���콺 R��ư �����3
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()
