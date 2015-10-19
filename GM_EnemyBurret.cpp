#include "GM_Enemy.h"
#include "GM_Varble.h"
#include "main.h"
#include <math.h>
#include "GM_Item.h"
void Sincurve_Enemy(int* x,int* y,int counter_dist,int flo);
void Sincurve2_Enemy(int* x,int* y,int counter_dist,int flo);
void Coscurve_Enemy(int* x,int* y,int counter_dist,int flo);
void Coscurve2_Enemy(int* x,int* y,int counter_dist,int flo);
//Max_Enemy
void CGame_Enemy::Enemy_Processin(Enemy_SP *enemy)
{
					int a,b,c;
					int flag_a=0;
					int body_a=0;
					int gla=0;
//�G�̏������ЂƂ����s
	if(Enemy_num!=0)
	{
		for(int i=0;i<Enemy_num;i++)
		{

			switch(enemy[i].Process[enemy[i].pro][0])//�p�^�[������
			{
			case 0://�ړ�����
				if(enemy[i].Process[enemy[i].pro][3]==0)
				{
					enemy[i].Process[enemy[i].pro][3]=200;
				}
				if(enemy[i].Process[enemy[i].pro][1]>enemy[i].x)
				{
					int xs=(enemy[i].Process[enemy[i].pro][1]-enemy[i].x)/enemy[i].Process[enemy[i].pro][3];
					enemy[i].x=enemy[i].x+xs;
				}
				else
				{
					int xs=(enemy[i].x-enemy[i].Process[enemy[i].pro][1])/enemy[i].Process[enemy[i].pro][3];
					enemy[i].x=enemy[i].x-xs;
				}
				if(enemy[i].Process[enemy[i].pro][2]>enemy[i].y)
				{
					int ys=(enemy[i].Process[enemy[i].pro][2]-enemy[i].y)/enemy[i].Process[enemy[i].pro][3];
					enemy[i].y=enemy[i].y+ys;
				}
				else
				{
					int ys=(enemy[i].y-enemy[i].Process[enemy[i].pro][2])/enemy[i].Process[enemy[i].pro][3];
					enemy[i].y=enemy[i].y-ys;
				}
				enemy[i].Process[enemy[i].pro][3]--;
				if(enemy[i].Process[enemy[i].pro][3]<=0)
				{
					enemy[i].pro++;
				}
				break;
			case 1://�s���p�^�[���w��
					enemy[i].pattern[0]=enemy[i].Process[enemy[i].pro][1];
					enemy[i].pattern_process=-1;
					enemy[i].pattern[1]=enemy[i].Process[enemy[i].pro][2];
					enemy[i].pattern_speed=enemy[i].Process[enemy[i].pro][3];
					enemy[i].pro++;
				break;
			case 2:
				enemy[i].barrage.speed[enemy[i].pro]=enemy[i].Process[enemy[i].pro][2];//�X�s�[�h
				Bullet_check(enemy[i].barrage,
					enemy[i].Process[enemy[i].pro][1],//�p�^�[��
					enemy[i].Process[enemy[i].pro][4],//�U���l
					enemy[i].Process[enemy[i].pro][3],//����
					enemy[i].Process[enemy[i].pro][2],//�e�̃X�s�[�h
					enemy[i].x,
					enemy[i].y,
					&enemy[i]
					);
					enemy[i].pro++;
				break;
			case 3://Wait
				if(time_flag!=0)
				{
					time_dest=enemy[i].Process[enemy[i].pro][1];
					time_flag=0;
				}

				time_dest--;
				if(time_dest<=0)
				{
					time_flag=1;
					enemy[i].pro++;
				}
				break;
			case 4:
				enemy[i].pro++;//�X���[
				break;
			case 5:
				//goto���x��
				if(enemy[i].flag_break==1)
				{
					enemy[i].flag_break=0;
					break;
				}
				for(int ikk=0;ikk<50;ikk++)
				{
					if(enemy[i].Process[ikk][0]==4)//���x��
					{
						if(enemy[i].Process[ikk][1]==enemy[i].Process[enemy[i].pro][1])
						{
							//���S��v
							enemy[i].pro=ikk;
						}
					}
				}
				enemy[i].pro++;
				break;
			case 6:
				//Ifgoto(�ϐ��ƕϐ�)
				
				a=b=c=0;
				a=varble_body.Return_varbles(enemy[i].Process[enemy[i].pro][1]);
				b=enemy[i].Process[enemy[i].pro][2];
				c=varble_body.Return_varbles(enemy[i].Process[enemy[i].pro][3]);
				if(b==char_int('>'))
				{
					if(a>c)
					{
						flag_a=1;
					}
				}
				else if(b==char_int('<'))
				{
					if(a<c)
					{
						flag_a=1;
					}
				}
				else if(b==char_int('='))
				{
					if(a==c)
					{
						flag_a=1;
					}
				}

				if(flag_a==1)
				{
					//�W�����v
					for(int ikk=0;ikk<50;ikk++)
					{
						if(enemy[i].Process[ikk][0]==5)//���x��
						{
							if(enemy[i].Process[ikk][1]==enemy[i].Process[enemy[i].pro][4])
							{
								//���S��v
								enemy[i].pro=ikk;
							}
						}
					}
				}
				enemy[i].pro++;
				break;
			case 7:
				a=b=c=0;
				flag_a=0;
				a=varble_body.Return_varbles(enemy[i].Process[enemy[i].pro][1]);
				b=enemy[i].Process[enemy[i].pro][2];
				c=enemy[i].Process[enemy[i].pro][3];
				if(b==char_int('>'))
				{
					if(a>c)
					{
						flag_a=1;
					}
				}
				else if(b==char_int('<'))
				{
					if(a<c)
					{
						flag_a=1;
					}
				}
				else if(b==char_int('='))
				{
					if(a==c)
					{
						flag_a=1;
					}
				}
				if(flag_a==1)
				{
					//�W�����v
					for(int ikk=0;ikk<50;ikk++)
					{
						if(enemy[i].Process[ikk][0]==5)//���x��
						{
							if(enemy[i].Process[ikk][1]==enemy[i].Process[enemy[i].pro][4])
							{
								//���S��v
								enemy[i].pro=ikk;
							}
						}
					}
				}
				enemy[i].pro++;
				break;
			case 8:
				//�e�f�[�^�[�̃��[�h
				body_a=0;
					switch(enemy[i].Process[enemy[i].pro][1])
					{
					case 1:
						//�v���C���[��HP
						body_a=body->enemy_hp;
						break;
					case 2:
						//�v���C����X�ʒu
						body_a=body->enemy_x;
						break;
					case 3:
						//�v���C����Y�ʒu
						body_a=body->enemy_y;
						break;
					case 5:
						//�v���C���V�t�g�L�[����
						body_a=body->shift_key;
						break;
					case 6:
						//�G��X�ʒu
						body_a=enemy[i].x;
						break;
					case 7:
						//�G��Y�ʒu
						body_a=enemy[i].y;
						break;
					case 8:
						//�G��HP
						body_a=enemy[i].HP;
						break;

					}
				varble_body.Move_varbles(body_a,enemy[i].Process[enemy[i].pro][2]);
				//Move_varbles(enemy[i].Process[enemy[i].pro][1],enemy[i].Process[enemy[i].pro][2]);
				enemy[i].pro++;
				break;
			case 9:
				varble_body.Add_varbles(enemy[i].Process[enemy[i].pro][1],enemy[i].Process[enemy[i].pro][2]);
				enemy[i].pro++;
				break;
			case 10:
				if(enemy[i].Process[enemy[i].pro][1]==9999)
				{
					int ad=0;
					ad=varble_body.Return_varbles(enemy[i].Process[enemy[i].pro][2]);
					ad++;
					varble_body.Move_varbles(ad,enemy[i].Process[enemy[i].pro][2]);
					//++

				}
				else if(enemy[i].Process[enemy[i].pro][1]==99999)
				{
					//--
					int ad=0;
					ad=varble_body.Return_varbles(enemy[i].Process[enemy[i].pro][2]);
					ad--;
					varble_body.Move_varbles(ad,enemy[i].Process[enemy[i].pro][2]);
				}
				else
				{
					varble_body.Move_varbles(enemy[i].Process[enemy[i].pro][1],enemy[i].Process[enemy[i].pro][2]);
				}
				enemy[i].pro++;
				break;
			case 11:
				varble_body.Delete_varbles(enemy[i].Process[enemy[i].pro][1]);
				enemy[i].pro++;
				break;
			case 12:
				varble_body.Alldelete_varbles();
				enemy[i].pro++;
				break;
			case 13:
				//���[�h�X�N���v�g�t�@�C��
				ScriptAddProcess_Enemy(enemy,enemy[i].Process[enemy[i].pro][1]);
				enemy[i].pro++;
				break;
			case 14:
				enemy[i].pro++;
				break;
			case 15://�A�C�e���̎ˏo
				gla=0;
				gla=item.Glaphic_ID_check(enemy[i].Process[enemy[i].pro][3]);
				item.Set_Item(enemy[i].x,enemy[i].y,&body->item_g[gla],enemy[i].Process[enemy[i].pro][1],enemy[i].Process[enemy[i].pro][2],enemy[i].Process[enemy[i].pro][3]);
				enemy[i].pro++;
				break;
			case 18://BGM�Đ�
				StopSoundMem( body->sound_bgm[0]) ;
				DeleteSoundMem( body->sound_bgm[0] ) ;
				body->sound_bgm[0]=body->sound_bgm[1];
				PlaySoundMem(body->sound_bgm[0],DX_PLAYTYPE_LOOP);
				enemy[i].pro++;
				break;
			case 19://BGM��~
				StopSoundMem( body->sound_bgm[0]) ;
				enemy[i].pro++;
				break;

			case 99:
				//�폜����
				DeleteAt_EnemyProcess(enemy,i);
				break;

			}
		}
	}
}



