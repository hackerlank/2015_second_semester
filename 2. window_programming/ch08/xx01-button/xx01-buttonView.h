
// xx01-buttonView.h : Cxx01buttonView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"
		//�������ϱ� ��Ŭ���
		#include "MyButton.h"


class Cxx01buttonView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	Cxx01buttonView();
	DECLARE_DYNCREATE(Cxx01buttonView)

public:
	enum{ IDD = IDD_XX01BUTTON_FORM };

// Ư���Դϴ�.
public:
	Cxx01buttonDoc* GetDocument() const;

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
	virtual ~Cxx01buttonView();
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
			//cmybutton���� �ٲ��ְ�
			CMyButton button;
			afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // xx01-buttonView.cpp�� ����� ����
inline Cxx01buttonDoc* Cxx01buttonView::GetDocument() const
   { return reinterpret_cast<Cxx01buttonDoc*>(m_pDocument); }
#endif

