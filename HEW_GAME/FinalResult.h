//------------------------------------------------------------------------
// �t�@�C����: FinalResult.h
// �@�\: �ŏI���ʂɊւ��Ă̂̌v�Z�ƕ\��
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// �ŏI���ʂɊւ��Ă̂̌v�Z�ƕ\��������������
/// </summary>
void InitFinalResult();

/// <summary>
/// �_���ɂ���ă����N���v�Z����
/// </summary>
void CountFinalRank();

/// <summary>
/// �ŏI���ʂɊւ��Ă̂̌v�Z�ƕ\�������s����
/// </summary>
void UpdateFinalResult();

/// <summary>
/// �ŏI���ʂɊւ��Ă̂̌v�Z�ƕ\�������Z�b�g����
/// </summary>
void ResetFinalResult();

/// <summary>
/// �ŏI���ʂɊւ��Ă̂̌v�Z�ƕ\�������
/// </summary>
void TurnOffFinalResult();

/// <summary>
/// ���̃^�C�v�̊ό��q�����Ɋ��
/// </summary>
/// <param name="visitorType">���̊ό��q�̃^�C�v</param>
void VisitorFeelVeryGood(VISITOR_TYPE visitorType);

/// <summary>
/// ���̃^�C�v�̊ό��q�����
/// </summary>
/// <param name="visitorType">���̊ό��q�̃^�C�v</param>
void VisitorFeelGood(VISITOR_TYPE visitorType);

/// <summary>
/// ���̃^�C�v�̊ό��q���܂��܂��Ǝv��
/// </summary>
/// <param name="visitorType">���̊ό��q�̃^�C�v</param>
void VisitorFeelAlright(VISITOR_TYPE visitorType);

/// <summary>
/// ���̃^�C�v�̊ό��q���C�ɓ���Ȃ�
/// </summary>
/// <param name="visitorType">���̊ό��q�̃^�C�v</param>
void VisitorFeelBad(VISITOR_TYPE visitorType);

/// <summary>
/// ���̃^�C�v�̊ό��q�����ɋC�ɓ���Ȃ�
/// </summary>
/// <param name="visitorType">���̊ό��q�̃^�C�v</param>
void VisitorFeelVeryBad(VISITOR_TYPE visitorType);

/// <summary>
/// �����N���\���ł��邩�ǂ������擾
/// </summary>
/// <returns>�����N�\���̃t���O</returns>
int GetShowRankFlg();

/// <summary>
/// �����N���\���ł��邩�ǂ�����ݒ�
/// </summary>
/// <param name="value">�ݒ肳�������l</param>
void SetShowRankFlg(int value);

/// <summary>
/// �ŏI�_�����擾
/// </summary>
/// <returns>�ŏI�_��</returns>
int GetFinalScore();
