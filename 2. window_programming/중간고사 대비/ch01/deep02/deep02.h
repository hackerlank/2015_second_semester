
// deep02.h : deep02 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cdeep02App:
// �� Ŭ������ ������ ���ؼ��� deep02.cpp�� �����Ͻʽÿ�.
//

class Cdeep02App : public CWinApp
{
public:
	Cdeep02App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cdeep02App theApp;
