
// p02-dialog2View.cpp : Cp02dialog2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "p02-dialog2.h"
#endif

#include "p02-dialog2Doc.h"
#include "p02-dialog2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp02dialog2View

IMPLEMENT_DYNCREATE(Cp02dialog2View, CView)

BEGIN_MESSAGE_MAP(Cp02dialog2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cp02dialog2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cp02dialog2View 생성/소멸

Cp02dialog2View::Cp02dialog2View()
{
			//변수 초기화 ㄱㄱ
			mystr = "테슷트";
			myfont = 1;
}

Cp02dialog2View::~Cp02dialog2View()
{
}

BOOL Cp02dialog2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cp02dialog2View 그리기

void Cp02dialog2View::OnDraw(CDC* pDC)
{
	Cp02dialog2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// fonts배열에 글자체를 넣어놓고, int값을 변경해서 글씨를 바꾸는 방법
	CString fonts[] = {"굴림", "궁서체", "바탕"};
	CFont font;
	font.CreatePointFont(200, fonts[myfont]);
	pDC->SelectObject(&font);

	pDC->TextOutA(10, 10, mystr);
}


// Cp02dialog2View 인쇄


void Cp02dialog2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cp02dialog2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cp02dialog2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cp02dialog2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cp02dialog2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp02dialog2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp02dialog2View 진단

#ifdef _DEBUG
void Cp02dialog2View::AssertValid() const
{
	CView::AssertValid();
}

void Cp02dialog2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cp02dialog2Doc* Cp02dialog2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp02dialog2Doc)));
	return (Cp02dialog2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cp02dialog2View 메시지 처리기
#include "MyDialog.h"

void Cp02dialog2View::OnLButtonDown(UINT nFlags, CPoint point)
{	
	CMyDialog dlg;
	
	//dlg.edit.SetWindowTextA(mystr); //->이 코드를 쓰면 dlg가 생성된뒤 다시 파괴
	//수동으로 전달하고
	dlg.str = mystr;
	dlg.font = myfont;

	int res = dlg.DoModal();
	if(res == IDC_OK) {
		//dlg.edit.GetWindowTextA(mystr);
		//myfont = dlg.combo.GetCurSel();
		//수동으로 전달 받는
		mystr = dlg.str;
		myfont = dlg.font;
	}
	if(res == IDC_CLEAR) {
		mystr == "";
	}
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
