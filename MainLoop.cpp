#include "main.h"

int debug_1=0;//�f�o�b�O�p�ϐ�
int CMainLoop::mainloop(void)
{
	if(debug_1==0)
	{
		setGameMode(GMODE_LOAD);//
		debug_1=1;
	}
	switch(gmode)
	{
		case GMODE_TITLE://�^�C�g�����
			title();
			break;

		case GMODE_LOAD:
			load();
			break;

		case GMODE_BODY://�Q�[���{��
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