
// p01-drawcircles.h : p01-drawcircles ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp01drawcirclesApp:
// �� Ŭ������ ������ ���ؼ��� p01-drawcircles.cpp�� �����Ͻʽÿ�.
//

class Cp01drawcirclesApp : public CWinApp
{
public:
	Cp01drawcirclesApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp01drawcirclesApp theApp;
