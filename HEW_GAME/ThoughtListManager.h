//------------------------------------------------------------------------
// ファイル名: ThoughtListManager.h
// 機能: 観光客が遊ぶ時感想に関しての処理
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// 観光客が遊ぶ時感想に関しての処理を初期化する
/// </summary>
void InitThoughtListManager();

/// <summary>
/// 観光客が遊ぶ時感想に関しての処理を実行する
/// </summary>
void UpdateThoughtListManager();

/// <summary>
/// 観光客が遊ぶ時感想に関しての処理を閉じる
/// </summary>
void TurnOffThoughtListManager();

/// <summary>
/// 各観光客に感想を生み出す
/// </summary>
/// <param name="buildType">この施設の種類</param>
/// <param name="buildEvent">この施設の内容</param>
void CreateThoughtToQueue(int buildType, int buildEvent);

/// <summary>
/// 一つ種類の観光客に一つの感想を作成
/// </summary>
/// <param name="visitorType">観光客の種類</param>
/// <param name="buildType">施設の種類</param>
/// <param name="buildEvent">施設の内容</param>
void CreateSingleTypeVisitorThought(VISITOR_TYPE visitorType, int buildType, int buildEvent);

/// <summary>
/// ステージによって感想を作成
/// </summary>
/// <param name="buildType">施設の種類</param>
/// <param name="buildEvent">施設の内容</param>
void CreateSingleTypeThoughtByStage(int buildType, int buildEvent);

/// <summary>
/// 一つの感想を隊列に入れる
/// </summary>
/// <param name="thought">感想の内容</param>
void AddSingleThoughtToQueue(const char* thought);

/// <summary>
/// 感想に関しての内容をリセットする
/// </summary>
void ResetThoughtQueueAndList();
