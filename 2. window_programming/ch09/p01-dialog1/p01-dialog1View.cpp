
// p01-dialog1View.cpp : Cp01dialog1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p01-dialog1.h"
#endif

#include "p01-dialog1Doc.h"
#include "p01-dialog1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp01dialog1View

IMPLEMENT_DYNCREATE(Cp01dialog1View, CView)

BEGIN_MESSAGE_MAP(Cp01dialog1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp01dialog1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cp01dialog1View ����/�Ҹ�

Cp01dialog1View::Cp01dialog1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cp01dialog1View::~Cp01dialog1View()
{
}

BOOL Cp01dialog1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cp01dialog1View �׸���

void Cp01dialog1View::OnDraw(CDC* /*pDC*/)
{
	Cp01dialog1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// Cp01dialog1View �μ�


void Cp01dialog1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp01dialog1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cp01dialog1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cp01dialog1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void Cp01dialog1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp01dialog1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp01dialog1View ����

#ifdef _DEBUG
void Cp01dialog1View::AssertValid() const
{
	CView::AssertValid();
}

void Cp01dialog1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp01dialog1Doc* Cp01dialog1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp01dialog1Doc)));
	return (Cp01dialog1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cp01dialog1View �޽��� ó����

//L��ư�� �������� ������ dialog�� ������ �غ��� 
void Cp01dialog1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialog dlg(IDD_DIALOG1);
	if(dlg.DoModal() == IDOK) {
		MessageBox("OK", "TEST");
	}

	CView::OnLButtonDown(nFlags, point);
}
