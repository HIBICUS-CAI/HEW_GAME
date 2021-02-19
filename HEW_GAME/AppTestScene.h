//------------------------------------------------------------------------
// ファイル名: AppTestScene.h
// 機能: テスト用シーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitTestScene()
{
    CreateSceneNode(SCENENODE("test", NULL,
        SCENECAMERA(POSITION_2D(1, 1), 160, 30)));
    GetSceneNodeByName("test")->SetBaseUIO(
        GetUIObjByName("final-result"));
}

void UpdateTestScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("test"));
}

void TurnOffTestScene()
{

}
