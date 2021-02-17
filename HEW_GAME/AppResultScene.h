//------------------------------------------------------------------------
// �ե�������: AppResultScene.h
// �C��: ��K�Y�����`����v���Ƥ�����
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
