#pragma once
#include "Bullet.h"

class Item : public Unit
{
private:
	int frame;
	BulletType bullet_type;
public:
	Item();
	~Item();
	void Update();
	void Draw();
	BulletType GetBulletType() { return bullet_type; }
};

