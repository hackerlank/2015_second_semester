#pragma once
#include "input.h"
#include	"KeyboardHandler.h"
#include	"MouseHandler.h"

class CMfcInput :
	public CInput
{
public:
	CMfcInput(CWnd *view, float scaleX, float scaleY);
	~CMfcInput(void);

	CKeyboardHandler	*keyHandler;
	CMouseHandler		*mouseHandler;

	boolean	isKeyPressed(int keyCode);
	boolean	isMouseDown();
	std::vector<CKeyEvent*>		&getKeyEvents();
	std::vector<CMouseEvent*>	&getMouseEvents();

	void	OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void	OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	void	OnLButtonDown(UINT nFlags, CPoint point);
	void	OnLButtonUp(UINT nFlags, CPoint point);

};

