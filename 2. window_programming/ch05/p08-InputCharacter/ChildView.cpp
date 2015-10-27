
// ChildView.cpp : CChildView Ŭ������ ����
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

//��������10���� ���� ����
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	CFont font;
	//���� ũ��, ����ü
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CRect r;
	this->GetClientRect(&r);

	CreateSolidCaret(2, 30); //�ɷ��� �����Ѵ�. (ĳ���� ũ�⵵ ���� ���η� ��������)
	SetCaretPos(CPoint(r.right, r.bottom-10)); //ĳ���� ��ġ�� �����Ѵ�. 
	
	ShowCaret();
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	//CWnd::OnKillFocus(pNewWnd);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	HideCaret();
	::DestroyCaret();
}
