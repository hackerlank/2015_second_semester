/*p04 : ���콺 Ŀ�� �����ϱ�
�������� Ŭ���̾�Ʈ������ Ÿ���� �׸� �� ���콺 Ŀ���� Ÿ�� ���ʰ� �ٱ��ʿ� ���� �� �ٸ� ����� ������ ����. 
Ŀ���� ���ʿ� ���� ���� ����� ���� Ŀ���� ����ϰ�, �ٱ��ʿ� �������� �ü���� �����ϴ� Ŀ�� �� �ϳ��� ����� ���̴�. 
*/
// ChildView.cpp : CChildView Ŭ������ ����
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
