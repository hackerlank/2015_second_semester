
// p02-cclientdc.h : p02-cclientdc ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp02cclientdcApp:
// �� Ŭ������ ������ ���ؼ��� p02-cclientdc.cpp�� �����Ͻʽÿ�.
//

class Cp02cclientdcApp : public CWinApp
{
public:
	Cp02cclientdcApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp02cclientdcApp theApp;
