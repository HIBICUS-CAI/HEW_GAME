//------------------------------------------------------------------------
// ファイル名: CustomizedApp.h
// 機能: ゲームの拡張要素に関しての補完
//------------------------------------------------------------------------

#pragma once

#include "Structs.h"

/// <summary>
/// 拡張要素を初期化する
/// </summary>
void AppInit();

/// <summary>
/// 拡張要素を更新する
/// </summary>
void AppUpdate();

/// <summary>
/// 拡張要素を閉じる
/// </summary>
void AppTurnOff();

/// <summary>
/// 拡張要素のキーボードイベントを行う
/// </summary>
/// <param name="keyCode">キー番号</param>
void AppKeyboardEvent(int keyCode);

/// <summary>
/// 拡張要素のボタンイベントを行う
/// </summary>
/// <param name="value">ボタン番号</param>
void AppButtonEvent(int value);

/// <summary>
/// 拡張要素を他のエフェクトで出力する
/// </summary>
void AppPostPrint();
