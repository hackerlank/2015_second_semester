#pragma once
#include	"SnakePart.h"
#include	<vector>
class CSnake
{
public:
	CSnake(void);
	~CSnake(void);

	static	const	int UP= 0;
	static	const	int LEFT= 1;
	static	const	int DOWN= 2;
	static	const	int RIGHT= 3;

	std::vector<CSnakePart*> parts;
	int	direction;

	void	turnLetf();
	void	turnRight();
	void	eat();
	void	advance();
	bool	checkBitten();
};

