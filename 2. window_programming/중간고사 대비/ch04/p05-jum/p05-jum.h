
// p05-jum.h : p05-jum ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp05jumApp:
// �� Ŭ������ ������ ���ؼ��� p05-jum.cpp�� �����Ͻʽÿ�.
//

class Cp05jumApp : public CWinApp
{
public:
	Cp05jumApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp05jumApp theApp;
