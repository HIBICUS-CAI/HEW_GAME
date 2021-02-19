//------------------------------------------------------------------------
// ファイル名: AppBtnEvemt.h
// 機能: ゲームボタン処理
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// タイトル画面に対してのボタン処理
/// </summary>
/// <param name="value"></param>
void TitleSceneBtnEvent(int value);

/// <summary>
/// 話し合い画面に対してのボタン処理
/// </summary>
/// <param name="value"></param>
void DialogSceneBtnEvent(int value);

/// <summary>
/// ステージ選択画面に対してのボタン処理
/// </summary>
/// <param name="value"></param>
void StageSelectSceneBtnEvent(int value);

/// <summary>
/// 名前付き画面に対してのボタン処理
/// </summary>
/// <param name="value"></param>
void NamingSceneBtnEvent(int value);

/// <summary>
/// 施設作成画面に対してのボタン処理
/// </summary>
/// <param name="value"></param>
void BuildingSceneBtnEvent(int value);

/// <summary>
/// 最終結果画面に対してのボタン処理
/// </summary>
/// <param name="value"></param>
void FinalResultSceneBtnEvent(int value);
