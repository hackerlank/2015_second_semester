
// p01-mdiView.h : Cp01mdiView Ŭ������ �������̽�
//

#pragma once


class Cp01mdiView : public CView
{
protected: // serialization������ ��������ϴ�.
	Cp01mdiView();
	DECLARE_DYNCREATE(Cp01mdiView)

// Ư���Դϴ�.
public:
	Cp01mdiDoc* GetDocument() const;

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
	virtual ~Cp01mdiView();
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

#ifndef _DEBUG  // p01-mdiView.cpp�� ����� ����
inline Cp01mdiDoc* Cp01mdiView::GetDocument() const
   { return reinterpret_cast<Cp01mdiDoc*>(m_pDocument); }
#endif

