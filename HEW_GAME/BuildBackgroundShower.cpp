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

    for (int i = 0; i < 10; i++)
    {
        g_NrestBackGSprites[i] = CreateSingleSprite(
            "Assets\\Sprites\\building-base.txt",
            POSITION_2D(100 + i * 60, 38),
            40, 2
        );
    }
}

void LoadDefaultPart1()
{
    g_FarBackGSprites[0] = CreateSingleSprite(
        "Assets\\Sprites\\hill1.txt", POSITION_2D(0, 0),
        30, 10);
    g_FarBackGSprites[1] = CreateSingleSprite(
        "Assets\\Sprites\\hill2.txt", POSITION_2D(150, 0),
        30, 10);

    g_FarBackGSAs[0] = CreateSpriteAnimator(4,
        "Assets\\SpriteAnimators\\sun\\sun",
        POSITION_2D(100, -2), 20, 10);
    g_FarBackGSAs[1] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud1-",
        POSITION_2D(40, 2), 17, 5);
}
void LoadDefaultPart2()
{
    g_FarBackGSAs[2] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud3-",
        POSITION_2D(80, 4), 17, 5);
    g_FarBackGSAs[3] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud5-",
        POSITION_2D(130, 1), 20, 5);

    g_NearBackGSAs[0] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake1-",
        POSITION_2D(0, 0), 30, 30);
    g_NearBackGSAs[1] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake2-",
        POSITION_2D(30, 0), 30, 30);
}
void LoadDefaultPart3()
{
    g_NearBackGSAs[2] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake3-",
        POSITION_2D(60, 0), 30, 30);
    g_NearBackGSAs[3] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake4-",
        POSITION_2D(90, 0), 30, 30);
    g_NearBackGSAs[4] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake5-",
        POSITION_2D(120, 0), 30, 30);
    g_NearBackGSAs[5] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake6-",
        POSITION_2D(150, 0), 30, 30);
}
void LoadDefaultPart4()
{
    g_NearBackGSAs[6] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake7-",
        POSITION_2D(180, 0), 30, 30);
    g_NearBackGSAs[7] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake8-",
        POSITION_2D(210, 0), 30, 30);
    g_NearBackGSAs[8] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake9-",
        POSITION_2D(240, 0), 30, 30);
}

void LoadBeachPart1()
{
    g_FarBackGSAs[0] = CreateSpriteAnimator(4,
        "Assets\\SpriteAnimators\\sun\\sun",
        POSITION_2D(70, 14), 20, 10);
    g_FarBackGSAs[1] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud1-",
        POSITION_2D(40, 2), 17, 5);
    g_FarBackGSAs[2] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud3-",
        POSITION_2D(80, 4), 17, 5);
    g_FarBackGSAs[3] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud5-",
        POSITION_2D(130, 1), 20, 5);
}
void LoadBeachPart2()
{
    g_NearBackGSAs[0] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea1-",
        POSITION_2D(0, 0), 30, 30);
    g_NearBackGSAs[1] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea2-",
        POSITION_2D(30, 0), 30, 30);
    g_NearBackGSAs[2] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea3-",
        POSITION_2D(60, 0), 30, 30);
}
void LoadBeachPart3()
{
    g_NearBackGSAs[3] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea4-",
        POSITION_2D(90, 0), 30, 30);
    g_NearBackGSAs[4] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea5-",
        POSITION_2D(120, 0), 30, 30);
    g_NearBackGSAs[5] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea6-",
        POSITION_2D(150, 0), 30, 30);
}
void LoadBeachPart4()
{
    g_NearBackGSAs[6] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea7-",
        POSITION_2D(180, 0), 30, 30);
    g_NearBackGSAs[7] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea8-",
        POSITION_2D(210, 0), 30, 30);
    g_NearBackGSAs[8] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea9-",
        POSITION_2D(240, 0), 30, 30);
}

void LoadDesertPart1()
{
    g_FarBackGSAs[0] = CreateSpriteAnimator(10,
        "Assets\\SpriteAnimators\\moon\\moon",
        POSITION_2D(90, 0), 20, 10);
    g_FarBackGSAs[1] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud1-",
        POSITION_2D(10, 2), 17, 5);
    g_FarBackGSAs[2] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud3-",
        POSITION_2D(40, 4), 17, 5);
    g_FarBackGSAs[3] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud5-",
        POSITION_2D(130, 1), 20, 5);
}
void LoadDesertPart2()
{
    g_NearBackGSAs[0] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand1-",
        POSITION_2D(0, 0), 30, 30);
    g_NearBackGSAs[1] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand2-",
        POSITION_2D(30, 0), 30, 30);
    g_NearBackGSAs[2] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand3-",
        POSITION_2D(60, 0), 30, 30);
}
void LoadDesertPart3()
{
    g_NearBackGSAs[3] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand4-",
        POSITION_2D(90, 0), 30, 30);
    g_NearBackGSAs[4] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand5-",
        POSITION_2D(120, 0), 30, 30);
    g_NearBackGSAs[5] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand6-",
        POSITION_2D(150, 0), 30, 30);
}
void LoadDesertPart4()
{
    g_NearBackGSAs[6] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand7-",
        POSITION_2D(180, 0), 30, 30);
    g_NearBackGSAs[7] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand8-",
        POSITION_2D(210, 0), 30, 30);
    g_NearBackGSAs[8] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand9-",
        POSITION_2D(240, 0), 30, 30);
}

void ReloadBackgroundByPlayingStage()
{
    InitBuildBackground();
    int stageID = GetPlayingStage();
    DebugLogI1("latest stage:", stageID);
    switch (stageID)
    {
    case STAGE_DEFAULT:
        LoadDefaultPart1();
        LoadDefaultPart2();
        LoadDefaultPart3();
        LoadDefaultPart4();
        break;

    case STAGE_BEACH:
        LoadBeachPart1();
        LoadBeachPart2();
        LoadBeachPart3();
        LoadBeachPart4();
        break;

    case STAGE_DESERT:
        LoadDesertPart1();
        LoadDesertPart2();
        LoadDesertPart3();
        LoadDesertPart4();
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
