
// p07-drawtext.h : p07-drawtext ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp07drawtextApp:
// �� Ŭ������ ������ ���ؼ��� p07-drawtext.cpp�� �����Ͻʽÿ�.
//

class Cp07drawtextApp : public CWinApp
{
public:
	Cp07drawtextApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp07drawtextApp theApp;
