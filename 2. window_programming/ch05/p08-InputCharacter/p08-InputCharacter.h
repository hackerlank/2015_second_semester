
// p08-InputCharacter.h : p08-InputCharacter ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp08InputCharacterApp:
// �� Ŭ������ ������ ���ؼ��� p08-InputCharacter.cpp�� �����Ͻʽÿ�.
//

class Cp08InputCharacterApp : public CWinApp
{
public:
	Cp08InputCharacterApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp08InputCharacterApp theApp;
