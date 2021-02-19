//------------------------------------------------------------------------
// ファイル名: Tools.h
// 機能: 雑な機能を提供する
//------------------------------------------------------------------------

#pragma once

#include <stdlib.h>
#include <time.h>
#include "Structs.h"
#include "DeclaredValues.h"

/// <summary>
/// 入出力を除いての処理一回循環させてかかったの時間を設定
/// </summary>
/// <param name="time">一回の循環がかかった時間</param>
void SetDeltaTime(int time);

/// <summary>
/// 前回の循環かかったの時間を取得
/// </summary>
/// <returns>前回の循環かかったの時間</returns>
int GetDeltaTime();

/// <summary>
/// 現実に前回の循環かかったの時間を取得
/// </summary>
/// <returns>現実に前回の循環かかったの時間</returns>
int GetRealDeltaTime();

/// <summary>
/// 前回の循環時間によってＦＰＳを計算、出力する
/// </summary>
void ShowFPSMT();

/// <summary>
/// 実行可能プログラムのタイトルを設定
/// </summary>
void InitTitle();

/// <summary>
/// タイトルを閉じる
/// </summary>
void CloseTitle();

/// <summary>
/// あるＩＮＴ型数値の桁数を計算する
/// </summary>
/// <param name="value">計算させたい数値</param>
/// <returns>数値の桁数</returns>
int GetIntValueBit(int value);

/// <summary>
/// ＩＮＴ型のリストを作り出す
/// </summary>
/// <returns>このリストのヘッドポインタ</returns>
QSINGLENODE* CreateQueue();

/// <summary>
/// あるリストに数値を入れる
/// </summary>
/// <param name="end">リストのエンドポインタ</param>
/// <param name="data">入れたい数値</param>
/// <returns>新しいエンドポインタ</returns>
QSINGLENODE* EnQueue(QSINGLENODE* end, int data);

/// <summary>
/// あるリストから数値を取り出す
/// </summary>
/// <param name="top">リストのヘッドポインタ</param>
/// <param name="end">リストのエンドポインタ</param>
/// <returns>取り出された数値</returns>
int DeQueue(QSINGLENODE* top, QSINGLENODE* end);

/// <summary>
/// 特定な種で乱数種を設定
/// </summary>
/// <param name="seedNum">種の内容</param>
void SetRandomBySeed(int seedNum);

/// <summary>
/// 時間で乱数種を設定
/// </summary>
void SetRandom();

/// <summary>
/// ある範囲の中に整数型の乱数を生成する
/// </summary>
/// <param name="minNum">範囲の中に一番小さい値</param>
/// <param name="maxNum">範囲の中に一番大きい値</param>
/// <returns>生成された乱数</returns>
int CreateRandomNumIn(int minNum, int maxNum);

/// <summary>
/// コンソールの色を変化させる
/// </summary>
/// <param name="color">声明された色の値の一つ</param>
void ChangeColorInConsole(int color);

/// <summary>
/// コンソールの色をリセット
/// </summary>
void ResetColorInConsole();

/// <summary>
/// フロート型の値を大きさによってイント型に変更する
/// </summary>
/// <param name="value">変更させたい値</param>
/// <returns>変更されたの値</returns>
int RoundFloatToInt(float value);

#ifndef SOUNDBYHAL
/// <summary>
/// ＷＡＶファイルをメモリの中に書き込む
/// </summary>
/// <param name="fname">音声ファイル名</param>
/// <param name="pMemBites">書き込められたメモリ指向のポインタ</param>
/// <param name="pMemBitesWithVol">音量付き書き込められたメモリ指向のポインタ</param>
/// <param name="fileSize">音声ファイルのサイズ</param>
void ReadWavFileIntoMemory(const char* fname, BYTE** pMemBites,
    BYTE** pMemBitesWithVol, DWORD* fileSize);
#endif // SOUNDBYHAL
