#include "BuilderManager.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"

SPRITE_ANIME g_WalkingBuilder;
SPRITE_ANIME g_StandingBuilder;
SPRITE_ANIME g_CurrBuildArrow;
int g_TimeCountBM = 0;

void InitBuilder()
{
    g_TimeCountBM = 0;
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
        &g_CurrBuildArrow, g_TimeCountBM++ % 60,
        POSITION_2D(52, 6)
    );

    if (g_TimeCountBM % 240 < 120)
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("build")->GetCamAddr(),
            &g_StandingBuilder, g_TimeCountBM++ % 60,
            POSITION_2D(30, 30)
        );
    }
    else
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("build")->GetCamAddr(),
            &g_WalkingBuilder, g_TimeCountBM++ % 60,
            POSITION_2D(30, 30)
        );
    }
}

void TurnOffBuilder()
{

}

void SetCurrBuildingPos(int value)
{

}

int GetCurrBuildingPos()
{

}
