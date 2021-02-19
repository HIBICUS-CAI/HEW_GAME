//------------------------------------------------------------------------
// ファイル名: SoundManager.h
// 機能: 音声に関しての機能を提供する
//------------------------------------------------------------------------

#pragma once

#include "Structs.h"

//#define NOTSOUND

/// <summary>
/// 音声システムを初期化する
/// </summary>
void InitSoundSys();

/// <summary>
/// ファイルを音声配列に書き込む
/// </summary>
/// <param name="fileName">ファイル名</param>
/// <param name="soundName">音声に付けたい名前</param>
/// <param name="isAlwaysNeed">常に使用されるかどうか</param>
void LoadSound(const char* fileName, const char* soundName,
    int isAlwaysNeed = 0);

#ifdef SOUNDBYHAL
/// <summary>
/// 名前で音声を取得
/// </summary>
/// <param name="soundName">音声に付けた名前</param>
/// <returns>音声指向のポインタ</returns>
SOUNDFILE_LOADED* GetSoundFile(const char* soundName);
#else
/// <summary>
/// 名前で音声を取得
/// </summary>
/// <param name="soundName">音声に付けた名前</param>
/// <returns>音声指向のポインタ</returns>
SOUNDFILE_IN_MEMBITE* GetSoundFile(const char* soundName);
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// 音声の音量変更
/// </summary>
/// <param name="soundName">音声に付けた名前</param>
/// <param name="vol">設置させたい音量</param>
void ChangeSoundFileVolume(const char* soundName, int vol);
#else
/// <summary>
/// 音声の音量変更
/// </summary>
/// <param name="soundName">音声に付けた名前</param>
/// <param name="vol">設置させたい音量</param>
void ChangeSoundFileVolume(const char* soundName, float vol);
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// 音声の音量変更
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
/// <param name="vol">設置させたい音量</param>
void ChangeSoundFileVolume(SOUNDFILE_LOADED* sound, int vol);
#else
/// <summary>
/// 音声の音量変更
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
/// <param name="vol">設置させたい音量</param>
void ChangeSoundFileVolume(SOUNDFILE_IN_MEMBITE* sound, float vol);
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// 背景音楽を再生する
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void PlayBackgroundMusic(SOUNDFILE_LOADED* sound);
#else
/// <summary>
/// 背景音楽を再生する
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void PlayBackgroundMusic(SOUNDFILE_IN_MEMBITE* sound);
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// 効果音を再生する
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void PlayEffectSound(SOUNDFILE_LOADED* sound);
#else
/// <summary>
/// 効果音を再生する
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void PlayEffectSound(SOUNDFILE_IN_MEMBITE* sound);
#endif // SOUNDBYHAL


#ifndef SOUNDBYHAL
/// <summary>
/// ある音声を一度だけ再生する
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void PlaySingleSoundOnce(SOUNDFILE_IN_MEMBITE* sound);
#endif // !SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// 音声をアンインストールする
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void UninstallSound(SOUNDFILE_LOADED* sound);
#else
/// <summary>
/// 音声をアンインストールする
/// </summary>
/// <param name="sound">音声に指向のポインタ</param>
void UninstallSound(SOUNDFILE_IN_MEMBITE* sound);
#endif // SOUNDBYHAL

/// <summary>
/// ロードされた音声の再生状況確定
/// </summary>
void CheckAllSoundHasEnded();

/// <summary>
/// 音声システムを閉じる
/// </summary>
void TurnOffSoundSys();
