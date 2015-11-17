#pragma once


// CMyEdit

class CMyEdit : public CEdit
{
	DECLARE_DYNAMIC(CMyEdit)

public:
	CMyEdit();
	virtual ~CMyEdit();
	bool checkFlag;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


