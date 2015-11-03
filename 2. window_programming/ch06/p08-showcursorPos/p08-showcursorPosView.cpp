
// p08-showcursorPosView.cpp : Cp08showcursorPosView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p08-showcursorPos.h"
#endif

#include "p08-showcursorPosDoc.h"
#include "p08-showcursorPosView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp08showcursorPosView

IMPLEMENT_DYNCREATE(Cp08showcursorPosView, CView)

BEGIN_MESSAGE_MAP(Cp08showcursorPosView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp08showcursorPosView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cp08showcursorPosView ����/�Ҹ�

Cp08showcursorPosView::Cp08showcursorPosView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cp08showcursorPosView::~Cp08showcursorPosView()
{
}

BOOL Cp08showcursorPosView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cp08showcursorPosView �׸���

void Cp08showcursorPosView::OnDraw(CDC* /*pDC*/)
{
	Cp08showcursorPosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// Cp08showcursorPosView �μ�


void Cp08showcursorPosView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp08showcursorPosView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cp08showcursorPosView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cp08showcursorPosView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void Cp08showcursorPosView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp08showcursorPosView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp08showcursorPosView ����

#ifdef _DEBUG
void Cp08showcursorPosView::AssertValid() const
{
	CView::AssertValid();
}

void Cp08showcursorPosView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp08showcursorPosDoc* Cp08showcursorPosView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp08showcursorPosDoc)));
	return (Cp08showcursorPosDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp08showcursorPosView �޽��� ó����
