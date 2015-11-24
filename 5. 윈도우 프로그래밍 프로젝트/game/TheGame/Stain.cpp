#include "StdAfx.h"
#include "Stain.h"


CStain::CStain(int x, int y, int type)
{
	this->x= x;
	this->y= y;
	this->type= type;
}


CStain::~CStain(void)
{
}

void	CStain::Set(int x, int y, int type)
{
	this->x= x;
	this->y= y;
	this->type= type;
}
