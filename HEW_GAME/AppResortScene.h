//------------------------------------------------------------------------
// �ե�������: AppBuildScene.h
// �C��: ʩ�O���ɥ��`����v���Ƥ�����
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"
#include "SceneManager.h"

//--------------------------------
int g_ResortTimeCount = 0;

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
    for (int i = 41; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(cam + i * width + j) = '.';
        }
    }

    //-------------------------------------
    ++g_ResortTimeCount;
    DebugLogI1("resort scene has used", g_ResortTimeCount);
    if (g_ResortTimeCount > 800)
    {
        g_ResortTimeCount = 0;
        SwitchSceneToName("event");
    }
}

void TurnOffResortScene()
{

}
