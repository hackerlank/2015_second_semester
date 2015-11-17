
// p04-editView.h : Cp04editView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cp04editView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Cp04editView();
	DECLARE_DYNCREATE(Cp04editView)

public:
	enum{ IDD = IDD_P04EDIT_FORM };

// Ư���Դϴ�.
public:
	Cp04editDoc* GetDocument() const;

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
	virtual ~Cp04editView();
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
	CEdit edit;
	CStatic static1;
	afx_msg void OnStnDisableStatic1();
	afx_msg void OnEnMaxtextEdit1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEditUndo();
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnEditPpaste();
	afx_msg void OnStnClickedStatic1();
};

#ifndef _DEBUG  // p04-editView.cpp�� ����� ����
inline Cp04editDoc* Cp04editView::GetDocument() const
   { return reinterpret_cast<Cp04editDoc*>(m_pDocument); }
#endif

