// エネミー動作プログラム
//エネミースクリプト解読
#include "DxLib.h"
#include "GM_Enemy.h"
#include "main.h"
#define Gbarrage1 "image/bullet.png"
#include "String.h"
//スクリプト（実際はきちんと外部ファイルに用意、今回はデバッグのため）

//ここまで
/*
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				 LPSTR lpCmdLine, int nCmdShow )
{
ChangeWindowMode( true ) ;
if( DxLib_Init() == -1 )	// ＤＸライブラリ初期化処理
	{
		 return -1;				// エラーが起きたら直ちに終了
	}


	SetDrawScreen( DX_SCREEN_BACK ) ;
	while(ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0)
	{
		ClearDrawScreen() ;
		
		ScriptAddProcess_Enemy(enemy_sp,script);
		ScriptAddProcess_Enemy(enemy_sp,script);
		ScriptAddProcess_Enemy(enemy_sp,script);
		DeleteAt_EnemyProcess(enemy_sp,0);
		ScreenFlip() ;
		WaitKey();
	}



	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;					// ソフトの終了
}
*/

int CGame_Enemy::ScriptAddProcess_Enemy(Enemy_SP *enemy,int scriptname)//動きを追加する
{
	if(Enemy_num>=Max_Enemy)
	{
		return -1;//敵キャラ作成数最大数を超えた
	}
	char script[100][256];
	for(int sp=0;sp<100;sp++)for(int cp=0;cp<256;cp++)script[sp][cp]=0;
	LoadFile(scriptname,&script[0][0],256);
	char scriptprocess[10][50];
	int S_CP=1;
	int S_SP=0;
	int SP=0;
	
	int CP=1;
	int counter=0;
	enemy[Enemy_num].pro=0;
	while(script[S_SP][0]!=NULL)//ファイルの終端まで
	{
		for(int i=0;i<10;i++)
		{
			for(int ii=0;ii<50;ii++)scriptprocess[i][ii]=0;
		}
		switch(script[S_SP][0])
		{
		case'/':
				 if(script[S_SP][1]!='/')
				 {
					 //文法エラー
					 goto error;
				 }
				 break;
		case'<':
			CP=0;
			S_CP=1;
			SP=0;
			while(script[S_SP][S_CP]!='>')
			{
				if(script[S_SP][S_CP]==',')
				{
					SP++;
					CP=0;
					S_CP++;
				}
				scriptprocess[SP][CP]=script[S_SP][S_CP];
				CP++;
				S_CP++;
			}
			break;
		}

			if(strcmp(scriptprocess[0],"set_enemy_xy")==0)
			{
				//移動指定0
				enemy[Enemy_num].Process[counter][0]=0;//パターン番号０移動を代入（パターン番号をdefineで英名にしたほうが良いかも）
				enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[1]);//ｘ位置指定
				enemy[Enemy_num].Process[counter][2]=atoi(scriptprocess[2]);//ｙ位置指定
				enemy[Enemy_num].Process[counter][3]=atoi(scriptprocess[3]);//速さ指定<ms後に着くという指定>
				if(enemy[Enemy_num].Process[counter][3]==0)
				{
					enemy[Enemy_num].Process[counter][3]=1;
				}
				counter++;
			
			}
			else if(strcmp(scriptprocess[0],"set_enemy_load")==0)
			{
				if(scriptprocess[1][0]!='0')
				{
					enemy[Enemy_num].Ghandle=LoadGraph( scriptprocess[1] ) ;//読み込み
					GetGraphSize( enemy[Enemy_num].Ghandle , &enemy[Enemy_num].w , &enemy[Enemy_num].h ) ;
					enemy[Enemy_num].w*=Enemy_joint;
					enemy[Enemy_num].h*=Enemy_joint;
					enemy[Enemy_num].HP=atoi(scriptprocess[2]);
				}
				else
				{
					enemy[Enemy_num].HP=-500;
					enemy[Enemy_num].Ghandle=0;
					enemy[Enemy_num].x=0;
					enemy[Enemy_num].y=0;

				}


			}
			else if(strcmp(scriptprocess[0],"set_fast_xy")==0)
			{
				enemy[Enemy_num].x=atoi(scriptprocess[1]);
				enemy[Enemy_num].y=atoi(scriptprocess[2]);
			}
			else if(strcmp(scriptprocess[0],"set_enemy_pattern")==0)
			{
				//行動パターン指定1
				enemy[Enemy_num].Process[counter][0]=1;
				enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[1]);//パターン指定
				enemy[Enemy_num].Process[counter][2]=atoi(scriptprocess[2]);//大きさ設定
				enemy[Enemy_num].Process[counter][3]=atoi(scriptprocess[3]);//速さ指定（移動量）
				counter++;

			}
			else if(strcmp(scriptprocess[0],"set_enemy_bullet")==0)
			{
				//球の発射2
				enemy[Enemy_num].Process[counter][0]=2;
				enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[1]);//パターン
				enemy[Enemy_num].Process[counter][2]=atoi(scriptprocess[2]);//スピード
				enemy[Enemy_num].Process[counter][3]=atoi(scriptprocess[3]);//発数
				enemy[Enemy_num].Process[counter][4]=atoi(scriptprocess[4]);//攻撃値
				counter++;
			}
			else if(strcmp(scriptprocess[0],"set_enemy_wait")==0)
			{
				//敵の処理を時間指定で停止3
				enemy[Enemy_num].Process[counter][0]=3;
				enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[1]);
				//enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[2]);
				counter++;
			}
			else if(strcmp(scriptprocess[0],"ravel")==0)//ラベル名の設定（数字変換管理)
			{
				//ラベル検索script[S_SP][S_CP]
				enemy[Enemy_num].Process[counter][0]=4;
				enemy[Enemy_num].Process[counter][1]=1;
				for(int j=0;scriptprocess[1][j]!='\0';j++)
				enemy[Enemy_num].Process[counter][1]*=char_int(scriptprocess[1][j]);
				counter++;
			}
			else if(strcmp(scriptprocess[0],"goto_ravel")==0)
			{
				enemy[Enemy_num].Process[counter][0]=5;
				enemy[Enemy_num].Process[counter][1]=1;
				for(int j=0;scriptprocess[1][j]!=0;j++)
				enemy[Enemy_num].Process[counter][1]*=char_int(scriptprocess[1][j]);
				counter++;
			}
			else if(strcmp(scriptprocess[0],"if_goto_A")==0)
			{
				enemy[Enemy_num].Process[counter][0]=6;
				int len;
				for(int jk=1;jk<=4;jk++)
				{
					len=0;
					len=strlen(scriptprocess[jk]);
					enemy[Enemy_num].Process[counter][jk]=1;
					for(int i=0;i<len;i++)enemy[Enemy_num].Process[counter][jk]*=char_int(scriptprocess[jk][i]);
				}
				counter++;
			}
			else if(strcmp(scriptprocess[0],"if_goto_B")==0)
			{
				enemy[Enemy_num].Process[counter][0]=7;
				int len;
				for(int jk=1;jk<=4;jk++)
				{
					if(jk==3)
					{
						enemy[Enemy_num].Process[counter][jk]=atoi(scriptprocess[jk]);
						jk=4;
					}
					len=0;
					len=strlen(scriptprocess[jk]);
					enemy[Enemy_num].Process[counter][jk]=1;
					for(int i=0;i<len;i++)enemy[Enemy_num].Process[counter][jk]*=char_int(scriptprocess[jk][i]);
				}
				
				counter++;
			}
			else if(strcmp(scriptprocess[0],"load_data")==0)
			{
				enemy[Enemy_num].Process[counter][0]=8;
				enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[1]);
				enemy[Enemy_num].Process[counter][2]=1;
				for(int j=0;scriptprocess[2][j]!='\0';j++)
				enemy[Enemy_num].Process[counter][2]*=char_int(scriptprocess[2][j]);
				counter++;
			}
			else if(strcmp(scriptprocess[0],"set_varble")==0)
			{
				enemy[Enemy_num].Process[counter][0]=9;
				enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[1]);
				enemy[Enemy_num].Process[counter][2]=1;
				for(int j=0;scriptprocess[2][j]!='\0';j++)
				enemy[Enemy_num].Process[counter][2]*=char_int(scriptprocess[2][j]);	
				counter++;
			}
			else if(strcmp(scriptprocess[0],"updata_varble")==0)
			{
				enemy[Enemy_num].Process[counter][0]=10;
				if(scriptprocess[1][0]=='+')
				{
					enemy[Enemy_num].Process[counter][1]=9999;
				}
				else if(scriptprocess[1][0]=='-')
				{
					enemy[Enemy_num].Process[counter][1]=99999;
				}
				else
				{
					enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[1]);
				}
				enemy[Enemy_num].Process[counter][2]=1;
				for(int j=0;scriptprocess[2][j]!='\0';j++)
				enemy[Enemy_num].Process[counter][2]*=char_int(scriptprocess[2][j]);	
				counter++;
			}
			else if(strcmp(scriptprocess[0],"delete_varble")==0)
			{
				enemy[Enemy_num].Process[counter][0]=11;
				enemy[Enemy_num].Process[counter][1]=1;
				for(int j=0;scriptprocess[1][j]!='\0';j++)
				enemy[Enemy_num].Process[counter][1]*=char_int(scriptprocess[1][j]);	
				counter++;

			}
			else if(strcmp(scriptprocess[0],"alldelete_varble")==0)
			{
				enemy[Enemy_num].Process[counter][0]=12;
				counter++;
			}
			else if(strcmp(scriptprocess[0],"set_loadscript")==0)
			{
				enemy[Enemy_num].Process[counter][0]=13;
				enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[1]);
				counter++;

			}
			else if(strcmp(scriptprocess[0],"break_goto")==0)
			{
				enemy[Enemy_num].Process[counter][0]=14;
				enemy[Enemy_num].Process[counter][1]=1;
				for(int j=0;scriptprocess[1][j]!=0;j++)
				enemy[Enemy_num].Process[counter][1]*=char_int(scriptprocess[1][j]);
				counter++;

			}
			else if(strcmp(scriptprocess[0],"set_item")==0)
			{	
				enemy[Enemy_num].Process[counter][0]=15;
				enemy[Enemy_num].Process[counter][1]=atoi(scriptprocess[1]);
				enemy[Enemy_num].Process[counter][2]=atoi(scriptprocess[2]);
				enemy[Enemy_num].Process[counter][3]=atoi(scriptprocess[3]);
				counter++;
			}
			else if(strcmp(scriptprocess[0],"play_bgm")==0)
			{
				//スクリプトの終端4
				enemy[Enemy_num].Process[counter][0]=18;
				body->sound_bgm[1]=LoadSoundMem( scriptprocess[1] ) ;
				counter++;
				
			}
			else if(strcmp(scriptprocess[0],"stop_bgm")==0)
			{
				//スクリプトの終端4
				enemy[Enemy_num].Process[counter][0]=19;
				counter++;
				
			}
			else if(strcmp(scriptprocess[0],"set_enemy_end")==0)
			{
				//スクリプトの終端4
				enemy[Enemy_num].Process[counter][0]=99;
				counter++;
				
			}


			S_SP++;
			S_CP=0;
			
	}
	Enemy_num++;//画面上の敵の数を１増やす

	return 1;//不明終了（強制作成）
error:
	return -1;
}

int CGame_Enemy::DeleteAt_EnemyProcess(Enemy_SP *enemy,int num)
{
	if(enemy[num].Ghandle!=0)DeleteGraph( enemy[num].Ghandle ) ;
	//エネミーの処理が終わった際にその指令をずらす。
	for(int i=num;i<(Enemy_num-1);i++)
	{
		enemy[i]=enemy[i+1];
	}

	Enemy_num--;

	return 0;
}

int CGame_Enemy::Format(void)
{
	//球データーの読み込み
	Gbarrage[0]=LoadGraph( Gbarrage1 ) ;
	GetGraphSize( Gbarrage[0], &Gbarrage_wh[0][0], &Gbarrage_wh[0][1] ) ;
	Enemy_num=0;
	for(int i=0;i<(Max_Enemy+10);i++)
	{
		enemy_sp[i].barrage.max=0;
	}
	return 0;
}