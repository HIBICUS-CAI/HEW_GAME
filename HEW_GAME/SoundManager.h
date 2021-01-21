//------------------------------------------------------------------------
// ファイル名: SoundManager.h
// 機能: 音声に関しての機能を提供する
//------------------------------------------------------------------------

#pragma once

#include "Structs.h"

void InitSoundInBitesArray();

void LoadWavSoundToSoundInBitesArray(const char* fileName, const char* soundName);

SOUNDFILE_IN_MEMBITE* GetSoundFile(const char* soundName);

void ChangeSoundFileVolume(const char* soundName, float vol);

void ChangeSoundFileVolume(SOUNDFILE_IN_MEMBITE* sound, float vol);

void PlayBackgroundMusic(SOUNDFILE_IN_MEMBITE* sound);

void PlayEffectSound(SOUNDFILE_IN_MEMBITE* sound);
