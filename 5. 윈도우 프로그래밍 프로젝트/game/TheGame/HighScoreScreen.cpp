#include "StdAfx.h"
#include "HighScoreScreen.h"
#include	<vector>
#include	"MfcGraphics.h"
#include	"Assets.h"
#include	"Graphics.h"
#include	"MrNomGame.h"
#include	"MainMenuScreen.h"
#include	"HelpScreen3.h"
#include	"Settings.h"

CHighScoreScreen::CHighScoreScreen(CGame *game): CScreen(game)
{
	lines= new CString[5];
	for(int i=0;i<5;i++){
		lines[i].Format("%d. %d", i+1, CSettings::highscores[i]);
	}
}


CHighScoreScreen::~CHighScoreScreen(void)
{
}

void	CHighScoreScreen::update(int delta)

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
			if(event->x < 64 && event->y > 416){
				game->setScreen(new CMainMenuScreen(game));
				return;
			}
		}
	}
}

void	CHighScoreScreen::render()

{
	CGraphics	*g=game->getGraphics();

	g->drawPixmap(CAssets::background, 0, 0);
	g->drawPixmap(CAssets::mainMenu, 64, 20, 0, 42, 196, 42);

	int	y=100;
	for(int i=0;i<5;i++){
		drawText(g, &lines[i], 20, y);
		y += 50;

	}

	g->drawPixmap(CAssets::buttons, 0, 416, 64, 64, 64, 64);
}
void	CHighScoreScreen::drawText(CGraphics *g, CString *line, int x, int y)
{
	int	len= line->GetLength();
	for(int i=0;i<len;i++){
		char	ch= line->GetAt(i);
		if(ch == ' '){
			x+= 20;
			continue;
		}

		int	srcX= 0;
		int	srcW= 0;

		if(ch == '.'){
			srcX=200;
			srcW= 10;
		}else{
			srcX= (ch-'0')*20;
			srcW= 20;
		}

		g->drawPixmap(CAssets::numbers, x, y, srcX, 0, srcW, 32);
		x += srcW;

	}
}


void	CHighScoreScreen::pause()
{

}

void	CHighScoreScreen::resume()
{

}

void	CHighScoreScreen::dispose()
{

}