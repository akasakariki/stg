#include "main.h"
#include "game_body.h"
#include "GM_Enemy.h"
#include <math.h>

void Sincurve_Actor(int* x,int* y,int counter_dist,int flo);
void Sincurve_Actor2(int* x,int* y,int counter_dist,int flo);
void Coscurve_Actor(int* x,int* y,int counter_dist,int flo);
void Coscurve_Actor2(int* x,int* y,int counter_dist,int flo);
void CGame_Body::Bullet_check(void)
{
	if(enemy_barrage.max<50&&bullet_count<=0)//弾が５０以下だったら弾追加
	{	
		PlaySoundMem( soud_se[0] , DX_PLAYTYPE_BACK ) ;
		//球の発射
		switch((int)enemy_level)
		{

		case 1://直進弾�U
			Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));

			break;
		case 2://直進球＊２
			Set_bur1(enemy_x+enemy_w,enemy_y);	
			Set_bur1(enemy_x+enemy_w,enemy_y+enemy_h);	
			break;
		case 3://追尾弾
			Set_bur3(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));
				break;
		case 4://追尾弾*2
			Set_bur3(enemy_x+enemy_w,enemy_y);
			Set_bur3(enemy_x+enemy_w,enemy_y+enemy_h);
			break;
		case 5://追尾*2＋直進
				Set_bur1(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));	
				Set_bur3((enemy_x+5)+enemy_w,enemy_y);
				Set_bur3((enemy_x+5)+enemy_w,enemy_y+enemy_w);
			break;
		case 6://追尾*4＋直進*3
				Set_bur1(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));	
				Set_bur1(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w);
				Set_bur3((enemy_x+5)+enemy_w,enemy_y);
				Set_bur3((enemy_x+5)+enemy_w,enemy_y+enemy_w);
			break;
		default	:
				enemy_level=6;
			break;
		}

	}

	bullet_count--;
	
}

void CGame_Body::Bullet_check2(void)
{

	if(enemy_barrage.max<50&&bullet_count<=0)//弾が５０以下だったら弾追加
	{	
				//球の発射
		switch((int)enemy_level)
		{
		case 1://Sin弾
			Set_bur2(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));
			break;
		case 2://Cos弾
			Set_bur6(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));				
			break;
		case 3://Sin弾+Cos弾
			Set_bur6(enemy_x+enemy_w,(int)enemy_y);
			Set_bur7(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));
			break;
		case 4://(Sin弾+Cos弾)*2
			Set_bur7(enemy_x+enemy_w,(int)enemy_y);
			Set_bur6(enemy_x+enemy_w,(int)enemy_y-(enemy_h/2));
			Set_bur6(enemy_x+enemy_w,(int)enemy_y+enemy_w);
			Set_bur7(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w);
			break;
		case 5://Sin弾*5
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w+enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w+enemy_w+enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w-enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w-enemy_w-enemy_w);
			break;
		case 6://直進�U*7
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w+enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w+enemy_w+enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w-enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w-enemy_w-enemy_w);
			break;

		}

	}

	bullet_count--;
	
}

void CGame_Body::Bullet_check3(void)
{
/*		if(enemy_barrage.max<50&&bullet_count<=0)//弾が５０以下だったら弾追加
	{	
			//球の発射
		switch(enemy_level)
		{
		case 1://追尾*2＋直進
				Set_bur1(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));	
				Set_bur3((enemy_x+5)+enemy_w,enemy_y);
				Set_bur3((enemy_x+5)+enemy_w,enemy_y+enemy_w);
			break;
		case 2://追尾*4＋直進*3
				Set_bur1(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));	
				Set_bur1(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w);
				Set_bur3((enemy_x+5)+enemy_w,enemy_y);
				Set_bur3((enemy_x+5)+enemy_w,enemy_y+enemy_w);
			break;
		case 3://Sin弾*5
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w+enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w+enemy_w+enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w-enemy_w);
				Set_bur8(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w-enemy_w-enemy_w);
			break;
		case 4://直進�U*7
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2));
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w+enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)+enemy_w+enemy_w+enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w-enemy_w);
				Set_bur4(enemy_x+enemy_w,(int)enemy_y+(enemy_h/2)-enemy_w-enemy_w-enemy_w);
			break;

		}

	}

	bullet_count--;
	
*/
	}

