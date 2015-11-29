#include "StdAfx.h"
#include "GameScreen.h"
#include	"MfcGraphics.h"
#include	"Assets.h"
#include	"Graphics.h"
#include	"MrNomGame.h"
#include	"MainMenuScreen.h"
//���� �ֱ�
#pragma comment(lib, "winmm")
#include <MMSystem.h>
#include <Windows.h>
#include "Settings.h"



CGameScreen::CGameScreen(CGame *game): CScreen(game)
{
	state= GameState::Ready;
	world= new CWorld();
	oldScore= 0;
	score= "";
}


CGameScreen::~CGameScreen(void)
{
	if(world != NULL)	delete world;
}

void	CGameScreen::update(int deltaTime)
{
	CGraphics	*g=game->getGraphics();

	if(state == GameState::Ready)		updateReady();
	else	if(state == GameState::Running) {		
		updateRunning(deltaTime);

	}
	else	if(state == GameState::Paused)		updatePaused();
	else	if(state == GameState::GameOver)	updateGameOver();
	game->getInput()->getKeyEvents();	
}


void	CGameScreen::updateReady()
{
	std::vector<CMouseEvent*>	mouseEvents= game->getInput()->getMouseEvents();
	if(mouseEvents.size() > 0)	state= GameState::Running;
	
	//ready â���� Ű���� �̺�Ʈ �����
		std::vector<CKeyEvent*> keyEvents = game->getInput()->getKeyEvents();
		if(keyEvents.size() > 0) state = GameState::Running;
	//ready â���� Ű���� �̺�Ʈ �����

		////���� �ֱ�
		PlaySound("..\\assets\\pac1.wav", NULL/*AfxGetInstanceHandle()*/,SND_ASYNC| SND_LOOP);
}

void	CGameScreen::updateRunning(int deltaTime)
{
	//////���� �ֱ�
	//CString soundpath = _T(".\assets\bitten.ogg");
	//PlaySound(soundpath, AfxGetInstanceHandle(), SND_ASYNC | SND_LOOP);
	
	//////���� �ֱ�

	std::vector<CMouseEvent*>	mouseEvents= game->getInput()->getMouseEvents();
	
	for(int i=0;i<mouseEvents.size();i++) {
		CMouseEvent	*evt= mouseEvents[i];
		if(evt->type == CMouseEvent::MOUSE_UP) {
			if(evt->x < 64 && evt->y < 64) {
				
				////���� �ֱ�
				//if(CSettings::soundEnabled){
				//	CAssets.bitten->play(1);
				//}

				
				
				state= GameState::Paused;
				return;
			}
		}
		if(evt->type == CMouseEvent::MOUSE_DOWN){
			////���콺 Ŭ������ �̵���Ű��
			if(evt->x < 20 && evt->y > 480 && evt->y < 530 )					world->snake->turnLetf();
			if(evt->x > 80 && evt->x < 160 && evt->y > 480 && evt->y <530)	world->snake->turnRight();
			if(evt->x > 20 && evt->x < 80 && evt->y > 320 && evt->y < 480)	world->snake->turnUp();
			if(evt->x > 20 && evt->x < 80 && evt->y > 540) world->snake->turnDown();
		}
	}

	//game�� Ű���� ����Ű �̺�Ʈ �����
		std::vector<CKeyEvent*> keyEvents = game->getInput()->getKeyEvents();
		for (int i=0 ; i<keyEvents.size() ; i++) {
			CKeyEvent *kevt = keyEvents[i];
			if(kevt->type == CKeyEvent::KEY_DOWN) {
				if(kevt->keyCode == VK_LEFT) world->snake->turnLetf();
				if(kevt->keyCode == VK_RIGHT) world->snake->turnRight();
				if(kevt->keyCode == VK_UP) world->snake->turnUp();
				if(kevt->keyCode == VK_DOWN) world->snake->turnDown();

			}
		} 
	//game�� Ű���� ����Ű �̺�Ʈ �����
	

	world->update(deltaTime);

	if(world->gameOver){
		/*
		if(CSettings.soundEnabled){
			CAssets.bitten.play(1);
		}
		*/
		state= GameState::GameOver;
		
		
		//����ٰ� ������ music.ogg ������ �ǰڴ�. 
		//PlaySound("C:\Users\multimedia\Desktop\game\assets\music.ogg", AfxGetInstanceHandle(), SND_ASYNC);
	PlaySound("..\\assets\\game.wav", NULL/*AfxGetInstanceHandle()*/,SND_ASYNC);
	}
	if(oldScore != world->score){
		oldScore= world->score;
		score.Format("%d", oldScore);
		/*
		if(CSettings::soundEnabled){
			CAssets.eat.play(1);
		}
		*/
	}
}

