#pragma once
#include "afxwin.h"


// CMyDialog 대화 상자입니다.

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMyDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
