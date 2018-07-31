#include "Player.h"

Player::Player(int num, float tx, float ty, float tr, float ts_max)
{
	Initialize(tx, ty, tr, ts_max, "");
	life = MAX_LIFE;

	gun.SetPlayerNumber(num);
	gun.Initialize();

	pEmitter = new Emitter(this);

	sound_mgr.SetSE("sound/se/metal01.mp3");//消滅時
	sound_mgr.SetSE("sound/se/swords04.mp3");//ヒット時
	sound_mgr.SetSE("sound/se/status01.mp3");//slow

	invincible_frame = FIRST_INVICIBLE_FRAME;
}

Player::~Player()
{
	if (pEmitter) {
		delete pEmitter;
		pEmitter = NULL;
	}

	pTarget = NULL;
}

void Player::SetPlayerImage(int i, const char* c)
{
	image_mode[i] = LoadGraph(c);
}

void Player::Update()
{
	controller.Update();

	if (flag) {
		Move();
		Rotation();

		//弾を発射する
		if (!controller.GetLeftButton()) {
			if (CheckHitKey(KEY_INPUT_DOWN) || controller.GetRightButton()) {
				gun.Trigger(x, y, rad);

				//攻撃時に移動速度を制限する
				if (dx > ATTACK_MAX_ACCELERATION) {
					dx = ATTACK_MAX_ACCELERATION;
				}
				if (dx < -ATTACK_MAX_ACCELERATION) {
					dx = -ATTACK_MAX_ACCELERATION;
				}
				if (dy > ATTACK_MAX_ACCELERATION) {
					dy = ATTACK_MAX_ACCELERATION;
				}
				if (dy < -ATTACK_MAX_ACCELERATION) {
					dy = -ATTACK_MAX_ACCELERATION;
				}
			}
		}

		//キャラに移動量を足す
		x += dx;
		y += dy;

		//自機が死んだかを判断
		Dead();
	}

	//エミッタの更新
	pEmitter->Update();

	//弾の更新
	gun.Update();

	//画面外処理
	OnScreen();

	if (invincible_frame > 0) {
		invincible_frame--;
	}
}

void Player::Draw()
{
	if (flag) {
		if (invincible_frame % 6 < 4) {
			if (controller.GetLeftButton()) {
				DrawRotaGraph(x, y, 1.0, rad + DEG_TO_RAD(90), image_mode[5], TRUE);
			}
			else {
				switch (gun.GetBulletType()) {
				case normal:
					DrawRotaGraph(x, y, 1.0, rad + DEG_TO_RAD(90), image_mode[0], TRUE);
					break;
				case shot:
					DrawRotaGraph(x, y, 1.0, rad + DEG_TO_RAD(90), image_mode[1], TRUE);
					break;
				case reflect:
					DrawRotaGraph(x, y, 1.0, rad + DEG_TO_RAD(90), image_mode[2], TRUE);
					break;
				case rapid:
					DrawRotaGraph(x, y, 1.0, rad + DEG_TO_RAD(90), image_mode[3], TRUE);
					break;
				case slow:
					DrawRotaGraph(x, y, 1.0, rad + DEG_TO_RAD(90), image_mode[4], TRUE);
					break;
				}
			}
		}
		else {
			//DrawRotaGraph(x, y, 1.0, rad + DEG_TO_RAD(90), image, TRUE);
		}
	}

	pEmitter->Draw();

	gun.Draw();

	//DrawFormatString(x, y, GetColor(255, 255, 255), "ammo:%d", gun.GetAmmo());
	
	DrawLifeBar();
	DrawAmmo();
}

void Player::SetLifeBar(float px, float py, const TCHAR* image)
{
	life_bar.Initialize(px, py, 0, 0, image);
	life_bar_base_image = LoadGraph("pic/LifeBarBase.png");
}

void Player::DrawLifeBar()
{
	float bx, by, bbx;
	bx = life_bar.GetX();
	by = life_bar.GetY();

	for (int i = 0; i < MAX_LIFE; i++) {
		bbx = bx + ((i % 2 == 0) ? (-12) : (0));
		DrawRotaGraph(bbx, by + (i * 12), 2.0, 0, life_bar_base_image, TRUE);
	}
	for (int i = 0; i < life; i++) {
		bbx = bx + ((i % 2 == 0) ? (-12) : 0);
		DrawRotaGraph(bbx, by + (i * 12), 2.0, 0, life_bar.GetImage(), TRUE);
	}
}

