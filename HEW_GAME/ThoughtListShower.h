//------------------------------------------------------------------------
// �ե�������: ThoughtListShower.h
// �C��: �Q��͸�����ʾ������I��
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// �Q��͸�����ʾ������I��γ��ڻ�
/// </summary>
void InitThoughtListShower();

/// <summary>
/// �Q��͸�����ʾ������I���g��
/// </summary>
void UpdateThoughtListShower();

/// <summary>
/// �Q��͸�����ʾ������I����]����
/// </summary>
void TurnOffThoughtListShower();

/// <summary>
/// ���륹�ץ饤�����Ф�ȡ��
/// </summary>
/// <returns>���Ф�ָ��Υݥ���</returns>
SPRITE* GetThoughtListSprites();

/// <summary>
/// ���륹�ץ饤�Ȥ��軭����
/// </summary>
/// <param name="offset">ƫ����</param>
void DrawThoughtSpriteByOffset(int offset);
