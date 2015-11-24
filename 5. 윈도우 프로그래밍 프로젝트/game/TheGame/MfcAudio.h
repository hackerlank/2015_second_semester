#pragma once
#include "audio.h"
#include	<vector>
class CMfcAudio :
	public CAudio
{
public:
	CMfcAudio(void);
	~CMfcAudio(void);

	std::vector<CSound*>	soundPool;

	virtual	CMusic	*newMusic(CString fname);
	virtual	CSound	*newSound(CString fname);
};

