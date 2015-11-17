
// p07-subclassingView.cpp : Cp07subclassingView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "p07-subclassing.h"
#endif

#include "p07-subclassingDoc.h"
#include "p07-subclassingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp07subclassingView

IMPLEMENT_DYNCREATE(Cp07subclassingView, CFormView)

BEGIN_MESSAGE_MAP(Cp07subclassingView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cp07subclassingView 생성/소멸

Cp07subclassingView::Cp07subclassingView()
	: CFormView(Cp07subclassingView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cp07subclassingView::~Cp07subclassingView()
{
}

void Cp07subclassingView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
}

BOOL Cp07subclassingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cp07subclassingView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cp07subclassingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp07subclassingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp07subclassingView 진단

#ifdef _DEBUG
void Cp07subclassingView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cp07subclassingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cp07subclassingDoc* Cp07subclassingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp07subclassingDoc)));
	return (Cp07subclassingDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp07subclassingView 메시지 처리기
