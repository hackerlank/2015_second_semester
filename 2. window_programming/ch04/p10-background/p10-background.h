
// p10-background.h : p10-background ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp10backgroundApp:
// �� Ŭ������ ������ ���ؼ��� p10-background.cpp�� �����Ͻʽÿ�.
//

class Cp10backgroundApp : public CWinApp
{
public:
	Cp10backgroundApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp10backgroundApp theApp;
