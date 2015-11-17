// MyEdit.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "p07-subclassing.h"
#include "MyEdit.h"
#include <ctype.h>

// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{

}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CMyEdit 메시지 처리기입니다.



//키보드는 치면 다 이어로옴
void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//if(nChar >= '0' && nChar <= '9' || nChar == '-') {
		//CEdit::OnChar(nChar, nRepCnt, nFlags);
	//}


	//무조건 대문자로 해주는 미완성 코드
	if ( nChar >= 'A' && nChar <= 'Z') {
		//nChar = 'a' - (-nChar + 'A');
		//nChar = 'a' + ('A' - nChar);
		nChar = toupper(nChar);
	}
	
	CEdit::OnChar(nChar, nRepCnt, nFlags);
	
	
}
