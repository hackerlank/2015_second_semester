
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "x06.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	filled = false;
	rect  = CRect(10, 10, 400, 100);
	
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
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Ellipse(&rect);
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	pressed = true;
	this->point = point;
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	pressed = false;
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// view밖에서 LButtonUp하면 게속 돌아댕기기 때문에 setCapture를 해줘야 한다. 
	if(pressed == true) {
		int dx = point.x - this->point.x;
		int dy = point.y - this->point.y;
		rect.left += dx;
		rect.right += dx;
		rect.top += dy;
		rect.bottom += dy;
		this->point = point;

		this->Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}
