
// p05-Colordialog.h : p05-Colordialog ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp05ColordialogApp:
// �� Ŭ������ ������ ���ؼ��� p05-Colordialog.cpp�� �����Ͻʽÿ�.
//

class Cp05ColordialogApp : public CWinAppEx
{
public:
	Cp05ColordialogApp();


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

extern Cp05ColordialogApp theApp;
