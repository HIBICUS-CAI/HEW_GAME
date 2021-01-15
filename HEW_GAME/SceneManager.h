//------------------------------------------------------------------------
// ファイル名: SceneManager.h
// 機能: 全てのシーンを管理する機能
//------------------------------------------------------------------------

#pragma once
#include "GameAppStructs.h"

/// <summary>
/// 今使っているシーンを設定
/// </summary>
/// <param name="sceneNode">シーン指向のポインタ</param>
void SetManagedCurrScene(SCENENODE* sceneNode);

/// <summary>
/// 今使っているシーンを取得
/// </summary>
/// <returns>シーン指向のポインタ</returns>
SCENENODE* GetManagedCurrScene();

/// <summary>
/// 使っているシーンを初期化する
/// </summary>
void InitCurrScene();

/// <summary>
/// 使っているシーンを更新する
/// </summary>
void UpdateCurrScene();

/// <summary>
/// あるシーンに変換する
/// </summary>
/// <param name="sceneName">シーンの名前</param>
void SwitchSceneToName(const char* sceneName);
