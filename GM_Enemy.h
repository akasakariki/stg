#pragma once
#include "DxLib.h"

#include "game_body.h"


class CGame_Enemy
{
private:
	
	int Gbarrage[10];//弾画像ハンドル
	int Gbarrage_wh[10][2];//弾画像のサイズ
	void Bullet_check(Barrage &barrage,int pattern,int attacknum,int barragenum,int speed,int x,int y,Enemy_SP* enemy_sp);
	void Bullet_process(Barrage &enemy_barrage);
	void pattern_move(Enemy_SP *enemy);
	CGame_Body *body;
	//停滞パターン用変数
	int time_flag;
	int time_dest;
public:
	int Enemy_num;//敵の数
	void address_body(CGame_Body *body_dist);
	int Format(void);
	int ScriptAddProcess_Enemy(Enemy_SP *enemy,int script);//動きを追加する
	int DeleteAt_EnemyProcess(Enemy_SP *enemy,int num);
	int DeleteAt_Burreage(Barrage *enemy_barrage,int i);
	void Enemy_Processin(Enemy_SP *enemy);//敵をすべて描写と処理
	void Draw_Enemy(void);

	Enemy_SP enemy_sp[Max_Enemy+10];
	//以下敵の弾パターン関数
	void Set_bur1(int x,int y,int speed,int attacknum,Barrage *barrage);
	void Set_bur2(int x,int y,int speed,int attacknum,Barrage *barrage);
	void Set_bur3(int x,int y,int speed,int attacknum,Barrage *barrage);
	void Set_bur4(int x,int y,int speed,int attacknum,Barrage *barrage);
	void Set_bur5(int x,int y,int speed,int attacknum,Barrage *barrage);
	//以下敵のパターン関数
	void Enemy_pattern1(Enemy_SP *enemy);
	void Enemy_pattern2(Enemy_SP *enemy);
	void Enemy_pattern3(Enemy_SP *enemy);
	void Enemy_pattern4(Enemy_SP *enemy);
	void Enemy_pattern5(Enemy_SP *enemy);
};