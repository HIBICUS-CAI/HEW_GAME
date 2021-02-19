//------------------------------------------------------------------------
// ファイル名: BuildBackgroundShower.h
// 機能: 各ステージの背景演出に関しての処理
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// ステージの背景処理に初期化を行う
/// </summary>
void InitBuildBackground();

/// <summary>
/// ステージの背景に関しての処理
/// </summary>
void UpdateBuildBackground();

/// <summary>
/// ステージの背景に関しての内容を閉じる
/// </summary>
void TurnOffBuildBackground();

/// <summary>
/// やっているステージで背景のスプライトとアニメタルを再ロードする
/// </summary>
void ReloadBackgroundByPlayingStage();

/// <summary>
/// 遠いところのスプライト配列を取得
/// </summary>
/// <returns>遠いところのスプライト配列に指向のポインタ</returns>
SPRITE* GetBuildFarSprites();

/// <summary>
/// 遠いところのスプライトアニメタル配列を取得
/// </summary>
/// <returns>遠いところのスプライトアニメタル配列に指向のポインタ</returns>
SPRITE_ANIME* GetBuildFarSAs();

/// <summary>
/// 近いところのスプライトアニメタル配列を取得
/// </summary>
/// <returns>近いところのスプライトアニメタル配列に指向のポインタ</returns>
SPRITE_ANIME* GetBuildNearSAs();
