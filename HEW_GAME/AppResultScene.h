//------------------------------------------------------------------------
// ファイル名: AppResultScene.h
// 機能: 最終結果シーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

//------------------
#include "SpriteAnimator.h"
#include "GameAppStructs.h"
SPRITE_ANIME g_s;
int g_ttime;

void InitResultScene()
{
    CreateSceneNode(SCENENODE("result", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));

    GetSceneNodeByName("result")->SetBaseUIO(
        GetUIObjByName("final-result"));
    ClearSceneCamBuffer(GetSceneNodeByName("result"));

    //--------------------
    g_s = CreateSpriteAnimator(
        60, "Assets\\SpriteAnimators\\result\\C",
        POSITION_2D(0, 0), 70, 35
    );
    g_ttime = 0;
}

void UpdateResultScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("result"));

    //---------------------
    DrawSpriteAnimatorToCamBuffer(
        GetSceneNodeByName("result")->GetCamAddr(),
        &g_s, (g_ttime++) % 60, POSITION_2D(0, 0)
    );
}

void TurnOffResultScene()
{

}
