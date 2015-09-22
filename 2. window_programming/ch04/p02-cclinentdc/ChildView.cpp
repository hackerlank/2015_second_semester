
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p02-cclinent.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	count = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
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

void CChildView::OnPaint() {
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.

	//연습문제 2번
	for(int i=0 ; i<count ; i++) {
			CPoint point = ps[i];
			dc.Rectangle(point.x-20, point.y-20, point.x+20, point.y+20);
	}
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	//CPaintDC dc(this); //->안되는이유 : 
	dc.Rectangle(point.x-20, point.y-20, point.x+20, point.y+20);

	/*TRACE("x1 = %d, y1 = %d, x2 = %d, y2 = %d \n", 
		dc.m_ps.rcPaint.left, 
		dc.m_ps.rcPaint.top, 
		dc.m_ps.rcPaint.right, 
		dc.m_ps.rcPaint.bottom); //디버깅 시작하면 MFC창을 옮길떄마다 좌표가 찍혀나옴
	*/
	//연습문제 2번
	ps[count++] = point;

	CWnd::OnLButtonDown(nFlags, point);
}