void CGame_Body::Bullet_Processing(void)
{
					int k=0;
				int j=999;
				int temp=0;
	//描写も兼ねる
	if(enemy_barrage.max>0)
	{

		for(int i=0;i<enemy_barrage.max;i++)
		{
			if(enemy_barrage.x[i]>640)
			{
				DeleteAt_Burreage(&enemy_barrage,i);

			}
			if(enemy_barrage.alpha[i]<255)
			{
				enemy_barrage.alpha[i]+=8;
			}
			SetDrawBlendMode(DX_BLENDMODE_ALPHA,enemy_barrage.alpha[i]) ;

			switch(enemy_barrage.pattern[i])	
			{
			case 1:
				enemy_barrage.x[i]+=enemy_barrage.speed[i];
				DrawGraph( enemy_barrage.x[i],enemy_barrage.y[i] , bullet_G[1], true ) ;
				break;
			case 2:
				enemy_barrage.counter[i]+=enemy_barrage.speed[i];
				Sincurve_Actor(&enemy_barrage.x[i],&enemy_barrage.y[i],enemy_barrage.counter[i],enemy_barrage.speed[i]);
				if(enemy_barrage.counter[i]>360)
				{
					enemy_barrage.counter[i]=0;
				}
				DrawGraph( enemy_barrage.x[i],enemy_barrage.y[i] , bullet_G[0], true ) ;
				break;
			case 3:

				if(*Enemy_num!=0)
				{
					for(int ii=0;ii<*Enemy_num;ii++)
					{
						if(enemy_sp[ii]->HP!=-500)
						{
							temp=enemy_sp[ii]->y-enemy_barrage.y[i];
							if(temp<0)temp*=-1;//符号反転
							if(j>temp)
							{
								j=temp;
								k=ii;
							}
						}
						
					}

					if(temp!=0)
					{
						if(enemy_barrage.y[i]>(enemy_sp[k]->y+(enemy_sp[k]->h/2)))
						{
							enemy_barrage.y[i]-=enemy_barrage.speed[i];
						}
						else if(enemy_barrage.y[i]<enemy_sp[k]->y+(enemy_sp[k]->h/2))
						{
							enemy_barrage.y[i]+=enemy_barrage.speed[i];
						}
					}
						

						

				}
				enemy_barrage.x[i]+=enemy_barrage.speed[i];//敵がいないのであれば直進モード
				DrawGraph( enemy_barrage.x[i],enemy_barrage.y[i] , bullet_G[0], true ) ;
				break;
			case 4:
				enemy_barrage.counter[i]+=enemy_barrage.speed[i];
				Sincurve_Actor2(&enemy_barrage.x[i],&enemy_barrage.y[i],enemy_barrage.counter[i],enemy_barrage.speed[i]);
				if(enemy_barrage.counter[i]>360)
				{
					enemy_barrage.counter[i]=0;
				}
				DrawGraph( enemy_barrage.x[i],enemy_barrage.y[i] , bullet_G[0], true ) ;
				break;
			case 5:
				enemy_barrage.counter[i]+=enemy_barrage.speed[i];
				Coscurve_Actor(&enemy_barrage.x[i],&enemy_barrage.y[i],enemy_barrage.counter[i],enemy_barrage.speed[i]);
				if(enemy_barrage.counter[i]>360)
				{
					enemy_barrage.counter[i]=0;
				}
				DrawGraph( enemy_barrage.x[i],enemy_barrage.y[i] , bullet_G[0], true ) ;
				break;
			case 6:
				enemy_barrage.counter[i]+=enemy_barrage.speed[i];
				Coscurve_Actor2(&enemy_barrage.x[i],&enemy_barrage.y[i],enemy_barrage.counter[i],enemy_barrage.speed[i]);
				if(enemy_barrage.counter[i]>360)
				{
					enemy_barrage.counter[i]=0;
				}
				DrawGraph( enemy_barrage.x[i],enemy_barrage.y[i] , bullet_G[0], true ) ;
				break;


			}

			int kj=0;
			if(enemy_barrage.pattern[i]==1||enemy_barrage.pattern[i]==3)
			{
				kj=0;
			}
			else
			{
				kj=1;
			}
			for(int k=0;k<*Enemy_num;k++)
			{
				for(int j=0;j<bullet_size[kj][0];j++)
				{

					//攻撃判定
					if(enemy_sp[k]->x<(enemy_barrage.x[i]-j)&&(enemy_sp[k]->x+enemy_sp[k]->w)>(enemy_barrage.x[i]-j))
					{
						//横範囲内
						if(enemy_sp[k]->y<(enemy_barrage.y[i]+(enemy_barrage.GSize_Y/2))&&(enemy_sp[k]->y+enemy_sp[k]->h)>(enemy_barrage.y[i]+(enemy_barrage.GSize_Y/2)))
						{
							PlaySoundMem( soud_se[1] , DX_PLAYTYPE_BACK ) ;
							enemy_sp[k]->HP-=enemy_barrage.attacknum[i];
							DeleteAt_Burreage(&enemy_barrage,i);
						}
					}
				}
			}
		}
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0) ;


}
int CGame_Body::DeleteAt_Burreage(Barrage *enemy_barrage,int i)
{

	for(int ii=i;ii<enemy_barrage->max;ii++)
	{
					enemy_barrage->x[ii]=enemy_barrage->x[ii+1];
					enemy_barrage->y[ii]=enemy_barrage->y[ii+1];
					enemy_barrage->attacknum[ii]=enemy_barrage->attacknum[ii+1];
					enemy_barrage->speed[ii]=enemy_barrage->speed[ii+1];
					enemy_barrage->pattern[ii]=enemy_barrage->pattern[ii+1];
					enemy_barrage->counter[ii]=enemy_barrage->counter[ii+1];
					enemy_barrage->alpha[ii]=enemy_barrage->alpha[ii+1];
	}
	enemy_barrage->max--;

			
	return 0;
}
void Sincurve_Actor(int* x,int* y,int counter_dist,int flo)//Sin
{
	//int counter=counter_dist%180;//周期８０
	*y+=sin(counter_dist* PI / 180)*4;
    *x+=flo;
	
}

