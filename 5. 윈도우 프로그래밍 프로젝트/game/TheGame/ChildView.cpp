
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "TheGame.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include		"MrNomGame.h"

// CChildView

CChildView::CChildView()
{
	////GetTickCount() - OS�����Ҷ����� ������ �ð��� m sec������ �����ִ� �Լ��̴�. 
	previousTime= ::GetTickCount();
	game= new CMrNomGame();

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_LBUTTONDOWN()
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
	CDC*	canvas= (CDC*)game->getCanvas();
	int		w, h;
	game->getSize(w, h);
	dc.BitBlt(0, 0, w, h, canvas, 0, 0, SRCCOPY);
	TRACE("w=%d, h=%d\n", w, h);


}

void	CChildView::onIdle()
{
	DWORD	currentTime= ::GetTickCount();
	int		delta= (currentTime-previousTime);
	previousTime= currentTime;
	game->update(delta);
	game->render();

}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	CRect	r;
	GetParent()->GetClientRect(&r);
	game->create(this, r.Width(), r.Height());

	return 0;
}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	game->setSize(cx, cy);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	/*switch(nChar) {
	case VK_LEFT :
		game->getInput()->OnKeyDown(nChar, nRepCnt, nFlags);
		break;
	case VK_RIGHT :
		game->getInput()->OnKeyDown(nChar, nRepCnt, nFlags);
		break;
	case VK_UP :
		game->getInput()->OnKeyDown(nChar, nRepCnt, nFlags);
		break;
	case VK_DOWN :
		game->getInput()->OnKeyDown(nChar, nRepCnt, nFlags);
		break;
	}*/


	game->getInput()->OnKeyDown(nChar, nRepCnt, nFlags);
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	game->getInput()->OnKeyUp(nChar, nRepCnt, nFlags);

	CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	game->getInput()->OnLButtonDown(nFlags, point);
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	game->getInput()->OnLButtonUp(nFlags, point);

	CWnd::OnLButtonUp(nFlags, point);
}
