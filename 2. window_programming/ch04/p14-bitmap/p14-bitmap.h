
// p14-bitmap.h : p14-bitmap ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp14bitmapApp:
// �� Ŭ������ ������ ���ؼ��� p14-bitmap.cpp�� �����Ͻʽÿ�.
//

class Cp14bitmapApp : public CWinApp
{
public:
	Cp14bitmapApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp14bitmapApp theApp;
