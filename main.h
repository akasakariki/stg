#pragma once
#include "DxLib.h"
#include "game_body.h"
#include "GM_Enemy.h"
#define script_ext	"sc"
#define scriptF	"script/"//�X�N���v�g�t�H���_�[�̎w�� 
#define FileNameLEN	80
#define debug_mode	true//�f�o�b�O���[�h�̐ݒ�
#define PI	3.141593
enum GAMEMODE//�Q�[�����[�h�̎��
{
	GMODE_TITLE=1,GMODE_LOAD,GMODE_BODY,GMODE_CONFIG,GMODE_GAMEOVER,GMODE_END
};
class CMainLoop
{

	protected:
		GAMEMODE gmode;//���[�h
		GAMEMODE setGameMode(GAMEMODE mode);//�Q�[�����[�h��ݒ肷��
		virtual void title(void);//�^�C�g�����[�h
		virtual void load(void);//�X�N���v�g�t�@�C�����[�h���[�h
		virtual void body(void);//�Q�[�����[�h
		virtual void config(void);//�ݒ胂�[�h
		virtual void gameover(void);//�Q�[���I�[�o�[
		virtual void end(void);//�I�������E�E�E����Ȃ�����
		//�ϐ��֌W
		int loadingF;//���[�f�B���O�t���O
		char Load_FileName[FileNameLEN];//���[�h�t�@�C�����̋L���p
		int loading_format;//�������t���O
		CGame_Body gmbody;
		CGame_Enemy enemy;
		int menu_img[5];
		int menu_bgm[2];
	public:
		//���C�����[�v
		int mainloop(void);
};
extern long char_int(char moji);

//int FileNames=�t�@�C����(���p�����̂�)
//char script=�ǂݍ��ݐ�̃X�N���v�gchar�̐擪�A�h���X
//int cx=�Q�����z��̊m�ۗ̈�i�P�s���̍ő啶�����j
extern int LoadFile(int FileNames,char *script,int cx);