#include "Game.h"

int Game::p1_win = 0;
int Game::p2_win = 0;

Game::Game(ISceneChanger* changer) : BaseScene(changer)
{
}

//‰Šú‰»
void Game::Initialize()
{
	frame = 0;
	select_mode = 0;
	fight = true;
	
	background = LoadGraph("pic/Background_cross.png");

	p1 = new Player(0, SCREEN_CENTER_X - 300, SCREEN_CENTER_Y, 12, 2);
	p1->SetLifeBar(32, 20, "pic/Particle_P1.png");
	p1->SetParticleImage("pic/Particle_P1.png");
	p1->controller.SetGamePad(DX_INPUT_PAD1);
	//p1->gun.SetBulletType(slow);
	p1->SetPlayerImage(0, "pic/Player_P1_Normal.png");
	p1->SetPlayerImage(1, "pic/Player_P1_Shot.png");
	p1->SetPlayerImage(2, "pic/Player_P1_Reflect.png");
	p1->SetPlayerImage(3, "pic/Player_P1_Rapid.png");
	p1->SetPlayerImage(4, "pic/Player_P1_Slow.png");
	p1->SetPlayerImage(5, "pic/Player_P1_Speed.png");

	p1->gun.SetBulletImage(0, "pic/Bullet_P1_Normal.png");
	p1->gun.SetBulletImage(1, "pic/Bullet_P1_Shot.png");
	p1->gun.SetBulletImage(2, "pic/Bullet_P1_Reflect.png");
	p1->gun.SetBulletImage(3, "pic/Bullet_P1_Rapid.png");
	p1->gun.SetBulletImage(4, "pic/Bullet_P1_Slow.png");

	p2 = new Player(1, SCREEN_CENTER_X + 300, SCREEN_CENTER_Y, 12, 2);
	p2->SetLifeBar(FIELD_RIGHT + 32, 20, "pic/Particle_P2.png");
	p2->SetParticleImage("pic/Particle_P2.png");
	p2->controller.SetGamePad(DX_INPUT_PAD2);
	p2->SetRad(DEG_TO_RAD(180));
	//p2->gun.SetBulletType(rapid);
	p2->SetPlayerImage(0, "pic/Player_P2_Normal.png");
	p2->SetPlayerImage(1, "pic/Player_P2_Shot.png");
	p2->SetPlayerImage(2, "pic/Player_P2_Reflect.png");
	p2->SetPlayerImage(3, "pic/Player_P2_Rapid.png");
	p2->SetPlayerImage(4, "pic/Player_P2_Slow.png");
	p2->SetPlayerImage(5, "pic/Player_P2_Speed.png");

	p2->gun.SetBulletImage(0, "pic/Bullet_P2_Normal.png");
	p2->gun.SetBulletImage(1, "pic/Bullet_P2_Shot.png");
	p2->gun.SetBulletImage(2, "pic/Bullet_P2_Reflect.png");
	p2->gun.SetBulletImage(3, "pic/Bullet_P2_Rapid.png");
	p2->gun.SetBulletImage(4, "pic/Bullet_P2_Slow.png");


	sound_mgr.SetBGM("sound/bgm/Žvl’ÇÕ.mp3");
	sound_mgr.PlayBGM(0);
}

void Game::Finalize()
{
	delete p1;
	delete p2;
}

//XV
void Game::Update()
{
	BaseScene::Update();

	p1->Update();
	p2->Update();

	if (fight) {
		item_mgr.Update();

		p1->BulletHit(p2->gun);
		p2->BulletHit(p1->gun);

		item_mgr.HitPlayer(*p1);
		item_mgr.HitPlayer(*p2);

		if (!p1->GetFlag()) {
			s_win = "P2";
			p2_win++;
			fight = false;
		}
		if (!p2->GetFlag()) {
			s_win = "P1";
			p1_win++;
			fight = false;
		}
	}
	else {
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0 ||
			pad1_input.Buttons[12]) {
			switch (select_mode) {
			case 0:
				mSceneChanger->ChangeScene(eScene_Game);
				break;
			case 1:
				mSceneChanger->ChangeScene(eScene_Menu);
				break;
			}
		}

		if (CheckHitKey(KEY_INPUT_UP) ||
			pad1_input.Buttons[0]) {
			select_mode = 0;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) ||
			pad1_input.Buttons[1]) {
			select_mode = 1;
		}
	}
}

//•`‰æ
void Game::Draw()
{
	//”wŒi
	DrawGraph(0, 0, background, FALSE);

	//UI˜g
	DrawBox(0, 0, FIELD_LEFT, FIELD_BOTTOM, GetColor(100, 100, 100), TRUE);
	DrawBox(FIELD_RIGHT, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GetColor(100, 100, 100), TRUE);

	p1->Draw();
	p2->Draw();
	item_mgr.Draw();

	if (!fight) {
		DrawFormatString(SCREEN_CENTER_X - 9*3, SCREEN_CENTER_Y - 40, GetColor(255, 255, 0), "%s WIN", s_win.c_str());

		if (select_mode == 0) {
			DrawFormatString(SCREEN_CENTER_X - 9*3, SCREEN_CENTER_Y, GetColor(0, 255, 0), "Replay");
		}
		else {
			DrawFormatString(SCREEN_CENTER_X - 9*3, SCREEN_CENTER_Y, GetColor(255, 255, 255), "Replay");
		}
		if (select_mode == 1) {
			DrawFormatString(SCREEN_CENTER_X - 9*6, SCREEN_CENTER_Y + 25, GetColor(0, 255, 0), "Back to Menu");
		}
		else {
			DrawFormatString(SCREEN_CENTER_X - 9*6, SCREEN_CENTER_Y + 25, GetColor(255, 255, 255), "Back to Menu");
		}

		DrawFormatString(SCREEN_CENTER_X - 200-9*6, SCREEN_CENTER_Y - 40, GetColor(255, 255, 255), "P1_WIN : %d", p1_win);
		DrawFormatString(SCREEN_CENTER_X + 200, SCREEN_CENTER_Y - 40, GetColor(255, 255, 255), "P2_WIN : %d", p2_win);
	}
}