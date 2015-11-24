#pragma once
class CMusic
{
public:
	CMusic(void);
	~CMusic(void);

	virtual	void	play()=0;
	virtual	void	stop()=0;
	virtual	void	pause()=0;
	virtual	void	setLooping(boolean looping)=0;
	virtual	void	setVolume(float volume)=0;
	virtual	boolean	isPlaying()=0;
	virtual	boolean	isStopped()=0;
	virtual	boolean	isLooping()=0;

	virtual	void	dispose()=0;
	
};

