#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"

#include "Player.h"
#include "ItemManager.h"
#include "SoundManager.h"

//ゲーム画面クラス
class Game : public BaseScene {
private:
	static int p1_win, p2_win;

	int frame, select_mode;
	bool fight;
	std::string s_win;

	Player *p1, *p2;
	SoundManager sound_mgr;
	ItemManager item_mgr;

	int background;

public :
    Game::Game(ISceneChanger* changer);
    void Initialize() override;    //初期化処理をオーバーライド。
    void Finalize() override;        //終了処理をオーバーライド。
    void Update() override;        //更新処理をオーバーライド。
    void Draw() override;            //描画処理をオーバーライド。

};
