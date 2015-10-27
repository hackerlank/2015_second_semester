
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p08-InputCharacter.h"
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
	ON_WM_CHAR()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
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

//연습문제10번도 같이 ㄱㄱ
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	CFont font;
	//글자 크기, 글자체
	font.CreatePointFont(150, "Consolas");
	dc.SelectObject(&font);
	
	CRect r;
	this->GetClientRect(&r);
	
	dc.DrawText(str, str.GetLength(), &r, DT_LEFT);
	if(str.GetLength() != 0 ) {
		dc.DrawText(str, str.GetLength(), &r, DT_LEFT|DT_CALCRECT);
		this->SetCaretPos(CPoint(r.Width(), r.Height()-30));
	} else {
		this->SetCaretPos(CPoint(0, 0));
	}
}



void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect r;
	this->GetClientRect(&r);

	if(nChar == VK_BACK) {
		if(str.GetLength() > 0 ) {
			str.Delete(str.GetLength()-1);
		}
	} else {
		str.AppendChar(nChar);

	}
	this->Invalidate();
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}


void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	//CWnd::OnSetFocus(pOldWnd);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect r;
	this->GetClientRect(&r);

	CreateSolidCaret(2, 30); //케럿을 생성한다. (캐럿의 크기도 가로 세로로 조절가능)
	SetCaretPos(CPoint(r.right, r.bottom-10)); //캐럿의 위치를 설정한다. 
	
	ShowCaret();
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	//CWnd::OnKillFocus(pNewWnd);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	HideCaret();
	::DestroyCaret();
}
