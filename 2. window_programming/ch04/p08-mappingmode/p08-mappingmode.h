
// p08-mappingmode.h : p08-mappingmode ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp08mappingmodeApp:
// �� Ŭ������ ������ ���ؼ��� p08-mappingmode.cpp�� �����Ͻʽÿ�.
//

class Cp08mappingmodeApp : public CWinApp
{
public:
	Cp08mappingmodeApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp08mappingmodeApp theApp;
