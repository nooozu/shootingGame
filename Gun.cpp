#include "Gun.h"

Gun::Gun()
{
	sound_mgr.SetSE("sound/se/GUN_SE/shotgun-reload.mp3");//弾のリロード
	sound_mgr.SetSE("sound/se/GUN_SE/M1 Garand Single.mp3");//弾の発射
	sound_mgr.SetSE("sound/se/GUN_SE/M4A1_Single.mp3");//shotの発射音
	sound_mgr.SetSE("sound/se/GUN_SE/Skorpion.mp3");//反射弾の発射
	sound_mgr.SetSE("sound/se/GUN_SE/pistol01.mp3");//rapidの発射音
	sound_mgr.SetSE("sound/se/GUN_SE/shotgun.mp3");//rapidの発射音
}

Gun::~Gun()
{
}

void Gun::Initialize()
{
	switch (num) {
	case 0:
		bullet_image = LoadGraph("pic/BulletGreen.png");
		break;
	case 1:
		bullet_image = LoadGraph("pic/BulletLightBlue.png");
		break;
	}

	bullet_type = normal;
	ammo = 0;
}

void Gun::Update()
{
	//残弾数がない場合ノーマルにする
	if (!normal) {
		if (ammo <= 0) {
			bullet_type = normal;
		}
	}

	for (auto itr = bulletList.begin(); itr != bulletList.end();) {
		itr->Update();//更新処理

		//Bulletの消滅処理
		if (!itr->GetFlag()) {
			itr = bulletList.erase(itr);
		}
		else {
			itr++;
		}
	}

	for (auto itr = slowList.begin(); itr != slowList.end();) {
		itr->Update();//更新処理

		//slowの消滅処理
		if (!itr->GetFlag()) {
			itr = slowList.erase(itr);
		}
		else {
			itr++;
		}
	}

	frame++;
}

void Gun::Draw()
{
	for (auto itr = bulletList.begin(); itr != bulletList.end(); itr++) {
		itr->Draw();//描画処理
	}

	for (auto itr = slowList.begin(); itr != slowList.end(); itr++) {
		itr->Draw();//描画処理
	}
}

void Gun::Trigger(int px, int py, float rad)
{
	switch (bullet_type) {
	case normal:
		if (frame > BULLET_INTERVAL_NORMAL) {
			Bullet* p = new Bullet(px, py, rad, bullet_type_image[0]);
			p->SetSpeed(BULLET_SPEED_NORMAL);
			p->SetRadius(BULLET_RADIUS_NORMAL);
			bulletList.push_back(*p);
			delete p;
			p = NULL;

			sound_mgr.PlaySE(1);
			frame = 0;
		}
		break;
	case shot:
		if (frame > BULLET_INTERVAL_SHOT) {
			Bullet* p = new Bullet(px, py, 0, bullet_type_image[1]);
			for (int i = 0; i < 5; i++) {
				float r = rad + DEG_TO_RAD((i * 5 - 10));
				p->SetSpeed(BULLET_SPEED_SHOT);
				p->SetRadius(BULLET_RADIUS_SHOT);
				p->SetAngle(r);
				bulletList.push_back(*p);

				ammo--;
			}
			delete p;
			p = NULL;

			sound_mgr.PlaySE(2);
			frame = 0;
		}
		break;
	case reflect:
		if (frame > BULLET_INTERVAL_REFLECT) {
			Bullet* p = new Bullet(px, py, rad, bullet_type_image[2]);
			p->SetReflect(true);
			p->SetSpeed(BULLET_SPEED_REFLECT);
			p->SetRadius(BULLET_RADIUS_REFLECT);
			bulletList.push_back(*p);
			delete p;
			p = NULL;

			ammo--;
			sound_mgr.PlaySE(3);
			frame = 0;
		}
		break;
	case rapid:
		if (frame > BULLET_INTERVAL_RAPID) {
			Bullet* p = new Bullet(px, py, rad, bullet_type_image[3]);
			float r = rad + DEG_TO_RAD((GetRand(20) - 10));
			p->SetRad(r);
			p->SetRapid(true);
			p->SetSpeed(BULLET_SPEED_RAPID);
			p->SetRadius(BULLET_RADIUS_RAPID);
			bulletList.push_back(*p);
			delete p;
			p = NULL;

			ammo--;
			sound_mgr.PlaySE(4);
			frame = 0;
		}
		break;
	case slow:
		if (frame > BULLET_INTERVAL_SLOW) {
			Bullet* p = new Bullet(px, py, rad, bullet_type_image[4]);
			p->SetSpeed(BULLET_SPEED_SLOW);
			p->SetRadius(BULLET_RADIUS_SLOW);
			slowList.push_back(*p);
			delete p;
			p = NULL;

			ammo--;
			sound_mgr.PlaySE(5);
			frame = 0;
		}
		break;
	}
}

void Gun::EraseAll()
{
	bulletList.clear();
	slowList.clear();
}

void Gun::SetBulletType(BulletType b)
{
	bullet_type = b;
	switch (bullet_type) {
	case shot:
		ammo = BULLET_AMMO_SHOT;
		break;
	case reflect:
		ammo = BULLET_AMMO_REFLECT;
		break;
	case rapid:
		ammo = BULLET_AMMO_RAPID;
		break;
	case slow:
		ammo = BULLET_AMMO_SLOW;
		break;
	}
	sound_mgr.PlaySE(0);
}

void Gun::SetBulletImage(int i, const char* c)
{
	bullet_type_image[i] = LoadGraph(c);
}