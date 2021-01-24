//------------------------------------------------------------------------
// �ե�������: SoundManager.h
// �C��: �������v���ƤΙC�ܤ��ṩ����
//------------------------------------------------------------------------

#pragma once

#include "Structs.h"

/// <summary>
/// ���������ƥ����ڻ�����
/// </summary>
void InitSoundSys();

/// <summary>
/// �ե�������������Ф˕����z��
/// </summary>
/// <param name="fileName">�ե�������</param>
/// <param name="soundName">�����˸���������ǰ</param>
/// <param name="isAlwaysNeed">����ʹ�ä���뤫�ɤ���</param>
void LoadSound(const char* fileName, const char* soundName,
    int isAlwaysNeed = 0);

#ifdef SOUNDBYHAL
/// <summary>
/// ��ǰ��������ȡ��
/// </summary>
/// <param name="soundName">�����˸�������ǰ</param>
/// <returns>����ָ��Υݥ���</returns>
SOUNDFILE_LOADED* GetSoundFile(const char* soundName);
#else
/// <summary>
/// ��ǰ��������ȡ��
/// </summary>
/// <param name="soundName">�����˸�������ǰ</param>
/// <returns>����ָ��Υݥ���</returns>
SOUNDFILE_IN_MEMBITE* GetSoundFile(const char* soundName);
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// �������������
/// </summary>
/// <param name="soundName">�����˸�������ǰ</param>
/// <param name="vol">�O�ä�����������</param>
void ChangeSoundFileVolume(const char* soundName, int vol);
#else
/// <summary>
/// �������������
/// </summary>
/// <param name="soundName">�����˸�������ǰ</param>
/// <param name="vol">�O�ä�����������</param>
void ChangeSoundFileVolume(const char* soundName, float vol);
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// �������������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
/// <param name="vol">�O�ä�����������</param>
void ChangeSoundFileVolume(SOUNDFILE_LOADED* sound, int vol);
#else
/// <summary>
/// �������������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
/// <param name="vol">�O�ä�����������</param>
void ChangeSoundFileVolume(SOUNDFILE_IN_MEMBITE* sound, float vol);
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// �������S����������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void PlayBackgroundMusic(SOUNDFILE_LOADED* sound);
#else
/// <summary>
/// �������S����������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void PlayBackgroundMusic(SOUNDFILE_IN_MEMBITE* sound);
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// ����������������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void PlayEffectSound(SOUNDFILE_LOADED* sound);
#else
/// <summary>
/// ����������������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void PlayEffectSound(SOUNDFILE_IN_MEMBITE* sound);
#endif // SOUNDBYHAL


#ifndef SOUNDBYHAL
/// <summary>
/// ����������һ�Ȥ�����������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void PlaySingleSoundOnce(SOUNDFILE_IN_MEMBITE* sound);
#endif // !SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// �����򥢥󥤥󥹥ȩ`�뤹��
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void UninstallSound(SOUNDFILE_LOADED* sound);
#else
/// <summary>
/// �����򥢥󥤥󥹥ȩ`�뤹��
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void UninstallSound(SOUNDFILE_IN_MEMBITE* sound);
#endif // SOUNDBYHAL

/// <summary>
/// ��`�ɤ��줿����������״�r�_��
/// </summary>
void CheckAllSoundHasEnded();

/// <summary>
/// ���������ƥ���]����
/// </summary>
void TurnOffSoundSys();
