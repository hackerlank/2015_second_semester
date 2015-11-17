
// xx03-subclassingView.cpp : Cxx03subclassingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "xx03-subclassing.h"
#endif

#include "xx03-subclassingDoc.h"
#include "xx03-subclassingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cxx03subclassingView

IMPLEMENT_DYNCREATE(Cxx03subclassingView, CFormView)

BEGIN_MESSAGE_MAP(Cxx03subclassingView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_CHECK1, &Cxx03subclassingView::OnBnClickedCheck1)
END_MESSAGE_MAP()

// Cxx03subclassingView ����/�Ҹ�

Cxx03subclassingView::Cxx03subclassingView()
	: CFormView(Cxx03subclassingView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cxx03subclassingView::~Cxx03subclassingView()
{
}

void Cxx03subclassingView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
	DDX_Control(pDX, IDC_CHECK1, check);
}

BOOL Cxx03subclassingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void Cxx03subclassingView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cxx03subclassingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cxx03subclassingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cxx03subclassingView ����

#ifdef _DEBUG
void Cxx03subclassingView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cxx03subclassingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cxx03subclassingDoc* Cxx03subclassingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cxx03subclassingDoc)));
	return (Cxx03subclassingDoc*)m_pDocument;
}
#endif //_DEBUG


// Cxx03subclassingView �޽��� ó����


void Cxx03subclassingView::OnBnClickedCheck1()
{
	edit.checkFlag = (check.GetCheck() == 1);
	edit.SetFocus();
}
