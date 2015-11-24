#pragma once
#include "..\framework\screen.h"
class CHelpScreen2 :
	public CScreen
{
public:
	CHelpScreen2(CGame *game);
	~CHelpScreen2(void);
	void	update(int deltaTime);
	void	render();
	void	pause();
	void	resume();
	void	dispose();
};

