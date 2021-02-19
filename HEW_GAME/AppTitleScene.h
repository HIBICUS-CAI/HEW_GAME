//------------------------------------------------------------------------
// ファイル名: AppTitleScene.h
// 機能: タイトルシーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitTitleScene()
{
    CreateSceneNode(SCENENODE("title", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));
    GetSceneNodeByName("title")->SetBaseUIO(GetUIObjByName("title"));
    ClearSceneCamBuffer(GetSceneNodeByName("title"));
}

void UpdateTitleScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("title"));
}

void TurnOffTitleScene()
{

}
