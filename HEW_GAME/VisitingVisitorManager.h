//------------------------------------------------------------------------
// ファイル名: VisitingVisitorManager.h
// 機能: 観光客が遊ぶ時に関しての処理
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// 観光客が遊ぶ時に関しての処理を初期化
/// </summary>
void InitVisitingVisitorManager();

/// <summary>
/// 観光客が遊ぶ時に関しての処理を実行する
/// </summary>
void UpdateVisitingVisitorManager();

/// <summary>
/// 観光客が遊ぶ時に関しての処理を閉じる
/// </summary>
void TurnOffVisitingVisitorManager();

/// <summary>
/// 観光客、施設と背景が動けるかどうか
/// </summary>
/// <returns>動けるかどうか</returns>
int ResortCanMove();

/// <summary>
/// 移動フラグをリセットする
/// </summary>
void ResetResortMoveFlag();
