#pragma once
#include	<vector>
#include	"KeyEvent.h"

class CKeyboardHandler
{
	CWnd	*view;
	CRITICAL_SECTION m_cs;
	boolean	*pressedKeys;
	std::vector<CKeyEvent*>	keyEvents;
	std::vector<CKeyEvent*>	keyEventsBuffer;
public:
	CKeyboardHandler(CWnd *view);
	~CKeyboardHandler(void);

	void	OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void	OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	std::vector<CKeyEvent*> &getKeyEvents();
	boolean	isKeyPressed(int keyCode){
		if(keyCode >= 0 && keyCode < 128){
			return pressedKeys[keyCode];
		}
		return false;
	}

};

