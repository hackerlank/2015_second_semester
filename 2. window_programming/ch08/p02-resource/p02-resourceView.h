
// p02-resourceView.h : Cp02resourceView 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cp02resourceView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cp02resourceView();
	DECLARE_DYNCREATE(Cp02resourceView)

public:
	enum{ IDD = IDD_P02RESOURCE_FORM };

// 특성입니다.
public:
	Cp02resourceDoc* GetDocument() const;

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
	virtual ~Cp02resourceView();
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

#ifndef _DEBUG  // p02-resourceView.cpp의 디버그 버전
inline Cp02resourceDoc* Cp02resourceView::GetDocument() const
   { return reinterpret_cast<Cp02resourceDoc*>(m_pDocument); }
#endif