void Sincurve_Actor2(int* x,int* y,int counter_dist,int flo)//-Sin
{
	//int counter=counter_dist%180;//周期８０
	*y+=sin(counter_dist* PI / 180)*-4;
    *x+=flo;
	
}

void Coscurve_Actor(int* x,int* y,int counter_dist,int flo)//Cos
{
	//int counter=counter_dist%180;//周期８０
	*y+=cos(counter_dist* PI / 180)*4;
    *x+=flo;
	
}

void Coscurve_Actor2(int* x,int* y,int counter_dist,int flo)//-Cos
{
	//int counter=counter_dist%180;//周期８０
	*y+=cos(counter_dist* PI / 180)*-4;
    *x+=flo;
	
}


void CGame_Body::Set_bur1(int x,int y)
{
	//直線モード
		bullet_count=enemy_define_bulletInterval;
		enemy_barrage.alpha[enemy_barrage.max]=0;
			enemy_barrage.speed[enemy_barrage.max]=enemy_speed*2;
			enemy_barrage.GSize_X=bullet_size[0][0];
			enemy_barrage.GSize_Y=bullet_size[0][1];
			enemy_barrage.x[enemy_barrage.max]=(int)x;
			enemy_barrage.y[enemy_barrage.max]=(int)y;
			enemy_barrage.attacknum[enemy_barrage.max]=Bullet_Atc01;
			enemy_barrage.pattern[enemy_barrage.max]=1;//パターン１
			enemy_barrage.max++;
}

void CGame_Body::Set_bur2(int x,int y)
{
	//Sinモード
		bullet_count=enemy_define_bulletInterval;
			enemy_barrage.alpha[enemy_barrage.max]=0;
			enemy_barrage.speed[enemy_barrage.max]=enemy_speed;
			enemy_barrage.GSize_X=bullet_size[0][0];
			enemy_barrage.GSize_Y=bullet_size[0][1];
			enemy_barrage.x[enemy_barrage.max]=(int)x;
			enemy_barrage.y[enemy_barrage.max]=(int)y;
			enemy_barrage.attacknum[enemy_barrage.max]=Bullet_Atc01;
			enemy_barrage.pattern[enemy_barrage.max]=2;//パターン2
			enemy_barrage.counter[enemy_barrage.max]=0;
			enemy_barrage.max++;
}

void CGame_Body::Set_bur3(int x,int y)
{
	//追尾モード
		bullet_count=enemy_define_bulletInterval;
			enemy_barrage.alpha[enemy_barrage.max]=0;
			enemy_barrage.speed[enemy_barrage.max]=enemy_speed;
			enemy_barrage.GSize_X=bullet_size[0][0];
			enemy_barrage.GSize_Y=bullet_size[0][1];
			enemy_barrage.x[enemy_barrage.max]=(int)x;
			enemy_barrage.y[enemy_barrage.max]=(int)y;
			enemy_barrage.attacknum[enemy_barrage.max]=Bullet_Atc01;
			enemy_barrage.pattern[enemy_barrage.max]=3;//パターン3
			enemy_barrage.counter[enemy_barrage.max]=0;
			enemy_barrage.max++;
}
void CGame_Body::Set_bur4(int x,int y)
{
	//直線モード�U
		bullet_count=enemy_define_bulletInterval;
			enemy_barrage.alpha[enemy_barrage.max]=0;
			enemy_barrage.speed[enemy_barrage.max]=enemy_speed*3;
			enemy_barrage.GSize_X=bullet_size[0][0];
			enemy_barrage.GSize_Y=bullet_size[0][1];
			enemy_barrage.x[enemy_barrage.max]=(int)x;
			enemy_barrage.y[enemy_barrage.max]=(int)y;
			enemy_barrage.attacknum[enemy_barrage.max]=Bullet_Atc01;
			enemy_barrage.pattern[enemy_barrage.max]=1;//パターン１
			enemy_barrage.counter[enemy_barrage.max]=0;
			enemy_barrage.max++;
}

