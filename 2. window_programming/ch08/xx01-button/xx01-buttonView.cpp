
// xx01-buttonView.cpp : Cxx01buttonView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "xx01-button.h"
#endif

#include "xx01-buttonDoc.h"
#include "xx01-buttonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cxx01buttonView

IMPLEMENT_DYNCREATE(Cxx01buttonView, CFormView)

BEGIN_MESSAGE_MAP(Cxx01buttonView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &Cxx01buttonView::OnBnClickedButton1)
END_MESSAGE_MAP()

// Cxx01buttonView 생성/소멸

Cxx01buttonView::Cxx01buttonView()
	: CFormView(Cxx01buttonView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cxx01buttonView::~Cxx01buttonView()
{
}

void Cxx01buttonView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, button);
}

BOOL Cxx01buttonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cxx01buttonView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cxx01buttonView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cxx01buttonView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cxx01buttonView 진단

#ifdef _DEBUG
void Cxx01buttonView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cxx01buttonView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cxx01buttonDoc* Cxx01buttonView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cxx01buttonDoc)));
	return (Cxx01buttonDoc*)m_pDocument;
}
#endif //_DEBUG


// Cxx01buttonView 메시지 처리기


void Cxx01buttonView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
