//------------------------------------------------------------------------
// �t�@�C����: TitleBuilderShower.h
// �@�\: �^�C�g���V�[���ɍ��E�ړ��̃r���_�[��\������
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// ���E�ړ��̃r���_�[�\���Ɋւ��Ă̋@�\������������
/// </summary>
void InitTitleBuilderShower();

/// <summary>
/// ���E�ړ��̃r���_�[�\���Ɋւ��Ă̋@�\�����s����
/// </summary>
void UpdateTitleBuilderShower();

/// <summary>
/// ���E�ړ��̃r���_�[�\���Ɋւ��Ă̋@�\�����
/// </summary>
void TurnOffTitleBuilderShower();

/// <summary>
/// ���E�ړ��̃r���_�[�\���Ɋւ��Ă̋@�\�����Z�b�g����
/// </summary>
void ResetTitleBuilderShower();

/// <summary>
/// �����Ă���r���_�[���\���ł��邩�ǂ������擾
/// </summary>
/// <returns>�r���_�[�\���̃t���O</returns>
int GetCanShowStandBuilderFlg();

/// <summary>
/// �����Ă���r���_�[���\���ł��邩�ǂ�������ݒ�
/// </summary>
/// <param name="value">�ݒ肳�������l</param>
void SetCanShowStandBuilderFlg(int value);
