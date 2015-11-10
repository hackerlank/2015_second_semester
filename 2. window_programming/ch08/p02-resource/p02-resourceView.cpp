
// p02-resourceView.cpp : Cp02resourceView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "p02-resource.h"
#endif

#include "p02-resourceDoc.h"
#include "p02-resourceView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cp02resourceView

IMPLEMENT_DYNCREATE(Cp02resourceView, CFormView)

BEGIN_MESSAGE_MAP(Cp02resourceView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	//ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS1, &Cp02resourceView::OnIpnFieldchangedIpaddress1)
	ON_BN_CLICKED(IDC_BUTTON1, &Cp02resourceView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &Cp02resourceView::OnBnClickedCheck1)
END_MESSAGE_MAP()

// Cp02resourceView 생성/소멸

Cp02resourceView::Cp02resourceView()
	: CFormView(Cp02resourceView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cp02resourceView::~Cp02resourceView()
{
}

void Cp02resourceView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, push);
	DDX_Control(pDX, IDC_CHECK1, check);
	DDX_Control(pDX, IDC_CHECK2, state3);
	DDX_Control(pDX, IDC_RADIO1, radio2);
	//DDX_Control(pDX, IDC_RADIO1, xxx);

}

BOOL Cp02resourceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cp02resourceView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
		////초기값 설정
	check.SetCheck(1);
	state3.SetCheck(2);
	//xxx.SetCheck(1);

}

void Cp02resourceView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cp02resourceView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cp02resourceView 진단

#ifdef _DEBUG
void Cp02resourceView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cp02resourceView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cp02resourceDoc* Cp02resourceView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cp02resourceDoc)));
	return (Cp02resourceDoc*)m_pDocument;
}
#endif //_DEBUG


// Cp02resourceView 메시지 처리기


void Cp02resourceView::OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void Cp02resourceView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox("Cp02resourceView::OnBnClickedButton1", "hahahahha", MB_OK);
}

////8장 연습문제 4번 - 체크박스의 onoff상태에 따라 푸시 버튼의 활성화비활성화 상태가 변경되도록 수정핫기오
void Cp02resourceView::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(check.GetCheck()) {
		push.EnableWindow(true);
	} else {
		push.EnableWindow(false);
	}
}


void Cp02resourceView::OnDraw(CDC* pDC)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CBrush b(RGB(0, 0, 255));
	pDC->SelectObject(&b);
	pDC->Rectangle(19, 19, 300, 400);


}
