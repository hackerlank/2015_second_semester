
// p05-ColordialogView.cpp : Cp05ColordialogView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "p05-Colordialog.h"
#endif

#include "p05-ColordialogDoc.h"
#include "p05-ColordialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp05ColordialogView

IMPLEMENT_DYNCREATE(Cp05ColordialogView, CView)

BEGIN_MESSAGE_MAP(Cp05ColordialogView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp05ColordialogView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cp05ColordialogView 생성/소멸

Cp05ColordialogView::Cp05ColordialogView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	str = "jmleeeeeeeeeeee";
	color = RGB(255, 0, 0);
}

Cp05ColordialogView::~Cp05ColordialogView()
{
}

BOOL Cp05ColordialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cp05ColordialogView 그리기

void Cp05ColordialogView::OnDraw(CDC* pDC)
{
	Cp05ColordialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->SetTextColor(color);
	pDC->TextOutA(100, 100, str);
}


// Cp05ColordialogView 인쇄


void Cp05ColordialogView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp05ColordialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cp05ColordialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cp05ColordialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cp05ColordialogView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp05ColordialogView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp05ColordialogView 진단

#ifdef _DEBUG
void Cp05ColordialogView::AssertValid() const
{
	CView::AssertValid();
}

void Cp05ColordialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp05ColordialogDoc* Cp05ColordialogView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp05ColordialogDoc)));
	return (Cp05ColordialogDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp05ColordialogView 메시지 처리기

//쓰여진 cstring을 dlg를 열어서 색깔을 바꾸어 보자 
void Cp05ColordialogView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CColorDialog dlg(color);
	//CDialog dlg;
	dlg.DoModal();
	color = dlg.GetColor();
	this->Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
