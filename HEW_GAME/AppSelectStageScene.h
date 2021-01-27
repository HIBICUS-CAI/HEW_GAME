//------------------------------------------------------------------------
// ¥Õ¥¡¥¤¥ëÃû: AppSelectStageScene.h
// ™CÄÜ: ¥¹¥Æ©`¥¸ßx’k¥·©`¥ó¤Ëév¤·¤Æ¤ÎÉùÃ÷
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitSelectStageScene()
{
    CreateSceneNode(SCENENODE("select", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));
    GetSceneNodeByName("select")->SetBaseUIO(
        GetUIObjByName("stage-select"));
    ClearSceneCamBuffer(GetSceneNodeByName("select"));
}

void UpdateSelectStageScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("select"));
}

void TurnOffSelectStageScene()
{

}
