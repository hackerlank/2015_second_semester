
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "prac01.h"
#include "ChildView.h"
#include "MainFrm.h"

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
	//ch03-prac02 : ���콺 Ŀ���� ������ ���� �����쿡�� �⺻���� �����ϴ� ���� ���������� ����ǵ��� �����Ͻÿ�
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_NO), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	//ch03-prac05 : �������� �̸��� ȭ�鿡 ����ϵ��� �����Ͻÿ�
	dc.TextOutA(50, 50, AfxGetApp()->m_pszExeName);
	//ch03-prac06 : �����۶� �Էµ� ����� ���ڸ� ȭ�鿡 ����ϵ��� �����Ͻÿ�
	dc.TextOutA(100, 100, AfxGetApp()->m_lpCmdLine);
	////ch03-prac07 : CMainFrame�� ������ Ÿ��Ʋ�� ������ ����ϵ��� �����Ͻÿ�
	//CMainFrame *frame = (CMainFrame*)AfxGetMainWnd()->GetWindowTextA();
	//dc.TextOutA(150, 150, (CMainFrame*)AfxGetMainWnd()->GetWindowTextA(SetWindowText("gaga")));
	//dc.TextOutA(150, 150, GetParent()->GetWindowTextA(str));

}

