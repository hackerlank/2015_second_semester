#pragma once
#include "screen.h"
#include	"Graphics.h"

class CHighScoreScreen :
	public CScreen
{
	CString	*lines;

public:
	CHighScoreScreen(CGame *game);
	~CHighScoreScreen(void);
	void	update(int deltaTime);
	void	render();
	void	pause();
	void	resume();
	void	dispose();
	void	drawText(CGraphics *g, CString *line, int x, int y);
};


