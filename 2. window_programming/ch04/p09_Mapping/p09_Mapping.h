
// p09_Mapping.h : p09_Mapping ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp09_MappingApp:
// �� Ŭ������ ������ ���ؼ��� p09_Mapping.cpp�� �����Ͻʽÿ�.
//

class Cp09_MappingApp : public CWinApp
{
public:
	Cp09_MappingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp09_MappingApp theApp;
