#include "StdAfx.h"
#include "KeyboardHandler.h"

CKeyboardHandler::CKeyboardHandler(CWnd *view)
{
	InitializeCriticalSection(&m_cs); 
	this->view= view;
	this->pressedKeys= new boolean[128];
}


CKeyboardHandler::~CKeyboardHandler(void)
{
	delete[] this->pressedKeys;
}

void CKeyboardHandler::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	EnterCriticalSection(&m_cs);                     

	CKeyEvent	*keyEvent= new CKeyEvent();
	keyEvent->type= CKeyEvent::KEY_DOWN;
	keyEvent->keyCode= nChar;
	if(nChar >=0 && nChar < 128){
		this->pressedKeys[nChar]= true;
	}
	keyEventsBuffer.push_back(keyEvent);

	LeaveCriticalSection(&m_cs); 
}


void CKeyboardHandler::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	EnterCriticalSection(&m_cs);                     

	CKeyEvent	*keyEvent= new CKeyEvent();
	keyEvent->type= CKeyEvent::KEY_UP;
	keyEvent->keyCode= nChar;
	if(nChar >=0 && nChar < 128){
		this->pressedKeys[nChar]= false;
	}
	keyEventsBuffer.push_back(keyEvent);

	LeaveCriticalSection(&m_cs); 
}

std::vector<CKeyEvent*> &CKeyboardHandler::getKeyEvents()
{
	EnterCriticalSection(&m_cs);                     

	for(int i=0;i<(int)keyEvents.size();i++){
		delete keyEvents[i];
	}
	keyEvents.clear();

	for(int i=0;i<(int)keyEventsBuffer.size();i++){
		keyEvents.push_back(keyEventsBuffer[i]);
	}
	keyEventsBuffer.clear();

	LeaveCriticalSection(&m_cs); 
	return keyEvents;
}
