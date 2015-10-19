#include "main.h"
#include "game_body.h"
#include "GM_Varble.h"
CVarble varble_body;
#include "Animation.h"
CAnime anime;
#include "GM_Item.h"
CItem item;
void CMainLoop::body()
{
	if(loading_format!=1)//初期化
	{
		varble_body.Reset_varbles();
		enemy.address_body(&gmbody);//アドレスの引き渡し（参照時に使用）
		for(int i=0;i<Max_Enemy;i++)
		gmbody.address_int(&enemy.enemy_sp[i],&enemy.Enemy_num,i);//上記と同じく
		enemy.Format();
		enemy.ScriptAddProcess_Enemy(enemy.enemy_sp,1);//スクリプトを処理し、動きを設定
		//enemy.ScriptAddProcess_Enemy(enemy.enemy_sp,script2);//スクリプトを処理し、動きを設定
		item.Farst_Section(&gmbody);
		gmbody.First_Section();
		loading_format=1;
	}
	item.DrawItem();
	//描写関係
	enemy.Draw_Enemy();

	//操作関係
	gmbody.Draw_Enemy();
	gmbody.Operation_Enemy();




	
	if(gmbody.GameOver_check()==1)
	{
		//ゲームオーバー
		setGameMode(GMODE_GAMEOVER);
	}
}


void CGame_Body::Draw_Enemy(void)
{
		int flag_alpha=0;
		int alpha=100;
			Bullet_Processing();
			anime.draw_animation(baku_G);

		if(reset_timer<Reset_Counter)
		{
			
			
			if(reset_timer%5==0)
			{
				if(reset_timer<(Reset_Counter/2)&&bomb_mode!=1)
				{
					enemy_x+=3;
				}
				flag_alpha_add*=-1;
			}
			if(flag_alpha_add==1)
			{
				SetDrawBlendMode( DX_BLENDMODE_ALPHA , 255 ) ;
			}
			else
			{
				SetDrawBlendMode( DX_BLENDMODE_ALPHA , 50 ) ;
			}
			reset_timer++;
		}
		else
		{
			bomb_mode=0;
		}
		//描写関係
		DrawGraph( enemy_x ,enemy_y , Genemy[0] , true ) ;
		if(shift_key!=0)
		{
			DrawGraph( enemy_x+ActorCenter_CX ,enemy_y+ActorCenter_CY , centerG , true ) ;
		}
		if(reset_timer<Reset_Counter)
		{
			SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
		}
		//メーター関係の描写
		if((enemy_y+enemy_h)>400)
		{
			alpha=((enemy_y+enemy_h)-400)*(meter_defaultalpha/20);
			SetDrawBlendMode( DX_BLENDMODE_ALPHA , meter_defaultalpha-alpha ) ;
		}
		else
		{
			SetDrawBlendMode( DX_BLENDMODE_ALPHA , meter_defaultalpha ) ;
		}
		if(alpha>=400)
		{
			flag_alpha=-420;
			SetDrawBlendMode( DX_BLENDMODE_ALPHA , meter_defaultalpha ) ;
		}
		
		DrawGraph( 0 ,420+flag_alpha , Gmeterbg , true ) ;
		DrawExtendGraph( 60 ,430+flag_alpha ,((hpmeter_size_x/100)*enemy_hp)+60 , 445+flag_alpha  , Gmeter_HP , TRUE ) ;
		DrawFormatString( 5 , 457+flag_alpha , GetColor( 255 , 255 , 255 ) ,"残り%d機",enemy_machi ) ;
		
		for(int i=0;i<enemy_machi;i++)
		{
			DrawGraph(75+(i*25) ,457+flag_alpha , GMater_jiki , true ) ;
		}
		for(int i=0;i<enemy_bomb;i++)
		{
			DrawGraph(300+(i*25) ,457+flag_alpha , GMater_bomb, true ) ;
		}
		//エネミーレベルはとりあえず画像処理にさせる予定だけどとりあえず文字表示
		DrawFormatString( 470 , 430+flag_alpha , GetColor( 255 , 255 , 255 ) ,"EnemyLevel:%.1f",(enemy_level-0.1) ) ;
		DrawFormatString( 470 , 460+flag_alpha , GetColor( 255 , 255 , 255 ) ,"Stage%d",stagelevel ) ;
		//メーター描写ここまで
		

		if(reset_timer<(Reset_Counter/2))
		{
			if(flag_alpha_add==1)
			{
				SetDrawBlendMode( DX_BLENDMODE_ALPHA , 180) ;
			}
			else
			{
				SetDrawBlendMode( DX_BLENDMODE_ALPHA , 50) ;
			}
			DrawGraph( 0 , 90 ,inter_g[0] , true ) ;
		}
		SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

		//デバッグテスト用
		if(debug_mode==true)
		{
			if(CheckHitKey(KEY_INPUT_NUMPAD0  ))
			{
				while(CheckHitKey(KEY_INPUT_NUMPAD0 ));
				enemy_level--;
			}
			if(CheckHitKey(KEY_INPUT_NUMPAD1  ))
			{
				while(CheckHitKey(KEY_INPUT_NUMPAD1 ));
				enemy_level++;
			}
			if(CheckHitKey(KEY_INPUT_PGDN   ) )enemy_hp--;//エネミーのHPを減らしテスト
			if(CheckHitKey(KEY_INPUT_1    ) )
			{
				while(CheckHitKey(KEY_INPUT_1    ));
				enemy_level++;
			}
			if(CheckHitKey(KEY_INPUT_2    ) )		
			{
				while(CheckHitKey(KEY_INPUT_2    ));
				enemy_level--;
			}
			int MouseX , MouseY ;
			GetMousePoint( &MouseX , &MouseY ) ;
			DrawFormatString( 0 , 0, GetColor( 255 , 255 , 255 ) ,"mousecursor→X:%d	Y:%d",MouseX,MouseY ) ;
			DrawFormatString( 0 , 25, GetColor( 255 , 255 , 255 ) ,"actor→X:%d Y:%d",enemy_x,enemy_y ) ;
			DrawFormatString( 0 , 50, GetColor( 255 , 255 , 255 ) ,"actor_burret:%d/50",enemy_barrage.max) ;

		}
}

