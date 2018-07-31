#pragma once
#include "PlayerConfig.h"
#include "Controller.h"
#include "Gun.h"
#include "Emitter.h"
#include "SoundManager.h"

class Player : public Unit
{
private:
	int number;
	int life;
	float image_size;

	int image_mode[6];

	Emitter* pEmitter;

	Player* pTarget;

	Unit life_bar;
	int life_bar_base_image;

	SoundManager sound_mgr;

	int invincible_frame;
public:
	Gun gun;
	Controller controller;

	//x, y, radius, speed_max
	Player(int, float, float, float, float);
	~Player();
	void Move();
	void Rotation();
	void Update();
	void Draw();

	void SetPlayerImage(int, const char*);
	void SetLifeBar(float px, float py, const TCHAR* image);
	void DrawLifeBar();
	void DrawAmmo();
	void Dead();
	void GiveDamage();

	void SetTarget(Player* p) { pTarget = p; }
	void SetParticleImage(const TCHAR* timage) { pEmitter->SetParticleImage(LoadGraph(timage)); }
	
	void BulletHit(Gun& enemy_gun);
};