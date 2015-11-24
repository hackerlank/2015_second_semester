#pragma once
class CKeyEvent
{
public:
	CKeyEvent(void);
	~CKeyEvent(void);
	enum	{KEY_DOWN=0, KEY_UP=1};
	int		type;
	int		keyCode;
	char	keyChar;
};

