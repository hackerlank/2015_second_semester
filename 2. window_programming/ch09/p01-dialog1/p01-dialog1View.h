
// p01-dialog1View.h : Cp01dialog1View Ŭ������ �������̽�
//

#pragma once


class Cp01dialog1View : public CView
{
protected: // serialization������ ��������ϴ�.
	Cp01dialog1View();
	DECLARE_DYNCREATE(Cp01dialog1View)

// Ư���Դϴ�.
public:
	Cp01dialog1Doc* GetDocument() const;

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
	virtual ~Cp01dialog1View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // p01-dialog1View.cpp�� ����� ����
inline Cp01dialog1Doc* Cp01dialog1View::GetDocument() const
   { return reinterpret_cast<Cp01dialog1Doc*>(m_pDocument); }
#endif

