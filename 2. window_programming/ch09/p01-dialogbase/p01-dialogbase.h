
// p01-dialogbase.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Cp01dialogbaseApp:
// �� Ŭ������ ������ ���ؼ��� p01-dialogbase.cpp�� �����Ͻʽÿ�.
//

class Cp01dialogbaseApp : public CWinApp
{
public:
	Cp01dialogbaseApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern Cp01dialogbaseApp theApp;