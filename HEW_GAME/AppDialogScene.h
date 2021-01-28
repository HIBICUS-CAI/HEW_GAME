//------------------------------------------------------------------------
// �ե�������: AppDialogScene.h
// �C��: Ԓ���Ϥ����`����v���Ƥ�����
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"
#include "SpriteAnimator.h"

SPRITE_ANIME g_NextBtnSpriteAnimator;
int g_BtnAnimatorOffset = 0;

void InitDialogScene()
{
    CreateSceneNode(SCENENODE("dialog", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 40)));
    GetSceneNodeByName("dialog")->SetBaseUIO(
        GetUIObjByName("dialog"));
    ClearSceneCamBuffer(GetSceneNodeByName("dialog"));

    //-----------------------------------------
    GetUIObjByName("dialog")->
        AddBtn(UI_BUTTON(TEMP_BTN_DIALOG_1, POSITION_2D(60, 17),
            (char*)"TEST", BTN_DESIGN::LINE));

    g_NextBtnSpriteAnimator = CreateSpriteAnimator(8,
        "Assets\\SpriteAnimators\\next-arrow\\arrow",
        POSITION_2D(156, 50), 16, 8);
}

void UpdateDialogScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("dialog"));

    char* cam = GetSceneNodeByName("dialog")->GetCamAddr()->
        GetCamBuffer();
    int width = GetSceneNodeByName("dialog")->GetCamAddr()->
        CameraWidth;
    int height = GetSceneNodeByName("dialog")->GetCamAddr()->
        CameraHeight;

    for (int i = 0; i < width; i++)
    {
        *(cam + (height - 1) * width + i) = '_';
    }

    DrawSpriteAnimatorToUpdateBuffer(
        &g_NextBtnSpriteAnimator, (g_BtnAnimatorOffset++) % 60);
}

void TurnOffDialogScene()
{

}
