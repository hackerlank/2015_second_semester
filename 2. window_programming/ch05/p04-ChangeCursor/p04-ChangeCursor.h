
// p04-ChangeCursor.h : p04-ChangeCursor ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp04ChangeCursorApp:
// �� Ŭ������ ������ ���ؼ��� p04-ChangeCursor.cpp�� �����Ͻʽÿ�.
//

class Cp04ChangeCursorApp : public CWinApp
{
public:
	Cp04ChangeCursorApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp04ChangeCursorApp theApp;
