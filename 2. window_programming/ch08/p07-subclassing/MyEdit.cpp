// MyEdit.cpp : ���� �����Դϴ�.
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



// CMyEdit �޽��� ó�����Դϴ�.



//Ű����� ġ�� �� �̾�ο�
void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//if(nChar >= '0' && nChar <= '9' || nChar == '-') {
		//CEdit::OnChar(nChar, nRepCnt, nFlags);
	//}


	//������ �빮�ڷ� ���ִ� �̿ϼ� �ڵ�
	if ( nChar >= 'A' && nChar <= 'Z') {
		//nChar = 'a' - (-nChar + 'A');
		//nChar = 'a' + ('A' - nChar);
		nChar = toupper(nChar);
	}
	
	CEdit::OnChar(nChar, nRepCnt, nFlags);
	
	
}
