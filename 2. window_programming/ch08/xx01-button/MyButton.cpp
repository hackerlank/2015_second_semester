// MyButton.cpp : ���� �����Դϴ�.
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



// CMyButton �޽��� ó�����Դϴ�.



//���� �׷���� �Ҷ� ȣ��ȴ� �̰���
//�׷��ϱ� �긦 �̿��ؾ� ������
//����� ���������ϳ�
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
			dc.TextOutA(0, 0, "�繮��");
	}
	dc.Detach();

}
