#pragma once
class CSound
{
public:
	CSound(void);
	~CSound(void);

	virtual	void	play(float volume)=0;
	virtual	void	dispose()=0;
};

