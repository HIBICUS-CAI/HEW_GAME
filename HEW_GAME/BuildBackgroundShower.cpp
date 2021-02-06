#include "BuildBackgroundShower.h"
#include "SpriteAnimator.h"
#include "AppDeclared.h"
#include "SceneNode.h"
#include "BuilderManager.h"

SPRITE g_FarBackGSprites[8];
SPRITE_ANIME g_FarBackGSAs[8];
SPRITE_ANIME g_NearBackGSAs[9];
SPRITE g_NrestBackGSprites[10];
SPRITE_ANIME g_NrestBackGSAs[10];
int g_TimeCountBBS = 0;
float g_OffsetPerFrameCountNear = 0.f;
float g_OffsetPerFrameCountFar = 0.f;
float g_OffsetPerFrameCountNrest = 0.f;

void InitBuildBackground()
{
    SPRITE* temp1 = new SPRITE();
    SPRITE_ANIME* temp2 = new SPRITE_ANIME();
    for (int i = 0; i < 8; i++)
    {
        g_FarBackGSprites[i] = *temp1;
    }
    for (int i = 0; i < 8; i++)
    {
        g_FarBackGSAs[i] = *temp2;
    }
    for (int i = 0; i < 9; i++)
    {
        g_NearBackGSAs[i] = *temp2;
    }
    for (int i = 0; i < 10; i++)
    {
        g_NrestBackGSAs[i] = *temp2;
    }
    delete temp1;
    delete temp2;

    g_TimeCountBBS = 0;
    g_OffsetPerFrameCountNear = 0.f;
    g_OffsetPerFrameCountFar = 0.f;
    g_OffsetPerFrameCountNrest = 0.f;
}

void ReloadBackgroundByPlayingStage()
{
    InitBuildBackground();
    int stageID = GetPlayingStage();
    DebugLogI1("latest stage:", stageID);
    switch (stageID)
    {
    case STAGE_DEFAULT:
        for (int i = 0; i < 2; i++)
        {
            g_FarBackGSprites[i] = *(GetHillsInStage1() + i);
        }
        for (int i = 0; i < 4; i++)
        {
            g_FarBackGSAs[i] = *(GetSunCloudInStage1() + i);
        }
        for (int i = 0; i < 9; i++)
        {
            g_NearBackGSAs[i] = *(GetLakeSAs() + i);
        }
        for (int i = 0; i < 10; i++)
        {
            g_NrestBackGSprites[i] = *(GetBuildSceneBase() + i);
        }

        break;

    case STAGE_BEACH:
        for (int i = 0; i < 4; i++)
        {
            g_FarBackGSAs[i] = *(GetSunCloudInStage2() + i);
        }
        for (int i = 0; i < 9; i++)
        {
            g_NearBackGSAs[i] = *(GetBeachSAs() + i);
        }
        for (int i = 0; i < 10; i++)
        {
            g_NrestBackGSprites[i] = *(GetBuildSceneBase() + i);
        }

        break;

    case STAGE_DESERT:
        for (int i = 0; i < 4; i++)
        {
            g_FarBackGSAs[i] = *(GetMoonCloudInStage3() + i);
        }
        for (int i = 0; i < 9; i++)
        {
            g_NearBackGSAs[i] = *(GetDesertSAs() + i);
        }
        for (int i = 0; i < 10; i++)
        {
            g_NrestBackGSprites[i] = *(GetBuildSceneBase() + i);
        }

        break;

    default:
        ErrorLogI1("you cannot go with this stage:", stageID);
        break;
    }
}

void UpdateBuildBackground()
{
    int offsetByCurrBuild = GetCurrBuildingPos();
    int builderMoveFlg = GetBuilderMovFlg();
    if (offsetByCurrBuild == 0)
    {
        if (builderMoveFlg == BUILDER_GO_RIGHT)
        {
            g_OffsetPerFrameCountNear += 0.22f;
            g_OffsetPerFrameCountFar += 0.1f;
            g_OffsetPerFrameCountNrest += 0.967f;
        }
    }
    else if (offsetByCurrBuild == BUILDINGS_SIZE)
    {
        if (builderMoveFlg == BUILDER_GO_LEFT)
        {
            g_OffsetPerFrameCountNear -= 0.22f;
            g_OffsetPerFrameCountFar -= 0.1f;
            g_OffsetPerFrameCountNrest -= 0.967f;
        }
    }
    else
    {
        if (builderMoveFlg == BUILDER_GO_RIGHT)
        {
            g_OffsetPerFrameCountNear += 0.22f;
            g_OffsetPerFrameCountFar += 0.1f;
            g_OffsetPerFrameCountNrest += 0.967f;
        }
        else if (builderMoveFlg == BUILDER_GO_LEFT)
        {
            g_OffsetPerFrameCountNear -= 0.22f;
            g_OffsetPerFrameCountFar -= 0.1f;
            g_OffsetPerFrameCountNrest -= 0.967f;
        }
    }

    int i = 0;
    while ((g_FarBackGSprites + i)->Visible)
    {
        DrawSingleSpriteToCamBuffer(
            GetSceneNodeByName("build")->GetCamAddr(),
            g_FarBackGSprites + i,
            (g_FarBackGSprites + i)->Position -
            POSITION_2D((int)g_OffsetPerFrameCountFar, -5)
        );
        ++i;
    }

    i = 0;
    while ((g_FarBackGSAs + i)->SubSprites->Visible)
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("build")->GetCamAddr(),
            g_FarBackGSAs + i, g_TimeCountBBS % 60,
            (g_FarBackGSAs + i)->SubSprites->Position -
            POSITION_2D((int)g_OffsetPerFrameCountFar, 0)
        );
        ++i;
    }

    for (int i = 0; i < 9; i++)
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("build")->GetCamAddr(),
            g_NearBackGSAs + i, g_TimeCountBBS % 60,
            (g_NearBackGSAs + i)->SubSprites->Position -
            POSITION_2D((int)g_OffsetPerFrameCountNear, -10)
        );
    }

    for (int i = 0; i < 10; i++)
    {
        DrawSingleSpriteToCamBuffer(
            GetSceneNodeByName("build")->GetCamAddr(),
            g_NrestBackGSprites + i,
            (g_NrestBackGSprites + i)->Position -
            POSITION_2D((int)g_OffsetPerFrameCountNrest, 0)
        );
    }

    ++g_TimeCountBBS;
}

void TurnOffBuildBackground()
{

}

SPRITE* GetBuildFarSprites()
{
    return g_FarBackGSprites;
}

SPRITE_ANIME* GetBuildFarSAs()
{
    return g_FarBackGSAs;
}

SPRITE_ANIME* GetBuildNearSAs()
{
    return g_NearBackGSAs;
}
