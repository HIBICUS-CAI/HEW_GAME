//------------------------------------------------------------------------
// �ե�������: ResultTips.h
// �C��: ��ꤤ���ˤʤ뤿����Ҋ�α�ʾ
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// ��Ҋ�α�ʾ���v���Ƥ΄I�����ڻ�����
/// </summary>
void InitResultTips();

/// <summary>
/// ��Ҋ��Ȥ����������Ф��O������
/// </summary>
/// <param name="string">�ϕ�����������������</param>
void SetResultTipsTo(const char* string);

/// <summary>
/// �ƥ��åץ�����F�Ǥ��뤫�ɤ������O��
/// </summary>
/// <param name="value">�O������������</param>
void SetCanShowTipsFlg(int value);

/// <summary>
/// �ƥ��åץ�����F�Ǥ��뤫�ɤ�����ȡ��
/// </summary>
/// <returns>�ƥ��åץ�����F�Υե饰</returns>
int GetCanShowTipsFlg();

/// <summary>
/// ��Ҋ�α�ʾ���v���Ƥ΄I���g�Ф���
/// </summary>
void UpdateResultTips();

/// <summary>
/// ��Ҋ�α�ʾ���v���Ƥ΄I���ꥻ�åȤ���
/// </summary>
void ResetResultTips();

/// <summary>
/// ��Ҋ�α�ʾ���v���Ƥ΄I����]����
/// </summary>
void TurnOffResulttips();
