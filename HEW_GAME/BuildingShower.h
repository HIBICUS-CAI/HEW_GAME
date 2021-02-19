//------------------------------------------------------------------------
// �t�@�C����: BuildingShower.h
// �@�\: �{�ݍ쐬�Ɋւ��Ă̕\���Ɖ��o����
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

#define SPRING_OFFSET 0
#define FOOD_OFFSET 1
#define POOL_OFFSET 2
#define DRINK_OFFSET 3
#define CINEMA_OFFSET 4
#define KARAOKE_OFFSET 5
#define HOTEL_OFFSET 6
#define CAMP_OFFSET 7
#define HANDMAKE_OFFSET 8

/// <summary>
/// �{�ݍ쐬�Ɋւ��Ă̕\���Ɖ��o����������������
/// </summary>
void InitBuildingShower();

/// <summary>
/// �{�ݍ쐬�Ɋւ��Ă̕\���Ɖ��o���������s����
/// </summary>
void UpdateBuildingShower();

/// <summary>
/// �{�ݍ쐬�Ɋւ��Ă̕\���Ɖ��o���������
/// </summary>
void TurnOffBuildingShower();

/// <summary>
/// ������Ă���ʒu�Ƀn���}�̉��o��\������
/// </summary>
void ShowBuildingHammer();

/// <summary>
/// �{�ݍ쐬�Ɋւ��Ă̕\���Ɖ��o�����̎��Ԃ����Z�b�g����
/// </summary>
void ResetBuildingShowerTimer();

/// <summary>
/// �e�{�݂̃X�v���C�g��ۑ����Ă���z����擾
/// </summary>
/// <returns>�X�v���C�g��ۑ����Ă���z��Ɏw���̃|�C���^</returns>
SPRITE* GetBuildingSprites();
