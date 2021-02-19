//------------------------------------------------------------------------
// ファイル名: AppBuildScene.h
// 機能: 施設作成シーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"
#include "SceneManager.h"

void InitResortScene()
{
    CreateSceneNode(SCENENODE("resort", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));

    GetSceneNodeByName("resort")->SetBaseUIO(
        GetUIObjByName("empty"));
    ClearSceneCamBuffer(GetSceneNodeByName("resort"));
}

void UpdateResortScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("resort"));

    char* cam = GetSceneNodeByName("resort")->GetCamAddr()->
        GetCamBuffer();
    int width = GetSceneNodeByName("resort")->GetCamAddr()->
        CameraWidth;
    int height = GetSceneNodeByName("resort")->GetCamAddr()->
        CameraHeight;
    for (int i = 0; i < width; i++)
    {
        *(cam + 40 * width + i) = '-';
    }
    /*for (int i = 0; i < (height - 41); i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(cam + (i / 2 * 2 + 41) * width + j / 4 * 4) = '.';
        }
    }*/
}

void TurnOffResortScene()
{

}
