//------------------------------------------------------------------------
// �ե�������: FinalResult.h
// �C��: ��K�Y�����v���ƤΤ�Ӌ��ȱ�ʾ
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// ��K�Y�����v���ƤΤ�Ӌ��ȱ�ʾ����ڻ�����
/// </summary>
void InitFinalResult();

/// <summary>
/// �����ˤ�äƥ�󥯤�Ӌ�㤹��
/// </summary>
void CountFinalRank();

/// <summary>
/// ��K�Y�����v���ƤΤ�Ӌ��ȱ�ʾ��g�Ф���
/// </summary>
void UpdateFinalResult();

/// <summary>
/// ��K�Y�����v���ƤΤ�Ӌ��ȱ�ʾ��ꥻ�åȤ���
/// </summary>
void ResetFinalResult();

/// <summary>
/// ��K�Y�����v���ƤΤ�Ӌ��ȱ�ʾ���]����
/// </summary>
void TurnOffFinalResult();

/// <summary>
/// ���Υ����פ��Q��ͤ��ǳ���ϲ��
/// </summary>
/// <param name="visitorType">�����Q��ͤΥ�����</param>
void VisitorFeelVeryGood(VISITOR_TYPE visitorType);

/// <summary>
/// ���Υ����פ��Q��ͤ�ϲ��
/// </summary>
/// <param name="visitorType">�����Q��ͤΥ�����</param>
void VisitorFeelGood(VISITOR_TYPE visitorType);

/// <summary>
/// ���Υ����פ��Q��ͤ��ޤ��ޤ���˼��
/// </summary>
/// <param name="visitorType">�����Q��ͤΥ�����</param>
void VisitorFeelAlright(VISITOR_TYPE visitorType);

/// <summary>
/// ���Υ����פ��Q��ͤ��ݤ����ʤ�
/// </summary>
/// <param name="visitorType">�����Q��ͤΥ�����</param>
void VisitorFeelBad(VISITOR_TYPE visitorType);

/// <summary>
/// ���Υ����פ��Q��ͤ��ǳ��˚ݤ����ʤ�
/// </summary>
/// <param name="visitorType">�����Q��ͤΥ�����</param>
void VisitorFeelVeryBad(VISITOR_TYPE visitorType);

/// <summary>
/// ��󥯤���F�Ǥ��뤫�ɤ�����ȡ��
/// </summary>
/// <returns>��󥯱�F�Υե饰</returns>
int GetShowRankFlg();

/// <summary>
/// ��󥯤���F�Ǥ��뤫�ɤ������O��
/// </summary>
/// <param name="value">�O������������</param>
void SetShowRankFlg(int value);

/// <summary>
/// ��K������ȡ��
/// </summary>
/// <returns>��K����</returns>
int GetFinalScore();
