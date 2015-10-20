/*p04 : 마우스 커서 변경하기
윈도우의 클라이언트영역에 타원을 그린 후 마우스 커서가 타원 안쪽과 바깥쪽에 있을 떄 다른 모양을 갖도록 하자. 
커서가 안쪽에 있을 때는 사용자 정의 커서를 사용하고, 바깥쪽에 있을때는 운영체제가 제공하는 커서 중 하나를 사용할 것이다. 
*/
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p04-changecursor.h"
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
	ON_WM_SETCURSOR()
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
	dc.Ellipse(50, 50, 500, 200);
}



BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if(nHitTest == HTCLIENT) {
		CPoint point;
		::GetCursorPos(&point);
		ScreenToClient(&point);
		CRgn rgn;
		rgn.CreateEllipticRgn(50, 50, 500, 200);
		if(rgn.PtInRegion(point))
			::SetCursor(AfxGetApp()->LoadCursorA(IDC_CURSOR1));
		else 
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		return TRUE;
	}

	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}
