//------------------------------------------------------------------------
// ファイル名: GameApp.h
// 機能: ゲームの基本循環
//------------------------------------------------------------------------

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Structs.h"

/// <summary>
/// ゲームが必要なものを全部初期化する
/// </summary>
/// <returns>成功かどうかを示す</returns>
int Init();

/// <summary>
/// ゲームを実行する
/// </summary>
void RunGame();

/// <summary>
/// ゲームを閉じる
/// </summary>
void TurnOff();

/// <summary>
/// ゲームの要素を更新する
/// </summary>
void Update();

/// <summary>
/// 出力用バッファを文字配列のように出力する
/// </summary>
void Draw();
