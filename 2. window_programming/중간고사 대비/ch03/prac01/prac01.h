
// prac01.h : prac01 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cprac01App:
// �� Ŭ������ ������ ���ؼ��� prac01.cpp�� �����Ͻʽÿ�.
//

class Cprac01App : public CWinApp
{
public:
	Cprac01App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cprac01App theApp;
