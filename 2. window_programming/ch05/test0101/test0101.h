
// test0101.h : test0101 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Ctest0101App:
// �� Ŭ������ ������ ���ؼ��� test0101.cpp�� �����Ͻʽÿ�.
//

class Ctest0101App : public CWinApp
{
public:
	Ctest0101App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctest0101App theApp;
