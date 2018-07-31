#pragma once
#include <list>
#include <vector>
#include "Bullet.h"
#include "PlayerConfig.h"
#include "SoundManager.h"

class Gun
{
private:
	int ammo;
	BulletType bullet_type;
	int num, frame;
	int bullet_image;
	int bullet_type_image[5];
	SoundManager sound_mgr;

public:
	std::vector<Bullet> bulletList;
	std::vector<Bullet> slowList;

	Gun();
	~Gun();

	void Initialize();
	void Update();
	void Draw();

	void SetBulletType(BulletType b);
	void SetPlayerNumber(int i) { num = i; }
	int GetAmmo() { return ammo; }
	int GetBulletCount() { return bulletList.size(); }
	BulletType GetBulletType() { return bullet_type; }

	void Trigger(int px, int py, float rad);
	void EraseAll();

	void SetBulletImage(int, const char*);
};