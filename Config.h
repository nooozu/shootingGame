#pragma once
#include "BaseScene.h"
#include "SoundManager.h"

//設定画面クラス
class Config : public BaseScene {
private:
	SoundManager sound_mgr;
	int select_num, se_volume, bgm_volume;
	int button_frame;

public :
    Config(ISceneChanger* changer);
    void Initialize() override;    //初期化処理をオーバーライド。
    //void Finalize() override;        //終了処理をオーバーライド。
    void Update() override;        //更新処理をオーバーライド。
    void Draw() override;            //描画処理をオーバーライド。

};
