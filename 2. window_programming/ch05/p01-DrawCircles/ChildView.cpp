
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p01-DrawCircles.h"
#include "ChildView.h"
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() {
	pressed = false;
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
	dc.SelectStockObject(NULL_BRUSH);
	for(int i=0 ; i<pss.size() ; i++) {
		CPoint xps = pss[i];
		CPoint xpe = pes[i];
		dc.Ellipse(xps.x, xps.y, xpe.x, xpe.y);
	}
	if(pressed == true) {
		dc.Ellipse(ps.x, ps.y, pe.x, pe.y);
	}
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	pressed = true;
	ps = pe = point;
	
	
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	pressed = false;
	::ReleaseCapture();
	pss.push_back(ps);
	pes.push_back(pe);
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pressed == true) {
		pe = point;
		this->Invalidate(true);

		/*
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);		
		dc.Ellipse(ps.x, ps.y, pe.x, pe.y);
		
		pe = point;
		dc.SetROP2(R2_NOT);		
		dc.Ellipse(ps.x, ps.y, pe.x, pe.y);
		*/
	}
	CWnd::OnMouseMove(nFlags, point);
}
