//------------------------------------------------------------------------
// �ե�������: BuildBackgroundShower.h
// �C��: �����Ʃ`���α����ݳ����v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// ���Ʃ`���α����I��˳��ڻ����Ф�
/// </summary>
void InitBuildBackground();

/// <summary>
/// ���Ʃ`���α������v���Ƥ΄I��
/// </summary>
void UpdateBuildBackground();

/// <summary>
/// ���Ʃ`���α������v���Ƥ����ݤ��]����
/// </summary>
void TurnOffBuildBackground();

/// <summary>
/// ��äƤ��륹�Ʃ`���Ǳ����Υ��ץ饤�Ȥȥ��˥᥿����٥�`�ɤ���
/// </summary>
void ReloadBackgroundByPlayingStage();

/// <summary>
/// �h���Ȥ���Υ��ץ饤�����Ф�ȡ��
/// </summary>
/// <returns>�h���Ȥ���Υ��ץ饤�����Ф�ָ��Υݥ���</returns>
SPRITE* GetBuildFarSprites();

/// <summary>
/// �h���Ȥ���Υ��ץ饤�ȥ��˥᥿�����Ф�ȡ��
/// </summary>
/// <returns>�h���Ȥ���Υ��ץ饤�ȥ��˥᥿�����Ф�ָ��Υݥ���</returns>
SPRITE_ANIME* GetBuildFarSAs();

/// <summary>
/// �����Ȥ���Υ��ץ饤�ȥ��˥᥿�����Ф�ȡ��
/// </summary>
/// <returns>�����Ȥ���Υ��ץ饤�ȥ��˥᥿�����Ф�ָ��Υݥ���</returns>
SPRITE_ANIME* GetBuildNearSAs();
