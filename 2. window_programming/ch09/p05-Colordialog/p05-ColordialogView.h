
// p05-ColordialogView.h : Cp05ColordialogView 클래스의 인터페이스
//

#pragma once


class Cp05ColordialogView : public CView
{
protected: // serialization에서만 만들어집니다.
	Cp05ColordialogView();
	DECLARE_DYNCREATE(Cp05ColordialogView)

// 특성입니다.
public:
	Cp05ColordialogDoc* GetDocument() const;

// 작업입니다.
public:
	//칼라를 칠해보게 변수선언
	CString str;
	COLORREF color;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~Cp05ColordialogView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // p05-ColordialogView.cpp의 디버그 버전
inline Cp05ColordialogDoc* Cp05ColordialogView::GetDocument() const
   { return reinterpret_cast<Cp05ColordialogDoc*>(m_pDocument); }
#endif

