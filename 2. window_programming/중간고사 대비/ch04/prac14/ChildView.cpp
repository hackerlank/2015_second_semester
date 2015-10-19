
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "prac14.h"
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
	//��Ʈ�� ���ҽ��� �ε��� �� ũ�� ������ ��´�. 
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	
	//�޸� DC�� ���� �� ��Ʈ���� ������ �ִ´�. 
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	//��Ʈ���� ȭ�鿡 ����Ѵ�. 
	dc.BitBlt(10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	/*dc.StretchBlt(10, 100, bmpinfo.bmWidth*4, bmpinfo.bmHeight*2, &dcmem, 0, 0, bmpinfo.bmWidth, 
		bmpinfo.bmHeight, SRCCOPY);*/
	dcmem.Rectangle(5, 5, 15, 15);

	dc.BitBlt(350, 50, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	

	if(nFlags == MK_LBUTTON) {
		dc.BitBlt(100, 100, bm.bmWidth, bm.bmHeight, &mdc, 0, 0, SRCCOPY);
	} else {
		dc.StretchBlt(10, 10, r.Width(), r.Height(), &mdc, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
	}
	this->Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}
