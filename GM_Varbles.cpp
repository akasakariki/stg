#include "GM_Varble.h"

//�ϐ��쐬
void CVarble::Add_varbles(int num, int name)
{
	if(Max<=MAX_ADD)
	{
		varbles[Max].body=num;
		varbles[Max].name=name;
		Max++;
	}
	else
	{
		//�ϐ�����l���E
	}
}
//�ϐ��폜�i��
void CVarble::Delete_varbles(int name)
{
	for(int i=0;i<Max;i++)
	{
		if(varbles[i].name==name)
		{
			for(int k=name;k<Max;k++)
			{
				varbles[k]=varbles[k+1];
			}
			break;
		}
	}
	//�G���[

}
void CVarble::Move_varbles(int num, int name)
{
	for(int i=0;i<Max;i++)
	{
		if(varbles[i].name==name)
		{
			varbles[i].body=num;
			break;
		}
	}
}

int  CVarble::Return_varbles(int name)
{
	for(int i=0;i<Max;i++)
	{
		if(varbles[i].name==name)
		{
			return varbles[i].body;
		}
	}	
	return -1;
}

void CVarble::Alldelete_varbles()
{
	while(Max<=0)
	{
		varbles[Max].name=0;
		varbles[Max].body=0;
	}
	Max=0;
}

void CVarble::Reset_varbles()
{
	Max=(MAX_ADD-1);
	Alldelete_varbles();

}