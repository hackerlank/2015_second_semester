
// deep01.h : deep01 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cdeep01App:
// �� Ŭ������ ������ ���ؼ��� deep01.cpp�� �����Ͻʽÿ�.
//

class Cdeep01App : public CWinApp
{
public:
	Cdeep01App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cdeep01App theApp;