void Player::DrawAmmo()
{
	float bx, by;

	bx = life_bar.GetX() - 15;
	by = life_bar.GetY() + 80;

	//DrawCircle(bx, by, 3, GetColor(0, 255, 0), FALSE);
	//DrawCircle(bx, by, 5, GetColor(255, 255, 0), FALSE);
	std::string s;
	switch (gun.GetBulletType())
	{
	case normal:
		s = "No";
		break;
	case shot:
		s = "Sh";
		break;
	case reflect:
		s = "Re";
		break;
	case rapid:
		s = "Ra";
		break;
	case slow:
		s = "Sl";
		break;
	default:
		s = "none";
		break;
	}

	DrawFormatString(bx, by, GetColor(255, 255, 255),"%s", s.c_str());
	DrawFormatString(bx - 10, by - 20, GetColor(255, 255, 255), "Type");
	
	DrawFormatString(bx - 10 , by + 40, GetColor(255, 255, 255), "Ammo");

	by += 65;

	if (gun.GetAmmo() == 0) {
		DrawFormatString(bx, by, GetColor(255, 255, 255), "∞");
	}
	else {
		for (int i = 0; i < gun.GetAmmo(); i++) {
			DrawBox(bx, by + (i * 5), bx + 6, by + 3 + (i * 5), GetColor(255, 255, 255), TRUE);
		}
	}
}

void Player::Move()
{
	if (controller.GetLeftButton()) {
		speed_max = 3;
	}
	else {
		speed_max = 2;
	}

	//移動（左スティック）
	if (controller.GetStick_LeftX() > STICK_SENSITIVITY) {
		if (dx < speed_max) {
			dx += ACCELERATION;
		}
	}
	else if (controller.GetStick_LeftX() < -STICK_SENSITIVITY) {
		if (dx > -speed_max) {
			dx -= ACCELERATION;
		}
	}
	else {
		if (dx > 0) {
			dx -= DECELERATION;
		}
		else if (dx < 0) {
			dx += DECELERATION;
		}
	}
	
	if (-controller.GetStick_LeftY() > 0.6) {
		if (dy < speed_max) {
			dy += ACCELERATION;
		}
	}
	else if (-controller.GetStick_LeftY() < -0.6) {
		if (dy > -speed_max) {
			dy -= ACCELERATION;
		}
	}
	else {
		if (dy > 0) {
			dy -= DECELERATION;
		}
		else if (dy < 0) {
			dy += DECELERATION;
		}
	}
}

void Player::Rotation()
{
	//回転（右スティック）
	if (controller.IsStickRDown()) {
		float current_rot = RAD_TO_DEG(rad);
		float stick_rot = controller.GetStickRightRotate();

		float sub = stick_rot - current_rot;
		sub -= floor(sub / 360.0) * 360.0;

		if (sub > 180.0) {
			sub -= 360.0;
		}
		if (sub < -180.0) {
			sub += 360.0;
		}

		float dif = sub * 0.2;
		if (dif > 2) {
			dif = 2;
		}
		if (dif < 2) {
			dif = -2;
		}

		current_rot += dif;
		rad = DEG_TO_RAD(current_rot);
	}
}

void Player::Dead()
{
	if (life <= 0) {
		pEmitter->ParticleGenerate(40);

		//弾をすべて消去
		gun.EraseAll();

		sound_mgr.PlaySE(0);

		flag = false;
	}
}

void Player::GiveDamage()
{
	life--;
	pEmitter->ParticleGenerate(5);
	sound_mgr.PlaySE(1);
	StartJoypadVibration(controller.GetGamePad(), 2000, 500);
	invincible_frame = DAMAGE_INVICIBLE_FRAME;
}

void Player::BulletHit(Gun& enemy_gun)
{
	if (flag) {
		if (invincible_frame <= 0) {
			for (auto itr = enemy_gun.bulletList.begin(); itr != enemy_gun.bulletList.end(); itr++) {
				if (itr->HitCheck(*this)) {
					GiveDamage();
					itr->SetFlag(false);
				}
			}

		}

        //slowがbulletを打ち消す
		for (auto itr = enemy_gun.slowList.begin(); itr != enemy_gun.slowList.end(); itr++) {

			for (auto bullet_itr = gun.bulletList.begin(); bullet_itr != gun.bulletList.end(); bullet_itr++) {

				
				if (itr->HitCheck(*bullet_itr)) {
					sound_mgr.PlaySE(2);
					bullet_itr->SetFlag(false);
				}

			}


			if (itr->HitCheck(*this)) {
				GiveDamage();
				itr->SetFlag(false);
			}
		}
	}
}