void	CGameScreen::updatePaused()
{
	std::vector<CMouseEvent*>	mouseEvents= game->getInput()->getMouseEvents();

	for(int i=0;i<mouseEvents.size();i++){
		CMouseEvent	*evt= mouseEvents[i];
		if(evt->type == CMouseEvent::MOUSE_UP){
			if(evt->x > 80 && evt->x <= 240){
				if(evt->y > 100 && evt->y <= 148){
					/*
					if(CSettings::soundEnabled){
						CAssets.click.play(1);
					}
					*/
					state= GameState::Running;
					return;
				}
				if(evt->y > 148 && evt->y < 196){
					/*
					if(CSettings::soundEnabled){
						CAssets.eat.play(1);
					}
					*/
					game->setScreen(new CMainMenuScreen(game));
					return;
				}
			}
		}
	}
}

void	CGameScreen::updateGameOver()
{
	std::vector<CMouseEvent*>	mouseEvents= game->getInput()->getMouseEvents();

	for(int i=0;i<mouseEvents.size();i++){
		CMouseEvent	*evt= mouseEvents[i];
		if(evt->type == CMouseEvent::MOUSE_UP){
			if(evt->x >= 128 && evt->x <= 192 && evt->y >= 200 && evt->y <= 264){
				/*
				if(CSettings::soundEnabled){
					CAssets.eat.play(1);
				}
				*/
				
				game->setScreen(new CMainMenuScreen(game));
			}
		}
	}
}

void	CGameScreen::render()
{
	CGraphics	*g= game->getGraphics();
	g->drawPixmap(CAssets::background, 0, 0);

	drawWorld(world);
	if(state == GameState::Ready)	drawReadyUI();
	if(state == GameState::Running)	drawRunningUI();
	if(state == GameState::Paused)	drawPausedUI();
	if(state == GameState::GameOver)	drawGameOverUI();
	drawText(g, score, g->getWidth()/2-score.GetLength()*20/2, g->getHeight()-42);


		//g->drawPixmap(CAssets::numbers, 100, 500, srcX, 0, srcWidth, 32);

}

void	CGameScreen::pause()
{
	if(state == GameState::Running)	state= GameState::Paused;
	if(world->gameOver){
		/*
		CSettings::addScore(world->score);
		CSettings::save(game->getFileIo());
		*/
	}
}

void	CGameScreen::resume()
{
}

void	CGameScreen::dispose()
{
}

