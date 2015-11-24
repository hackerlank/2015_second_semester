#pragma once
#include	"MouseEvent.h"
#include	<vector>
class CMouseHandler
{
	CWnd	*view;
	CRITICAL_SECTION m_cs;


public:
	CMouseHandler(CWnd	*view);
	~CMouseHandler(void);
	boolean	isClicked;
	int	clickedX;
	int	clickedY;

	std::vector<CMouseEvent*>	mouseEvents;
	std::vector<CMouseEvent*>	mouseEventsBuffer;

	boolean	isMouseDown();
	void	OnLButtonDown(UINT nFlags, CPoint point);
	void	OnLButtonUp(UINT nFlags, CPoint point);

	std::vector<CMouseEvent*> &getMouseEvents();

};

