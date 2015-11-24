#include "StdAfx.h"
#include "MfcInput.h"


CMfcInput::CMfcInput(CWnd *view, float scaleX, float scaleY)
{
	keyHandler= new CKeyboardHandler(view);
	mouseHandler= new CMouseHandler(view);
}


CMfcInput::~CMfcInput(void)
{
	delete mouseHandler;
	delete keyHandler;
}


boolean	CMfcInput::isKeyPressed(int keyCode)
{
	return keyHandler->isKeyPressed(keyCode);
}

boolean	CMfcInput::isMouseDown()
{
	return mouseHandler->isMouseDown();
}

std::vector<CKeyEvent*>		&CMfcInput::getKeyEvents()
{
	return keyHandler->getKeyEvents();
}
std::vector<CMouseEvent*>	&CMfcInput::getMouseEvents()
{
	return mouseHandler->getMouseEvents();
}

void	CMfcInput::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	keyHandler->OnKeyDown(nChar, nRepCnt, nFlags);
}
void	CMfcInput::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
	keyHandler->OnKeyUp(nChar, nRepCnt, nFlags);
}
void	CMfcInput::OnLButtonDown(UINT nFlags, CPoint point)
{
	mouseHandler->OnLButtonDown(nFlags, point);
}
void	CMfcInput::OnLButtonUp(UINT nFlags, CPoint point)
{
		mouseHandler->OnLButtonUp(nFlags, point);
}
