
// COkView.cpp : CChildView �� ������ Ŭ������ �����Ͽ���!!!! (childviewī���Ŀ�, okview�� �ٲ���)
//

#include "stdafx.h"
#include "ex03.h"
#include "okview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COkView

COkView::COkView()
{
}

COkView::~COkView()
{
}


BEGIN_MESSAGE_MAP(COkView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// COkView �޽��� ó����

BOOL COkView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE; 
}

void COkView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.

	dc.TextOutA(0,0,"OK");
	
}



void COkView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	this->MessageBox("I am OK", "COkView::OnLButtonDown", MB_OK);
	CWnd::OnLButtonDown(nFlags, point);
}
