
// p04-changecursor.h : p04-changecursor ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp04changecursorApp:
// �� Ŭ������ ������ ���ؼ��� p04-changecursor.cpp�� �����Ͻʽÿ�.
//

class Cp04changecursorApp : public CWinApp
{
public:
	Cp04changecursorApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp04changecursorApp theApp;
