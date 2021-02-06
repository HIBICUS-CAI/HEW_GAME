//------------------------------------------------------------------------
// ファイル名: VisitingBuildShower.h
// 機能: リゾートシーンに施設を表示するに関しての処理
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// 施設を表示するに関しての初期化
/// </summary>
void InitVisitingBuildShower();

/// <summary>
/// 施設を表示するに関しての時間をリセットする
/// </summary>
void ResetVisitingBuildShowerTimer();

/// <summary>
/// 施設を表示するに関しての処理を実行する
/// </summary>
void UpdateVisitingBuildShower();

/// <summary>
/// 施設を表示するに関しての処理を閉じる
/// </summary>
void TurnOffVisitingBuildShower();
