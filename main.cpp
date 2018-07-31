#include "DxLib.h"
#include "Fps.h"
#include "DefaultConfig.h"
#include "SceneMgr.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	ChangeWindowMode(TRUE);
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Fps fps;

    SceneMgr sceneMgr;
    sceneMgr.Initialize();

	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0){//画面更新 & メッセージ処理 & 画面消去

		fps.Update();

		DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GetColor(42, 42, 42), TRUE);

        sceneMgr.Update();  //更新
        sceneMgr.Draw();    //描画

		//DrawLine(0, SCREEN_CENTER_Y, SCREEN_WIDTH, SCREEN_CENTER_Y, GetColor(0, 255, 0));
		//DrawLine(SCREEN_CENTER_X, 0, SCREEN_CENTER_X, SCREEN_HEIGHT, GetColor(0, 255, 0));

		//fps.Draw();
		fps.Wait();
    }

    sceneMgr.Finalize();

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}