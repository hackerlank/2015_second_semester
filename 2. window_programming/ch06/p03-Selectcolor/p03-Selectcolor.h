
// p03-Selectcolor.h : p03-Selectcolor ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cp03SelectcolorApp:
// �� Ŭ������ ������ ���ؼ��� p03-Selectcolor.cpp�� �����Ͻʽÿ�.
//

class Cp03SelectcolorApp : public CWinAppEx
{
public:
	Cp03SelectcolorApp();


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
	//code
	afx_msg void OnColorRed();
	//void OnDraw(CDC* pDC); 
};

extern Cp03SelectcolorApp theApp;
