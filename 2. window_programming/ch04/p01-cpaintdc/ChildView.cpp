
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "cpaintdc.h"
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

int x=0;
void CChildView::OnPaint() {
	//CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	CClientDC dc(this); //!!!!!!!!!!!!!!!!!CClientDC와 CPaintDC를 확실히 구분해야 한다. !!!!!!!!!!!!!!
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.

	dc.Rectangle(10, 10, 100, 100); //x, y, width, height
	
	//if(dc.m_ps.rcPaint.right < 90) {
			dc.Ellipse(100, 100, 200, 200);
	//}
	TRACE("x= %10d\n", x++);
	/*
	TRACE("x1 = %d, y1 = %d, x2 = %d, y2 = %d \n", 
		dc.m_ps.rcPaint.left, 
		dc.m_ps.rcPaint.top, 
		dc.m_ps.rcPaint.right, 
		dc.m_ps.rcPaint.bottom); //디버깅 시작하면 MFC창을 옮길떄마다 좌표가 찍혀나옴
	*/
}

