
// p02-resourceView.cpp : Cp02resourceView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p02-resource.h"
#endif

#include "p02-resourceDoc.h"
#include "p02-resourceView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp02resourceView

IMPLEMENT_DYNCREATE(Cp02resourceView, CFormView)

BEGIN_MESSAGE_MAP(Cp02resourceView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	//ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS1, &Cp02resourceView::OnIpnFieldchangedIpaddress1)
	ON_BN_CLICKED(IDC_BUTTON1, &Cp02resourceView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &Cp02resourceView::OnBnClickedCheck1)
END_MESSAGE_MAP()

// Cp02resourceView ����/�Ҹ�

Cp02resourceView::Cp02resourceView()
	: CFormView(Cp02resourceView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cp02resourceView::~Cp02resourceView()
{
}

void Cp02resourceView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, push);
	DDX_Control(pDX, IDC_CHECK1, check);
	DDX_Control(pDX, IDC_CHECK2, state3);
	DDX_Control(pDX, IDC_RADIO1, radio2);
	//DDX_Control(pDX, IDC_RADIO1, xxx);

}

BOOL Cp02resourceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void Cp02resourceView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
		////�ʱⰪ ����
	check.SetCheck(1);
	state3.SetCheck(2);
	//xxx.SetCheck(1);

}

void Cp02resourceView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp02resourceView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp02resourceView ����

#ifdef _DEBUG
void Cp02resourceView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cp02resourceView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cp02resourceDoc* Cp02resourceView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp02resourceDoc)));
	return (Cp02resourceDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp02resourceView �޽��� ó����


void Cp02resourceView::OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void Cp02resourceView::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MessageBox("Cp02resourceView::OnBnClickedButton1", "hahahahha", MB_OK);
}

////8�� �������� 4�� - üũ�ڽ��� onoff���¿� ���� Ǫ�� ��ư�� Ȱ��ȭ��Ȱ��ȭ ���°� ����ǵ��� �����ֱ��
void Cp02resourceView::OnBnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(check.GetCheck()) {
		push.EnableWindow(true);
	} else {
		push.EnableWindow(false);
	}
}


void Cp02resourceView::OnDraw(CDC* pDC)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CBrush b(RGB(0, 0, 255));
	pDC->SelectObject(&b);
	pDC->Rectangle(19, 19, 300, 400);


}
