
// ex02_1.h : ex02_1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cex02_1App:
// �� Ŭ������ ������ ���ؼ��� ex02_1.cpp�� �����Ͻʽÿ�.
//

class Cex02_1App : public CWinApp
{
public:
	Cex02_1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cex02_1App theApp;
