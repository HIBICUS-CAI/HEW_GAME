//------------------------------------------------------------------------
// ファイル名: SceneNode.h
// 機能: シーンに関しての機能
//------------------------------------------------------------------------

#pragma once

#include "AppDeclared.h"
#include "UIObject.h"
#include "DeclaredValues.h"

/// <summary>
/// 番号であるシーンを取り出す
/// </summary>
/// <param name="id">シーン番号</param>
/// <returns>取り出したいシーンに指向のポインタ</returns>
SCENENODE* GetSceneNodeByID(int id);

/// <summary>
/// 名前であるシーンを取り出す
/// </summary>
/// <param name="name">シーンの名前</param>
/// <returns>取り出したいシーンに指向のポインタ</returns>
SCENENODE* GetSceneNodeByName(const char* name);

/// <summary>
/// シーン配列を初期化する
/// </summary>
void InitSceneNodes();

/// <summary>
/// あるシーンのカメラバッファを整理する
/// </summary>
/// <param name="sceneNode">シーン指向のポインタ</param>
void ClearSceneCamBuffer(SCENENODE* sceneNode);

/// <summary>
/// シーン配列に新たなシーンを追加
/// </summary>
/// <param name="sceneNode">新たなシーンの内容</param>
void CreateSceneNode(SCENENODE sceneNode);

/// <summary>
/// あるシーンの内容を更新用バッファに書き込む
/// </summary>
/// <param name="sceneNode">シーン指向のポインタ</param>
void DrawScene(SCENENODE* sceneNode);
