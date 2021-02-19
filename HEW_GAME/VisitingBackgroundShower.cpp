#include "VisitingBackgroundShower.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "BuildBackgroundShower.h"
#include "SceneNode.h"
#include "VisitingVisitorManager.h"

SPRITE g_ReNrestBackGSprites[11];
int g_TimeCountVBS = 0;
float g_ReOffsetPerFrameCountNear = 0.f;
float g_ReOffsetPerFrameCountFar = 0.f;
float g_ReOffsetPerFrameCountNrest = 0.f;

void InitVisitingBackground()
{
    g_TimeCountVBS = 0;
    g_ReOffsetPerFrameCountNear = 0.f;
    g_ReOffsetPerFrameCountFar = 0.f;
    g_ReOffsetPerFrameCountNrest = 0.f;

    for (int i = 0; i < 11; i++)
    {
        g_ReNrestBackGSprites[i] = *(GetResortSceneBase() + i);
    }
}

void ReloadVisitingBackground()
{

}

void UpdateVisitingBackground()
{
    if (ResortCanMove())
    {
        g_ReOffsetPerFrameCountNear += 0.22f / (180.f / 120.f) * SPEED_ZOOM;
        g_ReOffsetPerFrameCountFar += 0.1f / (180.f / 120.f) * SPEED_ZOOM;
        g_ReOffsetPerFrameCountNrest += 0.967f * SPEED_ZOOM;
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
