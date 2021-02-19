//------------------------------------------------------------------------
// ファイル名: AppBuildScene.h
// 機能: 施設作成シーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitBuildScene()
{
    CreateSceneNode(SCENENODE("build", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 120, 60)));

    GetSceneNodeByName("build")->SetBaseUIO(
        GetUIObjByName("build"));
    ClearSceneCamBuffer(GetSceneNodeByName("build"));
}

void UpdateBuildScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("build"));

    char* cam = GetSceneNodeByName("build")->GetCamAddr()->
        GetCamBuffer();
    int width = GetSceneNodeByName("build")->GetCamAddr()->
        CameraWidth;
    int height = GetSceneNodeByName("build")->GetCamAddr()->
        CameraHeight;
    for (int i = 0; i < width; i++)
    {
        *(cam + 40 * width + i) = '-';
    }
    for (int i = 41; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(cam + i * width + j / 2 * 2) = '.';
        }
    }
}

void TurnOffBuildScene()
{

}
