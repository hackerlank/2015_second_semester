
// p01-Button1View.h : Cp01Button1View Ŭ������ �������̽�
//

#pragma once


class Cp01Button1View : public CView
{
protected: // serialization������ ��������ϴ�.
	Cp01Button1View();
	DECLARE_DYNCREATE(Cp01Button1View)

// Ư���Դϴ�.
public:
	Cp01Button1Doc* GetDocument() const;
	CButton push;
	CButton check;
	CButton state3;
	CButton radio1;
	CButton radio2;
	CButton group;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~Cp01Button1View();
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void OnButtonClicked();
};

#ifndef _DEBUG  // p01-Button1View.cpp�� ����� ����
inline Cp01Button1Doc* Cp01Button1View::GetDocument() const
   { return reinterpret_cast<Cp01Button1Doc*>(m_pDocument); }
#endif

