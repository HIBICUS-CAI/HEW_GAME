//------------------------------------------------------------------------
// ファイル名: AppSelectStageScene.h
// 機能: ステージ選択シーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitSelectStageScene()
{
    CreateSceneNode(SCENENODE("select", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));
    GetSceneNodeByName("select")->SetBaseUIO(
        GetUIObjByName("stage-select"));
    ClearSceneCamBuffer(GetSceneNodeByName("select"));
}

void UpdateSelectStageScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("select"));

    char* cam = GetSceneNodeByName("select")->GetCamAddr()->
        GetCamBuffer();
    int width = GetSceneNodeByName("select")->GetCamAddr()->
        CameraWidth;
    int height = GetSceneNodeByName("select")->GetCamAddr()->
        CameraHeight;
    for (int i = 0; i < width; i++)
    {
        *(cam + 55 * width + i) = '-';
    }
    for (int i = 0; i < (height - 56); i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(cam + (i + 56) * width + j / 2 * 2) = '.';
        }
    }
}

void TurnOffSelectStageScene()
{

}
