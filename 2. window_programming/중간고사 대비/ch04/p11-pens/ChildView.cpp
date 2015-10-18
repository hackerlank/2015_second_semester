
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "p11-pens.h"
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
	
	int nPenStyle[] = {PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT, PS_NULL, PS_INSIDEFRAME};
	char *PenStyle[] = {"PS_SOLID", "PS_DASH", "PS_DOT", "PS_DASHDOT", "PS_DASHDOTDOT", "PS_NULL", "PS_INSIDEFRAME"};
	dc.SetTextAlign(TA_BASELINE);
	for(int i=0 ; i<sizeof(nPenStyle)/sizeof(nPenStyle[0]) ; i++) {
		CPen pen(nPenStyle[i], 1, RGB(0, 0, 255));
		dc.SelectObject(&pen);
		dc.TextOutA(50, 25+i*25, PenStyle[i], lstrlen(PenStyle[i]));
		dc.MoveTo(200, 25+i*25);
		dc.LineTo(500, 25+i*25);
	}
}

