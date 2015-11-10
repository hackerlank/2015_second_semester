
// p01-Button1View.cpp : Cp01Button1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "p01-Button1.h"
#endif

#include "p01-Button1Doc.h"
#include "p01-Button1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp01Button1View

IMPLEMENT_DYNCREATE(Cp01Button1View, CView)

BEGIN_MESSAGE_MAP(Cp01Button1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp01Button1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	////button들에 할당되어 있는 ID 101 값의 메시지를 주었다 . 
	ON_BN_CLICKED(101, OnButtonClicked)
END_MESSAGE_MAP()

// Cp01Button1View 생성/소멸

Cp01Button1View::Cp01Button1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cp01Button1View::~Cp01Button1View()
{
}

BOOL Cp01Button1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cp01Button1View 그리기

void Cp01Button1View::OnDraw(CDC* /*pDC*/)
{
	Cp01Button1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cp01Button1View 인쇄


void Cp01Button1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp01Button1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cp01Button1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cp01Button1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cp01Button1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp01Button1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp01Button1View 진단

#ifdef _DEBUG
void Cp01Button1View::AssertValid() const
{
	CView::AssertValid();
}

void Cp01Button1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp01Button1Doc* Cp01Button1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp01Button1Doc)));
	return (Cp01Button1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cp01Button1View 메시지 처리기


int Cp01Button1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	push.Create("Push Button", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20, 20, 160, 50), this, 101);
	check.Create("Check Box", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, CRect(20, 60, 160, 90), this, 101);
	state3.Create("3State Check Box", WS_CHILD | WS_VISIBLE | BS_AUTO3STATE, CRect(20, 100, 160, 130), this, 101);
	radio1.Create("radio 1", WS_CHILD | WS_VISIBLE | WS_GROUP | BS_AUTORADIOBUTTON, CRect(20, 170, 160, 200), this, 101);
	radio2.Create("radio 2", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, CRect(20, 210, 160, 240), this, 101);
	group.Create("Group Box", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, CRect(20, 140, 160, 250), this, 101);
	
	//디폴트 초기값주는 코드
	check.SetCheck(1);
	state3.SetCheck(2);
	radio2.SetCheck(1);
	return 0;
}

void Cp01Button1View::OnButtonClicked() {
	MessageBox("Cp01Button1View::OnButtonClicked", "test");
}