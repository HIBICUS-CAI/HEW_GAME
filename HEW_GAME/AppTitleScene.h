//------------------------------------------------------------------------
// �ե�������: AppTitleScene.h
// �C��: �����ȥ륷�`����v���Ƥ�����
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitTitleScene()
{
    CreateSceneNode(SCENENODE("title", NULL,
        SCENECAMERA(POSITION_2D(0, 0), 179, 60)));
    GetSceneNodeByName("title")->SetBaseUIO(GetUIObjByName("title"));
}

void UpdateTitleScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("title"));

    int width = GetSceneNodeByName("title")->GetCamAddr()->CameraWidth;
    int height = GetSceneNodeByName("title")->GetCamAddr()->CameraHeight;
    char* cam = GetSceneNodeByName("title")->GetCamAddr()->GetCamBuffer();

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(cam + i * width + j) = '.';
        }
    }
}

void TurnOffTitleScene()
{

}
