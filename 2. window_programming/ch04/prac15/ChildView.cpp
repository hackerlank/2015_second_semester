
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "prac15.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	mapmode = FALSE;
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
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);
	BITMAP bm;
	bitmap.GetBitmap(&bm);
	
	CDC mdc;
	mdc.CreateCompatibleDC(&dc);
	mdc.SelectObject(&bitmap);

	CRect r;
	this->GetClientRect(&r);
	
	
	if(mapmode == FALSE) {
		//dc.BitBlt(100, 100, bm.bmWidth, bm.bmHeight, &mdc, 0, 0, SRCCOPY);
		dc.StretchBlt(0, 0, r.Width(), r.Height(), &mdc, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
		mapmode = TRUE;
	} else {
		//dc.BitBlt(100, 100,bm.bmHeight , bm.bmWidth, &mdc, 0, 0, SRCCOPY);
		dc.StretchBlt(0, r.Height(), r.Width(), -r.Height(), &mdc, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
		mapmode = FALSE;
	}
	//CWnd::OnLButtonDown(nFlags, point);
}
