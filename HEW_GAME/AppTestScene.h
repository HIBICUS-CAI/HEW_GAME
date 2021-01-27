//------------------------------------------------------------------------
// �ե�������: AppTestScene.h
// �C��: �ƥ����å��`����v���Ƥ�����
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitTestScene()
{
    CreateSceneNode(SCENENODE("test", NULL,
        SCENECAMERA(POSITION_2D(1, 1), 160, 30)));
    GetSceneNodeByName("test")->SetBaseUIO(
        GetUIObjByName("final-result"));
}

void UpdateTestScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("test"));
}

void TurnOffTestScene()
{

}
