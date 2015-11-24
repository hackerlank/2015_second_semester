#pragma once
class CStain
{
public:
	CStain(int x, int y, int type);
	~CStain(void);

	static	const	int	TYPE_1= 0;
	static	const	int	TYPE_2= 1;
	static	const	int	TYPE_3= 2;
	int	x;
	int	y;
	int	type;

	void	Set(int x, int y, int type);
};

