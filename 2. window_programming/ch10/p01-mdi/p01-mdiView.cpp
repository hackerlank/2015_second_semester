
// p01-mdiView.cpp : Cp01mdiView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p01-mdi.h"
#endif

#include "p01-mdiDoc.h"
#include "p01-mdiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp01mdiView

IMPLEMENT_DYNCREATE(Cp01mdiView, CView)

BEGIN_MESSAGE_MAP(Cp01mdiView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp01mdiView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cp01mdiView ����/�Ҹ�

Cp01mdiView::Cp01mdiView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cp01mdiView::~Cp01mdiView()
{
}

BOOL Cp01mdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cp01mdiView �׸���

void Cp01mdiView::OnDraw(CDC* /*pDC*/)
{
	Cp01mdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// Cp01mdiView �μ�


void Cp01mdiView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp01mdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cp01mdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cp01mdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void Cp01mdiView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp01mdiView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp01mdiView ����

#ifdef _DEBUG
void Cp01mdiView::AssertValid() const
{
	CView::AssertValid();
}

void Cp01mdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp01mdiDoc* Cp01mdiView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp01mdiDoc)));
	return (Cp01mdiDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp01mdiView �޽��� ó����
