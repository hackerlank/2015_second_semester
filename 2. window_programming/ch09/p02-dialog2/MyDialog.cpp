// MyDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "p02-dialog2.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDialog::IDD, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
	DDX_Control(pDX, IDC_FONT, combo);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_FONT, &CMyDialog::OnCbnSelchangeFont)
	ON_BN_CLICKED(IDC_OK, &CMyDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CANCEL, &CMyDialog::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CLEAR, &CMyDialog::OnBnClickedClear)
END_MESSAGE_MAP()


// CMyDialog 메시지 처리기입니다.


void CMyDialog::OnCbnSelchangeFont()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMyDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//this->UpdateData();

	edit.GetWindowTextA(str);
	font = combo.GetCurSel();
	EndDialog(IDC_OK);
}


void CMyDialog::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	this->UpdateData(true);		//화면과 dialog에 있는 데이터를 일치 시켜라 (true false로 방향이 바뀜)
	EndDialog(IDC_CANCEL);
}


void CMyDialog::OnBnClickedClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(IDC_CLEAR);
}


BOOL CMyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	edit.SetWindowTextA(str);
	combo.SetCurSel(font);
	//edit.setcursel

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
