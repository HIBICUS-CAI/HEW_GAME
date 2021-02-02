//------------------------------------------------------------------------
// ファイル名: BuildBackgroundShower.h
// 機能: 各ステージの背景演出に関しての処理
//------------------------------------------------------------------------

#pragma once

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
