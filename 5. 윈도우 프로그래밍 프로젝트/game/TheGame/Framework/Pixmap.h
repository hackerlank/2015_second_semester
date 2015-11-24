#pragma once

class CPixmap
{
public:
	CPixmap(){};
	~CPixmap(void){};


	virtual	int		getWidth()=0;
	virtual	int		getHeight()=0;
	virtual	int		getFormat()=0;
	virtual	void	dispose()=0;
};

