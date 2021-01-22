//------------------------------------------------------------------------
// ファイル名: SoundManager.h
// 機能: 音声に関しての機能を提供する
//------------------------------------------------------------------------

#pragma once

#include "Structs.h"

/// <summary>
/// 音声システムを初期化する
/// </summary>
void InitSoundInBitesArray();

/// <summary>
/// ＷＡＶファイルを音声配列に書き込む
/// </summary>
/// <param name="fileName">ＷＡＶファイル名</param>
/// <param name="soundName">音声に付けたい名前</param>
void LoadWavSoundToSoundInBitesArray(const char* fileName, const char* soundName);

/// <summary>
/// 名前で音声を取得
/// </summary>
/// <param name="soundName">音声に付けた名前</param>
/// <returns>音声指向のポインタ</returns>
SOUNDFILE_IN_MEMBITE* GetSoundFile(const char* soundName);

/// <summary>
/// 音声の音量変更
/// </summary>
/// <param name="soundName">音声に付けた名前</param>
/// <param name="vol">設置させたい音量</param>
void ChangeSoundFileVolume(const char* soundName, float vol);

/// <summary>
/// 音声の音量変更
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
/// <param name="vol">設置させたい音量</param>
void ChangeSoundFileVolume(SOUNDFILE_IN_MEMBITE* sound, float vol);

/// <summary>
/// 背景音楽を再生する
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void PlayBackgroundMusic(SOUNDFILE_IN_MEMBITE* sound);

/// <summary>
/// 効果音を再生する
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void PlayEffectSound(SOUNDFILE_IN_MEMBITE* sound);

/// <summary>
/// ある音声を一度だけ再生する
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void PlaySingleSoundOnce(SOUNDFILE_IN_MEMBITE* sound);
