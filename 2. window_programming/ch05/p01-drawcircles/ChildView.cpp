//p01-drawcircles : ���콺�� �̿��Ͽ� ȭ�鿡 Ÿ���� �׸��� ���α׷��� ������.
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p01-drawcircles.h"
#include "ChildView.h"
#include <vector>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	//���ʹ�ư�� ������ ���� ���������� �ʱⰪ�� false;l
	drawMode = FALSE; 
	pressed = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
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
	
	
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	drawMode = TRUE;
	x1 = x2 = point.x;
	y1 = y2 = point.y;
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(drawMode) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		//������ �׸� Ÿ���� �����.
		dc.SetROP2(R2_NOT);
		dc.Ellipse(x1, y2, x2, y2);
		//���ο� Ÿ���� �׸���. 
		dc.SetROP2(R2_NOT);
		x2 = point.x;
		y2 = point.y;
		dc.Ellipse(x1, y1, x2, y2);
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	//�������� Ÿ���� �׸���. 
	dc.SetROP2(R2_COPYPEN);
	x2 = point.x;
	y2 = point.y;
	dc.Ellipse(x1, y1, x2, y2);
	//�׸��� ��带 ������.
	drawMode = FALSE;
	CWnd::OnLButtonUp(nFlags, point);
}
