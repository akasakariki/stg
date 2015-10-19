#include "main.h"

void CMainLoop::load()
{
	LoadGraphScreen( 0 , 0 , "image/load.jpg" , false ) ;

	gmbody.First_Section();
	setGameMode(GMODE_TITLE);
}