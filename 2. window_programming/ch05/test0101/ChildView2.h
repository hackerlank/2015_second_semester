
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once


// CChildView â

class CChildView2 : public CWnd
{
// �����Դϴ�.
public:
	CChildView2();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView2();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

