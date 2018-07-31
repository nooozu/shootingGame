#include "SoundManager.h"

//static bgm,se_volumeÇÃé¿ë‘
int SoundManager::bgm_volume = 30;
int SoundManager::se_volume = 40;

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
	for (int i = 0; i < se_array.size(); i++) {
		DeleteSoundMem(se_array[i]);
	}
	for (int i = 0; i < bgm_array.size(); i++) {
		DeleteSoundMem(bgm_array[i]);
	}
}

void SoundManager::SetBGM(const TCHAR* file)
{
	bgm_array.push_back(LoadSoundMem(file));
}

void SoundManager::SetSE(const TCHAR* file)
{
	se_array.push_back(LoadSoundMem(file));
}

void SoundManager::SetBGMVolume(int i)
{
	if (i < 0) {
		bgm_volume = 0;
	}
	else if (i > MAX_VOLUME) {
		bgm_volume = MAX_VOLUME;
	}
	else {
		bgm_volume = i;
	}
}
void SoundManager::SetSEVolume(int i)
{
	if (i < 0) {
		se_volume = 0;
	}
	else if (i > MAX_VOLUME) {
		se_volume = MAX_VOLUME;
	}
	else {
		se_volume = i;
	}
}

void SoundManager::PlayBGM(int i)
{
	if (i < bgm_array.size() && i >= 0) {
		ChangeVolumeSoundMem(255 * bgm_volume / MAX_VOLUME, bgm_array[i]);
		PlaySoundMem(bgm_array[i], DX_PLAYTYPE_LOOP);
	}
	else {
		printfDx("óvëfêî[%d]ÇÃBGMÇÕë∂ç›ÇµÇ‹ÇπÇÒ\n", i);
	}
}

void SoundManager::PlaySE(int i)
{
	if (i < se_array.size() && i >= 0) {
		ChangeVolumeSoundMem(255 * se_volume / MAX_VOLUME, se_array[i]);
		PlaySoundMem(se_array[i], DX_PLAYTYPE_BACK);
	}
	else {
		printfDx("óvëfêî[%d]ÇÃSEÇÕë∂ç›ÇµÇ‹ÇπÇÒ\n", i);
	}
}