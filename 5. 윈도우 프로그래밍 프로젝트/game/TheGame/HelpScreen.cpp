#include "StdAfx.h"
#include "HelpScreen.h"
#include	<vector>
#include	"MfcGraphics.h"
#include	"Assets.h"
#include	"Graphics.h"
#include	"MrNomGame.h"
#include	"MainMenuScreen.h"
#include	"HelpScreen2.h"

CHelpScreen::CHelpScreen(CGame *game): CScreen(game)
{

}


CHelpScreen::~CHelpScreen(void)
{
}

void	CHelpScreen::update(int delta)

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
			if(event->x > 256 && event->y > 416){
				game->setScreen(new CHelpScreen2(game));
				return;
			}
		}
	}
}

void	CHelpScreen::render()

{
	CGraphics	*g=game->getGraphics();

	g->drawPixmap(CAssets::background, 0, 0);
	g->drawPixmap(CAssets::help1, 64, 100);
	g->drawPixmap(CAssets::buttons, 256, 416, 0, 64, 64, 64);
}

void	CHelpScreen::pause()
{

}

void	CHelpScreen::resume()
{

}

void	CHelpScreen::dispose()
{

}