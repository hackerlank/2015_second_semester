#pragma once
#include	"Pixmap.h"

class CGraphics
{
public:
//	CGraphics(CBitmap *frameBuffer);
	CGraphics();
	~CGraphics(void);

	enum	PixmapFormat {ARGB888, ARGB4444, RGB565};
	
	virtual	CPixmap	*newPixMap(CString fileName, PixmapFormat format)=0;

	virtual	void	clear(int color)=0;
	virtual	void	drawPixel(int x, int y, int color)=0;
	virtual	void	drawLine(int x, int y, int x2, int y2, int color)=0;
	virtual	void	drawRect(int x, int y, int width, int height, int color)=0;
	virtual	void	drawPixmap(CPixmap *pixmap, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight)=0;
	virtual	void	drawPixmap(CPixmap *pixmap, int x, int y)=0;
	virtual	int		getWidth()=0;
	virtual	int		getHeight()=0;
	virtual	void*	getCanvas()=0;

};
