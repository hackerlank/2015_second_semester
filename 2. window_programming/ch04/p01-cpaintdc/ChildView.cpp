
// ChildView.cpp : CChildView Ŭ������ ����
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

int x=0;
void CChildView::OnPaint() {
	//CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	CClientDC dc(this); //!!!!!!!!!!!!!!!!!CClientDC�� CPaintDC�� Ȯ���� �����ؾ� �Ѵ�. !!!!!!!!!!!!!!
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.

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
		dc.m_ps.rcPaint.bottom); //����� �����ϸ� MFCâ�� �ű拚���� ��ǥ�� ��������
	*/
}

