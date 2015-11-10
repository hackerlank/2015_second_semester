
// xx02-staticView.cpp : Cxx02staticView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "xx02-static.h"
#endif

#include "xx02-staticDoc.h"
#include "xx02-staticView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cxx02staticView

IMPLEMENT_DYNCREATE(Cxx02staticView, CFormView)

BEGIN_MESSAGE_MAP(Cxx02staticView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cxx02staticView 생성/소멸

Cxx02staticView::Cxx02staticView()
	: CFormView(Cxx02staticView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	pressed = false;

}

Cxx02staticView::~Cxx02staticView()
{
}

void Cxx02staticView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYSTATIC, picture);
}

BOOL Cxx02staticView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cxx02staticView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cxx02staticView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cxx02staticView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cxx02staticView 진단

#ifdef _DEBUG
void Cxx02staticView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cxx02staticView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cxx02staticDoc* Cxx02staticView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cxx02staticDoc)));
	return (Cxx02staticDoc*)m_pDocument;
}
#endif //_DEBUG


// Cxx02staticView 메시지 처리기


void Cxx02staticView::OnDraw(CDC* pDC)
{
	for(int i=0 ; i<ps.size() ; i++) {
		if(i == 0) {
			pDC->MoveTo(ps[i]);
		} else {
			pDC->LineTo(ps[i]);
		}
	}
}


void Cxx02staticView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		pressed = false;
		this->SetTimer(4/*번*/, 2000/*초*/, NULL);
	//CFormView::OnLButtonUp(nFlags, point);
}


void Cxx02staticView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		ps.clear();
		pressed = true;
		ps.push_back(point);
	//CFormView::OnLButtonDown(nFlags, point);
}


void Cxx02staticView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(pressed == 1) {
		ps.push_back(point);
		this->Invalidate();
	}
	//CFormView::OnMouseMove(nFlags, point);
}


void Cxx02staticView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->KillTimer(nIDEvent);
	CClientDC dc(&picture);

	for(int i=0 ; i<ps.size() ; i++) {
		if(i == 0) {
			dc.MoveTo(ps[i]);
		} else {
			dc.LineTo(ps[i]);
		}
	}
	ps.clear();
	//this->Invalidate();
	//CFormView::OnTimer(nIDEvent);
}