void	CGameScreen::drawWorld(CWorld * world)
{
	CString str;
	CGraphics	*g= game->getGraphics();
	CSnake		*snake= world->snake;
	CSnakePart	*head= snake->parts[0];
	CStain		*stain= world->stain;
	CPixmap	*stainPixmap= NULL;

	if(stain->type == CStain::TYPE_1)	stainPixmap= CAssets::stain1;
	if(stain->type == CStain::TYPE_2)	stainPixmap= CAssets::stain2;
	if(stain->type == CStain::TYPE_3)	stainPixmap= CAssets::stain3;

	int	x= stain->x*32; //���� ��ǥ
	int	y= stain->y*32;
	//for(int i=0 ; i<352 ; i+=32) {
		//for(int j=0 ; j<352 ; j+=32) {
			g->drawPixmap(stainPixmap, x, y);
	//	}
//	}
	for(int i=1;i<snake->parts.size();i++){
		CSnakePart	*part= snake->parts[i];
		x= part->x*32;//���� ��ǥ
		y= part->y*32;

		//g->drawPixmap(CAssets::tail, x, y);
	}

	CPixmap	*headPixmap= NULL;
	if(snake->direction == CSnake::UP)	headPixmap= CAssets::headUp;
	if(snake->direction == CSnake::LEFT)	headPixmap= CAssets::headLeft;
	if(snake->direction == CSnake::DOWN)	headPixmap= CAssets::headDown;
	if(snake->direction == CSnake::RIGHT)	headPixmap= CAssets::headRight;
	x= head->x*32+16;
	y= head->y*32+16;
	g->drawPixmap(headPixmap, x-headPixmap->getWidth()/2, y-headPixmap->getHeight()/2);
}

void	CGameScreen::drawText(CGraphics *g, CString line, int x, int y)
{
	int i=1;
	for(int i=0;i<line.GetLength();i++){
		char	character= line.GetAt(i);
		if(character == ' '){
			x += 20;
			continue;
		}

		int	srcX= 0;
		int	srcWidth= 0;
		if(character == '.'){
			srcX= 200;
			srcWidth= 10;
		}else{
			srcX= (character - '0')*20;
			srcWidth= 20;
		}
			g->drawPixmap(CAssets::numbers, 200, 500, srcX, 0, srcWidth, 32);
			g->drawPixmap(CAssets::numbers, 220, 500, 0, 0, 20, 32);
		i=i+32;
		x += srcWidth;
	}

}

//readyȭ�� �̸� �׷��ִ� �Լ�
void	CGameScreen::drawReadyUI()
{
	CGraphics	*g= game->getGraphics();
	
	g->drawPixmap(CAssets::ready, 47, 100);
	g->drawLine(0, 416, 480, 416, RGB(255, 255, 255));
	g->drawLine(319, 416, 319, 0, RGB(255, 255, 255));
}

//�����ϴµ��� �׷��ִ� �Լ�
void	CGameScreen::drawRunningUI()
{
	CGraphics	*g= game->getGraphics();
	//�Ͻ����� ��ư
	g->drawPixmap(CAssets::buttons, 0, 0, 64, 192, 64, 64);
	//�߰��� ���߱�
	g->drawLine(0, 416, 480, 416, RGB(255, 255, 255));
	g->drawLine(319, 416, 319, 0, RGB(255, 255, 255));
	//�׹���Ű Ű���� �����ϱ�
	g->drawPixmap(CAssets::buttons, -20, 480, 64, 64, 64, 64); //<-
	g->drawPixmap(CAssets::buttons, 70, 480, 0, 64, 64, 64); //->
	g->drawPixmap(CAssets::buttons, 30, 430, 0, 128, 64, 64); //^
	g->drawPixmap(CAssets::buttons, 30, 520, 64, 128, 64, 64); //down

	/*
	int timer=0;
	timer=timer+1;
	g->drawRect(200,500,100,100,RGB(255,255,255));//�ð��� ����ٰ�?*/
}

void	CGameScreen::drawPausedUI()
{
	CGraphics	*g= game->getGraphics();
	g->drawPixmap(CAssets::pause, 80, 100);
	g->drawLine(0, 416, 480, 416, RGB(255, 255, 255));
	g->drawLine(319, 416, 319, 0, RGB(255, 255, 255));

}

void	CGameScreen::drawGameOverUI()
{

	CGraphics	*g= game->getGraphics();
	g->drawPixmap(CAssets::gameOver, 62, 100);
	g->drawPixmap(CAssets::buttons, 128, 200, 0, 192, 64, 64);
	g->drawLine(0, 416, 480, 416, RGB(255, 255, 255));
	g->drawLine(319, 416, 319, 0, RGB(255, 255, 255));
}

