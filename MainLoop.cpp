#include "main.h"

int debug_1=0;//デバッグ用変数
int CMainLoop::mainloop(void)
{
	if(debug_1==0)
	{
		setGameMode(GMODE_LOAD);//
		debug_1=1;
	}
	switch(gmode)
	{
		case GMODE_TITLE://タイトル画面
			title();
			break;

		case GMODE_LOAD:
			load();
			break;

		case GMODE_BODY://ゲーム本体
			body();
			break;

		case GMODE_CONFIG:
			config();
			break;

		case GMODE_GAMEOVER:
			gameover();
			break;

		case GMODE_END:
			end();
			break;
	}
	return 0;
}

GAMEMODE CMainLoop::setGameMode(GAMEMODE mode)
{
	gmode=mode;
	return gmode;
}