#pragma once
#include "afxwin.h"


// CMyDialog ��ȭ �����Դϴ�.

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMyDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString str;
	int font;
	CEdit edit;
	CComboBox combo;
	afx_msg void OnCbnSelchangeFont();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedClear();
	virtual BOOL OnInitDialog();
};