void CGame_Body::Set_bur5(int x,int y)
{
	//-Sinモード
		bullet_count=enemy_define_bulletInterval;
			enemy_barrage.alpha[enemy_barrage.max]=0;
			enemy_barrage.speed[enemy_barrage.max]=enemy_speed;
			enemy_barrage.GSize_X=bullet_size[0][0];
			enemy_barrage.GSize_Y=bullet_size[0][1];
			enemy_barrage.x[enemy_barrage.max]=(int)x;
			enemy_barrage.y[enemy_barrage.max]=(int)y;
			enemy_barrage.attacknum[enemy_barrage.max]=Bullet_Atc01;
			enemy_barrage.pattern[enemy_barrage.max]=4;//パターン4
			enemy_barrage.counter[enemy_barrage.max]=0;
			enemy_barrage.max++;
}

void CGame_Body::Set_bur6(int x,int y)
{
	//Cosモード
		bullet_count=enemy_define_bulletInterval;
			enemy_barrage.alpha[enemy_barrage.max]=0;
			enemy_barrage.speed[enemy_barrage.max]=enemy_speed;
			enemy_barrage.GSize_X=bullet_size[0][0];
			enemy_barrage.GSize_Y=bullet_size[0][1];
			enemy_barrage.x[enemy_barrage.max]=(int)x;
			enemy_barrage.y[enemy_barrage.max]=(int)y;
			enemy_barrage.attacknum[enemy_barrage.max]=Bullet_Atc01;
			enemy_barrage.pattern[enemy_barrage.max]=5;//パターン5
			enemy_barrage.counter[enemy_barrage.max]=0;
			enemy_barrage.max++;
}

void CGame_Body::Set_bur7(int x,int y)
{
	//-Cosモード
		bullet_count=enemy_define_bulletInterval;
			enemy_barrage.alpha[enemy_barrage.max]=0;
			enemy_barrage.speed[enemy_barrage.max]=enemy_speed;
			enemy_barrage.GSize_X=bullet_size[0][0];
			enemy_barrage.GSize_Y=bullet_size[0][1];
			enemy_barrage.x[enemy_barrage.max]=(int)x;
			enemy_barrage.y[enemy_barrage.max]=(int)y;
			enemy_barrage.attacknum[enemy_barrage.max]=Bullet_Atc01;
			enemy_barrage.pattern[enemy_barrage.max]=6;//パターン6
			enemy_barrage.counter[enemy_barrage.max]=0;
			enemy_barrage.max++;
}

void CGame_Body::Set_bur8(int x,int y)
{
	//Sinモード�U
		bullet_count=enemy_define_bulletInterval;
			enemy_barrage.alpha[enemy_barrage.max]=0;
			enemy_barrage.speed[enemy_barrage.max]=enemy_speed*2;
			enemy_barrage.GSize_X=bullet_size[0][0];
			enemy_barrage.GSize_Y=bullet_size[0][1];
			enemy_barrage.x[enemy_barrage.max]=(int)x;
			enemy_barrage.y[enemy_barrage.max]=(int)y;
			enemy_barrage.attacknum[enemy_barrage.max]=Bullet_Atc01;
			enemy_barrage.pattern[enemy_barrage.max]=2;//パターン2
			enemy_barrage.counter[enemy_barrage.max]=0;
			enemy_barrage.max++;
}

void CGame_Body::Set_bur9(int x,int y)
{
	//Cosモード�U
		bullet_count=enemy_define_bulletInterval;
			enemy_barrage.alpha[enemy_barrage.max]=0;
			enemy_barrage.speed[enemy_barrage.max]=enemy_speed*2;
			enemy_barrage.GSize_X=bullet_size[0][0];
			enemy_barrage.GSize_Y=bullet_size[0][1];
			enemy_barrage.x[enemy_barrage.max]=(int)x;
			enemy_barrage.y[enemy_barrage.max]=(int)y;
			enemy_barrage.attacknum[enemy_barrage.max]=Bullet_Atc01;
			enemy_barrage.pattern[enemy_barrage.max]=5;//パターン5
			enemy_barrage.counter[enemy_barrage.max]=0;
			enemy_barrage.max++;
}

