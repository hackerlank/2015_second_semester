
// p3-disavleclosebutton.h : p3-disavleclosebutton ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp3disavleclosebuttonApp:
// �� Ŭ������ ������ ���ؼ��� p3-disavleclosebutton.cpp�� �����Ͻʽÿ�.
//

class Cp3disavleclosebuttonApp : public CWinApp
{
public:
	Cp3disavleclosebuttonApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp3disavleclosebuttonApp theApp;
