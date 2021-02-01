//------------------------------------------------------------------------
// �ե�������: BuilderManager.h
// �C��: ʩ�O�����ߤ��v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

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
void SetCurrBuildingPos(int value);

/// <summary>
/// �����äƤ���λ�ä�ȡ��
/// </summary>
/// <returns>λ�ä΂�</returns>
int GetCurrBuildingPos();
