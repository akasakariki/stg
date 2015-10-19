#include <fstream>
#include "main.h"
using namespace std;
int LoadFile(int FileNames,char *script,int cx)
{
	char FileName[256];
	wsprintf(FileName,"%s%d.%s",scriptF,FileNames,script_ext);
	fstream data_file;
	data_file.open(FileName);//ファイルオープン	
	if(data_file.fail())
	{
		//ファイルが存在しない（何ならかの原因で開けない）
		return -1;
	}

	int fsp=0;//スクリプト読み込みカウンタ
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
		else if(check==' ')//空白削除
		{

		}
		else
		{
			//body[fsp][fcp]=check;
			*(script+((fsp*cx)+fcp))=check;
			fcp++;
		}

	}


	data_file.close();//終了処理
	return 0;
}

