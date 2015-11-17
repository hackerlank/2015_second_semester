
// xx01-buttonView.cpp : Cxx01buttonView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "xx01-button.h"
#endif

#include "xx01-buttonDoc.h"
#include "xx01-buttonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cxx01buttonView

IMPLEMENT_DYNCREATE(Cxx01buttonView, CFormView)

BEGIN_MESSAGE_MAP(Cxx01buttonView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &Cxx01buttonView::OnBnClickedButton1)
END_MESSAGE_MAP()

// Cxx01buttonView ����/�Ҹ�

Cxx01buttonView::Cxx01buttonView()
	: CFormView(Cxx01buttonView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cxx01buttonView::~Cxx01buttonView()
{
}

void Cxx01buttonView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, button);
}

BOOL Cxx01buttonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void Cxx01buttonView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cxx01buttonView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cxx01buttonView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cxx01buttonView ����

#ifdef _DEBUG
void Cxx01buttonView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cxx01buttonView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cxx01buttonDoc* Cxx01buttonView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cxx01buttonDoc)));
	return (Cxx01buttonDoc*)m_pDocument;
}
#endif //_DEBUG


// Cxx01buttonView �޽��� ó����


void Cxx01buttonView::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
