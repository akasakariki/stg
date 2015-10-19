#include "main.h"
int over_flag=0;
int image=0;
int over_alpha=0;
void CMainLoop::gameover()
{
	if(over_flag==0)
	{
		image=LoadGraph("image/gameover.jpg");
		over_flag=1;
	}
	if(over_alpha<256)
	{
		over_alpha+=5;
	}
	SetDrawBlendMode( DX_BLENDMODE_ALPHA ,over_alpha) ;

	DrawGraph( 0 , 0 ,image , FALSE ) ;
	if(CheckHitKey( KEY_INPUT_Z ) ){//‹Ù‹}’Eo—p
		DxLib_End();			
	}
}