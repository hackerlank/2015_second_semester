
// p06-drawline.h : p06-drawline ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp06drawlineApp:
// �� Ŭ������ ������ ���ؼ��� p06-drawline.cpp�� �����Ͻʽÿ�.
//

class Cp06drawlineApp : public CWinApp
{
public:
	Cp06drawlineApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp06drawlineApp theApp;
