
// xx02-staticView.cpp : Cxx02staticView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "xx02-static.h"
#endif

#include "xx02-staticDoc.h"
#include "xx02-staticView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cxx02staticView

IMPLEMENT_DYNCREATE(Cxx02staticView, CFormView)

BEGIN_MESSAGE_MAP(Cxx02staticView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cxx02staticView ����/�Ҹ�

Cxx02staticView::Cxx02staticView()
	: CFormView(Cxx02staticView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	pressed = false;

}

Cxx02staticView::~Cxx02staticView()
{
}

void Cxx02staticView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYSTATIC, picture);
}

BOOL Cxx02staticView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void Cxx02staticView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cxx02staticView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cxx02staticView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cxx02staticView ����

#ifdef _DEBUG
void Cxx02staticView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cxx02staticView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cxx02staticDoc* Cxx02staticView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cxx02staticDoc)));
	return (Cxx02staticDoc*)m_pDocument;
}
#endif //_DEBUG


// Cxx02staticView �޽��� ó����


void Cxx02staticView::OnDraw(CDC* pDC)
{
	for(int i=0 ; i<ps.size() ; i++) {
		if(i == 0) {
			pDC->MoveTo(ps[i]);
		} else {
			pDC->LineTo(ps[i]);
		}
	}
}


void Cxx02staticView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
		pressed = false;
		this->SetTimer(4/*��*/, 2000/*��*/, NULL);
	//CFormView::OnLButtonUp(nFlags, point);
}


void Cxx02staticView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
		ps.clear();
		pressed = true;
		ps.push_back(point);
	//CFormView::OnLButtonDown(nFlags, point);
}


void Cxx02staticView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pressed == 1) {
		ps.push_back(point);
		this->Invalidate();
	}
	//CFormView::OnMouseMove(nFlags, point);
}


void Cxx02staticView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	this->KillTimer(nIDEvent);
	CClientDC dc(&picture);

	for(int i=0 ; i<ps.size() ; i++) {
		if(i == 0) {
			dc.MoveTo(ps[i]);
		} else {
			dc.LineTo(ps[i]);
		}
	}
	ps.clear();
	//this->Invalidate();
	//CFormView::OnTimer(nIDEvent);
}
