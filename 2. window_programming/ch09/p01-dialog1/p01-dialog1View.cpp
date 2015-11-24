
// p01-dialog1View.cpp : Cp01dialog1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "p01-dialog1.h"
#endif

#include "p01-dialog1Doc.h"
#include "p01-dialog1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp01dialog1View

IMPLEMENT_DYNCREATE(Cp01dialog1View, CView)

BEGIN_MESSAGE_MAP(Cp01dialog1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp01dialog1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cp01dialog1View 생성/소멸

Cp01dialog1View::Cp01dialog1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cp01dialog1View::~Cp01dialog1View()
{
}

BOOL Cp01dialog1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cp01dialog1View 그리기

void Cp01dialog1View::OnDraw(CDC* /*pDC*/)
{
	Cp01dialog1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cp01dialog1View 인쇄


void Cp01dialog1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp01dialog1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cp01dialog1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cp01dialog1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cp01dialog1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp01dialog1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp01dialog1View 진단

#ifdef _DEBUG
void Cp01dialog1View::AssertValid() const
{
	CView::AssertValid();
}

void Cp01dialog1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp01dialog1Doc* Cp01dialog1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp01dialog1Doc)));
	return (Cp01dialog1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cp01dialog1View 메시지 처리기

//L버튼을 눌렀을때 생성한 dialog가 나오게 해보자 
void Cp01dialog1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialog dlg(IDD_DIALOG1);
	if(dlg.DoModal() == IDOK) {
		MessageBox("OK", "TEST");
	}

	CView::OnLButtonDown(nFlags, point);
}
