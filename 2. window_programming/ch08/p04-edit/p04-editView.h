
// p04-editView.h : Cp04editView 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cp04editView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cp04editView();
	DECLARE_DYNCREATE(Cp04editView)

public:
	enum{ IDD = IDD_P04EDIT_FORM };

// 특성입니다.
public:
	Cp04editDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~Cp04editView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // p04-editView.cpp의 디버그 버전
inline Cp04editDoc* Cp04editView::GetDocument() const
   { return reinterpret_cast<Cp04editDoc*>(m_pDocument); }
#endif

