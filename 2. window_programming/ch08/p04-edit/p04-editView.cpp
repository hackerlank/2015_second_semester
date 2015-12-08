
// p04-editView.cpp : Cp04editView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "p04-edit.h"
#endif

#include "p04-editDoc.h"
#include "p04-editView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp04editView

IMPLEMENT_DYNCREATE(Cp04editView, CFormView)

BEGIN_MESSAGE_MAP(Cp04editView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_STN_DISABLE(IDC_STATIC1, &Cp04editView::OnEnMaxtextEdit1)
	ON_EN_CHANGE(IDC_EDIT1, &Cp04editView::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &Cp04editView::OnBnClickedButton1)
	ON_COMMAND(ID_EDIT_UNDO, &Cp04editView::OnEditUndo)
	ON_COMMAND(ID_EDIT_CUT, &Cp04editView::OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, &Cp04editView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &Cp04editView::OnEditPaste)
	ON_COMMAND(ID_EDIT_PPASTE, &Cp04editView::OnEditPpaste)
	ON_STN_CLICKED(IDC_STATIC1, &Cp04editView::OnStnClickedStatic1)
END_MESSAGE_MAP()

// Cp04editView 생성/소멸

Cp04editView::Cp04editView()
	: CFormView(Cp04editView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cp04editView::~Cp04editView()
{
}

void Cp04editView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
	DDX_Control(pDX, IDC_STATIC1, static1);
}

BOOL Cp04editView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cp04editView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
	//20글자 넘어 갈수 없게 세팅해준다. 
	//edit.SetLimitText(20);
	
	//editDoc의 주소를 읽어와서 넣어준다. 
	CString str1 = this->GetDocument()->str; //document가 가진 str을 가져온다. 

	edit.SetWindowTextA(str1);
}

void Cp04editView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp04editView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp04editView 진단

#ifdef _DEBUG
void Cp04editView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cp04editView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cp04editDoc* Cp04editView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp04editDoc)));
	return (Cp04editDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp04editView 메시지 처리기


void Cp04editView::OnEnMaxtextEdit1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox("Cp04editView::OnEnMaxtextEdit1", "오바야");
}


void Cp04editView::OnEnChangeEdit1()
{	
	/*CString str;
	edit.GetWindowTextA(str);
	static1.SetWindowTextA(str);*/

	edit.GetWindowTextA(this->GetDocument()->str);

	//document에게 바뀌었다고 조치하라고 알려줌
	this->GetDocument()->SetModifiedFlag(true);
}

//연습문제11
void Cp04editView::OnBnClickedButton1()
{
	CString str;
	edit.GetWindowTextA(str);
	static1.SetWindowTextA(str);

}

//연습문제12번
//실행취소.잘라내기.복사등등 기능 추가
void Cp04editView::OnEditUndo() { edit.Undo(); }
void Cp04editView::OnEditCut() { edit.Cut(); }
void Cp04editView::OnEditCopy() { edit.Copy(); }
void Cp04editView::OnEditPaste() { edit.Paste(); }
void Cp04editView::OnEditPpaste() {
	//MessageBox("따블카피를 했습니다","DDoubleCopy");
	edit.Paste(); edit.Paste();

}


void Cp04editView::OnStnClickedStatic1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
