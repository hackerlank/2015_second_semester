
// p05-trackmouse.h : p05-trackmouse ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp05trackmouseApp:
// �� Ŭ������ ������ ���ؼ��� p05-trackmouse.cpp�� �����Ͻʽÿ�.
//

class Cp05trackmouseApp : public CWinApp
{
public:
	Cp05trackmouseApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp05trackmouseApp theApp;
