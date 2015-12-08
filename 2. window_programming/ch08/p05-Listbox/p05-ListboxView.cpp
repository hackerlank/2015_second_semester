
// p05-ListboxView.cpp : Cp05ListboxView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p05-Listbox.h"
#endif

#include "p05-ListboxDoc.h"
#include "p05-ListboxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp05ListboxView

IMPLEMENT_DYNCREATE(Cp05ListboxView, CFormView)

BEGIN_MESSAGE_MAP(Cp05ListboxView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &Cp05ListboxView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cp05ListboxView::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST2, &Cp05ListboxView::OnLbnSelchangeList2)
END_MESSAGE_MAP()

// Cp05ListboxView ����/�Ҹ�

Cp05ListboxView::Cp05ListboxView()
	: CFormView(Cp05ListboxView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cp05ListboxView::~Cp05ListboxView()
{
}

void Cp05ListboxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list1);
	DDX_Control(pDX, IDC_LIST2, list2);
}

BOOL Cp05ListboxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void Cp05ListboxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//list1�� string�� �߰����ֱ�.
	list1.AddString("�����"); 
	list1.AddString("�ڻ���"); 
	list1.AddString("�ӻ���"); 
	list1.AddString("������"); 
	list1.AddString("������");
	list1.SetCurSel(3);



}

void Cp05ListboxView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp05ListboxView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp05ListboxView ����

#ifdef _DEBUG
void Cp05ListboxView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cp05ListboxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cp05ListboxDoc* Cp05ListboxView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp05ListboxDoc)));
	return (Cp05ListboxDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp05ListboxView �޽��� ó����

//��ư1 �̺�Ʈ ó���ϱ�
void Cp05ListboxView::OnBnClickedButton1()
{
	if(list1.GetCurSel() >= 0) {
		CString str; 
		list1.GetText(list1.GetCurSel(), str);
		list1.DeleteString(list1.GetCurSel());
		list2.AddString(str);
		if(list1.GetCurSel() == 0) {

		} else if(list1.GetCurSel() <= 1)
			list1.SetCurSel(list1.GetCurSel()+1);
		
	}
}


void Cp05ListboxView::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}


void Cp05ListboxView::OnLbnSelchangeList2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
