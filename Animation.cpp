#include "Animation.h"
#include "DxLib.h"
int CAnime::fastsection()
{
	//‰Šú‰»
	Max=0;
	return 0;
}

int CAnime::set_Animation(int x,int y, int w, int h)
{
	if(Max>=Max_Enemy)
	{
		//Å‘å”‚ğ’´‚¦‚½ƒGƒ‰[
		return -1;
	}
	animes[Max].x=x;
	animes[Max].y=y;
	animes[Max].w=w;
	animes[Max].h=h;
	animes[Max].sprittime=0;
	animes[Max].spritenum=0;
	Max++;
	return 0;
}

int CAnime::delete_Animation(int num)
{
	for(int i=num;i<Max;i++)
	{
		animes[i]=animes[1+1];
	}
	Max--;
	return 0;
}

int CAnime::draw_animation(int *baku_G)
{
	if(Max<=0)
	{
		return 0;
	}
	for(int i=0;i<Max;i++)
	{
		DrawExtendGraph( animes[i].x-rect_anime,animes[i].y-rect_anime, animes[i].x+animes[i].w+rect_anime ,animes[i].y+animes[i].h+rect_anime, baku_G[animes[i].spritenum] , TRUE ) ;
		if(animes[i].sprittime>Animation_msecond)
		{
			animes[i].sprittime=0;
			animes[i].spritenum++;
		}
		else
		{
			animes[i].sprittime++;
		}
		if(animes[i].spritenum>=Baku_g_num)
		{
			delete_Animation(i);
			i--;
		}
	}
	return 0;
}
