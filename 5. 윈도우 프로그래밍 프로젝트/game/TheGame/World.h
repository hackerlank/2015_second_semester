#pragma once

#include	"Snake.h"
#include	"Stain.h"
class CWorld
{
public:
	CWorld(void);
	~CWorld(void);

	static	const	int	WORLD_WIDTH= 10;
	static	const	int	WORLD_HEIGHT= 13;
	static	const	int	SCORE_INCREMENT= 10;
	static	const	float	TICK_INITIAL;
	static	const	float	TICK_DECREMENT;
	static			float	tick;

	CSnake	*snake;
	CStain	*stain;
	bool	gameOver;
	int		score;

	int		*fields;
	float	tickTime;

	void	placeStain();
	void	update(float deltaTime);
};

