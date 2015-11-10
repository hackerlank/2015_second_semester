
// xx02-staticView.h : Cxx02staticView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include <vector>
#include "afxwin.h"

class Cxx02staticView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Cxx02staticView();
	DECLARE_DYNCREATE(Cxx02staticView)

public:
	enum{ IDD = IDD_XX02STATIC_FORM };

// Ư���Դϴ�.
public:
	Cxx02staticDoc* GetDocument() const;
			//1.���� �����ϼ���
			std::vector <CPoint> ps;
			bool pressed;

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
	virtual ~Cxx02staticView();
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
	virtual void OnDraw(CDC* /*pDC*/);
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CStatic picture;
};

#ifndef _DEBUG  // xx02-staticView.cpp�� ����� ����
inline Cxx02staticDoc* Cxx02staticView::GetDocument() const
   { return reinterpret_cast<Cxx02staticDoc*>(m_pDocument); }
#endif

