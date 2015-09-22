
// COkView.cpp : CChildView 와 유사한 클래스를 구현하였다!!!! (childview카피후에, okview로 바꿔줌)
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



// COkView 메시지 처리기

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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.

	dc.TextOutA(0,0,"OK");
	
}



void COkView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->MessageBox("I am OK", "COkView::OnLButtonDown", MB_OK);
	CWnd::OnLButtonDown(nFlags, point);
}
