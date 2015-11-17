
// xx03-subclassingView.cpp : Cxx03subclassingView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "xx03-subclassing.h"
#endif

#include "xx03-subclassingDoc.h"
#include "xx03-subclassingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cxx03subclassingView

IMPLEMENT_DYNCREATE(Cxx03subclassingView, CFormView)

BEGIN_MESSAGE_MAP(Cxx03subclassingView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_CHECK1, &Cxx03subclassingView::OnBnClickedCheck1)
END_MESSAGE_MAP()

// Cxx03subclassingView 생성/소멸

Cxx03subclassingView::Cxx03subclassingView()
	: CFormView(Cxx03subclassingView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cxx03subclassingView::~Cxx03subclassingView()
{
}

void Cxx03subclassingView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
	DDX_Control(pDX, IDC_CHECK1, check);
}

BOOL Cxx03subclassingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cxx03subclassingView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cxx03subclassingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cxx03subclassingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cxx03subclassingView 진단

#ifdef _DEBUG
void Cxx03subclassingView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cxx03subclassingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cxx03subclassingDoc* Cxx03subclassingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cxx03subclassingDoc)));
	return (Cxx03subclassingDoc*)m_pDocument;
}
#endif //_DEBUG


// Cxx03subclassingView 메시지 처리기


void Cxx03subclassingView::OnBnClickedCheck1()
{
	edit.checkFlag = (check.GetCheck() == 1);
	edit.SetFocus();
}
