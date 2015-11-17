
// p05-ListboxView.h : Cp05ListboxView 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cp05ListboxView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cp05ListboxView();
	DECLARE_DYNCREATE(Cp05ListboxView)

public:
	enum{ IDD = IDD_P05LISTBOX_FORM };

// 특성입니다.
public:
	Cp05ListboxDoc* GetDocument() const;

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
	virtual ~Cp05ListboxView();
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
	CListBox list1;
	CListBox list2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLbnSelchangeList2();
};

#ifndef _DEBUG  // p05-ListboxView.cpp의 디버그 버전
inline Cp05ListboxDoc* Cp05ListboxView::GetDocument() const
   { return reinterpret_cast<Cp05ListboxDoc*>(m_pDocument); }
#endif

