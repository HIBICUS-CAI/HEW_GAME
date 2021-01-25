//------------------------------------------------------------------------
// ファイル名: AppDeclared.h
// 機能: 拡張要素に関しての値の声明
//------------------------------------------------------------------------

#pragma once
#include "GameAppStructs.h"

#define SCENENODESIZE 20

#define START_NEW_GAME 0x0003
#define LOAD_GAME_DATA 0x0004
#define LOAD_DATA_1 0x0005
#define LOAD_DATA_2 0x0006
#define LOAD_DATA_3 0x0007
#define GAME_SIMPLY_MANUAL 0x0008
#define THIS_GAME_LINK 0x0009
#define CLOSE_SAVE_DATA 0x000a
#define CLOSE_MANUAL 0x000b
#define CLOSE_LINK 0x000c
#define DIALOG_NEXT 0x000d

/// <summary>
/// シーン配列を取得
/// </summary>
/// <returns>シーン配列</returns>
SCENENODE* GetSceneNodeArray();

/// <summary>
/// シーン配列を設定
/// </summary>
/// <param name="index">シーンの偏移量</param>
/// <param name="temp">臨時的なシーン声明</param>
void SetSceneNodeArray(int index, SCENENODE temp);

/// <summary>
/// 使っているシーンを設定
/// </summary>
/// <param name="sceneNode">シーン指向のポインタ</param>
void SetCurrScene(SCENENODE* sceneNode);

/// <summary>
/// 使っているシーンを取得
/// </summary>
/// <returns>シーン指向のポインタ</returns>
SCENENODE* GetCurrScene();
