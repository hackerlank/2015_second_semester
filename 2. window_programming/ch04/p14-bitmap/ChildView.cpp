
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p14-bitmap.h"
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
	
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);
	BITMAP bm;
	bitmap.GetBitmap(&bm);
	
	CDC mdc;
	mdc.CreateCompatibleDC(&dc);
	mdc.SelectObject(&bitmap);

	CDC mdc1;
	mdc1.CreateCompatibleDC(&dc);
	CBitmap b1;
	b1.CreateCompatibleBitmap(&dc,bm.bmWidth,bm.bmHeight);
	mdc1.SelectObject(&b1);


	for(int i=0;i<bm.bmHeight;i++){
		for(int j=0;j<bm.bmWidth;j++){
			mdc1.SetPixelV(j,bm.bmHeight-i,mdc.GetPixel(j,i));
		}
	}
	
	dc.BitBlt(100,100,bm.bmWidth,bm.bmHeight,&mdc1,0,0,SRCCOPY);
	//dc.BitBlt(x,y,w,h,&mdc,x1,y1,SRCCOPY);
	/*
	CRect r;
	this->GetClientRect(&r);
	dc.StretchBlt(0,0,r.Width(),r.Height(),&mdc,0,0
		,bm.bmWidth,bm.bmHeight,SRCCOPY);
	*/
		}

