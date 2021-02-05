#include "VisitingBackgroundShower.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "BuildBackgroundShower.h"
#include "SceneNode.h"

//SPRITE g_ReFarBackGSprites[8];
//SPRITE_ANIME g_ReFarBackGSAs[8];
//SPRITE_ANIME g_ReNearBackGSAs[9];
SPRITE g_ReNrestBackGSprites[11];
//SPRITE_ANIME g_ReNrestBackGSAs[10];
int g_TimeCountVBS = 0;
float g_ReOffsetPerFrameCountNear = 0.f;
float g_ReOffsetPerFrameCountFar = 0.f;
float g_ReOffsetPerFrameCountNrest = 0.f;

void InitVisitingBackground()
{
    /*SPRITE* temp1 = new SPRITE();
    SPRITE_ANIME* temp2 = new SPRITE_ANIME();
    for (int i = 0; i < 8; i++)
    {
        g_ReFarBackGSprites[i] = *temp1;
    }
    for (int i = 0; i < 8; i++)
    {
        g_ReFarBackGSAs[i] = *temp2;
    }
    for (int i = 0; i < 9; i++)
    {
        g_ReNearBackGSAs[i] = *temp2;
    }
    for (int i = 0; i < 10; i++)
    {
        g_ReNrestBackGSAs[i] = *temp2;
    }
    delete temp1;
    delete temp2;*/

    g_TimeCountVBS = 0;
    g_ReOffsetPerFrameCountNear = 0.f;
    g_ReOffsetPerFrameCountFar = 0.f;
    g_ReOffsetPerFrameCountNrest = 0.f;

    for (int i = 0; i < 11; i++)
    {
        g_ReNrestBackGSprites[i] = CreateSingleSprite(
            "Assets\\Sprites\\building-base.txt",
            POSITION_2D(70 + i * 54, 38),
            40, 2
        );
    }
}

void ReloadVisitingBackground()
{
    /*for (int i = 0; i < 8; i++)
    {
        g_ReFarBackGSprites[i] = *(GetBuildFarSprites() + i);
        g_ReFarBackGSAs[i] = *(GetBuildFarSAs() + i);
    }
    for (int i = 0; i < 9; i++)
    {
        g_ReNearBackGSAs[i] = *(GetBuildNearSAs() + i);
    }*/
}

void UpdateVisitingBackground()
{
    if (g_TimeCountVBS > 120)
    {
        g_ReOffsetPerFrameCountNear += 0.22f / (180.f / 120.f);
        g_ReOffsetPerFrameCountFar += 0.1f / (180.f / 120.f);
        g_ReOffsetPerFrameCountNrest += 0.967f;
    }


    int i = 0;
    while ((GetBuildFarSprites() + i)->Visible)
    {
        DrawSingleSpriteToCamBuffer(
            GetSceneNodeByName("resort")->GetCamAddr(),
            GetBuildFarSprites() + i,
            (GetBuildFarSprites() + i)->Position -
            POSITION_2D((int)g_ReOffsetPerFrameCountFar, -5)
        );
        ++i;
    }

    i = 0;
    while ((GetBuildFarSAs() + i)->SubSprites->Visible)
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("resort")->GetCamAddr(),
            GetBuildFarSAs() + i, g_TimeCountVBS % 60,
            (GetBuildFarSAs() + i)->SubSprites->Position -
            POSITION_2D((int)g_ReOffsetPerFrameCountFar, 0)
        );
        ++i;
    }

    for (int i = 0; i < 9; i++)
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("resort")->GetCamAddr(),
            GetBuildNearSAs() + i, g_TimeCountVBS % 60,
            (GetBuildNearSAs() + i)->SubSprites->Position -
            POSITION_2D((int)g_ReOffsetPerFrameCountNear, -10)
        );
    }

    for (int i = 0; i < 11; i++)
    {
        DrawSingleSpriteToCamBuffer(
            GetSceneNodeByName("resort")->GetCamAddr(),
            g_ReNrestBackGSprites + i,
            (g_ReNrestBackGSprites + i)->Position -
            POSITION_2D((int)g_ReOffsetPerFrameCountNrest, 0)
        );
    }

    ++g_TimeCountVBS;
}

void TurnOffVisitingBackground()
{

}

void ResetResortBGTimerAndOffset()
{
    g_TimeCountVBS = 0;
    g_ReOffsetPerFrameCountNear = 0.f;
    g_ReOffsetPerFrameCountFar = 0.f;
    g_ReOffsetPerFrameCountNrest = 0.f;
}
