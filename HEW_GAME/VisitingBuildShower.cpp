#include "VisitingBuildShower.h"
#include "BuildingShower.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"

int g_VBudSTimeCount = 0;
float g_VBudSOffsetPerFrameCount = 0.f;
POSITION_2D g_VisitingBuildPosOrigin[BUILDINGS_SIZE];

void InitVisitingBuildShower()
{
    g_VBudSOffsetPerFrameCount = 0.f;
    g_VBudSTimeCount = 0;

    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        g_VisitingBuildPosOrigin[i] =
            POSITION_2D(70 + 54 + i * 54, 0);
    }
}

void ResetVisitingBuildShowerTimer()
{
    g_VBudSOffsetPerFrameCount = 0.f;
    g_VBudSTimeCount = 0;
}

void UpdateVisitingBuildShower()
{
    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        if ((GetEditBuildingsArray() + i)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            int canSeeBlank = 0;
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
                GetSceneNodeByName("resort")->GetCamAddr(),
                GetBuildingSprites() + spriteOffset,
                g_VisitingBuildPosOrigin[i] -
                POSITION_2D(
                    (int)g_VBudSOffsetPerFrameCount - widthOffset,
                    -heightOffset
                ),
                canSeeBlank
            );
        }
    }

    if (g_VBudSTimeCount > 120)
    {
        g_VBudSOffsetPerFrameCount += 0.967f;
    }
    ++g_VBudSTimeCount;
}

void TurnOffVisitingBuildShower()
{

}
