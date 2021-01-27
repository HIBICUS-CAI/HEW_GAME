//------------------------------------------------------------------------
// ファイル名: AppNamingScene.h
// 機能: 名前付きシーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitNamingScene()
{
    CreateSceneNode(SCENENODE("naming", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 30)));
    GetSceneNodeByName("naming")->SetBaseUIO(
        GetUIObjByName("naming"));
    ClearSceneCamBuffer(GetSceneNodeByName("naming"));
}

void UpdateNamingScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("naming"));
}

void TurnOffNamingScene()
{

}