#include "bgm_se_list.h"
void CGame_Body::First_Section(void)
{
	score=0;
	farst=0;
	bomb_mode=2;
	bomb_time=0;
	Genemy[0]=LoadGraph( enemy_image ) ;//エネミー読み込み
	Gmeter_HP=LoadGraph(hpmeter_g);
	GetGraphSize( Genemy[0] , &enemy_w , &enemy_h ) ;//エネミー画像の大きさを取得
	Gmeterbg=LoadGraph(meter_bg);
	enemy_x=-20;
	enemy_y=235;
	enemy_level=1.0f;
	stagelevel=1;
	enemy_bomb=define_bomb;
	enemy_barrage.max=0;
	enemy_hp=0;//標準HP100%
	enemy_machi=define_match+1;//残機を３と設定
	GMater_jiki=LoadGraph( jiki_g ) ;//残機表示用画像
	GMater_bomb=LoadGraph( bomb_g ) ;
	//バレット読み込み
	bullet_G[0]=LoadGraph( bullet_g1 ) ;
	GetGraphSize( bullet_G[0] , &bullet_size[0][0] , &bullet_size[0][1]) ;
	centerG=LoadGraph( enemy_center_g ) ;
	GetGraphSize( centerG , &centerG_CX , &centerG_CY ) ;
	bullet_G[1]=LoadGraph( bullet_g2 ) ;
	GetGraphSize( bullet_G[1] , &bullet_size[1][0] , &bullet_size[1][1]) ;
	//爆発読み込み
	LoadDivGraph( Bakudef_g,Baku_g_num, 8 , 2 , 96 , 96 ,baku_G ) ;
	anime.fastsection();
	reset_timer=0;
	flag_alpha_add=1;

	inter_g[0]=LoadGraph("image/st.png");
	//item関係
	item_g[0]=LoadGraph( item_g_1 ) ;
	item_g[1]=LoadGraph( item_g_2 ) ;
	item_g[2]=LoadGraph( item_g_3 ) ;
	item_g[3]=LoadGraph( item_g_4 ) ;
	item_g[4]=LoadGraph( item_g_5 ) ;

	//音声関係
	soud_se[0]=LoadSoundMem(hassya_se) ;
	soud_se[1]=LoadSoundMem(hit) ;
	soud_se[2]=LoadSoundMem(up) ;
	soud_se[3]=LoadSoundMem(bokan) ;
	soud_se[4]=LoadSoundMem(buzzer) ;
	soud_se[5]=LoadSoundMem(item_get) ;

}

int CGame_Body::GameOver_check(void)
{
	if(enemy_hp<=0)
	{
		reset_timer=0;
		if(farst!=0)
		{
			anime.set_Animation(enemy_x,enemy_y,centerG_CX*3,centerG_CY*3);
		}
		else
		{
			farst=1;
		}
		enemy_x=-20;
		enemy_y=235;
		if(enemy_machi<=0)
		{
			return 1;
		}
		else
		{
			StopSoundMem( soud_se[4] ) ;
			PlaySoundMem( soud_se[4] , DX_PLAYTYPE_BACK ) ;

			enemy_machi--;//残機数を減らして
			enemy_hp=100;//回復
			enemy_level=1.0f;
			enemy_bomb=2;
		}
	}
	return 0;

}

