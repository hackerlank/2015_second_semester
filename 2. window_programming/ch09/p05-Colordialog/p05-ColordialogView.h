
// p05-ColordialogView.h : Cp05ColordialogView Ŭ������ �������̽�
//

#pragma once


class Cp05ColordialogView : public CView
{
protected: // serialization������ ��������ϴ�.
	Cp05ColordialogView();
	DECLARE_DYNCREATE(Cp05ColordialogView)

// Ư���Դϴ�.
public:
	Cp05ColordialogDoc* GetDocument() const;

// �۾��Դϴ�.
public:
	//Į�� ĥ�غ��� ��������
	CString str;
	COLORREF color;

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
	virtual ~Cp05ColordialogView();
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

#ifndef _DEBUG  // p05-ColordialogView.cpp�� ����� ����
inline Cp05ColordialogDoc* Cp05ColordialogView::GetDocument() const
   { return reinterpret_cast<Cp05ColordialogDoc*>(m_pDocument); }
#endif

