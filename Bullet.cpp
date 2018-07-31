#include "Bullet.h"

Bullet::Bullet(float tx, float ty, float trad, int timage)
{
	Initialize(tx, ty, 3, 5, "");
	SetImage(timage);
	rad = trad;
	speed = speed_max;
	reflect = false;
	rapid = false;
	slow = false;
	Rotate();
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	x += dx;
	y += dy;

	if (reflect) {
		if (ref_frame <= 0) {
			flag = false;
		}
		ref_frame--;
	}
	if (rapid) {
		if (rapid_frame <= 0) {
			flag = false;
		}
		rapid_frame--;
	}
	if (slow) {
		if (slow_frame <= 0) {
			flag = false;
		}
		slow_frame--;
	}

	//‰æ–ÊŠO‚Éo‚½Žž‚Ìˆ—
	OutScreen();
}

void Bullet::Draw()
{
	DrawRotaGraph(x, y, 1.0, rad + DEG_TO_RAD(90), image, TRUE);
	//DrawCircle(x, y, radius, GetColor(255, 255, 0), FALSE);
}

void Bullet::OutScreen()
{
	if (reflect) {
		if (x < FIELD_LEFT + radius) {
			x = FIELD_LEFT + radius;
			dx *= -1;
		}
		if (y < FIELD_TOP + radius) {
			y = FIELD_TOP + radius;
			dy *= -1;
		}
		if (x > FIELD_RIGHT - radius) {
			x = FIELD_RIGHT - radius;
			dx *= -1;
		}
		if (y > FIELD_BOTTOM - radius) {
			y = FIELD_BOTTOM - radius;
			dy *= -1;
		}
	}
	else {
		if (x < FIELD_LEFT - radius || y < FIELD_TOP - radius || x > FIELD_RIGHT + radius || y > FIELD_BOTTOM + radius) {
			flag = false;
		}
	}
}

void Bullet::SetAngle(float frad)
{
	rad = frad;
	Rotate();
}

void Bullet::SetReflect(bool b)
{ 
	reflect = b;
	if (reflect) {
		ref_frame = REFLECT_DELETE_TIME;
	}
}

void Bullet::SetSlow(bool b) {
	slow = b;
	if (slow) {
		slow_frame = SLOW_DELETE_TIME;
	}
}

void Bullet::SetRapid(bool b)
{
	rapid = b;
	if (rapid) {
		rapid_frame = RAPID_DELETE_TIME;
	}
}