void CGame_Enemy::Bullet_check(Barrage &barrage,int pattern,int attacknum,int barragenum,int speed,int x,int y,Enemy_SP* enemy_sp)
{
	int keisan1=0;
	int keisan2=0;
	float temp=0.0f;
	//���̔���
	if(barrage.max<50)//�e���T�O�ȉ���������e�ǉ�
	{
		switch(pattern)
		{
		case 1://����
			//���x���P�͒������[�h
			if(barragenum>1)
			{
				
				keisan1=(barragenum+1)/2;
				temp=((barragenum+1)/2)-keisan1;
				if(temp>=0.5)keisan1++;
				keisan2=(enemy_sp->h*2)/barragenum;
				for(int ji=1;ji<keisan1;ji++)
				{
					Set_bur1(x+(ji*keisan2),(y+(enemy_sp->h/2))-(ji*keisan2),speed,attacknum,&barrage);
					Set_bur1(x+(ji*keisan2),(y+(enemy_sp->h/2))+(ji*keisan2),speed,attacknum,&barrage);
				}

			}
			else
			{
				Set_bur1(x,y+(enemy_sp->h/2),speed,attacknum,&barrage);
			}
			break;
		case 2://Sin�e
				Set_bur2(x,y+(enemy_sp->h/2),speed,attacknum,&barrage);
			break;
		case 3://-Sin�e
				Set_bur3(x,y+(enemy_sp->h/2),speed,attacknum,&barrage);
			break;
		case 4://Cos�e+(-Cos�e)
				Set_bur4(x,y+(enemy_sp->h/2),speed,attacknum,&barrage);
				Set_bur5(x,y+(enemy_sp->h/2),speed,attacknum,&barrage);
		}

	}




}

