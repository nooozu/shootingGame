#include "Fps.h"

Fps::Fps()
{
	start_time = 0;
	count = 0;
	fps = 0;
}

Fps::~Fps()
{
}

bool Fps::Update()
{
	if (count == 0) {
		//現在時刻を保存
		start_time = GetNowCount();
	}

	if (count == N) {
		int t = GetNowCount();
		fps = 1000.0f / ((t - start_time) / (float)N);
		count = 0;
		start_time = t;
	}

	count++;

	return true;
}

void Fps::Draw()
{
	DrawFormatString(10, SCREEN_HEIGHT - 20, GetColor(255, 255, 255), "%.1f", fps);
}

void Fps::Wait()
{
	int took_time = GetNowCount() - start_time;     //かかった時間
	int wait_time = count * 1000 / FPS - took_time; //待機時間

	if (wait_time > 0) {
		Sleep(wait_time);//待機
	}
}