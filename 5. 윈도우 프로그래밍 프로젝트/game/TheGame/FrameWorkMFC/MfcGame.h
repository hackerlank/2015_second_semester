#pragma once
#include	"stdafx.h"
#include	"game.h"
#include	"Graphics.h"
#include	"Input.h"


class CMfcGame :
	public CGame
{

public:
	CMfcGame(void);
	~CMfcGame(void);
	void	create(void *view, int width, int height);

	CGraphics	*graphics;
	CInput		*input;
	CScreen		*screen;

	CInput*		getInput();
	CGraphics*	getGraphics();
	
	void		setScreen(CScreen *screen);
	CScreen*	getCurrentScreen();
	CScreen*	getStartScreen();
	void*		getCanvas();
	void		setSize(int w, int h);
	void		update(int deltaTime);
	void		render();

};
