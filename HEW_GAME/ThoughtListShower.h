//------------------------------------------------------------------------
// ファイル名: ThoughtListShower.h
// 機能: 観光客感想を表示させる処理
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// 観光客感想を表示させる処理の初期化
/// </summary>
void InitThoughtListShower();

/// <summary>
/// 観光客感想を表示させる処理を実行
/// </summary>
void UpdateThoughtListShower();

/// <summary>
/// 観光客感想を表示させる処理を閉じる
/// </summary>
void TurnOffThoughtListShower();

/// <summary>
/// 感想スプライト配列を取得
/// </summary>
/// <returns>配列に指向のポインタ</returns>
SPRITE* GetThoughtListSprites();

/// <summary>
/// 感想スプライトを描画する
/// </summary>
/// <param name="offset">偏移量</param>
void DrawThoughtSpriteByOffset(int offset);
