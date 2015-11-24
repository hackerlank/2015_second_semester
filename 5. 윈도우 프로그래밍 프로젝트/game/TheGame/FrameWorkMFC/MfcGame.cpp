#include	"stdafx.h"
#include	"MfcGame.h"
#include	"MfcGraphics.h"
#include	"MfcInput.h"


CMfcGame::CMfcGame(void)
{
	graphics= NULL;
	input= NULL;
	screen= NULL;
	view= NULL;
}


CMfcGame::~CMfcGame(void)
{
	if(graphics != NULL)	delete graphics;
	if(input != NULL)		delete input;
	if(screen != NULL)		delete screen;
}


void	CMfcGame::create(void *view, int width, int height)
{
	this->view= view;
	this->width= width;
	this->height= height;

	CWnd	*v= (CWnd*)view;

	CBitmap	*bitmap= new CBitmap();
	bitmap->CreateCompatibleBitmap(v->GetDC(), width, height);

	CDC	*canvas= new CDC();
	canvas->CreateCompatibleDC(v->GetDC());
	canvas->SelectObject(bitmap);

	graphics= new CMfcGraphics(canvas, width, height);

	input= new CMfcInput(v, (float)width, (float)height);

	screen= getStartScreen();
}

void		CMfcGame::setSize(int w, int h)
{
	this->width= w;
	this->height= h;

	CWnd	*v= (CWnd*)view;
	CBitmap	*bitmap= new CBitmap();
	bitmap->CreateCompatibleBitmap(v->GetDC(), width, height);

	CBitmap	*oldBitmap=  ((CDC *)(this->graphics->getCanvas()))->SelectObject(bitmap);
	delete oldBitmap;

	delete	input;
	input= new CMfcInput(v, (float)w, (float)h);
}

CInput		*CMfcGame::getInput()
{	
	return input; 
}

CGraphics	*CMfcGame::getGraphics()
{	
	return graphics; 
}
	
void		CMfcGame::setScreen(CScreen *screen)
{
	if(screen == NULL)	return;
	this->screen->pause();
	this->screen->dispose();
	screen->update(0);

	this->screen= screen;
}

CScreen		*CMfcGame::getCurrentScreen()
{
	return screen;

}

CScreen		*CMfcGame::getStartScreen()
{
	return screen;
}
void*	CMfcGame::getCanvas()
{
	return this->graphics->getCanvas();
}

void		CMfcGame::update(int deltaTime)
{
	this->getCurrentScreen()->update(deltaTime);
}



void		CMfcGame::render()
{
	this->getCurrentScreen()->render();
	CRect	r(0, 0, this->width, this->height);
	((CWnd *)(this->view))->InvalidateRect(&r, false);
}
