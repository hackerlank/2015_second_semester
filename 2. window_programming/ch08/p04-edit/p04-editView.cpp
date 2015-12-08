
// p04-editView.cpp : Cp04editView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "p04-edit.h"
#endif

#include "p04-editDoc.h"
#include "p04-editView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp04editView

IMPLEMENT_DYNCREATE(Cp04editView, CFormView)

BEGIN_MESSAGE_MAP(Cp04editView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_STN_DISABLE(IDC_STATIC1, &Cp04editView::OnEnMaxtextEdit1)
	ON_EN_CHANGE(IDC_EDIT1, &Cp04editView::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &Cp04editView::OnBnClickedButton1)
	ON_COMMAND(ID_EDIT_UNDO, &Cp04editView::OnEditUndo)
	ON_COMMAND(ID_EDIT_CUT, &Cp04editView::OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, &Cp04editView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &Cp04editView::OnEditPaste)
	ON_COMMAND(ID_EDIT_PPASTE, &Cp04editView::OnEditPpaste)
	ON_STN_CLICKED(IDC_STATIC1, &Cp04editView::OnStnClickedStatic1)
END_MESSAGE_MAP()

// Cp04editView ����/�Ҹ�

Cp04editView::Cp04editView()
	: CFormView(Cp04editView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cp04editView::~Cp04editView()
{
}

void Cp04editView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
	DDX_Control(pDX, IDC_STATIC1, static1);
}

BOOL Cp04editView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void Cp04editView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
	//20���� �Ѿ� ���� ���� �������ش�. 
	//edit.SetLimitText(20);
	
	//editDoc�� �ּҸ� �о�ͼ� �־��ش�. 
	CString str1 = this->GetDocument()->str; //document�� ���� str�� �����´�. 

	edit.SetWindowTextA(str1);
}

void Cp04editView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp04editView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp04editView ����

#ifdef _DEBUG
void Cp04editView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cp04editView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cp04editDoc* Cp04editView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp04editDoc)));
	return (Cp04editDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp04editView �޽��� ó����


void Cp04editView::OnEnMaxtextEdit1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MessageBox("Cp04editView::OnEnMaxtextEdit1", "���پ�");
}


void Cp04editView::OnEnChangeEdit1()
{	
	/*CString str;
	edit.GetWindowTextA(str);
	static1.SetWindowTextA(str);*/

	edit.GetWindowTextA(this->GetDocument()->str);

	//document���� �ٲ���ٰ� ��ġ�϶�� �˷���
	this->GetDocument()->SetModifiedFlag(true);
}

//��������11
void Cp04editView::OnBnClickedButton1()
{
	CString str;
	edit.GetWindowTextA(str);
	static1.SetWindowTextA(str);

}

//��������12��
//�������.�߶󳻱�.������ ��� �߰�
void Cp04editView::OnEditUndo() { edit.Undo(); }
void Cp04editView::OnEditCut() { edit.Cut(); }
void Cp04editView::OnEditCopy() { edit.Copy(); }
void Cp04editView::OnEditPaste() { edit.Paste(); }
void Cp04editView::OnEditPpaste() {
	//MessageBox("����ī�Ǹ� �߽��ϴ�","DDoubleCopy");
	edit.Paste(); edit.Paste();

}


void Cp04editView::OnStnClickedStatic1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
