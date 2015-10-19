#pragma once
#define rect_anime 50//アニメーションサイズの倍率
#include "game_body.h"
struct _animedata
{
	int x;
	int y;
	int w;
	int h;
	int spritenum;
	int sprittime;
};
class CAnime
{
private:
	int Max;
	_animedata animes[Max_Enemy];
public:
	int fastsection(void);
	int set_Animation(int x,int y,int w,int h);
	int delete_Animation(int num);
	int draw_animation(int *baku_G);
};


