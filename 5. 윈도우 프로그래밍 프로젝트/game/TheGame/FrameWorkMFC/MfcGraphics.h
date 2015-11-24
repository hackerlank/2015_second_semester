#pragma once
#include "graphics.h"
class CMfcGraphics :
	public CGraphics
{
	//AssetManager	*assets;
	//CBitmap			*frameBuffer;
	CDC				*canvas;
	int				width;
	int				height;
	CRect			srcRect;
	CRect			dstRect;

public:
	CMfcGraphics(CDC *canvas, int width, int height);
	~CMfcGraphics(void);

	virtual	CPixmap	*newPixMap(CString fileName, PixmapFormat format);

	virtual	void	clear(int color);
	virtual	void	drawPixel(int x, int y, int color);
	virtual	void	drawLine(int x, int y, int x2, int y2, int color);
	virtual	void	drawRect(int x, int y, int width, int height, int color);
	virtual	void	drawPixmap(CPixmap *pixmap, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight);
	virtual	void	drawPixmap(CPixmap *pixmap, int x, int y);
	virtual	int		getWidth(){		return width; }
	virtual	int		getHeight(){	return height; }
	virtual	void*	getCanvas();

};

