//------------------------------------------------------------------------
// ファイル名: BuildingShower.h
// 機能: 施設作成に関しての表示と演出処理
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

#define SPRING_OFFSET 0
#define FOOD_OFFSET 1
#define POOL_OFFSET 2
#define DRINK_OFFSET 3
#define CINEMA_OFFSET 4
#define KARAOKE_OFFSET 5
#define HOTEL_OFFSET 6
#define CAMP_OFFSET 7
#define HANDMAKE_OFFSET 8

/// <summary>
/// 施設作成に関しての表示と演出処理を初期化する
/// </summary>
void InitBuildingShower();

/// <summary>
/// 施設作成に関しての表示と演出処理を実行する
/// </summary>
void UpdateBuildingShower();

/// <summary>
/// 施設作成に関しての表示と演出処理を閉じる
/// </summary>
void TurnOffBuildingShower();

/// <summary>
/// 今作っている位置にハンマの演出を表示する
/// </summary>
void ShowBuildingHammer();

/// <summary>
/// 施設作成に関しての表示と演出処理の時間をリセットする
/// </summary>
void ResetBuildingShowerTimer();

/// <summary>
/// 各施設のスプライトを保存している配列を取得
/// </summary>
/// <returns>スプライトを保存している配列に指向のポインタ</returns>
SPRITE* GetBuildingSprites();
