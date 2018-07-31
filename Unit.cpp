#include "Unit.h"

void Unit::Initialize(float tx, float ty, float tr, float ts_max, const TCHAR* timage)
{
	flag = true;
	image = LoadGraph(timage);
	x = tx, y = ty;
	radius = tr;
	speed_max = ts_max;
	rad = 0, speed = 0;
}

void Unit::Finalize()
{
}

void Unit::Rotate()
{
	dx = cos(rad) * speed;
	dy = sin(rad) * speed;
	//DrawLine(x, y, vx, vy, GetColor(255, 255, 255));
}

void Unit::SetSpeed(float f)
{
	dx = cos(rad) * f;
	dy = sin(rad) * f;
}

void Unit::DebugData(float tx, float ty)
{
	DrawCircle(x, y, 2, GetColor(0, 0, 255), TRUE);
	DrawCircle(x, y, 10, GetColor(255, 255, 0), FALSE);

	DrawFormatString(tx, ty + 20 * 1, GetColor(255, 255, 255), "x = %.1f", x);
	DrawFormatString(tx, ty + 20 * 2, GetColor(255, 255, 255), "y = %.1f", y);
	DrawFormatString(tx, ty + 20 * 3, GetColor(255, 255, 255), "rad = %.1f", rad);
	DrawFormatString(tx, ty + 20 * 4, GetColor(255, 255, 255), "speed = %.1f", speed);
	DrawFormatString(tx, ty + 20 * 5, GetColor(255, 255, 255), "speed_max = %.1f", speed_max);
}

void Unit::OnScreen()
{
	if (x < FIELD_LEFT + radius) {
		x = FIELD_LEFT + radius;
	}
	if (x > FIELD_RIGHT - radius) {
		x = FIELD_RIGHT - radius;
	}

	if (y < FIELD_TOP + radius) {
		y = FIELD_TOP + radius;
	}
	if (y > FIELD_BOTTOM - radius) {
		y = FIELD_BOTTOM - radius;
	}
}

bool Unit::HitCheck(const Unit t)
{
	if (POW2(x - t.x) + POW2(y - t.y) <= POW2(radius + t.radius)) {
		return true;
	}

	return false;
}