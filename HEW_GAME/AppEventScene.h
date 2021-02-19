//------------------------------------------------------------------------
// ファイル名: AppEventScene.h
// 機能: 施設イベントシーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"
#include "SceneManager.h"

//--------------------------------
int g_EventTimeCount = 0;

void InitEventScene()
{
    CreateSceneNode(SCENENODE("event", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));

    GetSceneNodeByName("event")->SetBaseUIO(
        GetUIObjByName("empty"));
    ClearSceneCamBuffer(GetSceneNodeByName("event"));
}

void UpdateEventScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("event"));

    //-------------------------------------
    ++g_EventTimeCount;
    char* cam = GetSceneNodeByName("event")->GetCamAddr()->
        GetCamBuffer();
    int width = GetSceneNodeByName("event")->GetCamAddr()->
        CameraWidth;
    int height = GetSceneNodeByName("event")->GetCamAddr()->
        CameraHeight;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(cam + i * width + j) = '-';
        }
    }

    DebugLogI1("event scene has used", g_EventTimeCount);
    if (g_EventTimeCount > 60)
    {
        g_EventTimeCount = 0;
        SwitchSceneToName("feeling");
    }
}

void TurnOffEventScene()
{

}
