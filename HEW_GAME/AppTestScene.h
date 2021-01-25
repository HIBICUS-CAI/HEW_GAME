#pragma once

#include "SceneNode.h"

void InitTestScene()
{
    CreateSceneNode(SCENENODE("test", NULL,
        SCENECAMERA(POSITION_2D(1, 1), 160, 30)));
    GetSceneNodeByName("test")->SetBaseUIO(
        GetUIObjByName("naming"));
}

void UpdateTestScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("test"));
}

void TurnOffTestScene()
{

}
