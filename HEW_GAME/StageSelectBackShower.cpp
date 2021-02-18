#include "StageSelectBackShower.h"
#include "AppDeclared.h"
#include "DeclaredValues.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"

SPRITE g_FarBackGSpritesSSBS[8];
SPRITE_ANIME g_FarBackGSAsSSBS[8];
SPRITE_ANIME g_NearBackGSAsSSBS[9];
SPRITE g_NrestBackGSpritesSSBS[10];
SPRITE_ANIME g_NrestBackGSAsSSBS[10];
int g_TimeCountSSBS = 0;
float g_OffsetPerFrameCountNearSSBS = 0.f;
float g_OffsetPerFrameCountFarSSBS = 0.f;
float g_OffsetPerFrameCountNrestSSBS = 0.f;
int g_SavedBtnEvent = -1;
int g_SwitchDirection = 0;

void InitStageSelectBackGShower()
{
    g_TimeCountSSBS = 0;
    g_OffsetPerFrameCountNearSSBS = 0.f;
    g_OffsetPerFrameCountFarSSBS = 0.f;
    g_OffsetPerFrameCountNrestSSBS = 0.f;
    g_SavedBtnEvent = -1;
    g_SwitchDirection = 0;
}

void UpdateStageSelectBackGShower()
{
    int btnEvent = GetSelectedBtn()->Event;
    if (btnEvent != g_SavedBtnEvent)
    {
        g_SavedBtnEvent = btnEvent;
        SPRITE* tempS = new SPRITE();
        SPRITE_ANIME* tempSA = new SPRITE_ANIME();
        for (int i = 0; i < 8; i++)
        {
            g_FarBackGSpritesSSBS[i] = *tempS;
            g_FarBackGSAsSSBS[i] = *tempSA;
        }
        for (int i = 0; i < 9; i++)
        {
            g_NearBackGSAsSSBS[i] = *tempSA;
        }
        for (int i = 0; i < 10; i++)
        {
            g_NrestBackGSpritesSSBS[i] = *tempS;
            g_NrestBackGSAsSSBS[i] = *tempSA;

        }
        delete tempS;
        delete tempSA;
        switch (g_SavedBtnEvent)
        {
        case BEGIN_STAGE_1:
            for (int i = 0; i < 2; i++)
            {
                g_FarBackGSpritesSSBS[i] = *(GetHillsInStage1() + i);
            }
            for (int i = 0; i < 4; i++)
            {
                g_FarBackGSAsSSBS[i] = *(GetSunCloudInStage1() + i);
            }
            for (int i = 0; i < 9; i++)
            {
                g_NearBackGSAsSSBS[i] = *(GetLakeSAs() + i);
            }
            for (int i = 0; i < 10; i++)
            {
                //g_NrestBackGSpritesSSBS[i] = *(GetBuildSceneBase() + i);
            }

            break;

        case BEGIN_STAGE_2:
            for (int i = 0; i < 4; i++)
            {
                g_FarBackGSAsSSBS[i] = *(GetSunCloudInStage2() + i);
            }
            for (int i = 0; i < 9; i++)
            {
                g_NearBackGSAsSSBS[i] = *(GetBeachSAs() + i);
            }
            for (int i = 0; i < 10; i++)
            {
                //g_NrestBackGSpritesSSBS[i] = *(GetBuildSceneBase() + i);
            }

            break;

        case BEGIN_STAGE_3:
            for (int i = 0; i < 4; i++)
            {
                g_FarBackGSAsSSBS[i] = *(GetMoonCloudInStage3() + i);
            }
            for (int i = 0; i < 9; i++)
            {
                g_NearBackGSAsSSBS[i] = *(GetDesertSAs() + i);
            }
            for (int i = 0; i < 10; i++)
            {
                //g_NrestBackGSpritesSSBS[i] = *(GetBuildSceneBase() + i);
            }

            break;

        default:
            break;
        }
    }

    if ((int)g_OffsetPerFrameCountNearSSBS > 90)
    {
        g_SwitchDirection = 1;
    }
    else if ((int)g_OffsetPerFrameCountNearSSBS < 0)
    {
        g_SwitchDirection = 0;
    }

    if (!g_SwitchDirection)
    {
        g_OffsetPerFrameCountNearSSBS += 0.22f / (180.f / 120.f);
        g_OffsetPerFrameCountFarSSBS += 0.1f / (180.f / 120.f);
        g_OffsetPerFrameCountNrestSSBS += 0.967f;
    }
    else
    {
        g_OffsetPerFrameCountNearSSBS -= 0.22f / (180.f / 120.f);
        g_OffsetPerFrameCountFarSSBS -= 0.1f / (180.f / 120.f);
        g_OffsetPerFrameCountNrestSSBS -= 0.967f;
    }

    int i = 0;
    while ((g_FarBackGSpritesSSBS + i)->Visible)
    {
        DrawSingleSpriteToCamBuffer(
            GetSceneNodeByName("select")->GetCamAddr(),
            g_FarBackGSpritesSSBS + i,
            (g_FarBackGSpritesSSBS + i)->Position -
            POSITION_2D((int)g_OffsetPerFrameCountFarSSBS, -20)
        );
        ++i;
    }

    i = 0;
    while ((g_FarBackGSAsSSBS + i)->SubSprites->Visible)
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("select")->GetCamAddr(),
            g_FarBackGSAsSSBS + i, g_TimeCountSSBS % 60,
            (g_FarBackGSAsSSBS + i)->SubSprites->Position -
            POSITION_2D((int)g_OffsetPerFrameCountFarSSBS, -15)
        );
        ++i;
    }

    for (int i = 0; i < 9; i++)
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("select")->GetCamAddr(),
            g_NearBackGSAsSSBS + i, g_TimeCountSSBS % 60,
            (g_NearBackGSAsSSBS + i)->SubSprites->Position -
            POSITION_2D((int)g_OffsetPerFrameCountNearSSBS, -25)
        );
    }

    /*for (int i = 0; i < 11; i++)
    {
        DrawSingleSpriteToCamBuffer(
            GetSceneNodeByName("resort")->GetCamAddr(),
            g_ReNrestBackGSprites + i,
            (g_ReNrestBackGSprites + i)->Position -
            POSITION_2D((int)g_ReOffsetPerFrameCountNrest, 0)
        );
    }*/

    ++g_TimeCountSSBS;
}

void TurnOffStageSelectBackGShower()
{

}

void ResetStageSelectBackGShower()
{
    g_TimeCountSSBS = 0;
    g_OffsetPerFrameCountNearSSBS = 0.f;
    g_OffsetPerFrameCountFarSSBS = 0.f;
    g_OffsetPerFrameCountNrestSSBS = 0.f;
    g_SavedBtnEvent = -1;
    g_SwitchDirection = 0;

    if (GetSceneNodeByName("select") != NULL)
    {
        ClearSceneCamBuffer(GetSceneNodeByName("select"));
    }
}
