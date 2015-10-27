
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p07-InputKetStroke.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	filled = false;
	//p = CPoint;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
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
	if(filled) {
		dc.SelectStockObject(BLACK_BRUSH);
	} else {
		dc.SelectStockObject(NULL_BRUSH);
	}
	dc.Ellipse(p.x-30, p.y-30, p.x+30, p.y+30);
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	CRect r;
	this->GetClientRect(&r);
	//p = CPoint(r.Width()/2, r.Height()/2);
	p = CPoint(30, 30);
	return 0;
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(nChar == VK_LEFT)	p.x -=30;
	if(nChar == VK_RIGHT)	p.x +=30;
	if(nChar == VK_UP)		p.y -= 30;
	if(nChar == VK_DOWN)	p.y += 30;
	if(nChar == VK_SPACE)	filled = !filled;

	if(p.x < 30)	p.x = 30;
	if(p.y < 30)	p.y = 30;

	CRect r;
	this->GetClientRect(r);
	if(p.x >= r.Width()-30)		p.x = r.Width()-30;
	if(p.y >= r.Height()-30)		p.y = r.Height()-30;
	this->Invalidate();

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
