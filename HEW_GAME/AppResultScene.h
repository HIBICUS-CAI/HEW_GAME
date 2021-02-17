//------------------------------------------------------------------------
// ファイル名: AppResultScene.h
// 機能: 最終結果シーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitResultScene()
{
    CreateSceneNode(SCENENODE("result", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));

    GetSceneNodeByName("result")->SetBaseUIO(
        GetUIObjByName("empty"));
    ClearSceneCamBuffer(GetSceneNodeByName("result"));
}

void UpdateResultScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("result"));
}

void TurnOffResultScene()
{

}
