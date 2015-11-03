
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "p03-Selectcolor.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	color = RGB(255, 0, 0);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CChildView::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE/*906*/, &CChildView::OnColorBlue)
	ON_COMMAND(ID_COLOR_YELLOW/*906*/, &CChildView::OnColorYellow)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CChildView::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CChildView::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CChildView::OnUpdateColorGreen)
	ON_WM_CONTEXTMENU()
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
	CFont font;
	font.CreatePointFont(200, "궁서체");
	dc.SelectObject(&font);

	dc.SetTextColor(color);
	dc.TextOutA(200, 200, "이재문 만세에에에에에에");
}



void CChildView::OnColorRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	color = RGB(255, 0, 0);
	this->Invalidate();
}


void CChildView::OnColorGreen()
{
	color = RGB(0, 255, 0);
	this->Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CChildView::OnColorBlue()
{
	color = RGB(0, 0, 255);
	this->Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
void CChildView::OnColorYellow()
{
	color = RGB(255, 255, 0);
	this->Invalidate();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CChildView::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if(color == RGB(255, 0, 0)) {
		pCmdUI->SetText("이재문 만세");
	}
}


void CChildView::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	if(color == RGB(0, 0, 255)) {
		pCmdUI->Enable(false);
	}
}


void CChildView::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	if(color == RGB(0, 255, 0)) {
		pCmdUI->SetCheck(1);
	}
}

//컨텍스트 메뉴 만들기 실습까지 게속
void CChildView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// //컨텍스트 메뉴 만들기1
	//CMenu menu;
	//menu.LoadMenuA(IDR_MENU1);
	//CMenu *p = menu.GetSubMenu(0);
	//p->TrackPopupMenu(TPM_RIGHTALIGN | TPM_RIGHTBUTTON, 	point.x, point.y, pWnd);
	
	
	////실습 6-2? 코드를 이용한 메뉴 생성
	CMenu menu;
	menu.CreatePopupMenu();
	menu.AppendMenuA(MF_STRING, ID_COLOR_RED, "빨갱이");
	menu.AppendMenuA(MF_STRING, ID_COLOR_GREEN, "초록이");
	menu.AppendMenuA(MF_STRING, ID_COLOR_BLUE/*906*/, "퍼랭이");
	menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, pWnd);

}
