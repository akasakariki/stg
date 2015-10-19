#include "DxLib.h"
#include "main.h"
CMainLoop *mainloop;
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
	// �`����ʂ𗠂ɂ���
	if(debug_mode==true)ChangeWindowMode( TRUE ) ;//�f�o�b�O���[�h�̂Ƃ��̂݃E�B���h�E���[�h�ɕύX����B

	

	if(DxLib_Init()==-1)
	{
		return -1;
	}
	SetDrawScreen( DX_SCREEN_BACK ) ;
	mainloop=new CMainLoop();//���C�����[�`���N���X�̃������m��



	//���C�����[�v
	while(mainloop->mainloop()==0)//FPS����Ɋւ��Ă̓��C�u�����Ŏ����I�Ǘ�����邽�ߖ�������Ƃ���B
	{
		ScreenFlip() ;
		// ��ʂ�������
		ClearDrawScreen() ;
		if(CheckHitKey( KEY_INPUT_F1 ) ){//�ً}�E�o�p
			break;				
		}

	}

	delete mainloop;
	DxLib_End();
	return 0;
}

