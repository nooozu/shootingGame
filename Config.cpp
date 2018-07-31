#include "Config.h"
#include "DxLib.h"

Config::Config(ISceneChanger* changer) : BaseScene(changer)
{
}

//初期化
void Config::Initialize()
{
	select_num = 0;
	button_frame = 0;
	se_volume = sound_mgr.GetSEVolume();
	bgm_volume = sound_mgr.GetBGMVolume();
}

//更新
void Config::Update(){
	BaseScene::Update();

	if (button_frame > 30) {
		if (pad1_input.Buttons[0]) {
			button_frame = 0;
			select_num--;
		}
		if (pad1_input.Buttons[1]) {
			button_frame = 0;
			select_num++;
		}
	}
	else {
		button_frame++;
	}
	if (select_num < 0) {
		select_num = 1;
	}
	if (select_num > 1) {
		select_num = 0;
	}

	if (pad1_input.Buttons[2]) {
		if (select_num == 0) {
			bgm_volume--;
		}
		if (select_num == 1) {
			se_volume--;
		}
	}
	if (pad1_input.Buttons[3]) {
		if (select_num == 0) {
			bgm_volume++;
		}
		if (select_num == 1) {
			se_volume++;
		}
	}

	if (bgm_volume < 0) {
		bgm_volume = 0;
	}
	if (bgm_volume > 100) {
		bgm_volume = 100;
	}
	if (se_volume < 0) {
		se_volume = 0;
	}
	if (se_volume > 100) {
		se_volume = 100;
	}

    if (pad1_input.Buttons[13]) {
		sound_mgr.SetBGMVolume(bgm_volume);
		sound_mgr.SetSEVolume(se_volume);
		mSceneChanger->ChangeScene(eScene_Menu);
    }
}

//描画
void Config::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Bボタンで戻る");

	DrawFormatString(SCREEN_CENTER_X - 9*3, SCREEN_CENTER_Y - 9, GetColor(255, 255, 255), "Config");

	if (select_num == 0) {
		DrawFormatString(SCREEN_CENTER_X - 9 * 3, SCREEN_CENTER_Y + 18, GetColor(0, 255, 0), "BGM : %3d", bgm_volume);
	}
	else {
		DrawFormatString(SCREEN_CENTER_X - 9 * 3, SCREEN_CENTER_Y + 18, GetColor(255, 255, 255), "BGM : %3d", bgm_volume);
	}
	if (select_num == 1) {
		DrawFormatString(SCREEN_CENTER_X - 9 * 3, SCREEN_CENTER_Y + 18 * 2, GetColor(0, 255, 0), " SE : %3d", se_volume);
	}
	else {
		DrawFormatString(SCREEN_CENTER_X - 9 * 3, SCREEN_CENTER_Y + 18 * 2, GetColor(255, 255, 255), " SE : %3d", se_volume);
	}
}
