#include "StdAfx.h"
#include "LoadingScreen.h"
#include	"MfcGraphics.h"
#include	"Assets.h"
#include	"Graphics.h"
#include	"MrNomGame.h"
#include	"MainMenuScreen.h"


CLoadingScreen::CLoadingScreen(CGame *game): CScreen(game)
{
}


CLoadingScreen::~CLoadingScreen(void)
{
}


void	CLoadingScreen::update(int deltaTime)
{
	CGraphics	*g= ((CMrNomGame*)game)->getGraphics();
	CAssets::background= g->newPixMap("..\\assets\\background.png", CGraphics::RGB565);
	CAssets::logo= g->newPixMap("..\\assets\\logo.png", CGraphics::ARGB4444);
	CAssets::mainMenu= g->newPixMap("..\\assets\\mainMenu.png", CGraphics::ARGB4444);
	CAssets::buttons= g->newPixMap("..\\assets\\buttons.png", CGraphics::ARGB4444);
	CAssets::help1= g->newPixMap("..\\assets\\help1.png", CGraphics::ARGB4444);
	CAssets::help2= g->newPixMap("..\\assets\\help2.png", CGraphics::ARGB4444);
	CAssets::help3= g->newPixMap("..\\assets\\help3.png", CGraphics::ARGB4444);
	CAssets::numbers= g->newPixMap("..\\assets\\numbers.png", CGraphics::ARGB4444);
	CAssets::ready= g->newPixMap("..\\assets\\ready.png", CGraphics::ARGB4444);
	CAssets::pause= g->newPixMap("..\\assets\\pausemenu.png", CGraphics::ARGB4444);
	CAssets::gameOver= g->newPixMap("..\\assets\\gameOver.png", CGraphics::ARGB4444);
	CAssets::headUp= g->newPixMap("..\\assets\\headUp.png", CGraphics::ARGB4444);
	CAssets::headLeft= g->newPixMap("..\\assets\\headLeft.png", CGraphics::ARGB4444);
	CAssets::headDown= g->newPixMap("..\\assets\\headDown.png", CGraphics::ARGB4444);
	CAssets::headRight= g->newPixMap("..\\assets\\headRight.png", CGraphics::ARGB4444);
	CAssets::tail= g->newPixMap("..\\assets\\tail.png", CGraphics::ARGB4444);
	CAssets::stain1= g->newPixMap("..\\assets\\stain1.png", CGraphics::ARGB4444);
	CAssets::stain2= g->newPixMap("..\\assets\\stain2.png", CGraphics::ARGB4444);
	CAssets::stain3= g->newPixMap("..\\assets\\stain3.png", CGraphics::ARGB4444);

	game->setSize(CAssets::background->getWidth(), CAssets::background->getHeight());

	//newscreen
	game->setScreen(new CMainMenuScreen(game));
}

void	CLoadingScreen::render()
{ 
}


void	CLoadingScreen::pause()
{

}

void	CLoadingScreen::resume()
{

}

void	CLoadingScreen::dispose()
{

}
