
// p01_DocumentViewView.h : Cp01_DocumentViewView Ŭ������ �������̽�
//

#pragma once


class Cp01_DocumentViewView : public CView
{
protected: // serialization������ ��������ϴ�.
	Cp01_DocumentViewView();
	DECLARE_DYNCREATE(Cp01_DocumentViewView)

// Ư���Դϴ�.
public:
	Cp01_DocumentViewDoc* GetDocument() const;

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
	virtual ~Cp01_DocumentViewView();
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

#ifndef _DEBUG  // p01_DocumentViewView.cpp�� ����� ����
inline Cp01_DocumentViewDoc* Cp01_DocumentViewView::GetDocument() const
   { return reinterpret_cast<Cp01_DocumentViewDoc*>(m_pDocument); }
#endif

