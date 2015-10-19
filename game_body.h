#pragma once

#define enemy_image "image/actor.png"
#define enemy_center_g	"image/enemy_center.png"
#define meter_defaultalpha	200
#define Reset_Counter	360
#define meter_bg "image/matebg.jpg"
#define hpmeter_g	"image/hp.jpg"
#define jiki_g "image/jiki.png"
#define bomb_g "image/bomb.png"
#define bullet_g1 "image/bullet.png"
#define bullet_g2 "image/bullet2.png"
#define Bakudef_g "image/baku.bmp"
#define Baku_g_num	16
#define Animation_msecond	90/Baku_g_num

#define hpmeter_size_x 400
#define enemy_speed 10
#define enemy_define_bulletspead 5;
#define enemy_define_bulletInterval 10;//60FPS�Ȃ̂Ōv�Z��ł�60/�l�b���ɔ���
#define ActorCenter_CX	13	//�Z���^�[�̓����蔻��̈ʒu���w��
#define ActorCenter_CY	13
#define Bullet_Atc01	15
#define Max_Enemy	15
#define Max_barrage 50
#define dath_num 30//�G�ƏՓˎ��̓G�ւ̃_���[�W�i���������@�͔j��j
#define Enemy_joint	0.75	//�G�̐ڐG����ŁA�G�̂����蔻��͈́i0�`1�j

#define Max_Actorburrugeser	5

#define Item_Ten	300


#define define_match 3//�c�@�̏������l
#define define_bomb  0//bomb��
#define define_maxlevel  7
//�A�C�e���摜�p�X
#define item_g_1 "image/power.png"
#define item_g_2 "image/ten.png"
#define item_g_3 "image/l.png"
#define item_g_4 "image/jikis.png"
#define item_g_5 ""
struct Barrage
{
	int max;
	int x[Max_barrage];
	int y[Max_barrage];
	int pattern[Max_barrage];
	int speed[Max_barrage];
	int attacknum[Max_barrage];
	int Ghandle;
	int GSize_X;
	int GSize_Y;
	int counter[Max_barrage];
	int alpha[Max_barrage];
};

struct Enemy_SP
{
	long Process[50][5];//�G�̓������X�^�b�N���|�b�v
	int Ghandle;
	int HP;
	int x,y;
	int w,h;
	int pattern[2];
	int pattern_process;
	Barrage barrage;//�e���f�[�^�[
	int pro;
	int count;
	int c,cc;
	int pattern_speed;
	int flag_break;
};

class CGame_Body
{
protected:
		int stagelevel;
		int inter_g[5];
		int farst;
		//�G�l�~�[�摜
		int Genemy[4];
		int centerG;
		int bullet_size[10][2];
		//���[�^�[���摜
		int Gmeterbg;
		int Gmeter_HP;
		int GMater_jiki;
		int GMater_bomb;
		//�G�l�~�[�̒e������
		Barrage enemy_barrage;//���x�����オ��ɂ�Ēe����ω��ł���悤�ɂ��邽�߁A50�e�܂�	
		//�e�֌W
		int bullet_count;
		int flag_alpha_add;
		Enemy_SP *enemy_sp[Max_Enemy];//�A�h���X
		int *Enemy_num;
		int DeleteAt_Burreage(Barrage *enemy_barrage,int i);
public:
		void reset(void);
		//�G�l�~�[HP�Ȃǃp�����[�^�[�֌W
		int enemy_machi;
		int bomb_mode;
		float enemy_level;//���x���ɂ�苅���ω�
		float enemy_bomb;
		long score;
		int shift_key;
		int bullet_G[10];
		//�G�l�~�[XY���W
		int enemy_x;
		int enemy_y;
		int enemy_w;
		int enemy_h;

		int centerG_CX;
		int centerG_CY;
		int reset_timer;

		int enemy_hp;//�Ƃ肠�����ő�100���Ƃ����l��
		int baku_G[Baku_g_num];//�����A�j���[�V����

		int item_g[5];

		//�T�E���h�֌W
		//BGM
		int sound_bgm[3];
		//SE
		int soud_se[8];
		//�{������
		int bomb_time;
			//�֐��ꗗ
		void Draw_Enemy(void);
		void Operation_Enemy(void);
		void First_Section(void);
		int GameOver_check(void);
		void Bullet_check(void);
		void Bullet_check2(void);
		void Bullet_check3(void);
		void Bullet_Processing(void);
		void address_int(Enemy_SP *enemy_sp_dist,int *Enemy_num_dist,int i);


		//�e�֐�(�e�̎�ނł킯�܂�)
		void Set_bur1(int x,int y);
		void Set_bur2(int x,int y);
		void Set_bur3(int x,int y);
		void Set_bur4(int x,int y);
		void Set_bur5(int x,int y);
		void Set_bur6(int x,int y);
		void Set_bur7(int x,int y);
		void Set_bur8(int x,int y);
		void Set_bur9(int x,int y);


		//�A�C�e���֘A
		
};