void CGame_Enemy::Bullet_process(Barrage &enemy_barrage)
{
	//�`�ʂ����˂�
	if(enemy_barrage.max>0)
	{
		for(int i=0;i<enemy_barrage.max;i++)
		{
			if(enemy_barrage.x[i]>640)
			{
				DeleteAt_Burreage(&enemy_barrage,i);
			
			}
			switch(enemy_barrage.pattern[i])	
			{
			case 1:
				enemy_barrage.x[i]-=enemy_barrage.speed[i];
				//DrawGraph( enemy_barrage.x[i],enemy_barrage.y[i] , Gbarrage[0], true ) ;

				break;
			case 2://Sin
				enemy_barrage.counter[i]+=enemy_barrage.speed[i];
				Sincurve_Enemy(&enemy_barrage.x[i],&enemy_barrage.y[i],enemy_barrage.counter[i],enemy_barrage.speed[i]);
				if(enemy_barrage.counter[i]>360)
				{
					enemy_barrage.counter[i]=0;
				}
				break;
			case 3://-Sin
				enemy_barrage.counter[i]+=enemy_barrage.speed[i];
				Sincurve2_Enemy(&enemy_barrage.x[i],&enemy_barrage.y[i],enemy_barrage.counter[i],enemy_barrage.speed[i]);
				if(enemy_barrage.counter[i]>360)
				{
					enemy_barrage.counter[i]=0;
				}

				break;
			case 4://Cos
				enemy_barrage.counter[i]+=enemy_barrage.speed[i];
				Coscurve_Enemy(&enemy_barrage.x[i],&enemy_barrage.y[i],enemy_barrage.counter[i],enemy_barrage.speed[i]);
				if(enemy_barrage.counter[i]>360)
				{
					enemy_barrage.counter[i]=0;
				}

				break;
			case 5://-Cos
				enemy_barrage.counter[i]+=enemy_barrage.speed[i];
				Coscurve2_Enemy(&enemy_barrage.x[i],&enemy_barrage.y[i],enemy_barrage.counter[i],enemy_barrage.speed[i]);
				if(enemy_barrage.counter[i]>360)
				{
					enemy_barrage.counter[i]=0;
				}

				break;
			}
			DrawTurnGraph( enemy_barrage.x[i],enemy_barrage.y[i] , Gbarrage[0], true ) ;
			//�Փ˔���
			if(body->reset_timer>=Reset_Counter)
			{
			if((body->enemy_x+body->centerG_CX+ActorCenter_CX)>=enemy_barrage.x[i]&&(body->enemy_x+ActorCenter_CX)<=(enemy_barrage.x[i]))//X�l��v�i�͈͈ȓ��j
				{
					if(((body->enemy_y+body->centerG_CY+ActorCenter_CY)>=enemy_barrage.y[i]+(enemy_barrage.GSize_Y/2)))//Y�l��v�i���S�͈͈ȓ��j
					{
						//�Փ˂Ɣ���
						if((body->enemy_y+ActorCenter_CY)<=(enemy_barrage.y[i]+(enemy_barrage.GSize_Y/2)))
						{
							body->enemy_hp-=enemy_barrage.attacknum[i];//�U���l��]
							DeleteAt_Burreage(&enemy_barrage,i);//���������e������

						}
					}
				}
			}
		}
	}




}


