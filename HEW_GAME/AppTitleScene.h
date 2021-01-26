//------------------------------------------------------------------------
// ¥Õ¥¡¥¤¥ëÃû: AppTitleScene.h
// ™CÄÜ: ¥¿¥¤¥È¥ë¥·©`¥ó¤Ëév¤·¤Æ¤ÎÉùÃ÷
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
}

void TurnOffTitleScene()
{

}
