
// p01_DocumentView.h : p01_DocumentView ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp01_DocumentViewApp:
// �� Ŭ������ ������ ���ؼ��� p01_DocumentView.cpp�� �����Ͻʽÿ�.
//

class Cp01_DocumentViewApp : public CWinAppEx
{
public:
	Cp01_DocumentViewApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp01_DocumentViewApp theApp;
