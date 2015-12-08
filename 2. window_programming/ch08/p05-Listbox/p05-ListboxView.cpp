
// p05-ListboxView.cpp : Cp05ListboxView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// Cp05ListboxView 생성/소멸

Cp05ListboxView::Cp05ListboxView()
	: CFormView(Cp05ListboxView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cp05ListboxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//list1에 string값 추가해주기.
	list1.AddString("김사장"); 
	list1.AddString("박사장"); 
	list1.AddString("임사장"); 
	list1.AddString("차사장"); 
	list1.AddString("공사장");
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


// Cp05ListboxView 진단

#ifdef _DEBUG
void Cp05ListboxView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cp05ListboxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cp05ListboxDoc* Cp05ListboxView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp05ListboxDoc)));
	return (Cp05ListboxDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp05ListboxView 메시지 처리기

//버튼1 이벤트 처리하기
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}


void Cp05ListboxView::OnLbnSelchangeList2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
