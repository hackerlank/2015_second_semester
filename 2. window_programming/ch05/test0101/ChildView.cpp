
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "test0101.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	count=0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView �޽��� ó����

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	dc.TextOutA(0, 0, "childview");
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//MessageBox("������", "�޽���", MB_OK);
	CClientDC dc(this);
	CString str = "gkgkgk";
	
	if(count==0) {
		dc.SetTextColor(RGB(0,0,255));
		dc.TextOutA(point.x, point.y, str);
		count++;
	} else if(count==1) {
		dc.SetTextColor(RGB(0,255,0));
		dc.TextOutA(point.x, point.y, str);
		count++;
	} else  {
		dc.SetTextColor(RGB(255,0,0));
		dc.TextOutA(point.x, point.y, str);
		count=0;
	}
	CWnd::OnLButtonDown(nFlags, point);
}
