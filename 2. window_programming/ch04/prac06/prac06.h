
// prac06.h : prac06 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cprac06App:
// �� Ŭ������ ������ ���ؼ��� prac06.cpp�� �����Ͻʽÿ�.
//

class Cprac06App : public CWinApp
{
public:
	Cprac06App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cprac06App theApp;
