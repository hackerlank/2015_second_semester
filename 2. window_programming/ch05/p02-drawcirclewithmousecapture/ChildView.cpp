
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p02-drawcirclewithmousecapture.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	drawMode = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
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
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//MFC함수를 이용하여 마우스 캡처를 시작한다. 
	SetCapture();
	drawMode = TRUE;
	x1 = x2 = point.x;
	y1 = y2 = point.y;
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	//최종적인 타원을 그린다. 
	dc.SetROP2(R2_COPYPEN);
	x2 = point.x;
	y2 = point.y;
	dc.Ellipse(x1, y1, x2, y2);
	//그리기 모드를 끝낸다.
	drawMode = FALSE;
	//API함수를 이용하여 마우스 캡처를 해제한다. 
	::ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(drawMode) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		//이전에 그린 타원을 지운다.
		dc.SetROP2(R2_NOT);
		dc.Ellipse(x1, y2, x2, y2);
		//새로운 타원을 그린다. 
		dc.SetROP2(R2_NOT);
		x2 = point.x;
		y2 = point.y;
		dc.Ellipse(x1, y1, x2, y2);
	}
	CWnd::OnMouseMove(nFlags, point);
}
