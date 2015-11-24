#pragma once
#include "screen.h"
class CHelpScreen :
	public CScreen
{
public:
	CHelpScreen(CGame *game);
	~CHelpScreen(void);

	void	update(int deltaTime);
	void	render();
	void	pause();
	void	resume();
	void	dispose();

};

