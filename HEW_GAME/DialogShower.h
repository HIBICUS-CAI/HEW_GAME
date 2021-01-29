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

/// <summary>
/// ��Ԓ���٥�Ȥ��K���ֱ���v�B������ꥻ�å�
/// </summary>
void ResetUsingPointerAndFlag();

/// <summary>
/// �⤷੤äƤ����ˤ����ä��饹�ץ饤�Ȥ���äƤ���
/// </summary>
/// <param name="thisName">��੤äƤ�����</param>
/// <param name="preName">ǰ��੤ä���</param>
void SwitchSprite(char* thisName, char* preName);

/// <summary>
/// ���ץ饤�ȥ��˥᥿��ե饰�ˤ�äƥ��ץ饤�Ȥ����
/// </summary>
void DrawTalkingSprite();
