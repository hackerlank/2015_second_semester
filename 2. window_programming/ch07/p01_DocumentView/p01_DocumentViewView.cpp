
// p01_DocumentViewView.cpp : Cp01_DocumentViewView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p01_DocumentView.h"
#endif

#include "p01_DocumentViewDoc.h"
#include "p01_DocumentViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp01_DocumentViewView

IMPLEMENT_DYNCREATE(Cp01_DocumentViewView, CView)

BEGIN_MESSAGE_MAP(Cp01_DocumentViewView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp01_DocumentViewView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cp01_DocumentViewView ����/�Ҹ�

Cp01_DocumentViewView::Cp01_DocumentViewView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cp01_DocumentViewView::~Cp01_DocumentViewView()
{
}

BOOL Cp01_DocumentViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cp01_DocumentViewView �׸���

void Cp01_DocumentViewView::OnDraw(CDC* pDC)
{
	Cp01_DocumentViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	//7�� - 1 ����
	CBrush b(RGB(255, 0, 0, ));
	CBrush *oldBrush = pDC->SelectObject(&b);
	pDC->Rectangle(50, 50, 200, 200);
	pDC->Ellipse(200, 200, 400, 400);
	pDC->SelectObject(oldBrush);
}


// Cp01_DocumentViewView �μ�


void Cp01_DocumentViewView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp01_DocumentViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cp01_DocumentViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cp01_DocumentViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void Cp01_DocumentViewView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp01_DocumentViewView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp01_DocumentViewView ����

#ifdef _DEBUG
void Cp01_DocumentViewView::AssertValid() const
{
	CView::AssertValid();
}

void Cp01_DocumentViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp01_DocumentViewDoc* Cp01_DocumentViewView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp01_DocumentViewDoc)));
	return (Cp01_DocumentViewDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp01_DocumentViewView �޽��� ó����
