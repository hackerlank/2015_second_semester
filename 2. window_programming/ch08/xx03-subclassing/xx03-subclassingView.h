
// xx03-subclassingView.h : Cxx03subclassingView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "myedit.h"
#include "afxwin.h"


class Cxx03subclassingView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Cxx03subclassingView();
	DECLARE_DYNCREATE(Cxx03subclassingView)

public:
	enum{ IDD = IDD_XX03SUBCLASSING_FORM };

// Ư���Դϴ�.
public:
	Cxx03subclassingDoc* GetDocument() const;

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
	virtual ~Cxx03subclassingView();
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
	CMyEdit edit;
	CButton check;
	afx_msg void OnBnClickedCheck1();
};

#ifndef _DEBUG  // xx03-subclassingView.cpp�� ����� ����
inline Cxx03subclassingDoc* Cxx03subclassingView::GetDocument() const
   { return reinterpret_cast<Cxx03subclassingDoc*>(m_pDocument); }
#endif

