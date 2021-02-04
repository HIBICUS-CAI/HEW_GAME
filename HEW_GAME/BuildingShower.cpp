#include "BuildingShower.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"
#include "BuilderManager.h"

#define SPRING_OFFSET 0
#define FOOD_OFFSET 1
#define POOL_OFFSET 2
#define DRINK_OFFSET 3
#define CINEMA_OFFSET 4
#define KARAOKE_OFFSET 5
#define HOTEL_OFFSET 6
#define CAMP_OFFSET 7
#define HANDMAKE_OFFSET 8

float g_TimeCountBUILDS = 0.f;
float g_OffsetPerFrameCount = 0.f;
SPRITE g_BuildingSprites[9];
SPRITE_ANIME g_BuildingHammer;
POSITION_2D g_BuildingPosOrigin[BUILDINGS_SIZE];

void InitBuildingShower()
{
    g_BuildingSprites[SPRING_OFFSET] =
        CreateSingleSprite("Assets\\Sprites\\spring.txt",
            POSITION_2D(0, 0), 40, 25);
    g_BuildingSprites[FOOD_OFFSET] =
        CreateSingleSprite("Assets\\Sprites\\food.txt",
            POSITION_2D(0, 0), 40, 25);
    g_BuildingSprites[POOL_OFFSET] =
        CreateSingleSprite("Assets\\Sprites\\pool.txt",
            POSITION_2D(0, 0), 40, 25);
    g_BuildingSprites[DRINK_OFFSET] =
        CreateSingleSprite("Assets\\Sprites\\drink.txt",
            POSITION_2D(0, 0), 40, 22);
    g_BuildingSprites[CINEMA_OFFSET] =
        CreateSingleSprite("Assets\\Sprites\\cinema.txt",
            POSITION_2D(0, 0), 40, 25);
    g_BuildingSprites[KARAOKE_OFFSET] =
        CreateSingleSprite("Assets\\Sprites\\newkara.txt",
            POSITION_2D(0, 0), 25, 20);
    g_BuildingSprites[HOTEL_OFFSET] =
        CreateSingleSprite("Assets\\Sprites\\hotel.txt",
            POSITION_2D(0, 0), 40, 25);
    g_BuildingSprites[CAMP_OFFSET] =
        CreateSingleSprite("Assets\\Sprites\\camp.txt",
            POSITION_2D(0, 0), 40, 12);
    g_BuildingSprites[HANDMAKE_OFFSET] =
        CreateSingleSprite("Assets\\Sprites\\handmake.txt",
            POSITION_2D(0, 0), 40, 25);

    g_BuildingHammer = CreateSpriteAnimator(9,
        "Assets\\SpriteAnimators\\hammer\\hammer",
        POSITION_2D(40, 20), 40, 20);

    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        g_BuildingPosOrigin[i] =
            POSITION_2D(100 + i * 60, 0);
    }

    g_OffsetPerFrameCount = 0.f;
}

void ResetBuildingShowerTimer()
{
    g_OffsetPerFrameCount = 0.f;
}

void UpdateBuildingShower()
{
    int offsetByCurrBuild = GetCurrBuildingPos();
    int builderMoveFlg = GetBuilderMovFlg();
    int canSeeBlank = 0;
    if (offsetByCurrBuild == 0)
    {
        if (builderMoveFlg == BUILDER_GO_RIGHT)
        {
            g_OffsetPerFrameCount += 0.967f;
        }
    }
    else if (offsetByCurrBuild == BUILDINGS_SIZE)
    {
        if (builderMoveFlg == BUILDER_GO_LEFT)
        {
            g_OffsetPerFrameCount -= 0.967f;
        }
    }
    else
    {
        if (builderMoveFlg == BUILDER_GO_RIGHT)
        {
            g_OffsetPerFrameCount += 0.967f;
        }
        else if (builderMoveFlg == BUILDER_GO_LEFT)
        {
            g_OffsetPerFrameCount -= 0.967f;
        }
    }

    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        DebugLogI2("status", i, (int)(GetEditBuildingsArray() + i)->Status);
        DebugLogI2("type", i, (int)(GetEditBuildingsArray() + i)->Type);
        DebugLogI2("event", i, (int)(GetEditBuildingsArray() + i)->Event);


        if ((GetEditBuildingsArray() + i)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            int spriteOffset = 0;
            int heightOffset = 0;
            int widthOffset = 0;
            int type = (GetEditBuildingsArray() + i)->Type;
            switch (type)
            {
            case B_TYPE_HOTSPRING:
                spriteOffset = SPRING_OFFSET;
                heightOffset = 38 - 25;
                widthOffset = 0;
                canSeeBlank = 0;
                break;

            case B_TYPE_FOOD:
                spriteOffset = FOOD_OFFSET;
                heightOffset = 38 - 25;
                widthOffset = 0;
                canSeeBlank = 1;
                break;

            case B_TYPE_POOL:
                spriteOffset = POOL_OFFSET;
                heightOffset = 38 - 25;
                canSeeBlank = 1;
                break;

            case B_TYPE_DRINK:
                spriteOffset = DRINK_OFFSET;
                heightOffset = 38 - 22;
                widthOffset = 0;
                canSeeBlank = 1;
                break;

            case B_TYPE_CINEMA:
                spriteOffset = CINEMA_OFFSET;
                heightOffset = 38 - 25;
                canSeeBlank = 1;
                break;

            case B_TYPE_KARAOKE:
                spriteOffset = KARAOKE_OFFSET;
                heightOffset = 38 - 20;
                widthOffset = 10;
                canSeeBlank = 1;
                break;

            case B_TYPE_RESTPLACE:
                if ((GetEditBuildingsArray() + i)->
                    Event == B_EVNT_RESTHOTEL)
                {
                    spriteOffset = HOTEL_OFFSET;
                    heightOffset = 38 - 25;
                    widthOffset = 0;
                    canSeeBlank = 0;
                }
                else if ((GetEditBuildingsArray() + i)->
                    Event == B_EVNT_RESTCAMP)
                {
                    spriteOffset = CAMP_OFFSET;
                    heightOffset = 38 - 12;
                    widthOffset = 0;
                    canSeeBlank = 0;
                }
                break;

            case B_TYPE_MAKEBYHAND:
                spriteOffset = HANDMAKE_OFFSET;
                heightOffset = 38 - 25;
                widthOffset = 0;
                canSeeBlank = 1;
                break;

            default:
                break;
            }

            DrawSingleSpriteToCamBuffer(
                GetSceneNodeByName("build")->GetCamAddr(),
                g_BuildingSprites + spriteOffset,
                g_BuildingPosOrigin[i] -
                POSITION_2D((int)g_OffsetPerFrameCount - widthOffset, -heightOffset),
                canSeeBlank
            );
        }
    }
}

void TurnOffBuildingShower()
{

}

void ShowBuildingHammer()
{

}
