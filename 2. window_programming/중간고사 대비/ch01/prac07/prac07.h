
// prac07.h : prac07 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cprac07App:
// �� Ŭ������ ������ ���ؼ��� prac07.cpp�� �����Ͻʽÿ�.
//

class Cprac07App : public CWinApp
{
public:
	Cprac07App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cprac07App theApp;
