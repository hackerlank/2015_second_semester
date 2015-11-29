#pragma once
class CSettings
{
public:
	CSettings(void);
	~CSettings(void);
	static	boolean	soundEnabled;
	static	int	highscores[];
	static int currentscores;
	static	void	load(CString fileName);
	static	void	store(CString fileName);

};

