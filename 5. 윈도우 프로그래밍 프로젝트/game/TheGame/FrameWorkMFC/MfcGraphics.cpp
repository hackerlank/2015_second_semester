#include "StdAfx.h"
#include	"MfcPixmap.h"
#include	"MfcGraphics.h"


CMfcGraphics::CMfcGraphics(CDC *canvas, int witdh, int height)
{
	this->canvas= canvas;
	this->width= width;
	this->height= height;
}


CMfcGraphics::~CMfcGraphics(void)
{
}

CPixmap	*CMfcGraphics::newPixMap(CString fileName, CGraphics::PixmapFormat format)
{
	CImage	*bitmap= new CImage();
	HRESULT	result= bitmap->Load(fileName);
	return new CMfcPixmap(bitmap, ARGB888);
}

void	CMfcGraphics::clear(int color)
{
	//canvas->BitBlt(0, 0, srcRect.Width(), srcRect.Height(),NULL, NULL, WHITENESS);
	for(int i=0;i<dstRect.Width();i++){
		for(int j=0;j<dstRect.Height();j++){
			canvas->SetPixelV(i, j, color);
		}
	}
}

void	CMfcGraphics::drawPixel(int x, int y, int color)
{
	canvas->SetPixel(x, y, color);
}

void	CMfcGraphics::drawLine(int x, int y, int x2, int y2, int color)
{
	CPen	pen(PS_SOLID, 1, color);
	CPen	*oldPen= canvas->SelectObject(&pen);
	canvas->MoveTo(x, y);
	canvas->LineTo(x2, y2);
	canvas->SelectObject(oldPen);

}
void	CMfcGraphics::drawRect(int x, int y, int width, int height, int color)
{
	CPen	pen(PS_SOLID, 1, color);
	CPen	*oldPen= canvas->SelectObject(&pen);
	canvas->Rectangle(x, y, x+width, y+height);
	canvas->SelectObject(oldPen);

}
void	CMfcGraphics::drawPixmap(CPixmap *pixmap, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight)
{
	::StretchBlt(canvas->GetSafeHdc(), x, y, srcWidth-1, srcHeight-1, ((CMfcPixmap*)pixmap)->bitmap->GetDC(), srcX, srcY, srcWidth-1, srcHeight-1, SRCCOPY);
}

void	CMfcGraphics::drawPixmap(CPixmap *pixmap, int x, int y)
{
	::BitBlt(this->canvas->GetSafeHdc(), x, y, pixmap->getWidth(), pixmap->getHeight(), ((CMfcPixmap*)pixmap)->bitmap->GetDC(), 0, 0, SRCCOPY);
}

void*	CMfcGraphics::getCanvas()
{
	return canvas;
}
