
// p11-pens.h : p11-pens ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp11pensApp:
// �� Ŭ������ ������ ���ؼ��� p11-pens.cpp�� �����Ͻʽÿ�.
//

class Cp11pensApp : public CWinApp
{
public:
	Cp11pensApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp11pensApp theApp;
