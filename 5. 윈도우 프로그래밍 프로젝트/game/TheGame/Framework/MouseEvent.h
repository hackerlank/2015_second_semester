#pragma once
class CMouseEvent
{
public:
	CMouseEvent(void);
	~CMouseEvent(void);
	enum	{MOUSE_DOWN=0, MOUSE_UP=1};

	int	type;
	int	x, y;
	int	pointer;
};
