#pragma once
#include "..\framework\screen.h"
class CHelpScreen3 :
	public CScreen
{
public:
	CHelpScreen3(CGame *game);
	~CHelpScreen3(void);
	void	update(int deltaTime);
	void	render();
	void	pause();
	void	resume();
	void	dispose();
};

