#pragma once
#include	"Input.h"
#include	"Graphics.h"
#include	"Screen.h"

class CGame
{
protected:
	void		*view;
	int			width, height;
public:

	CGame();
	~CGame(void);
	virtual	void		create(void *view, int width, int height)=0;		// jmlee

	virtual	CInput		*getInput()=0;
	virtual	CGraphics	*getGraphics()=0;
	
	virtual	void		setScreen(CScreen *screen)=0;
	virtual	CScreen		*getCurrentScreen()=0;
	virtual	CScreen		*getStartScreen()=0;
	virtual	void		*getCanvas()=0;
	virtual	void		getSize(int &w, int& h){
		w= width;
		h= height;
	}
	virtual	void		setSize(int w, int h)=0;

	virtual	void		update(int deltaTime)=0;
	virtual	void		render()=0;
};

