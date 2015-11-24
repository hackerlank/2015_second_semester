#pragma once
#include "pixmap.h"
class CMfcPixmap :
	public CPixmap
{
	int	format;
public:
	CMfcPixmap(CImage *bitmap, int format);
	~CMfcPixmap(void);

	CImage	*bitmap;
	virtual	int		getWidth();
	virtual	int		getHeight();
	virtual	int		getFormat();
	virtual	void	dispose();
};

