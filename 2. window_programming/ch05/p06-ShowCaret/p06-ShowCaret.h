
// p06-ShowCaret.h : p06-ShowCaret ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp06ShowCaretApp:
// �� Ŭ������ ������ ���ؼ��� p06-ShowCaret.cpp�� �����Ͻʽÿ�.
//

class Cp06ShowCaretApp : public CWinApp
{
public:
	Cp06ShowCaretApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp06ShowCaretApp theApp;
