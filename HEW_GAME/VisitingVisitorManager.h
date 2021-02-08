//------------------------------------------------------------------------
// �ե�������: VisitingVisitorManager.h
// �C��: �Q��ͤ��[�֕r���v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// �Q��ͤ��[�֕r���v���Ƥ΄I�����ڻ�
/// </summary>
void InitVisitingVisitorManager();

/// <summary>
/// �Q��ͤ��[�֕r���v���Ƥ΄I���g�Ф���
/// </summary>
void UpdateVisitingVisitorManager();

/// <summary>
/// �Q��ͤ��[�֕r���v���Ƥ΄I����]����
/// </summary>
void TurnOffVisitingVisitorManager();

/// <summary>
/// �Q��͡�ʩ�O�ȱ������Ӥ��뤫�ɤ���
/// </summary>
/// <returns>�Ӥ��뤫�ɤ���</returns>
int ResortCanMove();

/// <summary>
/// �Ƅӥե饰��ꥻ�åȤ���
/// </summary>
void ResetResortMoveFlag();

/// <summary>
/// ��ֹ�ޤäƤ���λ�ä�ʩ�O�ηN�
/// </summary>
/// <returns>ʩ�O�ηN�</returns>
int GetCurrColliedBuildingType();

/// <summary>
/// ��ֹ�ޤäƤ���λ�ä�ʩ�O������
/// </summary>
/// <returns>ʩ�O������</returns>
int GetCurrColliedBuildingEvent();

/// <summary>
/// ���Υ꥾�`�Ȥ���ǰ��ȡ��
/// </summary>
/// <returns>�꥾�`�Ȥ���ǰ��ָ��Υݥ���</returns>
char* GetResortName();
