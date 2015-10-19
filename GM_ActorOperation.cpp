#include "main.h"
#include "game_body.h"
#define BombTime	180
void CGame_Body::Operation_Enemy(void)
{
	if(reset_timer>180)
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
		else if(CheckHitKey( KEY_INPUT_X   ) )
		{
			if(bomb_time<=0&&enemy_bomb>0)
			{
				bomb_time=BombTime;
				bomb_mode=1;
				reset_timer=Reset_Counter/2;
				enemy_bomb-=1.0f;
			}

		}
		
		else
		{
			bullet_count=0;
		}
	}
	if(bomb_time>0)
	{
		if(bomb_time%6==0)
		{
			Bullet_check2();
		}
		bomb_time--;
	}



}