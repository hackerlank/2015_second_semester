
// ChildView.cpp : CChildView 클래스의 구현
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
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	/*
	//비트맵 리소스를 로드한 후 크기 정보를 얻는다.
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);
	
	//메모리 DC를 만든 후 비트맵을 선택해 넣는다. 
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	//비트맵을 화면에 출력한다. 
	dc.BitBlt(10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	/*dc.StretchBlt(10, 100, bmpinfo.bmWidth*4, bmpinfo.bmHeight*2, &dcmem, 0, 0, bmpinfo.bmWidth, 
		bmpinfo.bmHeight, SRCCOPY);
	dcmem.Rectangle(5, 5, 15, 15);

	dc.BitBlt(350, 50, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	*/
	
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	
	dc.BitBlt(100, 100, bm.bmWidth, bm.bmHeight, &mdc, 0, 0, SRCCOPY);
	Invalidate();
	if(nFlags == MK_LBUTTON) {
		dc.StretchBlt(10, 10, r.Width(), r.Height(), &mdc, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
		
	} 
	
	CWnd::OnLButtonDown(nFlags, point);
}

