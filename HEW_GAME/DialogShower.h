//------------------------------------------------------------------------
// ファイル名: DialogShower.h
// 機能: 対話を行う時実行すべきの処理
//------------------------------------------------------------------------

#pragma once

#define PEOPLE_SPRITE_SIZE 16

/// <summary>
/// 対話処理機能を初期化する
/// </summary>
void InitDialogShower();

/// <summary>
/// 対話処理機能を実行する
/// </summary>
void UpdateDialogShower();

/// <summary>
/// 対話処理機能を閉じる
/// </summary>
void TurnOffDialogShower();

/// <summary>
/// 対話インデックスを取得
/// </summary>
/// <returns>対話インデックス</returns>
int GetDialogIndex();

/// <summary>
/// 対話インデックスを設定
/// </summary>
/// <param name="value">設定させたい値</param>
void SetDialogIndex(int value);
