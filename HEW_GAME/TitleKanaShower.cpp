#include "TitleKanaShower.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"

SPRITE g_TitleKana[7];
int g_TimeCountTKS = 0;
POSITION_2D g_KanaPos[7];

void InitTitleKanaShower()
{
    g_TitleKana[0] = CreateSingleSprite(
        "Assets\\Sprites\\title1.txt",
        POSITION_2D(0, 0), 20, 10
    );
    g_TitleKana[1] = CreateSingleSprite(
        "Assets\\Sprites\\title2.txt",
        POSITION_2D(0, 0), 20, 10
    );
    g_TitleKana[2] = CreateSingleSprite(
        "Assets\\Sprites\\title3.txt",
        POSITION_2D(0, 0), 20, 10
    );
    g_TitleKana[3] = CreateSingleSprite(
        "Assets\\Sprites\\title4.txt",
        POSITION_2D(0, 0), 20, 10
    );
    g_TitleKana[4] = CreateSingleSprite(
        "Assets\\Sprites\\title5.txt",
        POSITION_2D(0, 0), 20, 10
    );
    g_TitleKana[5] = CreateSingleSprite(
        "Assets\\Sprites\\title6.txt",
        POSITION_2D(0, 0), 20, 10
    );
    g_TitleKana[6] = CreateSingleSprite(
        "Assets\\Sprites\\title7.txt",
        POSITION_2D(0, 0), 20, 10
    );

    for (int i = 0; i < 7; i++)
    {
        g_KanaPos[i] = POSITION_2D(20 * (i + 1), 2);
    }

    g_TimeCountTKS = 0;
}

void UpdateTitleKanaShower()
{
    for (int i = 0; i < 5; i++)
    {
        DrawSingleSpriteToCamBuffer(
            GetSceneNodeByName("title")->GetCamAddr(),
            g_TitleKana + i, g_KanaPos[i]
        );
    }
}

void TurnOffTitleKanaShower()
{

}

void ResetTitleKanaShower()
{
    g_TimeCountTKS = 0;
}
