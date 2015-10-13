
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p12_brush.h"
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
	
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);
	CBrush x(&bitmap);

	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(x.GetSafeHandle()), NULL);

	x.Detach();
	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	CBrush brush(RGB(255,0,0));
	CBrush brush1(HS_DIAGCROSS, RGB(255,0 ,0));
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);
	CBrush brush2(&bitmap);
	
	//�簢���� ���� �� ä��
	/*CRect r;
	this->GetClientRect(&r);
	dc.SelectObject(&brush2);
	dc.Rectangle(&r);*/

	//�׸��� �ǰ���?
	/*dc.SelectObject(&brush);
	dc.Rectangle(50, 50, 200, 200);
	dc.SelectObject(&brush1);
	dc.Ellipse(250, 50, 400, 200);
	dc.SelectObject(&brush2);
	dc.RoundRect(450, 50, 600, 200, 50, 50);*/
}

