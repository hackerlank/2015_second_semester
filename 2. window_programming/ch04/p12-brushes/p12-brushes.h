
// p12-brushes.h : p12-brushes ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp12brushesApp:
// �� Ŭ������ ������ ���ؼ��� p12-brushes.cpp�� �����Ͻʽÿ�.
//

class Cp12brushesApp : public CWinApp
{
public:
	Cp12brushesApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp12brushesApp theApp;
