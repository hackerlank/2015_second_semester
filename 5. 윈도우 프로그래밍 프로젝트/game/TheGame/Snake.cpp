#include "StdAfx.h"
#include "Snake.h"


CSnake::CSnake(void)
{
	direction= UP;
	parts.push_back(new CSnakePart(5, 6));
	parts.push_back(new CSnakePart(5, 7));
	parts.push_back(new CSnakePart(5, 8));

}


CSnake::~CSnake(void)
{
	for(int i=0;i<parts.size();i++){
		delete parts[i];
	}
	parts.clear();
}

void	CSnake::turnLetf()
{
	direction += 1;
	if(direction > RIGHT)	direction= UP;
}

void	CSnake::turnRight()
{
	direction -= 1;
	if(direction < UP)	direction= RIGHT;
}

void	CSnake::eat()
{
	CSnakePart	*end= parts[parts.size()-1];
	parts.push_back(new CSnakePart(end->x, end->y));
}

int		x=0;
void	CSnake::advance()
{
	if(parts.size() <= 0)	return;
	x++;
	if(x < 1000)	return;
	x=0;
	CSnakePart	*head= parts[0];
	int	len= parts.size()-1;

	for(int i=parts.size()-1;i>0;i--){
		CSnakePart	*before= parts[i-1];
		CSnakePart	*part= parts[i];
		part->x= before->x;
		part->y= before->y;
	}

	if(direction == UP)	head->y -= 1;
	if(direction == LEFT)	head->x -= 1;
	if(direction == DOWN)	head->y += 1;
	if(direction == RIGHT)	head->x += 1;

	if(head->x < 0)		head->x= 9;
	if(head->x > 9)		head->x= 0;
	if(head->y < 0)		head->y= 12;
	if(head->y > 12)	head->y= 0;
}

bool	CSnake::checkBitten()
{
	if(parts.size()<=0)	return false;

	CSnakePart	*head= parts[0];

	for(int i=1;i<parts.size();i++){
		CSnakePart	*part= parts[i];
		if(head->x == part->x && head->y == part->y)	return true;
	}
	return false;
}