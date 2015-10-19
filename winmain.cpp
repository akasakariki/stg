#include "DxLib.h"
#include "main.h"
CMainLoop *mainloop;
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
	// 描画先画面を裏にする
	if(debug_mode==true)ChangeWindowMode( TRUE ) ;//デバッグモードのときのみウィンドウモードに変更する。

	

	if(DxLib_Init()==-1)
	{
		return -1;
	}
	SetDrawScreen( DX_SCREEN_BACK ) ;
	mainloop=new CMainLoop();//メインルーチンクラスのメモリ確保



	//メインループ
	while(mainloop->mainloop()==0)//FPS制御に関してはライブラリで自動的管理されるため無視するとする。
	{
		ScreenFlip() ;
		// 画面を初期化
		ClearDrawScreen() ;
		if(CheckHitKey( KEY_INPUT_F1 ) ){//緊急脱出用
			break;				
		}

	}

	delete mainloop;
	DxLib_End();
	return 0;
}

