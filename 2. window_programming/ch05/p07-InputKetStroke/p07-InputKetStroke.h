
// p07-InputKetStroke.h : p07-InputKetStroke ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp07InputKetStrokeApp:
// �� Ŭ������ ������ ���ؼ��� p07-InputKetStroke.cpp�� �����Ͻʽÿ�.
//

class Cp07InputKetStrokeApp : public CWinApp
{
public:
	Cp07InputKetStrokeApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp07InputKetStrokeApp theApp;
