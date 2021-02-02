#include "BuilderManager.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"

SPRITE_ANIME g_WalkingBuilder;
SPRITE_ANIME g_StandingBuilder;
SPRITE_ANIME g_CurrBuildArrow;
int g_TimeCountBM = 0;
int g_TimeCountBMArrow = 0;
int g_TimeCountBMBuilder = 0;
int g_TimeCountBMMoving = 0;
int g_MovFlg = 0;

void InitBuilder()
{
    SetCurrBuildingPosByBuilder(0);
    g_TimeCountBM = 0;
    g_TimeCountBMArrow = 0;
    g_TimeCountBMBuilder = 0;
    g_TimeCountBMMoving = 0;
    g_WalkingBuilder = CreateSpriteAnimator(30,
        "Assets\\SpriteAnimators\\builder\\builder-walk",
        POSITION_2D(0, 0), 20, 10);
    g_StandingBuilder = CreateSpriteAnimator(8,
        "Assets\\SpriteAnimators\\builder\\builder-stand",
        POSITION_2D(0, 0), 20, 10);
    g_CurrBuildArrow = CreateSpriteAnimator(8,
        "Assets\\SpriteAnimators\\next-arrow\\arrow",
        POSITION_2D(0, 0), 16, 8);
}

void UpdateBuilder()
{
    DrawSpriteAnimatorToCamBuffer(
        GetSceneNodeByName("build")->GetCamAddr(),
        &g_CurrBuildArrow, g_TimeCountBMArrow++ % 60,
        POSITION_2D(52, 6)
    );

    if (g_MovFlg == BUILDER_STOP)
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("build")->GetCamAddr(),
            &g_StandingBuilder, g_TimeCountBMBuilder++ % 60,
            POSITION_2D(30, 30)
        );
    }
    else if (g_MovFlg == BUILDER_GO_LEFT)
    {
        if (GetCurrBuildingPosByBuilder() > 0)
        {
            DrawSpriteAnimatorToCamBuffer(
                GetSceneNodeByName("build")->GetCamAddr(),
                &g_WalkingBuilder, 60 - (g_TimeCountBMBuilder % 60),
                POSITION_2D(30, 30)
            );
            g_TimeCountBMBuilder += 2;
            if (g_TimeCountBMMoving > 60)
            {
                SetBuilderMovFlg(BUILDER_STOP);
                g_TimeCountBMMoving = 0;
                SetCurrBuildingPosByBuilder(
                    GetCurrBuildingPosByBuilder() - 1
                );
            }
            else
            {
                ++g_TimeCountBMMoving;
            }
        }
        else
        {
            DrawSpriteAnimatorToCamBuffer(
                GetSceneNodeByName("build")->GetCamAddr(),
                &g_StandingBuilder, g_TimeCountBMBuilder++ % 60,
                POSITION_2D(30, 30)
            );
            SetBuilderMovFlg(BUILDER_STOP);
        }
    }
    else if (g_MovFlg == BUILDER_GO_RIGHT)
    {
        if (GetCurrBuildingPosByBuilder() < BUILDINGS_SIZE)
        {
            DrawSpriteAnimatorToCamBuffer(
                GetSceneNodeByName("build")->GetCamAddr(),
                &g_WalkingBuilder, g_TimeCountBMBuilder % 60,
                POSITION_2D(30, 30)
            );
            g_TimeCountBMBuilder += 2;
            if (g_TimeCountBMMoving > 60)
            {
                SetBuilderMovFlg(BUILDER_STOP);
                g_TimeCountBMMoving = 0;
                SetCurrBuildingPosByBuilder(
                    GetCurrBuildingPosByBuilder() + 1
                );
            }
            else
            {
                ++g_TimeCountBMMoving;
            }
        }
        else
        {
            DrawSpriteAnimatorToCamBuffer(
                GetSceneNodeByName("build")->GetCamAddr(),
                &g_StandingBuilder, g_TimeCountBMBuilder++ % 60,
                POSITION_2D(30, 30)
            );
            SetBuilderMovFlg(BUILDER_STOP);
        }
    }

    char* cam = GetSceneNodeByName("build")->GetCamAddr()->
        GetCamBuffer();
    int width = GetSceneNodeByName("build")->GetCamAddr()->
        CameraWidth;
    if (GetCurrBuildingPosByBuilder() != 10)
    {
        *(cam + 5 * width + 5) = GetCurrBuildingPosByBuilder() + 48;
    }
    else
    {
        *(cam + 5 * width + 5) = 49;
        *(cam + 5 * width + 6) = 48;
    }
}

void TurnOffBuilder()
{

}

void SetCurrBuildingPosByBuilder(int value)
{
    if (value<0 || value>BUILDINGS_SIZE)
    {
        ErrorLogI1("you cannot set this value to curr", value);
        return;
    }
    SetCurrBuildingPos(value);
}

int GetCurrBuildingPosByBuilder()
{
    return GetCurrBuildingPos();
}

void SetBuilderMovFlg(int value)
{
    g_MovFlg = value;
}

int GetBuilderMovFlg()
{
    return g_MovFlg;
}

void ResetBuilder()
{
    int g_TimeCountBM = 0;
    int g_TimeCountBMArrow = 0;
    int g_TimeCountBMBuilder = 0;
    int g_TimeCountBMMoving = 0;
    int g_MovFlg = 0;
    SetCurrBuildingPosByBuilder(0);
}
