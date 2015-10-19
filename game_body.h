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
#define enemy_define_bulletInterval 10;//60FPSなので計算上では60/値秒毎に発射
#define ActorCenter_CX	13	//センターの当たり判定の位置を指定
#define ActorCenter_CY	13
#define Bullet_Atc01	15
#define Max_Enemy	15
#define Max_barrage 50
#define dath_num 30//敵と衝突時の敵へのダメージ（ただし自機は破壊）
#define Enemy_joint	0.75	//敵の接触判定で、敵のあたり判定範囲（0～1）

#define Max_Actorburrugeser	5

#define Item_Ten	300


#define define_match 3//残機の初期数値
#define define_bomb  0//bomb数
#define define_maxlevel  7
//アイテム画像パス
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
	long Process[50][5];//敵の動きをスタック＆ポップ
	int Ghandle;
	int HP;
	int x,y;
	int w,h;
	int pattern[2];
	int pattern_process;
	Barrage barrage;//弾幕データー
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
		//エネミー画像
		int Genemy[4];
		int centerG;
		int bullet_size[10][2];
		//メーター等画像
		int Gmeterbg;
		int Gmeter_HP;
		int GMater_jiki;
		int GMater_bomb;
		//エネミーの弾道処理
		Barrage enemy_barrage;//レベルが上がるにつれて弾道を変化できるようにするため、50弾まで	
		//弾関係
		int bullet_count;
		int flag_alpha_add;
		Enemy_SP *enemy_sp[Max_Enemy];//アドレス
		int *Enemy_num;
		int DeleteAt_Burreage(Barrage *enemy_barrage,int i);
public:
		void reset(void);
		//エネミーHPなどパラメーター関係
		int enemy_machi;
		int bomb_mode;
		float enemy_level;//レベルにより球が変化
		float enemy_bomb;
		long score;
		int shift_key;
		int bullet_G[10];
		//エネミーXY座標
		int enemy_x;
		int enemy_y;
		int enemy_w;
		int enemy_h;

		int centerG_CX;
		int centerG_CY;
		int reset_timer;

		int enemy_hp;//とりあえず最大100％という考え
		int baku_G[Baku_g_num];//爆発アニメーション

		int item_g[5];

		//サウンド関係
		//BGM
		int sound_bgm[3];
		//SE
		int soud_se[8];
		//ボム発動
		int bomb_time;
			//関数一覧
		void Draw_Enemy(void);
		void Operation_Enemy(void);
		void First_Section(void);
		int GameOver_check(void);
		void Bullet_check(void);
		void Bullet_check2(void);
		void Bullet_check3(void);
		void Bullet_Processing(void);
		void address_int(Enemy_SP *enemy_sp_dist,int *Enemy_num_dist,int i);


		//弾関数(弾の種類でわけます)
		void Set_bur1(int x,int y);
		void Set_bur2(int x,int y);
		void Set_bur3(int x,int y);
		void Set_bur4(int x,int y);
		void Set_bur5(int x,int y);
		void Set_bur6(int x,int y);
		void Set_bur7(int x,int y);
		void Set_bur8(int x,int y);
		void Set_bur9(int x,int y);


		//アイテム関連
		
};

