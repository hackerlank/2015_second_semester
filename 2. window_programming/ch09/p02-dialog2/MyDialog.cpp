// MyDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "p02-dialog2.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog ��ȭ �����Դϴ�.

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


// CMyDialog �޽��� ó�����Դϴ�.


void CMyDialog::OnCbnSelchangeFont()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMyDialog::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//this->UpdateData();

	edit.GetWindowTextA(str);
	font = combo.GetCurSel();
	EndDialog(IDC_OK);
}


void CMyDialog::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	this->UpdateData(true);		//ȭ��� dialog�� �ִ� �����͸� ��ġ ���Ѷ� (true false�� ������ �ٲ�)
	EndDialog(IDC_CANCEL);
}


void CMyDialog::OnBnClickedClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(IDC_CLEAR);
}


BOOL CMyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	edit.SetWindowTextA(str);
	combo.SetCurSel(font);
	//edit.setcursel

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
