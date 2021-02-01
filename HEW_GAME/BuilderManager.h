//------------------------------------------------------------------------
// ファイル名: BuilderManager.h
// 機能: 施設担当者に関しての処理
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// 作成者に関しての初期化
/// </summary>
void InitBuilder();

/// <summary>
/// 作成者に関しての処理を更新する
/// </summary>
void UpdateBuilder();

/// <summary>
/// 作成者に関しての処理を閉じる
/// </summary>
void TurnOffBuilder();

/// <summary>
/// 今作っている位置を設定
/// </summary>
/// <param name="value">位置の値</param>
void SetCurrBuildingPos(int value);

/// <summary>
/// 今作っている位置を取得
/// </summary>
/// <returns>位置の値</returns>
int GetCurrBuildingPos();
