
// x15-Freelines.h : x15-Freelines ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cx15FreelinesApp:
// �� Ŭ������ ������ ���ؼ��� x15-Freelines.cpp�� �����Ͻʽÿ�.
//

class Cx15FreelinesApp : public CWinApp
{
public:
	Cx15FreelinesApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cx15FreelinesApp theApp;
