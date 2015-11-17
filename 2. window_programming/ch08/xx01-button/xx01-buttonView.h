
// xx01-buttonView.h : Cxx01buttonView 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxwin.h"
		//에러나니까 인클루드
		#include "MyButton.h"


class Cxx01buttonView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cxx01buttonView();
	DECLARE_DYNCREATE(Cxx01buttonView)

public:
	enum{ IDD = IDD_XX01BUTTON_FORM };

// 특성입니다.
public:
	Cxx01buttonDoc* GetDocument() const;

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
	virtual ~Cxx01buttonView();
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
			//cmybutton으로 바꿔주고
			CMyButton button;
			afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // xx01-buttonView.cpp의 디버그 버전
inline Cxx01buttonDoc* Cxx01buttonView::GetDocument() const
   { return reinterpret_cast<Cxx01buttonDoc*>(m_pDocument); }
#endif

