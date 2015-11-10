
// p02-resourceView.h : Cp02resourceView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cp02resourceView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Cp02resourceView();
	DECLARE_DYNCREATE(Cp02resourceView)

public:
	enum{ IDD = IDD_P02RESOURCE_FORM };

// Ư���Դϴ�.
public:
	Cp02resourceDoc* GetDocument() const;

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
	virtual ~Cp02resourceView();
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
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	CButton push;
	CButton check;
	CButton state3;

	CButton radio2;
CButton xxx;
afx_msg void OnBnClickedCheck1();
virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // p02-resourceView.cpp�� ����� ����
inline Cp02resourceDoc* Cp02resourceView::GetDocument() const
   { return reinterpret_cast<Cp02resourceDoc*>(m_pDocument); }
#endif

