
// p03-DisableCloseButtons.h : p03-DisableCloseButtons ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp03DisableCloseButtonsApp:
// �� Ŭ������ ������ ���ؼ��� p03-DisableCloseButtons.cpp�� �����Ͻʽÿ�.
//

class Cp03DisableCloseButtonsApp : public CWinApp
{
public:
	Cp03DisableCloseButtonsApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp03DisableCloseButtonsApp theApp;
