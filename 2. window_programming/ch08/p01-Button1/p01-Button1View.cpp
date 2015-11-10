
// p01-Button1View.cpp : Cp01Button1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p01-Button1.h"
#endif

#include "p01-Button1Doc.h"
#include "p01-Button1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp01Button1View

IMPLEMENT_DYNCREATE(Cp01Button1View, CView)

BEGIN_MESSAGE_MAP(Cp01Button1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp01Button1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	////button�鿡 �Ҵ�Ǿ� �ִ� ID 101 ���� �޽����� �־��� . 
	ON_BN_CLICKED(101, OnButtonClicked)
END_MESSAGE_MAP()

// Cp01Button1View ����/�Ҹ�

Cp01Button1View::Cp01Button1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cp01Button1View::~Cp01Button1View()
{
}

BOOL Cp01Button1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cp01Button1View �׸���

void Cp01Button1View::OnDraw(CDC* /*pDC*/)
{
	Cp01Button1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// Cp01Button1View �μ�


void Cp01Button1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp01Button1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cp01Button1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cp01Button1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void Cp01Button1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp01Button1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp01Button1View ����

#ifdef _DEBUG
void Cp01Button1View::AssertValid() const
{
	CView::AssertValid();
}

void Cp01Button1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp01Button1Doc* Cp01Button1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp01Button1Doc)));
	return (Cp01Button1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cp01Button1View �޽��� ó����


int Cp01Button1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	push.Create("Push Button", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20, 20, 160, 50), this, 101);
	check.Create("Check Box", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, CRect(20, 60, 160, 90), this, 101);
	state3.Create("3State Check Box", WS_CHILD | WS_VISIBLE | BS_AUTO3STATE, CRect(20, 100, 160, 130), this, 101);
	radio1.Create("radio 1", WS_CHILD | WS_VISIBLE | WS_GROUP | BS_AUTORADIOBUTTON, CRect(20, 170, 160, 200), this, 101);
	radio2.Create("radio 2", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, CRect(20, 210, 160, 240), this, 101);
	group.Create("Group Box", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, CRect(20, 140, 160, 250), this, 101);
	
	//����Ʈ �ʱⰪ�ִ� �ڵ�
	check.SetCheck(1);
	state3.SetCheck(2);
	radio2.SetCheck(1);
	return 0;
}

void Cp01Button1View::OnButtonClicked() {
	MessageBox("Cp01Button1View::OnButtonClicked", "test");
}