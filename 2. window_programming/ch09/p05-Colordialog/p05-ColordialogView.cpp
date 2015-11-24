
// p05-ColordialogView.cpp : Cp05ColordialogView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p05-Colordialog.h"
#endif

#include "p05-ColordialogDoc.h"
#include "p05-ColordialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp05ColordialogView

IMPLEMENT_DYNCREATE(Cp05ColordialogView, CView)

BEGIN_MESSAGE_MAP(Cp05ColordialogView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp05ColordialogView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cp05ColordialogView ����/�Ҹ�

Cp05ColordialogView::Cp05ColordialogView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	str = "jmleeeeeeeeeeee";
	color = RGB(255, 0, 0);
}

Cp05ColordialogView::~Cp05ColordialogView()
{
}

BOOL Cp05ColordialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cp05ColordialogView �׸���

void Cp05ColordialogView::OnDraw(CDC* pDC)
{
	Cp05ColordialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->SetTextColor(color);
	pDC->TextOutA(100, 100, str);
}


// Cp05ColordialogView �μ�


void Cp05ColordialogView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp05ColordialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cp05ColordialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cp05ColordialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void Cp05ColordialogView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp05ColordialogView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp05ColordialogView ����

#ifdef _DEBUG
void Cp05ColordialogView::AssertValid() const
{
	CView::AssertValid();
}

void Cp05ColordialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp05ColordialogDoc* Cp05ColordialogView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp05ColordialogDoc)));
	return (Cp05ColordialogDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp05ColordialogView �޽��� ó����

//������ cstring�� dlg�� ��� ������ �ٲپ� ���� 
void Cp05ColordialogView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CColorDialog dlg(color);

	dlg.DoModal();
	color = dlg.GetColor();
	this->Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
