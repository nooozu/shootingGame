#include "Menu.h"
#include "DxLib.h"

Menu::Menu(ISceneChanger* changer) : BaseScene(changer)
{
}

//èâä˙âª
void Menu::Initialize()
{
	select_mode = 0;
	image = LoadGraph("pic/title.png");
}

//çXêV
void Menu::Update(){
	BaseScene::Update();

	if (frame > 30) {
		if (CheckHitKey(KEY_INPUT_RETURN) != 0 || pad1_input.Buttons[12]) {
			//StartJoypadVibration(DX_INPUT_PAD1, 1000, 1000);
			switch (select_mode) {
			case 0:
				mSceneChanger->ChangeScene(eScene_Game);
				break;
			case 1:
				mSceneChanger->ChangeScene(eScene_Config);
				break;
			case 2:
				//ÉQÅ[ÉÄèIóπ
				break;
			}
		}

		if (CheckHitKey(KEY_INPUT_UP) ||
			pad1_input.Buttons[0]) {
			select_mode--;
			frame = 0;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) ||
			pad1_input.Buttons[1]) {
			select_mode++;
			frame = 0;
		}

		if (select_mode < 0) {
			select_mode = 1;
		}
		if (select_mode > 1) {
			select_mode = 0;
		}
	}
	else {
		frame++;
	}
}

//ï`âÊ
void Menu::Draw()
{
	DrawRotaGraph(640, 360, 14.0, 0.0, image, FALSE);
	//DrawFormatString(SCREEN_CENTER_X - 9*6, SCREEN_CENTER_Y - 9, GetColor(255, 255, 255), "DX_STOOTING!");

	if (select_mode == 0) {
		DrawFormatString(SCREEN_CENTER_X + 300 - 9, SCREEN_CENTER_Y + 100, GetColor(0, 255, 0), "Versus");
	}
	else {
		DrawFormatString(SCREEN_CENTER_X + 300, SCREEN_CENTER_Y + 100, GetColor(255, 255, 255), "Versus");
	}
	if (select_mode == 1) {
		DrawFormatString(SCREEN_CENTER_X + 300 - 9, SCREEN_CENTER_Y + 100 + 20, GetColor(0, 255, 0), "Config");
	}
	else{
		DrawFormatString(SCREEN_CENTER_X + 300, SCREEN_CENTER_Y + 100 + 20, GetColor(255, 255, 255), "Config");
	}
	/*
	if (select_mode == 2) {
		DrawFormatString(SCREEN_CENTER_X + 300 - 9, SCREEN_CENTER_Y + 100 + 40, GetColor(0, 255, 0), "Quit");
	}
	else {
		DrawFormatString(SCREEN_CENTER_X + 300, SCREEN_CENTER_Y + 100 + 40, GetColor(255, 255, 255), "Quit");
	}
	*/
}