//------------------------------------------------------------------------
// �t�@�C����: ThoughtListManager.h
// �@�\: �ό��q���V�Ԏ����z�Ɋւ��Ă̏���
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// �ό��q���V�Ԏ����z�Ɋւ��Ă̏���������������
/// </summary>
void InitThoughtListManager();

/// <summary>
/// �ό��q���V�Ԏ����z�Ɋւ��Ă̏��������s����
/// </summary>
void UpdateThoughtListManager();

/// <summary>
/// �ό��q���V�Ԏ����z�Ɋւ��Ă̏��������
/// </summary>
void TurnOffThoughtListManager();

/// <summary>
/// �e�ό��q�Ɋ��z�𐶂ݏo��
/// </summary>
/// <param name="buildType">���̎{�݂̎��</param>
/// <param name="buildEvent">���̎{�݂̓��e</param>
void CreateThoughtToQueue(int buildType, int buildEvent);

/// <summary>
/// ���ނ̊ό��q�Ɉ�̊��z���쐬
/// </summary>
/// <param name="visitorType">�ό��q�̎��</param>
/// <param name="buildType">�{�݂̎��</param>
/// <param name="buildEvent">�{�݂̓��e</param>
void CreateSingleTypeVisitorThought(VISITOR_TYPE visitorType, int buildType, int buildEvent);

/// <summary>
/// �X�e�[�W�ɂ���Ċ��z���쐬
/// </summary>
/// <param name="buildType">�{�݂̎��</param>
/// <param name="buildEvent">�{�݂̓��e</param>
void CreateSingleTypeThoughtByStage(int buildType, int buildEvent);

/// <summary>
/// ��̊��z�����ɓ����
/// </summary>
/// <param name="thought">���z�̓��e</param>
void AddSingleThoughtToQueue(const char* thought);

/// <summary>
/// ���z�Ɋւ��Ă̓��e�����Z�b�g����
/// </summary>
void ResetThoughtQueueAndList();
