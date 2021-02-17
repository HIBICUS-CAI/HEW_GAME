//------------------------------------------------------------------------
// ファイル名: TitleBuilderShower.h
// 機能: タイトルシーンに左右移動のビルダーを表示する
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// 左右移動のビルダー表示に関しての機能を初期化する
/// </summary>
void InitTitleBuilderShower();

/// <summary>
/// 左右移動のビルダー表示に関しての機能を実行する
/// </summary>
void UpdateTitleBuilderShower();

/// <summary>
/// 左右移動のビルダー表示に関しての機能を閉じる
/// </summary>
void TurnOffTitleBuilderShower();

/// <summary>
/// 左右移動のビルダー表示に関しての機能をリセットする
/// </summary>
void ResetTitleBuilderShower();

/// <summary>
/// 立っているビルダーが表現できるかどうかを取得
/// </summary>
/// <returns>ビルダー表現のフラグ</returns>
int GetCanShowStandBuilderFlg();

/// <summary>
/// 立っているビルダーが表現できるかどうかをを設定
/// </summary>
/// <param name="value">設定させたい値</param>
void SetCanShowStandBuilderFlg(int value);
