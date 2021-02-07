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
