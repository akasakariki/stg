#pragma once
#include "DxLib.h"
#include "game_body.h"
#include "GM_Enemy.h"
#define script_ext	"sc"
#define scriptF	"script/"//スクリプトフォルダーの指定 
#define FileNameLEN	80
#define debug_mode	true//デバッグモードの設定
#define PI	3.141593
enum GAMEMODE//ゲームモードの種類
{
	GMODE_TITLE=1,GMODE_LOAD,GMODE_BODY,GMODE_CONFIG,GMODE_GAMEOVER,GMODE_END
};
class CMainLoop
{

	protected:
		GAMEMODE gmode;//モード
		GAMEMODE setGameMode(GAMEMODE mode);//ゲームモードを設定する
		virtual void title(void);//タイトルモード
		virtual void load(void);//スクリプトファイルロードモード
		virtual void body(void);//ゲームモード
		virtual void config(void);//設定モード
		virtual void gameover(void);//ゲームオーバー
		virtual void end(void);//終了処理・・・いらないかも
		//変数関係
		int loadingF;//ローディングフラグ
		char Load_FileName[FileNameLEN];//ロードファイル名の記憶用
		int loading_format;//初期化フラグ
		CGame_Body gmbody;
		CGame_Enemy enemy;
		int menu_img[5];
		int menu_bgm[2];
	public:
		//メインループ
		int mainloop(void);
};
extern long char_int(char moji);

//int FileNames=ファイル名(半角数字のみ)
//char script=読み込み先のスクリプトcharの先頭アドレス
//int cx=２次元配列の確保領域（１行分の最大文字数）
extern int LoadFile(int FileNames,char *script,int cx);