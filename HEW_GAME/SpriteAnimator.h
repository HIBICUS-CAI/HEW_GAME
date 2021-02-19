//------------------------------------------------------------------------
// ファイル名: SpriteAnimator.h
// 機能: スプライトをまとめての管理と再現
//------------------------------------------------------------------------
#pragma once

#include "GameAppStructs.h"

/// <summary>
/// 一個のスプライトを作成
/// </summary>
/// <param name="fileName">スプライト記録しているファイルの名</param>
/// <param name="position">スプライト位置の座標</param>
/// <param name="width">スプライトの長さ</param>
/// <param name="height">スプライトの高さ</param>
/// <returns>作られたのスプライト</returns>
SPRITE CreateSingleSprite(const char* fileName, POSITION_2D position, int width, int height);

/// <summary>
/// 一個のスプライトを更新用バッファに書き込む
/// </summary>
/// <param name="sprite">書き込みたいスプライトに指向のポインタ</param>
void DrawSingleSpriteToUpdateBuffer(SPRITE* sprite);

/// <summary>
/// 一個のスプライトをカメラバッファに書き込む
/// </summary>
/// <param name="camBuffer">カメラバッファに指向のポインタ</param>
/// <param name="sprite">書き込みたいスプライトに指向のポインタ</param>
/// <param name="posInCam">書き込みたい座標</param>
void DrawSingleSpriteToCamBuffer(SCENECAMERA* camBuffer, SPRITE* sprite, POSITION_2D posInCam, int showSpace = 0);

/// <summary>
/// スプライトアニメタルを作成
/// </summary>
/// <param name="frameCount">キーフレームの数</param>
/// <param name="fileName">スプライト記録しているファイルの名(番号と拡張子抜き)</param>
/// <param name="position">スプライト位置の座標</param>
/// <param name="width">スプライトの長さ</param>
/// <param name="height">スプライトの高さ</param>
/// <returns>作られたのスプライトアニメタル</returns>
SPRITE_ANIME CreateSpriteAnimator(int frameCount, const char* fileName, POSITION_2D position, int width, int height);

/// <summary>
/// スプライトアニメタルを更新用バッファに書き込む
/// </summary>
/// <param name="spriteAnimator">書き込みたいスプライトアニメタルに指向のポインタ</param>
/// <param name="offset">偏移量</param>
void DrawSpriteAnimatorToUpdateBuffer(SPRITE_ANIME* spriteAnimator, int offset);

/// <summary>
/// スプライトアニメタルをカメラバッファに書き込む
/// </summary>
/// <param name="camBuffer">カメラバッファに指向のポインタ</param>
/// <param name="spriteAnimator">書き込みたいスプライトアニメタルに指向のポインタ</param>
/// <param name="offset">偏移量</param>
/// <param name="posInCam">書き込みたい座標</param>
void DrawSpriteAnimatorToCamBuffer(SCENECAMERA* camBuffer, SPRITE_ANIME* spriteAnimator, int offset, POSITION_2D posInCam, int showSpace = 0);
