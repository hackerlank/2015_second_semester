
// p08-showcursorPosView.h : Cp08showcursorPosView Ŭ������ �������̽�
//

#pragma once


class Cp08showcursorPosView : public CView
{
protected: // serialization������ ��������ϴ�.
	Cp08showcursorPosView();
	DECLARE_DYNCREATE(Cp08showcursorPosView)

// Ư���Դϴ�.
public:
	Cp08showcursorPosDoc* GetDocument() const;

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
	virtual ~Cp08showcursorPosView();
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
};

#ifndef _DEBUG  // p08-showcursorPosView.cpp�� ����� ����
inline Cp08showcursorPosDoc* Cp08showcursorPosView::GetDocument() const
   { return reinterpret_cast<Cp08showcursorPosDoc*>(m_pDocument); }
#endif

