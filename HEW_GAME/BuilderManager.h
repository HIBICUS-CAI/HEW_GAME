//------------------------------------------------------------------------
// ファイル名: BuilderManager.h
// 機能: 施設担当者に関しての処理
//------------------------------------------------------------------------

#pragma once

#define BUILDER_STOP 0
#define BUILDER_GO_LEFT 1
#define BUILDER_GO_RIGHT 2

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
void SetCurrBuildingPosByBuilder(int value);

/// <summary>
/// 今作っている位置を取得
/// </summary>
/// <returns>位置の値</returns>
int GetCurrBuildingPosByBuilder();

/// <summary>
/// 作成者の移動方向を設定
/// </summary>
/// <param name="value">移動方向</param>
void SetBuilderMovFlg(int value);

/// <summary>
/// 作成者の移動方向を取得
/// </summary>
/// <returns>作成者の移動方向</returns>
int GetBuilderMovFlg();

/// <summary>
/// 作成者に関しての特別変数をリセット
/// </summary>
void ResetBuilder();
