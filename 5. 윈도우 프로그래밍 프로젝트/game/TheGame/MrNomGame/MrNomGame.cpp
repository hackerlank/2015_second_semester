#include	"StdAfx.h"
#include	"MrNomGame.h"
#include	"LoadingScreen.h"


CMrNomGame::CMrNomGame(void)
{
}


CMrNomGame::~CMrNomGame(void)
{
}

CScreen	*CMrNomGame::getStartScreen(void)
{
	return new CLoadingScreen(this);
}



