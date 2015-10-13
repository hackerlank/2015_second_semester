
// ChildView.cpp : CChildView 클래스의 구현
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
	
	CRect r;
	this->GetClientRect(&r);
	dc.SetMapMode(MM_ISOTROPIC); //데이터 저장하기 위한 type은 int 
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(mapmode == MM_ANISOTROPIC)
		mapmode = MM_ISOTROPIC;
	else
		mapmode = MM_ANISOTROPIC;
	this->Invalidate(); //위에 가서 바뀐다. 

	CWnd::OnLButtonDown(nFlags, point);
	
}
