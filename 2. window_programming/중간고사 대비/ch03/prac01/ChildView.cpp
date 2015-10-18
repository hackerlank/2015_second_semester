
// ChildView.cpp : CChildView 클래스의 구현
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



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	//ch03-prac02 : 마우스 커서가 다음과 같이 윈도우에서 기본으로 제공하는 정지 아이콘으로 변경되도록 수정하시오
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_NO), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	//ch03-prac05 : 실행파일 이름을 화면에 출력하도록 수정하시오
	dc.TextOutA(50, 50, AfxGetApp()->m_pszExeName);
	//ch03-prac06 : 실행핼때 입력된 명령행 인자를 화면에 출력하도록 수정하시오
	dc.TextOutA(100, 100, AfxGetApp()->m_lpCmdLine);
	//ch03-prac07 : CMainFrame의 윈도우 타이틀을 가져와 출력하도록 수정하시오
	//CMainFrame *frame = (CMainFrame*)AfxGetMainWnd()->GetWindowTextA();
	//dc.TextOutA(150, 150, (CMainFrame*)AfxGetMainWnd()->GetWindowTextA(SetWindowText("gaga")));
	//dc.TextOutA(150, 150, GetParent()->GetWindowTextA(str));

}

