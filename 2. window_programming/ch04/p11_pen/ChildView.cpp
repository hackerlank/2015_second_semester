
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p11_pen.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
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
	
	CPen pen(PS_SOLID, 10, RGB(255, 0, 0));
	CPen *oldPen = dc.SelectObject(&pen);
	dc.Rectangle(0, 0, 100, 100);

	//CPen pen1(PS_SOLID, 10, RGB(0, 0, 255));
	//CPen *oldPen = dc.SelectObject(&pen);

	pen.DeleteObject();
	pen.CreatePen(PS_SOLID, 10, RGB(0, 0, 255));
	dc.SelectObject(&pen);

	dc.Ellipse(100, 100, 200, 200);
	
}

