//------------------------------------------------------------------------
// ファイル名: AppFeelingScene.h
// 機能: 最終感想シーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"
#include "SceneManager.h"

//--------------------------------
int g_FeelingTimeCount = 0;

void InitFeelingScene()
{
    CreateSceneNode(SCENENODE("feeling", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));

    GetSceneNodeByName("feeling")->SetBaseUIO(
        GetUIObjByName("empty"));
    ClearSceneCamBuffer(GetSceneNodeByName("feeling"));
}

void UpdateFeelingScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("feeling"));

    //-------------------------------------
    ++g_FeelingTimeCount;
    char* cam = GetSceneNodeByName("feeling")->GetCamAddr()->
        GetCamBuffer();
    int width = GetSceneNodeByName("feeling")->GetCamAddr()->
        CameraWidth;
    int height = GetSceneNodeByName("feeling")->GetCamAddr()->
        CameraHeight;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(cam + i * width + j) = '|';
        }
    }

    DebugLogI1("feeling scene has used", g_FeelingTimeCount);
    if (g_FeelingTimeCount > 60)
    {
        g_FeelingTimeCount = 0;
        SwitchSceneToName("result");
    }
}

void TurnOffFeelingScene()
{

}
