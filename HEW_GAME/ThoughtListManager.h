//------------------------------------------------------------------------
// �ե�������: ThoughtListManager.h
// �C��: �Q��ͤ��[�֕r������v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// �Q��ͤ��[�֕r������v���Ƥ΄I�����ڻ�����
/// </summary>
void InitThoughtListManager();

/// <summary>
/// �Q��ͤ��[�֕r������v���Ƥ΄I���g�Ф���
/// </summary>
void UpdateThoughtListManager();

/// <summary>
/// �Q��ͤ��[�֕r������v���Ƥ΄I����]����
/// </summary>
void TurnOffThoughtListManager();

/// <summary>
/// ���Q��ͤ˸�������߳���
/// </summary>
/// <param name="buildType">����ʩ�O�ηN�</param>
/// <param name="buildEvent">����ʩ�O������</param>
void CreateThoughtToQueue(int buildType, int buildEvent);

/// <summary>
/// һ�ķN��Q��ͤ�һ�Ĥθ��������
/// </summary>
/// <param name="visitorType">�Q��ͤηN�</param>
/// <param name="buildType">ʩ�O�ηN�</param>
/// <param name="buildEvent">ʩ�O������</param>
void CreateSingleTypeVisitorThought(VISITOR_TYPE visitorType, int buildType, int buildEvent);

/// <summary>
/// ���Ʃ`���ˤ�äƸ��������
/// </summary>
/// <param name="buildType">ʩ�O�ηN�</param>
/// <param name="buildEvent">ʩ�O������</param>
void CreateSingleTypeThoughtByStage(int buildType, int buildEvent);

/// <summary>
/// һ�Ĥθ������Ф�����
/// </summary>
/// <param name="thought">���������</param>
void AddSingleThoughtToQueue(const char* thought);

/// <summary>
/// ������v���Ƥ����ݤ�ꥻ�åȤ���
/// </summary>
void ResetThoughtQueueAndList();
