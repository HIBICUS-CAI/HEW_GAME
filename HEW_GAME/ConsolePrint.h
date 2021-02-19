//------------------------------------------------------------------------
// ファイル名: ConsolePrint.h
// 機能: 出力用バッファの内容をコンソールに出力する
//------------------------------------------------------------------------

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"

/// <summary>
/// コンソールの大きさとバッファを初期化する
/// </summary>
void InitOutputBuffer();

/// <summary>
/// 前回出力用バッファに書き込んだ内容を廃棄
/// </summary>
void ClearOutputBuffer();

/// <summary>
/// 出力用バッファの内容を文字配列の形で出力する
/// </summary>
void PrintOutputBuffer();

/// <summary>
/// 出力用バッファに必要な更新事項を行う
/// </summary>
void UpdateOutputBuffer();

#ifdef MY_DEBUG_INFO
/// <summary>
/// フレームレートを表示させる
/// </summary>
void ShowFPSAtScreen();
#endif // SHOWFPS

/// <summary>
/// ある位置に内容を直接に書き込む
/// </summary>
/// <param name="position">書き込む座標</param>
/// <param name="text">書き込みたい内容</param>
void WriteCharIntoOutputBuffer(POSITION_2D position, const char text);

/// <summary>
/// ある位置に文字配列内容を書き込む
/// </summary>
/// <param name="startPos">書き込む座標</param>
/// <param name="text">書き込みたい文字配列</param>
void WriteStrIntoOutputBufferByPos(POSITION_2D startPos, const char* text);

/// <summary>
/// ある位置に文字配列と数値を書き込む
/// </summary>
/// <param name="startPos">書き込む座標</param>
/// <param name="text">書き込みたい文字配列</param>
/// <param name="value">書き込みたい値</param>
void WriteStrInt1IntoOutputBufferByPos(POSITION_2D startPos, const char* text, int value);

/// <summary>
/// 出力制御ハンドルを閉じる
/// </summary>
void CloseMTPrint();
