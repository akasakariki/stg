#include "GM_Item.h"
#include "main.h"
#include <math.h>
int CItem::Farst_Section(CGame_Body* body_dist)
{
	body=body_dist;
	max=0;
	return 0;
}

int CItem::DrawItem(void)
{
	int num=0;
	if(max<=0)
	{
		return 0;
	}
	for(int i=0;i<max;i++)
	{
		DrawGraph( item[i].x, item[i].y, item[i].Glaphic, true) ;

		//ここから行動パターンによる計算
		switch(item[i].pattern)
		{
		case 1:
			item[i].x-=item[i].spead;
			break;
		case 2:
			item[i].y+=item[i].spead;
			break;
		case 3:
			item[i].x+=item[i].spead;
			item[i].y+=item[i].spead;
			break;
		case 4:
			item[i].x-=item[i].spead;
			item[i].y+=item[i].spead;
			break;
		case 5:
			item[i].x-=item[i].spead;
			item[i].y+=sin(((item[i].y/480)*1800)* PI / 180)*item[i].spead;
			
			break;
		default:
			item[i].x-=item[i].spead;
			item[i].y+=item[i].spead;
			break;
		}
				//ここからあたり判定
		if((body->enemy_x>item[i].x&&body->enemy_x<(item[i].x+item[i].g_w))||((body->enemy_x+body->enemy_w)>item[i].x&&(body->enemy_x+body->enemy_w)<(item[i].x+item[i].g_w)))
		{
			if(debug_mode)DrawString( 250 , 300 , "XOK!" , GetColor( 255 , 255 , 255 )  );
			if((body->enemy_y<item[i].y&&(body->enemy_y+body->enemy_h)>item[i].y)||(body->enemy_y<(item[i].y+item[i].g_h)&&(body->enemy_y+body->enemy_h)>(item[i].y+item[i].g_h)))
			{
				StopSoundMem(   body->soud_se[5]) ;
				PlaySoundMem(  body->soud_se[5] , DX_PLAYTYPE_BACK ) ;
				if(debug_mode)DrawString( 250 , 300 , "アイテム取得" , GetColor( 255 , 255 , 255 )  );
				//アイテムに当たった
				switch(item[i].kouka)
				{
				case 1:
					body->enemy_hp+=30;
					if(body->enemy_hp>100)body->enemy_hp=100;
					break;
				case 2:
					body->enemy_bomb+=0.1;
					break;
				case 3:
					if((int)body->enemy_level<=define_maxlevel)
					body->enemy_level+=0.1;

					num=body->enemy_level/0.1;
					num%=10;
					if(num==0)PlaySoundMem(  body->soud_se[2] , DX_PLAYTYPE_BACK ) ;
					if((int)body->enemy_level>define_maxlevel)
						body->enemy_level=define_maxlevel;
					break;
				case 4:
					body->score+=Item_Ten;
					break;
				case 5:
					if(body->enemy_machi<6)
					body->enemy_machi++;

						break;
				}
				DeleteAt_Item(i);
				
				

			}
		}
		else if(item[i].x>640||item[i].x<0||item[i].y>480||item[i].y<0)
		{
			DeleteAt_Item(i);
			

		}
	}
	return 0;
}
int CItem::DeleteAt_Item(int num)
{
	for(int i=num;i<=max+1;i++)
	{
		item[i]=item[i+1];
	}
	max--;
	return 0;
}
int CItem::Set_Item(int x,int y,int *glaphic_id,int pattern,int spead,int kouka)
{
	if(item_max<=max)
	{
		return 2;//最大数を超えています
	}
	item[max].x=x;
	item[max].y=y;
	item[max].Glaphic=*glaphic_id;
	GetGraphSize( *glaphic_id , &item[max].g_w , &item[max].g_h ) ;
	item[max].spead=spead;
	item[max].kouka=kouka;
	item[max].pattern=pattern;

	max++;
	return 0;
	
}

int CItem::Glaphic_ID_check(int kouka_num)
{
	switch(kouka_num)
	{
	case 1:
		return 0;
		break;
	case 2:
		return 0;
		break;
	case 3:
		return 2;
		break;
	case 4:
		return 1;
		break;
	case 5:
		return 3;
		break;
	}
	return 0;
}