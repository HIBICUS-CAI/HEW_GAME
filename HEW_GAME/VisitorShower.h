//------------------------------------------------------------------------
// ファイル名: VisitorShower.h
// 機能: 作成された観光客を表示させる
//------------------------------------------------------------------------

#pragma once

#define VISITORTYPE_MAXSIZE 9 

/// <summary>
/// 観光客アニメタルを初期化する
/// </summary>
void InitVisitorShower();

/// <summary>
/// 観光客アニメタルを実行する
/// </summary>
void UpdateVisitorShower();

/// <summary>
/// 観光客アニメタルを閉じる
/// </summary>
void TurnOffVisitorShower();

/// <summary>
/// 観光客スプライトを表示するかどうかを設定
/// </summary>
/// <param name="flag">表示のフラグ</param>
void SetShowVisitorFlg(int flag);

/// <summary>
/// 観光客スプライト表示に関しての内容をリセット
/// </summary>
void ResetAllAboutShowVisitors();
