
// prac16.h : prac16 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cprac16App:
// �� Ŭ������ ������ ���ؼ��� prac16.cpp�� �����Ͻʽÿ�.
//

class Cprac16App : public CWinApp
{
public:
	Cprac16App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cprac16App theApp;
