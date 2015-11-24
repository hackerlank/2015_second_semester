#pragma once
#include	"KeyEvent.h"
#include	"KeyboardHandler.h"
#include	"MouseEvent.h"
#include	"MouseHandler.h"

class CInput
{
	/*
	CKeyboardHandler		keyboardHandler;
	CMouseHandler			mouseHandler;
	*/
public:
	CInput(void);
	~CInput(void);
	virtual	boolean	isKeyPressed(int keyCode)=0;
	virtual	boolean	isMouseDown()=0;

	virtual	std::vector<CKeyEvent*>		&getKeyEvents()=0;
	virtual	std::vector<CMouseEvent*>	&getMouseEvents()=0;


	virtual	void	OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)=0;
	virtual	void	OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)=0;
	virtual	void	OnLButtonDown(UINT nFlags, CPoint point)=0;
	virtual	void	OnLButtonUp(UINT nFlags, CPoint point)=0;
};

