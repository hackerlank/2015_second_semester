
// p01-DrawCircles.h : p01-DrawCircles ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp01DrawCirclesApp:
// �� Ŭ������ ������ ���ؼ��� p01-DrawCircles.cpp�� �����Ͻʽÿ�.
//

class Cp01DrawCirclesApp : public CWinApp
{
public:
	Cp01DrawCirclesApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp01DrawCirclesApp theApp;
