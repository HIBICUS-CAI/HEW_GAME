//------------------------------------------------------------------------
// �t�@�C����: ResortNameManager.h
// �@�\: ���]�[�g���O���쐬�A�Ǘ�����@�\���
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// ���]�[�g���O�Ɋւ��Ă̓��e������������
/// </summary>
void InitResortNameManager();

/// <summary>
/// ���]�[�g���O�Ɋւ��Ă̏������s��
/// </summary>
void UpdateResortNameManager();

/// <summary>
/// ���]�[�g���O�Ɋւ��Ă̏��������
/// </summary>
void TurnOffResortNameManager();

/// <summary>
/// �m�肳�ꂽ���O�Ɗ֘A�ϐ���ۑ�����
/// </summary>
void SaveConfirmedName();

/// <summary>
/// �Վ��I�ȃv���t�B�b�N�X��ݒ�
/// </summary>
/// <param name="value">�{�^���l</param>
void SetTempName1(int value);

/// <summary>
/// �Վ��I�ȃT�t�B�b�N�X��ݒ�
/// </summary>
/// <param name="value">�{�^���l</param>
void SetTempName2(int value);
