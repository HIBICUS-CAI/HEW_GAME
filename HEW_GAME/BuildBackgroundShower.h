//------------------------------------------------------------------------
// �t�@�C����: BuildBackgroundShower.h
// �@�\: �e�X�e�[�W�̔w�i���o�Ɋւ��Ă̏���
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// �X�e�[�W�̔w�i�����ɏ��������s��
/// </summary>
void InitBuildBackground();

/// <summary>
/// �X�e�[�W�̔w�i�Ɋւ��Ă̏���
/// </summary>
void UpdateBuildBackground();

/// <summary>
/// �X�e�[�W�̔w�i�Ɋւ��Ă̓��e�����
/// </summary>
void TurnOffBuildBackground();

/// <summary>
/// ����Ă���X�e�[�W�Ŕw�i�̃X�v���C�g�ƃA�j���^�����ă��[�h����
/// </summary>
void ReloadBackgroundByPlayingStage();

/// <summary>
/// �����Ƃ���̃X�v���C�g�z����擾
/// </summary>
/// <returns>�����Ƃ���̃X�v���C�g�z��Ɏw���̃|�C���^</returns>
SPRITE* GetBuildFarSprites();

/// <summary>
/// �����Ƃ���̃X�v���C�g�A�j���^���z����擾
/// </summary>
/// <returns>�����Ƃ���̃X�v���C�g�A�j���^���z��Ɏw���̃|�C���^</returns>
SPRITE_ANIME* GetBuildFarSAs();

/// <summary>
/// �߂��Ƃ���̃X�v���C�g�A�j���^���z����擾
/// </summary>
/// <returns>�߂��Ƃ���̃X�v���C�g�A�j���^���z��Ɏw���̃|�C���^</returns>
SPRITE_ANIME* GetBuildNearSAs();
