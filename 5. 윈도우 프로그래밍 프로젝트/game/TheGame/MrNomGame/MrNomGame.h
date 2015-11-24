#pragma once
#include "..\FrameworkMFC\mfcgame.h"
class CMrNomGame :
	public CMfcGame
{
public:
	CMrNomGame(void);
	~CMrNomGame(void);

	CScreen	*getStartScreen();
};

