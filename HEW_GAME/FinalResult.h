//------------------------------------------------------------------------
// ファイル名: FinalResult.h
// 機能: 最終結果に関してのの計算と表示
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// 最終結果に関してのの計算と表示を初期化する
/// </summary>
void InitFinalResult();

/// <summary>
/// 点数によってランクを計算する
/// </summary>
void CountFinalRank();

/// <summary>
/// 最終結果に関してのの計算と表示を実行する
/// </summary>
void UpdateFinalResult();

/// <summary>
/// 最終結果に関してのの計算と表示をリセットする
/// </summary>
void ResetFinalResult();

/// <summary>
/// 最終結果に関してのの計算と表示を閉じる
/// </summary>
void TurnOffFinalResult();

/// <summary>
/// このタイプの観光客が非常に喜ぶ
/// </summary>
/// <param name="visitorType">この観光客のタイプ</param>
void VisitorFeelVeryGood(VISITOR_TYPE visitorType);

/// <summary>
/// このタイプの観光客が喜ぶ
/// </summary>
/// <param name="visitorType">この観光客のタイプ</param>
void VisitorFeelGood(VISITOR_TYPE visitorType);

/// <summary>
/// このタイプの観光客がまあまあと思う
/// </summary>
/// <param name="visitorType">この観光客のタイプ</param>
void VisitorFeelAlright(VISITOR_TYPE visitorType);

/// <summary>
/// このタイプの観光客が気に入らない
/// </summary>
/// <param name="visitorType">この観光客のタイプ</param>
void VisitorFeelBad(VISITOR_TYPE visitorType);

/// <summary>
/// このタイプの観光客が非常に気に入らない
/// </summary>
/// <param name="visitorType">この観光客のタイプ</param>
void VisitorFeelVeryBad(VISITOR_TYPE visitorType);

/// <summary>
/// ランクが表現できるかどうかを取得
/// </summary>
/// <returns>ランク表現のフラグ</returns>
int GetShowRankFlg();

/// <summary>
/// ランクが表現できるかどうかを設定
/// </summary>
/// <param name="value">設定させたい値</param>
void SetShowRankFlg(int value);

/// <summary>
/// 最終点数を取得
/// </summary>
/// <returns>最終点数</returns>
int GetFinalScore();
