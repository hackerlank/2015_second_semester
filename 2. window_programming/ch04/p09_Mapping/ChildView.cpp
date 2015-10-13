
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p09_Mapping.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	mapmode=MM_ISOTROPIC;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
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
	
	CRect r;
	this->GetClientRect(&r);
	dc.SetMapMode(MM_ISOTROPIC); //������ �����ϱ� ���� type�� int 
	dc.SetViewportExt(r.Width(), r.Height());
	dc.SetWindowExt(100, 100);
	dc.RoundRect(0, 0, 100, 100, 50, 50);
	
	/*
	CPoint lp(50,50);
	dc.LPtoDP(&lp);
	CString str;
	str.Format("%d, %d", lp.x, lp.y);
	dc.TextOutA(50, 50, str);
	*/
	
}
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(mapmode == MM_ANISOTROPIC)
		mapmode = MM_ISOTROPIC;
	else
		mapmode = MM_ANISOTROPIC;
	this->Invalidate(); //���� ���� �ٲ��. 

	CWnd::OnLButtonDown(nFlags, point);
	
}
