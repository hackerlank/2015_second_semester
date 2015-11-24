#pragma once
#include "screen.h"

class CLoadingScreen :
	public CScreen
{
public:
	CLoadingScreen(CGame *game);
	~CLoadingScreen(void);

	void	update(int deltaTime);
	void	render();
	void	pause();
	void	resume();
	void	dispose();

};

