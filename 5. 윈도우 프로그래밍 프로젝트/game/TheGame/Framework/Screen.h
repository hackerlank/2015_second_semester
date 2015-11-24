#pragma once
//#include	"Game.h"

class	CGame;

class CScreen
{
protected:
	public:
	CGame	*game;
	
public:
	CScreen(CGame *game){
		this->game= game;
	}
	~CScreen(void);

	virtual	void	update(int deltaTime)=0;
	virtual	void	render()=0;
	virtual	void	pause()=0;
	virtual	void	resume()=0;
	virtual	void	dispose()=0;
};

