
// xx03-subclassing.h : xx03-subclassing ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cxx03subclassingApp:
// �� Ŭ������ ������ ���ؼ��� xx03-subclassing.cpp�� �����Ͻʽÿ�.
//

class Cxx03subclassingApp : public CWinAppEx
{
public:
	Cxx03subclassingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cxx03subclassingApp theApp;
