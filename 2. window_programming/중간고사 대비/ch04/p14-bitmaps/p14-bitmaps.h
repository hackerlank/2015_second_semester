
// p14-bitmaps.h : p14-bitmaps ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp14bitmapsApp:
// �� Ŭ������ ������ ���ؼ��� p14-bitmaps.cpp�� �����Ͻʽÿ�.
//

class Cp14bitmapsApp : public CWinApp
{
public:
	Cp14bitmapsApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp14bitmapsApp theApp;
