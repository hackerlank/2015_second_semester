
// p02-cclinent.h : p02-cclinent ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp02cclinentApp:
// �� Ŭ������ ������ ���ؼ��� p02-cclinent.cpp�� �����Ͻʽÿ�.
//

class Cp02cclinentApp : public CWinApp
{
public:
	Cp02cclinentApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp02cclinentApp theApp;
