
// p02-MenuDesign.h : p02-MenuDesign ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp02MenuDesignApp:
// �� Ŭ������ ������ ���ؼ��� p02-MenuDesign.cpp�� �����Ͻʽÿ�.
//

class Cp02MenuDesignApp : public CWinAppEx
{
public:
	Cp02MenuDesignApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cp02MenuDesignApp theApp;
