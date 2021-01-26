//------------------------------------------------------------------------
// �ե�������: AppTitleScene.h
// �C��: �����ȥ륷�`����v���Ƥ�����
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitTitleScene()
{
    CreateSceneNode(SCENENODE("title", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));
    GetSceneNodeByName("title")->SetBaseUIO(GetUIObjByName("title"));
}

void UpdateTitleScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("title"));
}

void TurnOffTitleScene()
{

}
