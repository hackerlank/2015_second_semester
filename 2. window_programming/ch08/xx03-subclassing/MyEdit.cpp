// MyEdit.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "xx03-subclassing.h"
#include "MyEdit.h"


// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{
		checkFlag = false;
}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CMyEdit 메시지 처리기입니다.




void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(checkFlag == true) {
		if(nChar >= '0' && nChar <= '9' || nChar == '-') {
			CEdit::OnChar(nChar, nRepCnt, nFlags);
		}
	} else {
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	}
}
