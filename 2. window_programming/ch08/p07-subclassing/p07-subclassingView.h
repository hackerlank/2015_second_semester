
// p07-subclassingView.h : Cp07subclassingView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"
	//include ���־���
	#include "MyEdit.h"


class Cp07subclassingView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Cp07subclassingView();
	DECLARE_DYNCREATE(Cp07subclassingView)

public:
	enum{ IDD = IDD_P07SUBCLASSING_FORM };

// Ư���Դϴ�.
public:
	Cp07subclassingDoc* GetDocument() const;

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
	virtual ~Cp07subclassingView();
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
};

#ifndef _DEBUG  // p07-subclassingView.cpp�� ����� ����
inline Cp07subclassingDoc* Cp07subclassingView::GetDocument() const
   { return reinterpret_cast<Cp07subclassingDoc*>(m_pDocument); }
#endif

