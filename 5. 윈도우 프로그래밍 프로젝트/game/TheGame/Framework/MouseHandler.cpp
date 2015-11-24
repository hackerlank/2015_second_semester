#include "StdAfx.h"
#include "MouseHandler.h"


CMouseHandler::CMouseHandler(CWnd	*view)
{
	InitializeCriticalSection(&m_cs); 
	this->view= view;
}


CMouseHandler::~CMouseHandler(void)
{
}

boolean	CMouseHandler::isMouseDown()
{
	return isClicked;
}

void CMouseHandler::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	EnterCriticalSection(&m_cs);                     

	CMouseEvent	*mouseEvent= new CMouseEvent();
	mouseEvent->type= CMouseEvent::MOUSE_DOWN;
	isClicked= true;
	mouseEvent->x= point.x;
	mouseEvent->y= point.y;
	mouseEventsBuffer.push_back(mouseEvent);

	LeaveCriticalSection(&m_cs); 
}


void CMouseHandler::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	EnterCriticalSection(&m_cs);                     

	CMouseEvent	*mouseEvent= new CMouseEvent();
	mouseEvent->type= CMouseEvent::MOUSE_UP;
	isClicked= true;
	mouseEvent->x= point.x;
	mouseEvent->y= point.y;
	mouseEventsBuffer.push_back(mouseEvent);

	LeaveCriticalSection(&m_cs); 
}

std::vector<CMouseEvent*> &CMouseHandler::getMouseEvents()
{
	EnterCriticalSection(&m_cs);                     

	for(int i=0;i<(int)mouseEvents.size();i++){
		delete mouseEvents[i];
	}
	mouseEvents.clear();

	for(int i=0;i<(int)mouseEventsBuffer.size();i++){
		mouseEvents.push_back(mouseEventsBuffer[i]);
	}
	mouseEventsBuffer.clear();

	LeaveCriticalSection(&m_cs); 
	return mouseEvents;
}
