//------------------------------------------------------------------------
// ファイル名: UIObject.h
// 機能: ＵＩアイテムに関しての処理
//------------------------------------------------------------------------

#pragma once

#include <stdlib.h>
#include "DefinedValues.h"
#include "Structs.h"

/// <summary>
/// ＵＩアイテム配列を初期化する
/// </summary>
void InitUIObj();

/// <summary>
/// アイテムの番号であるＵＩアイテムを取り出す
/// </summary>
/// <param name="id">欲しいＵＩアイテムの番号</param>
/// <returns>番号に応じているＵＩアイテム</returns>
UIOBJECT* GetUIObjByID(int id);

/// <summary>
/// アイテムの名前であるＵＩアイテムを取り出す
/// </summary>
/// <param name="name">欲しいＵＩアイテムの名前</param>
/// <returns>名前に応じているＵＩアイテム</returns>
UIOBJECT* GetUIObjByName(const char* name);

/// <summary>
/// ＵＩアイテムを作り出す
/// </summary>
/// <param name="name">アイテムの名前</param>
/// <param name="startPoint">アイテムの始点座標</param>
/// <param name="width">アイテムの長さ</param>
/// <param name="height">アイテムの高さ</param>
/// <param name="design">アイテム枠のデザイン</param>
/// <param name="parent">このアイテムの親アイテム</param>
/// <param name="child">このアイテムの子アイテム</param>
/// <param name="visiblity">アイテムの可視性</param>
/// <returns>作れたアイテムのポインタ</returns>
UIOBJECT* CreateUIO(const char* name, POSITION_2D startPoint, int width, int height,
    UIO_DESIGN design, UIOBJECT* parent = NULL, UIOBJECT* child = NULL,
    int visiblity = 0);

/// <summary>
/// ＵＩアイテムを更新用バッファに書き込む
/// </summary>
/// <param name="uiObject">書き込みたいアイテムに指向のポインタ</param>
void DrawUIO(UIOBJECT* uiObject);

/// <summary>
/// アイテム中の文字内容を更新用バッファに書き込む
/// </summary>
/// <param name="uiObject">書き込みたいアイテムに指向のポインタ</param>
void DrawTextInUIO(UIOBJECT* uiObject);

/// <summary>
/// アイテム中のボタン内容を更新用バッファに書き込む
/// </summary>
/// <param name="uiObject">書き込みたいアイテムに指向のポインタ</param>
void DrawBtnInUIO(UIOBJECT* uiObject);
