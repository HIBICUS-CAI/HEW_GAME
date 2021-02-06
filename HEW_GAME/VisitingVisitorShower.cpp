#include "VisitingVisitorShower.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"

SPRITE_ANIME g_VisitorsInResortStand[3];
SPRITE_ANIME g_VisitorsInResortWalk[3];
int g_TimeCountVVS = 0;

void InitVisitingVisitorShower()
{
    for (int i = 0; i < 3; i++)
    {
        g_VisitorsInResortStand[i] = CreateSpriteAnimator(
            30, "Assets\\SpriteAnimators\\builder\\builder-stand",
            POSITION_2D(0, 0), 20, 10
        );
        g_VisitorsInResortWalk[i] = CreateSpriteAnimator(
            30, "Assets\\SpriteAnimators\\builder\\builder-walk",
            POSITION_2D(0, 0), 20, 10
        );
    }
    g_TimeCountVVS = 0;
}

void UpdateVisitingVisitorsShower()
{
    if (g_TimeCountVVS > 120)
    {
        for (int i = 0; i < 3; i++)
        {
            DrawSpriteAnimatorToCamBuffer(
                GetSceneNodeByName("resort")->GetCamAddr(),
                g_VisitorsInResortWalk + i,
                (g_TimeCountVVS) % 60,
                POSITION_2D(70 + 10 * i, 30)
            );
        }
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            DrawSpriteAnimatorToCamBuffer(
                GetSceneNodeByName("resort")->GetCamAddr(),
                g_VisitorsInResortStand + i,
                (g_TimeCountVVS) % 60,
                POSITION_2D(70 + 10 * i, 30)
            );
        }
    }

    g_TimeCountVVS += 1;
}

void TurnOffVisitingVisitorsShower()
{

}

void ResetVisitingVisitorShowerTime()
{
    g_TimeCountVVS = 0;
}