int CGame_Enemy::DeleteAt_Burreage(Barrage *enemy_barrage,int i)
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

void Sincurve_Enemy(int* x,int* y,int counter_dist,int flo)//Sin
{
	//int counter=counter_dist%180;//�����W�O
	*y+=sin(counter_dist* PI / 180)*4;
    *x-=flo;
	
}

void Sincurve2_Enemy(int* x,int* y,int counter_dist,int flo)//-Sin
{
	//int counter=counter_dist%180;//�����W�O
	*y+=sin(counter_dist* PI / 180)*-4;
    *x-=flo;
	
}

void Coscurve_Enemy(int* x,int* y,int counter_dist,int flo)//Cos
{
	//int counter=counter_dist%180;//�����W�O
	*y+=cos(counter_dist* PI / 180)*4;
    *x-=flo;
	
}

void Coscurve2_Enemy(int* x,int* y,int counter_dist,int flo)//-Cos
{
	//int counter=counter_dist%180;//�����W�O
	*y+=cos(counter_dist* PI / 180)*-4;
    *x-=flo;
	
}

//�������[�h
void CGame_Enemy::Set_bur1(int x,int y,int speed,int attacknum,Barrage *barrage)
{
		barrage->speed[barrage->max]=speed;
		barrage->x[barrage->max]=x;
		barrage->y[barrage->max]=y;
		barrage->pattern[barrage->max]=1;//�p�^�[���P
		barrage->GSize_X=Gbarrage_wh[0][0];
		barrage->GSize_Y=Gbarrage_wh[0][1];
		barrage->attacknum[barrage->max]=attacknum;
		barrage->max++;
}
//Sin���[�h
void CGame_Enemy::Set_bur2(int x,int y,int speed,int attacknum,Barrage *barrage)
{
		barrage->alpha[barrage->max]=0;
		barrage->speed[barrage->max]=enemy_speed/2;
		barrage->GSize_X=Gbarrage_wh[0][0];
		barrage->GSize_Y=Gbarrage_wh[0][1];
		barrage->x[barrage->max]=x;
		barrage->y[barrage->max]=y;
		barrage->attacknum[barrage->max]=attacknum;
		barrage->pattern[barrage->max]=2;//�p�^�[��2
		barrage->counter[barrage->max]=0;
		barrage->max++;
}
//-Sin���[�h
void CGame_Enemy::Set_bur3(int x,int y,int speed,int attacknum,Barrage *barrage)
{
		barrage->alpha[barrage->max]=0;
		barrage->speed[barrage->max]=enemy_speed/2;
		barrage->GSize_X=Gbarrage_wh[0][0];
		barrage->GSize_Y=Gbarrage_wh[0][1];
		barrage->x[barrage->max]=x;
		barrage->y[barrage->max]=y;
		barrage->attacknum[barrage->max]=attacknum;
		barrage->pattern[barrage->max]=3;//�p�^�[��3
		barrage->counter[barrage->max]=0;
		barrage->max++;
}
//Cos���[�h
void CGame_Enemy::Set_bur4(int x,int y,int speed,int attacknum,Barrage *barrage)
{
		barrage->alpha[barrage->max]=0;
		barrage->speed[barrage->max]=enemy_speed/2;
		barrage->GSize_X=Gbarrage_wh[0][0];
		barrage->GSize_Y=Gbarrage_wh[0][1];
		barrage->x[barrage->max]=x;
		barrage->y[barrage->max]=y;
		barrage->attacknum[barrage->max]=attacknum;
		barrage->pattern[barrage->max]=4;//�p�^�[��4
		barrage->counter[barrage->max]=0;
		barrage->max++;
}

//-Cos���[�h
void CGame_Enemy::Set_bur5(int x,int y,int speed,int attacknum,Barrage *barrage)
{
		barrage->alpha[barrage->max]=0;
		barrage->speed[barrage->max]=enemy_speed/2;
		barrage->GSize_X=Gbarrage_wh[0][0];
		barrage->GSize_Y=Gbarrage_wh[0][1];
		barrage->x[barrage->max]=x;
		barrage->y[barrage->max]=y;
		barrage->attacknum[barrage->max]=attacknum;
		barrage->pattern[barrage->max]=5;//�p�^�[��5
		barrage->counter[barrage->max]=0;
		barrage->max++;
}