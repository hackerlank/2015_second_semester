#pragma once
#include "..\framework\screen.h"
#include	"World.h"
#include	"Graphics.h"
#include	<vector>

class CGameScreen :
	public CScreen
{
public:
	CGameScreen(CGame *game);
	~CGameScreen(void);
	enum	GameState{	Ready, Running, Paused, GameOver};
	
	GameState	state;
	CWorld		*world;
	int			oldScore;
	CString		score;

	virtual	void	update(int deltaTime);
	virtual	void	render();
	virtual	void	pause();
	virtual	void	resume();
	virtual	void	dispose();

	void	updateReady();

	void	updateRunning(int deltaTime);
	void	updatePaused();
	void	updateGameOver();

	void	drawWorld(CWorld * world);
	void	drawText(CGraphics *g, CString line, int x, int y);

	void	drawReadyUI();
	void	drawRunningUI();
	void	drawPausedUI();
	void	drawGameOverUI();

};

