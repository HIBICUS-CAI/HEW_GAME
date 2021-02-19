//------------------------------------------------------------------------
// �t�@�C����: ThoughtListShower.h
// �@�\: �ό��q���z��\�������鏈��
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// �ό��q���z��\�������鏈���̏�����
/// </summary>
void InitThoughtListShower();

/// <summary>
/// �ό��q���z��\�������鏈�������s
/// </summary>
void UpdateThoughtListShower();

/// <summary>
/// �ό��q���z��\�������鏈�������
/// </summary>
void TurnOffThoughtListShower();

/// <summary>
/// ���z�X�v���C�g�z����擾
/// </summary>
/// <returns>�z��Ɏw���̃|�C���^</returns>
SPRITE* GetThoughtListSprites();

/// <summary>
/// ���z�X�v���C�g��`�悷��
/// </summary>
/// <param name="offset">�Έڗ�</param>
void DrawThoughtSpriteByOffset(int offset);
