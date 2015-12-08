
// p02-dialog2View.cpp : Cp02dialog2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p02-dialog2.h"
#endif

#include "p02-dialog2Doc.h"
#include "p02-dialog2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp02dialog2View

IMPLEMENT_DYNCREATE(Cp02dialog2View, CView)

BEGIN_MESSAGE_MAP(Cp02dialog2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp02dialog2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cp02dialog2View ����/�Ҹ�

Cp02dialog2View::Cp02dialog2View()
{
			//���� �ʱ�ȭ ����
			mystr = "�׽�Ʈ";
			myfont = 1;
}

Cp02dialog2View::~Cp02dialog2View()
{
}

BOOL Cp02dialog2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cp02dialog2View �׸���

void Cp02dialog2View::OnDraw(CDC* pDC)
{
	Cp02dialog2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// fonts�迭�� ����ü�� �־����, int���� �����ؼ� �۾��� �ٲٴ� ���
	CString fonts[] = {"����", "�ü�ü", "����"};
	CFont font;
	font.CreatePointFont(200, fonts[myfont]);
	pDC->SelectObject(&font);

	pDC->TextOutA(10, 10, mystr);
}


// Cp02dialog2View �μ�


void Cp02dialog2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp02dialog2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cp02dialog2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cp02dialog2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void Cp02dialog2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp02dialog2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp02dialog2View ����

#ifdef _DEBUG
void Cp02dialog2View::AssertValid() const
{
	CView::AssertValid();
}

void Cp02dialog2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp02dialog2Doc* Cp02dialog2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp02dialog2Doc)));
	return (Cp02dialog2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cp02dialog2View �޽��� ó����
#include "MyDialog.h"

void Cp02dialog2View::OnLButtonDown(UINT nFlags, CPoint point)
{	

	//button.create("dfdf"
	CMyDialog dlg;
	
	//dlg.edit.SetWindowTextA(mystr); //->�� �ڵ带 ���� dlg�� �����ȵ� �ٽ� �ı�
	//�������� �����ϰ�
	dlg.str = mystr;
	dlg.font = myfont;

	int res = dlg.DoModal();
	if(res == IDC_OK) {
		//dlg.edit.GetWindowTextA(mystr);
		//myfont = dlg.combo.GetCurSel();
		//�������� ���� �޴�
		mystr = dlg.str;
		myfont = dlg.font;
	}
	if(res == IDC_CLEAR) {
		mystr == "";
	}
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
