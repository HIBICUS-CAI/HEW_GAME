//------------------------------------------------------------------------
// ファイル名: VisitorThoughtManager.h
// 機能: 各観光客が遊ぶ時感想の作成
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// 管理機能によって一つ種類の観光客に一つの感想を作成
/// </summary>
/// <param name="visitorType">観光客の種類</param>
/// <param name="buildType">施設の種類</param>
/// <param name="buildEvent">施設の内容</param>
void CreateSingleVisitorThoughtByManager(VISITOR_TYPE visitorType, int buildType, int buildEvent);
