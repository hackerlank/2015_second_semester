#pragma once
#include	"Music.h"
#include	"Sound.h"

class CAudio
{
public:
	CAudio(void);
	~CAudio(void);

	virtual	CMusic	*newMusic(CString fname)=0;
	virtual	CSound	*newSound(CString fname)=0;
};

