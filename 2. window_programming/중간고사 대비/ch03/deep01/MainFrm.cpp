
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "deep01.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

//deep01 : MainFrame의 생성자에서 값 정해주기
CMainFrame::CMainFrame():m_Section("윈도우의크기")
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 프레임의 클라이언트 영역을 차지하는 뷰를 만듭니다.
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("뷰 창을 만들지 못했습니다.\n");
		return -1;
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	//deep02 : 뷰 윈도우 위에 다른 뷰 윈도우를 생성하기.
	m_wndView2.Create(TEXT("Static"),TEXT("DEMO"), WS_CHILD |WS_VISIBLE|WS_BORDER, CRect(5, 5, 100, 100), this,1);

	//deep01 : 레지스트리에 저장한 윈도우 크기, 위치보관
	CWinApp* pApp = (CWinApp*)AfxGetApp();
	CRect rect;
	GetWindowRect(rect);
	rect.left = pApp->GetProfileIntA(m_Section,"left", rect.left);
	rect.top = pApp->GetProfileIntA(m_Section, "top", rect.top);
	rect.right = pApp->GetProfileIntA(m_Section, "right", rect.right);
	rect.bottom = pApp->GetProfileIntA(m_Section, "bottom", rect.bottom);
	MoveWindow(rect);



	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 뷰 창으로 포커스를 이동합니다.
	m_wndView.SetFocus();
	m_wndView2.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 뷰에서 첫째 크랙이 해당 명령에 나타나도록 합니다.
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// 그렇지 않으면 기본 처리합니다.
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}




void CMainFrame::OnDestroy()
{
	CFrameWnd::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	//deep01 : 레지스트리에 저장한 윈도우 크기, 위치보관
	CWinApp* pApp = (CWinApp*)AfxGetApp();
	CRect rect;
	GetWindowRect(rect);
	pApp->WriteProfileInt(m_Section, "left", rect.left);
	pApp->WriteProfileInt(m_Section, "top", rect.top);
	pApp->WriteProfileInt(m_Section, "right", rect.right);
	pApp->WriteProfileInt(m_Section, "bottom", rect.bottom);

}
