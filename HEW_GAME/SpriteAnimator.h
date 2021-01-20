//------------------------------------------------------------------------
// �ե�������: SpriteAnimator.h
// �C��: ���ץ饤�Ȥ�ޤȤ�Ƥι�����٬F
//------------------------------------------------------------------------
#pragma once

#include "GameAppStructs.h"

SPRITE CreateSingleSprite(const char* fileName, POSITION_2D position, int width, int height);

void DrawSingleSpriteToUpdateBuffer(SPRITE* sprite);

SPRITE_ANIME CreateSpriteAnimator(int frameCount, const char* fileName, POSITION_2D position, int width, int height);
