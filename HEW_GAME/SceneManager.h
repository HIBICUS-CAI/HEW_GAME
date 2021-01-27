//------------------------------------------------------------------------
// ファイル名: SceneManager.h
// 機能: 全てのシーンを管理する機能
//------------------------------------------------------------------------

#pragma once
#include "GameAppStructs.h"

#define TESTSCENEFLAG 1
#define TITLESCENEFLAG 2
#define DIALOGSCENEFLAG 3
#define SELECTSCENEFLAG 4
#define NAMINGSCENEFLAG 5
#define BUILDINGSCENEFLAG 6
#define RESORTSCENEFLAG 7
#define EVENTSCENEFLAG 8
#define FEELINGSCENEFLAG 9
#define RESULTSCENEFLAG 10

/// <summary>
/// シーンのしるし取得
/// </summary>
/// <returns>シーンの記号</returns>
int GetSceneFlag();

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
