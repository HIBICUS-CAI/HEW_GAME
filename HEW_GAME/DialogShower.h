//------------------------------------------------------------------------
// �ե�������: DialogShower.h
// �C��: ��Ԓ���Ф��r�g�Ф��٤��΄I��
//------------------------------------------------------------------------

#pragma once

#define PEOPLE_SPRITE_SIZE 16

/// <summary>
/// ��Ԓ�I��C�ܤ���ڻ�����
/// </summary>
void InitDialogShower();

/// <summary>
/// ��Ԓ�I��C�ܤ�g�Ф���
/// </summary>
void UpdateDialogShower();

/// <summary>
/// ��Ԓ�I��C�ܤ��]����
/// </summary>
void TurnOffDialogShower();

/// <summary>
/// ��Ԓ����ǥå�����ȡ��
/// </summary>
/// <returns>��Ԓ����ǥå���</returns>
int GetDialogIndex();

/// <summary>
/// ��Ԓ����ǥå������O��
/// </summary>
/// <param name="value">�O������������</param>
void SetDialogIndex(int value);
