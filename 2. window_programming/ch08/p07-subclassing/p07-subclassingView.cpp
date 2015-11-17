
// p07-subclassingView.cpp : Cp07subclassingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p07-subclassing.h"
#endif

#include "p07-subclassingDoc.h"
#include "p07-subclassingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp07subclassingView

IMPLEMENT_DYNCREATE(Cp07subclassingView, CFormView)

BEGIN_MESSAGE_MAP(Cp07subclassingView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cp07subclassingView ����/�Ҹ�

Cp07subclassingView::Cp07subclassingView()
	: CFormView(Cp07subclassingView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cp07subclassingView::~Cp07subclassingView()
{
}

void Cp07subclassingView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
}

BOOL Cp07subclassingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void Cp07subclassingView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cp07subclassingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp07subclassingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp07subclassingView ����

#ifdef _DEBUG
void Cp07subclassingView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cp07subclassingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cp07subclassingDoc* Cp07subclassingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp07subclassingDoc)));
	return (Cp07subclassingDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp07subclassingView �޽��� ó����
