
// cpaintdc.h : cpaintdc ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CcpaintdcApp:
// �� Ŭ������ ������ ���ؼ��� cpaintdc.cpp�� �����Ͻʽÿ�.
//

class CcpaintdcApp : public CWinApp
{
public:
	CcpaintdcApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CcpaintdcApp theApp;
