
// xx03-subclassingView.h : Cxx03subclassingView 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "myedit.h"
#include "afxwin.h"


class Cxx03subclassingView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cxx03subclassingView();
	DECLARE_DYNCREATE(Cxx03subclassingView)

public:
	enum{ IDD = IDD_XX03SUBCLASSING_FORM };

// 특성입니다.
public:
	Cxx03subclassingDoc* GetDocument() const;

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
	virtual ~Cxx03subclassingView();
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
	CMyEdit edit;
	CButton check;
	afx_msg void OnBnClickedCheck1();
};

#ifndef _DEBUG  // xx03-subclassingView.cpp의 디버그 버전
inline Cxx03subclassingDoc* Cxx03subclassingView::GetDocument() const
   { return reinterpret_cast<Cxx03subclassingDoc*>(m_pDocument); }
#endif

