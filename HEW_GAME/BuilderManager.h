//------------------------------------------------------------------------
// �ե�������: BuilderManager.h
// �C��: ʩ�O�����ߤ��v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

#define BUILDER_STOP 0
#define BUILDER_GO_LEFT 1
#define BUILDER_GO_RIGHT 2

/// <summary>
/// �����ߤ��v���Ƥγ��ڻ�
/// </summary>
void InitBuilder();

/// <summary>
/// �����ߤ��v���Ƥ΄I�����¤���
/// </summary>
void UpdateBuilder();

/// <summary>
/// �����ߤ��v���Ƥ΄I����]����
/// </summary>
void TurnOffBuilder();

/// <summary>
/// �����äƤ���λ�ä��O��
/// </summary>
/// <param name="value">λ�ä΂�</param>
void SetCurrBuildingPosByBuilder(int value);

/// <summary>
/// �����äƤ���λ�ä�ȡ��
/// </summary>
/// <returns>λ�ä΂�</returns>
int GetCurrBuildingPosByBuilder();

/// <summary>
/// �����ߤ��Ƅӷ�����O��
/// </summary>
/// <param name="value">�Ƅӷ���</param>
void SetBuilderMovFlg(int value);

/// <summary>
/// �����ߤ��Ƅӷ����ȡ��
/// </summary>
/// <returns>�����ߤ��Ƅӷ���</returns>
int GetBuilderMovFlg();

/// <summary>
/// �����ߤ��v���Ƥ��؄e������ꥻ�å�
/// </summary>
void ResetBuilder();
