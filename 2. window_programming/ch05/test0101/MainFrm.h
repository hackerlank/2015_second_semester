
// MainFrm.h : CMainFrame 클래스의 인터페이스
//

#pragma once
#include "ChildView.h"
#include "ChildView2.h"
#include "ChildView3.h"
#include "ChildView4.h"


class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 컨트롤 모음이 포함된 멤버입니다.
	CStatusBar        m_wndStatusBar;
	CChildView     m_wndView;
	CChildView2    m_wndView2;
	CChildView3    m_wndView3;
	CChildView4    m_wndView4;

// 생성된 메시지 맵 함수
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

public:
	virtual void RecalcLayout(BOOL bNotify = TRUE);
};


