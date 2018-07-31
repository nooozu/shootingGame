#pragma once
#include "Unit.h"
#include "PlayerConfig.h"

class Bullet : public Unit
{
private:
	bool reflect, rapid, slow;
	int ref_frame, rapid_frame, slow_frame;

public:
	Bullet(float, float, float, int);
	~Bullet();
	void Update();
	void Draw();
	void OutScreen();

	void SetAngle(float frad);
	void SetReflect(bool b);
	void SetRapid(bool b);
	void SetSlow(bool b);
};

typedef enum {
	normal,
	shot,
	reflect,
	rapid,
	slow,
	
} BulletType;