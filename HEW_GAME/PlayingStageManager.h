//------------------------------------------------------------------------
// ファイル名: PlayingStageManager.h
// 機能: 各ステージを管理する機能を提供
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// ステージ管理機能を初期化する
/// </summary>
void InitPlayingStage();

/// <summary>
/// ステージ管理機能を実行
/// </summary>
void UpdatePlayingStage();

/// <summary>
/// ステージ管理機能を閉じる
/// </summary>
void TurnOffPlayingStage();

/// <summary>
/// 今選択されているステージを取得
/// </summary>
/// <returns>ステージ番号</returns>
int GetPlayingStageByManager();

/// <summary>
/// 選択されたステージを保存
/// </summary>
/// <param name="stageID">選択されたステージの番号</param>
void SetPlayingStageByManager(int stageID);

/// <summary>
/// 保存されたステージをリセット
/// </summary>
void ResetPlayingStageByManager();
