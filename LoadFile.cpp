#include <fstream>
#include "main.h"
using namespace std;
int LoadFile(int FileNames,char *script,int cx)
{
	char FileName[256];
	wsprintf(FileName,"%s%d.%s",scriptF,FileNames,script_ext);
	fstream data_file;
	data_file.open(FileName);//�t�@�C���I�[�v��	
	if(data_file.fail())
	{
		//�t�@�C�������݂��Ȃ��i���Ȃ炩�̌����ŊJ���Ȃ��j
		return -1;
	}

	int fsp=0;//�X�N���v�g�ǂݍ��݃J�E���^
	int fcp=0;
	char check;
	while(!data_file.eof())
	{
		data_file.get(check);
		if(check=='\n')
		{
			fcp=0;
			fsp++;
		}
		else if(check==' ')//�󔒍폜
		{

		}
		else
		{
			//body[fsp][fcp]=check;
			*(script+((fsp*cx)+fcp))=check;
			fcp++;
		}

	}


	data_file.close();//�I������
	return 0;
}

