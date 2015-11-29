#include "StdAfx.h"
#include "Settings.h"


CSettings::CSettings(void)
{
}


CSettings::~CSettings(void)
{
}

boolean	CSettings::soundEnabled;
int	CSettings::highscores[]={0, 0, 0, 0, 0};


void	CSettings::load(CString fileName)
{
/*	CFile	*file= new CFile();
	file->Open(
*/
}

void	CSettings::store(CString fileName)
{

}
