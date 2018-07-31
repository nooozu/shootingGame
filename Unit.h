#pragma once
#include <math.h>
#include "DxLib.h"
#include "DefaultConfig.h"

class Unit
{
protected:
	bool flag;
	int image;
	double x, y, dx, dy, radius, rad, speed, speed_max;

public:
	void Initialize(float, float, float, float, const TCHAR*);
	void Finalize();
	void Rotate();
	void DebugData(float, float);

	void OnScreen();

	void SetImage(const TCHAR* timage) { image = LoadGraph(timage); }
	void SetImage(int i) { image = i; }
	void SetRadius(float f) { radius = f; }
	void SetRad(float r) { rad = r; }
	void SetFlag(bool b) { flag = b; }
	void SetSpeed(float f);

	bool GetFlag() { return flag; }
	float GetX() { return x; }
	float GetY() { return y; }
	int GetImage() { return image; }
	bool HitCheck(const Unit);
};
