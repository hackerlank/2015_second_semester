#include "StdAfx.h"
#include "MainMenuScreen.h"
#include	"Graphics.h"
#include	"MrNomGame.h"
#include	"Assets.h"
#include	"HelpScreen.h"
#include	"HighScoreScreen.h"
#include	"GameScreen.h"


CMainMenuScreen::CMainMenuScreen(CGame *game): CScreen(game)
{
}


CMainMenuScreen::~CMainMenuScreen(void)
{
}


void	CMainMenuScreen::update(int deltaTime)
{
	CGraphics	*g=game->getGraphics();
	std::vector<CMouseEvent*>	mouseEvents= game->getInput()->getMouseEvents();
	game->getInput()->getKeyEvents();	// we do not need any key events, but it will be accumulated if we do not remove them

	int	w, h;
	game->getSize(w, h);
	int	len= mouseEvents.size();
	for(int i=0;i<len;i++){
		CMouseEvent	*event= mouseEvents[i];
		if(event->type == CMouseEvent::MOUSE_UP){
			CRect	r(0, h-64, 64, h);
			if(r.PtInRect(CPoint(event->x, event->y))){
				::MessageBoxA(NULL, "touchec", "xxx", MB_OK);
				return;
			}
			
			r= CRect(64, 220, 64+192, 220+42);
			if(r.PtInRect(CPoint(event->x, event->y))){
				// newscreen
				game->setScreen(new CGameScreen(game));
				return;
			}


			r= CRect(64, 220+42, 192, 220+42+42);
			if(r.PtInRect(CPoint(event->x, event->y))){
				// newscreen
				game->setScreen(new CHighScoreScreen(game));
				return;
			}

			r= CRect(64, 220+84, 192, 220+84+42);
			if(r.PtInRect(CPoint(event->x, event->y))){
				// newscreen
				game->setScreen(new CHelpScreen(game));
				return;
			}
		}
	}
}

void	CMainMenuScreen::render()
{

	CGraphics	*g= game->getGraphics();
	g->drawPixmap(CAssets::background, 0, 0);
	g->drawPixmap(CAssets::logo, 32, 20);
	g->drawPixmap(CAssets::mainMenu, 64, 220);
	g->drawPixmap(CAssets::buttons, 0, 416, 0, 0, 64, 64);

}



void	CMainMenuScreen::pause()
{

}

void	CMainMenuScreen::resume()
{

}

void	CMainMenuScreen::dispose()
{

}
