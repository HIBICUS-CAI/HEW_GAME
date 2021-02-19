//------------------------------------------------------------------------
// �t�@�C����: BuilderManager.h
// �@�\: �{�ݒS���҂Ɋւ��Ă̏���
//------------------------------------------------------------------------

#pragma once

#define BUILDER_STOP 0
#define BUILDER_GO_LEFT 1
#define BUILDER_GO_RIGHT 2

/// <summary>
/// �쐬�҂Ɋւ��Ă̏�����
/// </summary>
void InitBuilder();

/// <summary>
/// �쐬�҂Ɋւ��Ă̏������X�V����
/// </summary>
void UpdateBuilder();

/// <summary>
/// �쐬�҂Ɋւ��Ă̏��������
/// </summary>
void TurnOffBuilder();

/// <summary>
/// ������Ă���ʒu��ݒ�
/// </summary>
/// <param name="value">�ʒu�̒l</param>
void SetCurrBuildingPosByBuilder(int value);

/// <summary>
/// ������Ă���ʒu���擾
/// </summary>
/// <returns>�ʒu�̒l</returns>
int GetCurrBuildingPosByBuilder();

/// <summary>
/// �쐬�҂̈ړ�������ݒ�
/// </summary>
/// <param name="value">�ړ�����</param>
void SetBuilderMovFlg(int value);

/// <summary>
/// �쐬�҂̈ړ��������擾
/// </summary>
/// <returns>�쐬�҂̈ړ�����</returns>
int GetBuilderMovFlg();

/// <summary>
/// �쐬�҂Ɋւ��Ă̓��ʕϐ������Z�b�g
/// </summary>
void ResetBuilder();
