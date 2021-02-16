//------------------------------------------------------------------------
// ファイル名: ResultTips.h
// 機能: よりいいになるため意見の表示
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// 意見の表示に関しての処理を初期化する
/// </summary>
void InitResultTips();

/// <summary>
/// 意見をとある文字配列に設定する
/// </summary>
/// <param name="string">上書きしたい文字配列</param>
void SetResultTipsTo(const char* string);

/// <summary>
/// ティップスが表現できるかどうかを設定
/// </summary>
/// <param name="value">設定させたい値</param>
void SetCanShowTipsFlg(int value);

/// <summary>
/// ティップスが表現できるかどうかを取得
/// </summary>
/// <returns>ティップスが表現のフラグ</returns>
int GetCanShowTipsFlg();

/// <summary>
/// 意見の表示に関しての処理を実行する
/// </summary>
void UpdateResultTips();

/// <summary>
/// 意見の表示に関しての処理をリセットする
/// </summary>
void ResetResultTips();

/// <summary>
/// 意見の表示に関しての処理を閉じる
/// </summary>
void TurnOffResulttips();
