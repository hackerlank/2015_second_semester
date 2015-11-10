
// p01_DocumentViewView.cpp : Cp01_DocumentViewView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "p01_DocumentView.h"
#endif

#include "p01_DocumentViewDoc.h"
#include "p01_DocumentViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp01_DocumentViewView

IMPLEMENT_DYNCREATE(Cp01_DocumentViewView, CView)

BEGIN_MESSAGE_MAP(Cp01_DocumentViewView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp01_DocumentViewView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cp01_DocumentViewView 생성/소멸

Cp01_DocumentViewView::Cp01_DocumentViewView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cp01_DocumentViewView::~Cp01_DocumentViewView()
{
}

BOOL Cp01_DocumentViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cp01_DocumentViewView 그리기

void Cp01_DocumentViewView::OnDraw(CDC* pDC)
{
	Cp01_DocumentViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	//7장 - 1 ㄱㄱ
	CBrush b(RGB(255, 0, 0, ));
	CBrush *oldBrush = pDC->SelectObject(&b);
	pDC->Rectangle(50, 50, 200, 200);
	pDC->Ellipse(200, 200, 400, 400);
	pDC->SelectObject(oldBrush);
}


// Cp01_DocumentViewView 인쇄


void Cp01_DocumentViewView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp01_DocumentViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cp01_DocumentViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cp01_DocumentViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cp01_DocumentViewView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp01_DocumentViewView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp01_DocumentViewView 진단

#ifdef _DEBUG
void Cp01_DocumentViewView::AssertValid() const
{
	CView::AssertValid();
}

void Cp01_DocumentViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp01_DocumentViewDoc* Cp01_DocumentViewView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp01_DocumentViewDoc)));
	return (Cp01_DocumentViewDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp01_DocumentViewView 메시지 처리기
