#include "StdAfx.h"
#include "World.h"

const	float	CWorld::TICK_INITIAL= 0.5;
const	float	CWorld::TICK_DECREMENT= 0.05f;
float	CWorld::tick= 0.0f;
CWorld::CWorld(void)
{
	gameOver= false;
	score= 0;

	fields= new int[WORLD_WIDTH*WORLD_HEIGHT];
	for(int i=0;i< WORLD_WIDTH*WORLD_HEIGHT;i++){
		fields[i]= i;
	}

	tick= TICK_INITIAL;
	snake= new CSnake();
	stain= new CStain(0, 0, 0);

	tickTime= 0.0f;

	placeStain();

}


CWorld::~CWorld(void)
{
	delete[] fields;
	delete snake;
}

void	CWorld::placeStain()
{
	for(int i=0;i<snake->parts.size();i++){
		CSnakePart	*part= snake->parts[i];
		fields[part->x*WORLD_HEIGHT+part->y]= -1;
	}
	int	r= rand()%(WORLD_WIDTH*WORLD_HEIGHT);
	while(fields[r] == -1){
		r= ++r%(WORLD_WIDTH*WORLD_HEIGHT);
	}
	int	x= r/WORLD_HEIGHT;
	int	y= r%WORLD_HEIGHT;

	stain->Set(x, y, rand()%3);
}

void	CWorld::update(float deltaTime)
{
	if(gameOver)	return;
	tickTime += deltaTime;

	while(tickTime > tick){
		tickTime -= tick;

		snake->advance();

		if(snake->checkBitten()){
			gameOver= true;
			return;
		}

		CSnakePart	*head= snake->parts[0];
		if(head->x == stain->x && head->y == stain->y){
			score += SCORE_INCREMENT;
			snake->eat();
			if(snake->parts.size() == WORLD_WIDTH*WORLD_HEIGHT){
				gameOver= true;
				return;
			}
			placeStain();

			if(score % 100 == 0 && tick - TICK_DECREMENT > 0){
				tick -= TICK_DECREMENT;
			}
		}
	}
}

