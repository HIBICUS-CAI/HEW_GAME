//------------------------------------------------------------------------
// �t�@�C����: ResultTips.h
// �@�\: ��肢���ɂȂ邽�߈ӌ��̕\��
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// �ӌ��̕\���Ɋւ��Ă̏���������������
/// </summary>
void InitResultTips();

/// <summary>
/// �ӌ����Ƃ��镶���z��ɐݒ肷��
/// </summary>
/// <param name="string">�㏑�������������z��</param>
void SetResultTipsTo(const char* string);

/// <summary>
/// �e�B�b�v�X���\���ł��邩�ǂ�����ݒ�
/// </summary>
/// <param name="value">�ݒ肳�������l</param>
void SetCanShowTipsFlg(int value);

/// <summary>
/// �e�B�b�v�X���\���ł��邩�ǂ������擾
/// </summary>
/// <returns>�e�B�b�v�X���\���̃t���O</returns>
int GetCanShowTipsFlg();

/// <summary>
/// �ӌ��̕\���Ɋւ��Ă̏��������s����
/// </summary>
void UpdateResultTips();

/// <summary>
/// �ӌ��̕\���Ɋւ��Ă̏��������Z�b�g����
/// </summary>
void ResetResultTips();

/// <summary>
/// �ӌ��̕\���Ɋւ��Ă̏��������
/// </summary>
void TurnOffResulttips();
