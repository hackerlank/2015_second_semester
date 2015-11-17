// MyButton.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "xx01-button.h"
#include "MyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
{

}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
END_MESSAGE_MAP()



// CMyButton 메시지 처리기입니다.



//뭔가 그려줘야 할때 호출된다 이거져
//그러니까 얘를 이용해야 데겟져
//기억이 가물가물하네
void CMyButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CRect r;
	this->GetWindowRect(&r);
	
	CDC dc;
	//CClientDC dc(this);

	dc.Attach(lpDrawItemStruct->hDC);
	if(lpDrawItemStruct->itemState & ODS_SELECTED) {
			dc.TextOutA(0, 0, "j m lee");
	} else {
			dc.TextOutA(0, 0, "재문리");
	}
	dc.Detach();

}
