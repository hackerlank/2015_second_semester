
// prac02.h : prac02 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cprac02App:
// �� Ŭ������ ������ ���ؼ��� prac02.cpp�� �����Ͻʽÿ�.
//

class Cprac02App : public CWinApp
{
public:
	Cprac02App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cprac02App theApp;