void CGame_Enemy::Draw_Enemy(void)
{
	if(Enemy_num!=0)
	{
		for(int Num_Enemy=0;Num_Enemy<Enemy_num;Num_Enemy++)
		{
			if(enemy_sp[Num_Enemy].Ghandle!=0)
			{
				DrawGraph( enemy_sp[Num_Enemy].x, enemy_sp[Num_Enemy].y, enemy_sp[Num_Enemy].Ghandle, true ) ;
			}
			Bullet_process(enemy_sp[Num_Enemy].barrage);//弾の処理
			pattern_move(&enemy_sp[Num_Enemy]);
			if(((enemy_sp[Num_Enemy].x)<(body->enemy_x+ActorCenter_CX+body->centerG_CX)&&(enemy_sp[Num_Enemy].x+enemy_sp[Num_Enemy].w)>(body->enemy_x+ActorCenter_CX+body->centerG_CX))
				||(body->enemy_x+ActorCenter_CX)<(enemy_sp[Num_Enemy].x+enemy_sp[Num_Enemy].w)&&(body->enemy_x+ActorCenter_CX)>enemy_sp[Num_Enemy].x)
				
			{
				if(body->reset_timer>=Reset_Counter)
				if(enemy_sp[Num_Enemy].HP!=-200)
				if(((body->enemy_y+ActorCenter_CY)>enemy_sp[Num_Enemy].y&&(body->enemy_y+ActorCenter_CY)<(enemy_sp[Num_Enemy].y+enemy_sp[Num_Enemy].h))
					||(body->enemy_y+ActorCenter_CY+body->centerG_CY)>enemy_sp[Num_Enemy].y&&(body->enemy_y+ActorCenter_CY+body->centerG_CY)<(enemy_sp[Num_Enemy].y+enemy_sp[Num_Enemy].h))
				{
					if(debug_mode)DrawString( 250 , 265  , "完全接触接触" , GetColor( 255 , 255 , 255 )  );
					//自機衝突を判定
					enemy_sp[Num_Enemy].HP-=dath_num;//敵のHPを減らす
					body->enemy_hp=0;
				}

			}
			if(enemy_sp[Num_Enemy].HP!=-500)
			{
				if(enemy_sp[Num_Enemy].HP<=0&&enemy_sp[Num_Enemy].flag_break!=1)
				{
					StopSoundMem( body->soud_se[3] ) ;
					PlaySoundMem(  body->soud_se[3] , DX_PLAYTYPE_BACK ) ;
					if(enemy_sp[Num_Enemy].barrage.max>0&&enemy_sp[Num_Enemy].Ghandle!=0)
					{
						DeleteGraph( enemy_sp[Num_Enemy].Ghandle ) ;
						enemy_sp[Num_Enemy].Ghandle=0;
						enemy_sp[Num_Enemy].HP!=-200;
					}
					else
					{
					enemy_sp[Num_Enemy].flag_break=0;
					for(int i=0;i<50;i++)
					{
						if(enemy_sp[Num_Enemy].Process[i][0]==14)
						{
							//終了処理がないか検索
							for(int ikk=0;ikk<50;ikk++)
							{
								if(enemy_sp[Num_Enemy].Process[ikk][0]==4)//ラベル
								{
									if(enemy_sp[Num_Enemy].Process[ikk][1]==enemy_sp[Num_Enemy].Process[i][1])
									{
										//完全一致
										enemy_sp[Num_Enemy].pro=ikk;
										enemy_sp[Num_Enemy].flag_break=1;
										break;
									}
								}
							}
							break;

						}
					}
					if(enemy_sp[Num_Enemy].Ghandle!=0)
					{
						DeleteGraph( enemy_sp[Num_Enemy].Ghandle ) ;
						enemy_sp[Num_Enemy].Ghandle=0;
					}
					anime.set_Animation(enemy_sp[Num_Enemy].x,enemy_sp[Num_Enemy].y,enemy_sp[Num_Enemy].w,enemy_sp[Num_Enemy].h);
					enemy_sp[Num_Enemy].Ghandle=0;
					if(enemy_sp[Num_Enemy].flag_break!=1&&enemy_sp[Num_Enemy].barrage.max<=0)
					{
						//消去処理
						for(int i=Num_Enemy;i<Enemy_num;i++)
						{
							enemy_sp[i]=enemy_sp[i+1];
							
						}
						Enemy_num--;
					}
					
					}
				}
			}
		}
		Enemy_Processin(enemy_sp);//敵をすべて描写と処理
	}


}
void CGame_Enemy::pattern_move(Enemy_SP *enemy)
{
	switch(enemy->pattern[0])
	{
	case 1://くるくる回る～
		Enemy_pattern1(enemy);
		break;
	case 2:
		Enemy_pattern2(enemy);
		break;
	case 3:
		Enemy_pattern3(enemy);
		break;
	case 4:
		Enemy_pattern4(enemy);
		break;
	case 5:
		Enemy_pattern5(enemy);
		break;
	}
}


void CGame_Enemy::address_body(CGame_Body *body_dist)
{
	body=body_dist;
}

void CGame_Body::address_int(Enemy_SP *enemy_sp_dist,int *Enemy_num_dist,int i)
{
	enemy_sp[i]=enemy_sp_dist;
	Enemy_num=Enemy_num_dist;
}