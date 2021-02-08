//------------------------------------------------------------------------
// �ե�������: ThoughtListManager.h
// �C��: �Q��ͤ��[�֕r������v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

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
/// һ�Ĥθ������Ф�����
/// </summary>
/// <param name="thought">���������</param>
void AddSingleThoughtToQueue(const char* thought);

/// <summary>
/// ������v���Ƥ����ݤ�ꥻ�åȤ���
/// </summary>
void ResetThoughtQueueAndList();
