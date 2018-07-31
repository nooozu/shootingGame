#pragma once
#include "DxLib.h"
#include <vector>
#include <string>

#define MAX_VOLUME 100

class SoundManager
{
private:
	static int bgm_volume, se_volume;

	std::vector<int> bgm_array;
	std::vector<int> se_array;

public:

	SoundManager();
	~SoundManager();

	void SetBGM(const TCHAR* file);
	void SetSE(const TCHAR* file);

	static void SetBGMVolume(int i);
	static void SetSEVolume(int i);
	static int GetBGMVolume() { return bgm_volume; }
	static int GetSEVolume() { return se_volume; }

	void PlayBGM(int i);
	void PlaySE(int i);
};
