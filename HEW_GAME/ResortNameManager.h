//------------------------------------------------------------------------
// ファイル名: ResortNameManager.h
// 機能: リゾート名前を作成、管理する機能を提供
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// リゾート名前に関しての内容を初期化する
/// </summary>
void InitResortNameManager();

/// <summary>
/// リゾート名前に関しての処理を行う
/// </summary>
void UpdateResortNameManager();

/// <summary>
/// リゾート名前に関しての処理を閉じる
/// </summary>
void TurnOffResortNameManager();

/// <summary>
/// 確定された名前と関連変数を保存する
/// </summary>
void SaveConfirmedName();

/// <summary>
/// 臨時的なプレフィックスを設定
/// </summary>
/// <param name="value">ボタン値</param>
void SetTempName1(int value);

/// <summary>
/// 臨時的なサフィックスを設定
/// </summary>
/// <param name="value">ボタン値</param>
void SetTempName2(int value);
