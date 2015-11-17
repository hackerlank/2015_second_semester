
// p05-ListboxView.h : Cp05ListboxView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cp05ListboxView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Cp05ListboxView();
	DECLARE_DYNCREATE(Cp05ListboxView)

public:
	enum{ IDD = IDD_P05LISTBOX_FORM };

// Ư���Դϴ�.
public:
	Cp05ListboxDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~Cp05ListboxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CListBox list1;
	CListBox list2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLbnSelchangeList2();
};

#ifndef _DEBUG  // p05-ListboxView.cpp�� ����� ����
inline Cp05ListboxDoc* Cp05ListboxView::GetDocument() const
   { return reinterpret_cast<Cp05ListboxDoc*>(m_pDocument); }
#endif

