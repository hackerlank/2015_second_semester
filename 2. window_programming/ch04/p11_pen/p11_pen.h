
// p11_pen.h : p11_pen ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp11_penApp:
// �� Ŭ������ ������ ���ؼ��� p11_pen.cpp�� �����Ͻʽÿ�.
//

class Cp11_penApp : public CWinApp
{
public:
	Cp11_penApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp11_penApp theApp;
