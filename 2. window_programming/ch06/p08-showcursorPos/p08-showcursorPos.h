
// p08-showcursorPos.h : p08-showcursorPos ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp08showcursorPosApp:
// �� Ŭ������ ������ ���ؼ��� p08-showcursorPos.cpp�� �����Ͻʽÿ�.
//

class Cp08showcursorPosApp : public CWinAppEx
{
public:
	Cp08showcursorPosApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp08showcursorPosApp theApp;
