
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once


// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	BOOL drawMode; //�׸��� �۾��� ���� ������ ��Ÿ����. 
	int x1, y1, x2, y2; //Ÿ���� �����ϴ� ���簢���� �»��/���ϴ� ��ǥ��. 
	CPoint ps, pe;
	bool pressed;
	std::vector<CPoint> pss, pes;
// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

