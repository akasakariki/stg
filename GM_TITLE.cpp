#include "main.h"
int loadflag=0;
int alpha_rect=0;
int alpha_rect_f=0;
#include "bgm_se_list.h"
void CMainLoop::title()
{
	if(loadflag!=1)
	{
		menu_img[0]=LoadGraph( "image/title.jpg" ) ;
		menu_img[1]=LoadGraph( "image/please.png" ) ;
		menu_bgm[0]=LoadSoundMem( title_bgm );
		PlaySoundMem(menu_bgm[0],DX_PLAYTYPE_LOOP);
		alpha_rect=0;
		loadflag=1;
	}
	else
	{
		DrawGraph( 0 , 0 , menu_img[0] , FALSE ) ;
		if(alpha_rect_f==0)
		{
			alpha_rect+=5;
			if(alpha_rect>=255)
			{
				alpha_rect_f=1;
			}
		}
		else
		{
			alpha_rect-=5;
			if(alpha_rect<=0)
			{
				alpha_rect_f=0;
			}
		}
		SetDrawBlendMode( DX_BLENDMODE_ALPHA , alpha_rect) ;

		DrawGraph( 0 , 380 , menu_img[1] , FALSE ) ;
		SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
		if(CheckHitKey( KEY_INPUT_Z ) )
		{
			loadflag=0;
			StopSoundMem(menu_bgm[0]) ;
			DeleteSoundMem(menu_bgm[0]) ;
			DeleteGraph( menu_img[0]) ;
			DeleteGraph( menu_img[1]) ;
			setGameMode(GMODE_BODY);
		}

	}

}