
// p08_showcursorPos.h : p08_showcursorPos ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp08_showcursorPosApp:
// �� Ŭ������ ������ ���ؼ��� p08_showcursorPos.cpp�� �����Ͻʽÿ�.
//

class Cp08_showcursorPosApp : public CWinAppEx
{
public:
	Cp08_showcursorPosApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp08_showcursorPosApp theApp;
