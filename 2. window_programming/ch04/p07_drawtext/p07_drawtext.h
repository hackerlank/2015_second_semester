
// p07_drawtext.h : p07_drawtext ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp07_drawtextApp:
// �� Ŭ������ ������ ���ؼ��� p07_drawtext.cpp�� �����Ͻʽÿ�.
//

class Cp07_drawtextApp : public CWinApp
{
public:
	Cp07_drawtextApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp07_drawtextApp theApp;
