#pragma once
#include "screen.h"
class CMainMenuScreen :
	public CScreen
{
public:
	CMainMenuScreen(CGame *game);
	~CMainMenuScreen(void);

	virtual	void	update(int deltaTime);
	virtual	void	render();
	virtual	void	pause();
	virtual	void	resume();
	virtual	void	dispose();
};

