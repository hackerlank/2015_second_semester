#include "StdAfx.h"
#include "MfcPixmap.h"


CMfcPixmap::CMfcPixmap(CImage *bitmap, int format)
{
	this->bitmap= bitmap;
	this->format= format;
}


CMfcPixmap::~CMfcPixmap(void)
{
	delete bitmap;
}

int	CMfcPixmap::getWidth()
{
	return	bitmap->GetWidth();
}

int	CMfcPixmap::getHeight()
{
	return bitmap->GetHeight();
}

int	CMfcPixmap::getFormat()
{
	return format;
}

void	CMfcPixmap::dispose()
{
	// bitmap->recycle();
}

