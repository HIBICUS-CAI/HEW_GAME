//------------------------------------------------------------------------
// ファイル名: UIObject.h
// 機能: ＵＩアイテムに関しての処理
//------------------------------------------------------------------------

#pragma once

#include <conio.h>
#include <windows.h>
#include "Structs.h"

/// <summary>
/// 入力システムを初期化する
/// </summary>
void InitInputQueue();

/// <summary>
/// 入力リストを作成
/// </summary>
/// <returns>ＩＮＴ型リストの構造体ポインタ</returns>
QUEUE_INT* CreateInputQueue();

/// <summary>
/// 入力システム実行
/// </summary>
void Input();

/// <summary>
/// 押されたキーボードのボタンを取る
/// </summary>
void InsertInput();

/// <summary>
/// マルチスレッドで押されたキーボードのボタンを取る
/// </summary>
void InsertInputMT();

/// <summary>
/// 入力システムが使っているスレッドを閉じる
/// </summary>
void TurnOffMTInput();

/// <summary>
/// 取られたボタンを処理する
/// </summary>
void DisposeInput();

/// <summary>
/// ボタンの値によって機能を実行
/// </summary>
/// <param name="keyCode">入力リストから取り出した値</param>
void DispatchInput(int keyCode);

/// <summary>
/// 入力リストを取得
/// </summary>
/// <returns>入力リスト指向のポインタ</returns>
QUEUE_INT* GetInputQueue();
