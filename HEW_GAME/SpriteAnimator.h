//------------------------------------------------------------------------
// �ե�������: SpriteAnimator.h
// �C��: ���ץ饤�Ȥ�ޤȤ�Ƥι�����٬F
//------------------------------------------------------------------------
#pragma once

#include "GameAppStructs.h"

/// <summary>
/// һ���Υ��ץ饤�Ȥ�����
/// </summary>
/// <param name="fileName">���ץ饤��ӛ�h���Ƥ���ե��������</param>
/// <param name="position">���ץ饤��λ�ä�����</param>
/// <param name="width">���ץ饤�Ȥ��L��</param>
/// <param name="height">���ץ饤�Ȥθߤ�</param>
/// <returns>����줿�Υ��ץ饤��</returns>
SPRITE CreateSingleSprite(const char* fileName, POSITION_2D position, int width, int height);

/// <summary>
/// һ���Υ��ץ饤�Ȥ�����åХåե��˕����z��
/// </summary>
/// <param name="sprite">�����z�ߤ������ץ饤�Ȥ�ָ��Υݥ���</param>
void DrawSingleSpriteToUpdateBuffer(SPRITE* sprite);

/// <summary>
/// һ���Υ��ץ饤�Ȥ򥫥��Хåե��˕����z��
/// </summary>
/// <param name="camBuffer">�����Хåե���ָ��Υݥ���</param>
/// <param name="sprite">�����z�ߤ������ץ饤�Ȥ�ָ��Υݥ���</param>
/// <param name="posInCam">�����z�ߤ�������</param>
void DrawSingleSpriteToCamBuffer(SCENECAMERA* camBuffer, SPRITE* sprite, POSITION_2D posInCam, int showSpace = 0);

/// <summary>
/// ���ץ饤�ȥ��˥᥿�������
/// </summary>
/// <param name="frameCount">���`�ե�`�����</param>
/// <param name="fileName">���ץ饤��ӛ�h���Ƥ���ե��������(���ŤȒ����Ӓi��)</param>
/// <param name="position">���ץ饤��λ�ä�����</param>
/// <param name="width">���ץ饤�Ȥ��L��</param>
/// <param name="height">���ץ饤�Ȥθߤ�</param>
/// <returns>����줿�Υ��ץ饤�ȥ��˥᥿��</returns>
SPRITE_ANIME CreateSpriteAnimator(int frameCount, const char* fileName, POSITION_2D position, int width, int height);

/// <summary>
/// ���ץ饤�ȥ��˥᥿�������åХåե��˕����z��
/// </summary>
/// <param name="spriteAnimator">�����z�ߤ������ץ饤�ȥ��˥᥿���ָ��Υݥ���</param>
/// <param name="offset">ƫ����</param>
void DrawSpriteAnimatorToUpdateBuffer(SPRITE_ANIME* spriteAnimator, int offset);

/// <summary>
/// ���ץ饤�ȥ��˥᥿��򥫥��Хåե��˕����z��
/// </summary>
/// <param name="camBuffer">�����Хåե���ָ��Υݥ���</param>
/// <param name="spriteAnimator">�����z�ߤ������ץ饤�ȥ��˥᥿���ָ��Υݥ���</param>
/// <param name="offset">ƫ����</param>
/// <param name="posInCam">�����z�ߤ�������</param>
void DrawSpriteAnimatorToCamBuffer(SCENECAMERA* camBuffer, SPRITE_ANIME* spriteAnimator, int offset, POSITION_2D posInCam, int showSpace = 0);
