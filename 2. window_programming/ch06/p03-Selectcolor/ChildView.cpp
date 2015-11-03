
// ChildView.cpp : CChildView Ŭ������ ����
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
	CFont font;
	font.CreatePointFont(200, "�ü�ü");
	dc.SelectObject(&font);

	dc.SetTextColor(color);
	dc.TextOutA(200, 200, "���繮 ����������������");
}



void CChildView::OnColorRed()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	color = RGB(255, 0, 0);
	this->Invalidate();
}


void CChildView::OnColorGreen()
{
	color = RGB(0, 255, 0);
	this->Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}

void CChildView::OnColorBlue()
{
	color = RGB(0, 0, 255);
	this->Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}
void CChildView::OnColorYellow()
{
	color = RGB(255, 255, 0);
	this->Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}

void CChildView::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	if(color == RGB(255, 0, 0)) {
		pCmdUI->SetText("���繮 ����");
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

//���ؽ�Ʈ �޴� ����� �ǽ����� �Լ�
void CChildView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// //���ؽ�Ʈ �޴� �����1
	//CMenu menu;
	//menu.LoadMenuA(IDR_MENU1);
	//CMenu *p = menu.GetSubMenu(0);
	//p->TrackPopupMenu(TPM_RIGHTALIGN | TPM_RIGHTBUTTON, 	point.x, point.y, pWnd);
	
	
	////�ǽ� 6-2? �ڵ带 �̿��� �޴� ����
	CMenu menu;
	menu.CreatePopupMenu();
	menu.AppendMenuA(MF_STRING, ID_COLOR_RED, "������");
	menu.AppendMenuA(MF_STRING, ID_COLOR_GREEN, "�ʷ���");
	menu.AppendMenuA(MF_STRING, ID_COLOR_BLUE/*906*/, "�۷���");
	menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, pWnd);

}
