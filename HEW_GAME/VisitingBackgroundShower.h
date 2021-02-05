//------------------------------------------------------------------------
// ファイル名: VisitingBackgroundShower.h
// 機能: リゾートに各ステージのスプライトを表示
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// リゾートに各ステージのスプライトを初期化する
/// </summary>
void InitVisitingBackground();

/// <summary>
/// リゾートに各ステージのスプライトを再ロード
/// </summary>
void ReloadVisitingBackground();

/// <summary>
/// リゾートに各ステージのスプライトを描画する
/// </summary>
void UpdateVisitingBackground();

/// <summary>
/// リゾートに各ステージのスプライトを閉じる
/// </summary>
void TurnOffVisitingBackground();

/// <summary>
/// リゾートに関しての内容をリセット
/// </summary>
void ResetResortBGTimerAndOffset();
