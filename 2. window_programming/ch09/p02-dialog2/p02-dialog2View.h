
// p02-dialog2View.h : Cp02dialog2View Ŭ������ �������̽�
//

#pragma once


class Cp02dialog2View : public CView
{
protected: // serialization������ ��������ϴ�.
	Cp02dialog2View();
	DECLARE_DYNCREATE(Cp02dialog2View)

// Ư���Դϴ�.
public:
	Cp02dialog2Doc* GetDocument() const;

// �۾��Դϴ�.
public:
			//��������
			CString	mystr;
			int myfont;

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
	virtual ~Cp02dialog2View();
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

#ifndef _DEBUG  // p02-dialog2View.cpp�� ����� ����
inline Cp02dialog2Doc* Cp02dialog2View::GetDocument() const
   { return reinterpret_cast<Cp02dialog2Doc*>(m_pDocument); }
#endif

