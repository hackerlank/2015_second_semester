
// p02-drawcirclewithmousecapture.h : p02-drawcirclewithmousecapture ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp02drawcirclewithmousecaptureApp:
// �� Ŭ������ ������ ���ؼ��� p02-drawcirclewithmousecapture.cpp�� �����Ͻʽÿ�.
//

class Cp02drawcirclewithmousecaptureApp : public CWinApp
{
public:
	Cp02drawcirclewithmousecaptureApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp02drawcirclewithmousecaptureApp theApp;
