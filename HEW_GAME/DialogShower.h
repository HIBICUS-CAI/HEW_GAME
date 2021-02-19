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

/// <summary>
/// 対話イベントが終わる直後関連変数をリセット
/// </summary>
void ResetUsingPointerAndFlag();

/// <summary>
/// もし喋っている人が変わったらスプライトも変わっていく
/// </summary>
/// <param name="thisName">今喋っている人</param>
/// <param name="preName">前回喋った人</param>
void SwitchSprite(char* thisName, char* preName);

/// <summary>
/// スプライトアニメタルフラグによってスプライトを更新
/// </summary>
void DrawTalkingSprite();
