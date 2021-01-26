//------------------------------------------------------------------------
// ファイル名: UIObjDeclarer.h
// 機能: 全てのＵＩアイテムの声明と作成
//------------------------------------------------------------------------

#pragma once

#include "UIObject.h"

/// <summary>
/// 全てのＵＩアイテムの基本を作成する
/// </summary>
void CreateAllUIObjs();

/// <summary>
/// タイトル画面に関してのアイテムを作成
/// </summary>
void CreateTitleUIObjs();

/// <summary>
/// 話し合い画面に関してのアイテムを作成
/// </summary>
void CreateDialogUIObjs();

/// <summary>
/// ステージ選択画面に関してのアイテムを作成
/// </summary>
void CreateStageSelectUIObjs();

/// <summary>
/// リゾート名前画面に関してのアイテムを作成
/// </summary>
void CreateNameSetUIObjs();

/// <summary>
/// 施設作成画面に関してのアイテムを作成
/// </summary>
void CreateBuildingUIObjs();

/// <summary>
/// 最終結果画面に関してのアイテムを作成
/// </summary>
void CreateFinalResultUIObjs();
