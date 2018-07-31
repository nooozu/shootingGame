#pragma once
#include <math.h>
#include "DxLib.h"
#include "DefaultConfig.h"

class Fps
{
private:
	int start_time;
	int count;
	float fps;
	static const int N = 60;
	static const int FPS = 60;

public:
	Fps();
	~Fps();

	bool Update();
	void Draw();
	void Wait();
};

