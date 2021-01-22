//------------------------------------------------------------------------
// �ե�������: SoundManager.h
// �C��: �������v���ƤΙC�ܤ��ṩ����
//------------------------------------------------------------------------

#pragma once

#include "Structs.h"

/// <summary>
/// ���������ƥ����ڻ�����
/// </summary>
void InitSoundInBitesArray();

/// <summary>
/// �ף��֥ե�������������Ф˕����z��
/// </summary>
/// <param name="fileName">�ף��֥ե�������</param>
/// <param name="soundName">�����˸���������ǰ</param>
void LoadWavSoundToSoundInBitesArray(const char* fileName, const char* soundName);

/// <summary>
/// ��ǰ��������ȡ��
/// </summary>
/// <param name="soundName">�����˸�������ǰ</param>
/// <returns>����ָ��Υݥ���</returns>
SOUNDFILE_IN_MEMBITE* GetSoundFile(const char* soundName);

/// <summary>
/// �������������
/// </summary>
/// <param name="soundName">�����˸�������ǰ</param>
/// <param name="vol">�O�ä�����������</param>
void ChangeSoundFileVolume(const char* soundName, float vol);

/// <summary>
/// �������������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
/// <param name="vol">�O�ä�����������</param>
void ChangeSoundFileVolume(SOUNDFILE_IN_MEMBITE* sound, float vol);

/// <summary>
/// �������S����������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void PlayBackgroundMusic(SOUNDFILE_IN_MEMBITE* sound);

/// <summary>
/// ����������������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void PlayEffectSound(SOUNDFILE_IN_MEMBITE* sound);

/// <summary>
/// ����������һ�Ȥ�����������
/// </summary>
/// <param name="sound">������ָ��Υݥ���</param>
void PlaySingleSoundOnce(SOUNDFILE_IN_MEMBITE* sound);
