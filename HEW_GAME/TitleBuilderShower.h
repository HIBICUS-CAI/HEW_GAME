//------------------------------------------------------------------------
// �ե�������: TitleBuilderShower.h
// �C��: �����ȥ륷�`��������ƄӤΥӥ���`���ʾ����
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// �����ƄӤΥӥ���`��ʾ���v���ƤΙC�ܤ���ڻ�����
/// </summary>
void InitTitleBuilderShower();

/// <summary>
/// �����ƄӤΥӥ���`��ʾ���v���ƤΙC�ܤ�g�Ф���
/// </summary>
void UpdateTitleBuilderShower();

/// <summary>
/// �����ƄӤΥӥ���`��ʾ���v���ƤΙC�ܤ��]����
/// </summary>
void TurnOffTitleBuilderShower();

/// <summary>
/// �����ƄӤΥӥ���`��ʾ���v���ƤΙC�ܤ�ꥻ�åȤ���
/// </summary>
void ResetTitleBuilderShower();

/// <summary>
/// ���äƤ���ӥ���`����F�Ǥ��뤫�ɤ�����ȡ��
/// </summary>
/// <returns>�ӥ���`��F�Υե饰</returns>
int GetCanShowStandBuilderFlg();

/// <summary>
/// ���äƤ���ӥ���`����F�Ǥ��뤫�ɤ�������O��
/// </summary>
/// <param name="value">�O������������</param>
void SetCanShowStandBuilderFlg(int value);
