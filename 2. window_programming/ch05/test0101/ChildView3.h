
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once


// CChildView â

class CChildView3 : public CWnd
{
// �����Դϴ�.
public:
	CChildView3();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView3();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

