#include "main.h"
#include "game_body.h"

void CGame_Body::Operation_Enemy(void)
{
	//ï˚å¸ÉLÅ[Ç…ÇÊÇÈëÄçÏ
	shift_key=CheckHitKey( KEY_INPUT_LSHIFT )+CheckHitKey( KEY_INPUT_RSHIFT );
	if(shift_key!=0)
	{
		//í·ë¨
		if(CheckHitKey( KEY_INPUT_UP  ) )enemy_y-=(enemy_speed/2);
		if(CheckHitKey( KEY_INPUT_DOWN   ) )enemy_y+=(enemy_speed/2);
		if(CheckHitKey( KEY_INPUT_LEFT   ) )enemy_x-=(enemy_speed/2);
		if(CheckHitKey(KEY_INPUT_RIGHT  ) )enemy_x+=(enemy_speed/2);
	}
	else
	{
		if(CheckHitKey( KEY_INPUT_UP  ) )enemy_y-=enemy_speed;
		if(CheckHitKey( KEY_INPUT_DOWN   ) )enemy_y+=enemy_speed;
		if(CheckHitKey( KEY_INPUT_LEFT   ) )enemy_x-=enemy_speed;
		if(CheckHitKey(KEY_INPUT_RIGHT  ) )enemy_x+=enemy_speed;
	}
	if(enemy_x<0)enemy_x=0;
	if(enemy_y<0)enemy_y=0;
	if((enemy_x+enemy_w)>640)enemy_x=640-enemy_w;
	if((enemy_y+enemy_h)>480)enemy_y=480-enemy_h;
	if(CheckHitKey( KEY_INPUT_Z   ) )
	{
		//íeìπèàóù
		Bullet_check();
	}
	else
	{
		bullet_count=0;
	}



}