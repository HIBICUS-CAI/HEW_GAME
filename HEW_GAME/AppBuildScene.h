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

    //-----------------------------------
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(TEMP_BTN_BUILDING_1, POSITION_2D(27, 53),
            (char*)"TEST", BTN_DESIGN::LINE));

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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(cam + i * width + j) = '.';
        }
    }
}

void TurnOffBuildScene()
{

}
