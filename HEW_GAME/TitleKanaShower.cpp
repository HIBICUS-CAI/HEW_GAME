#include "TitleKanaShower.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"
#include "TitleBuilderShower.h"

SPRITE g_TitleKana[7];
int g_TimeCountTKS = 0;
POSITION_2D g_KanaPos[7];
int g_TimeCountLoadWaitTKS = 0;
int g_FinishWaitTKS = 0;
float g_FallDistance;

void InitTitleKanaShower()
{
    for (int i = 0; i < 7; i++)
    {
        char temp[32];
        sprintf_s(temp, sizeof(temp),
            "Assets\\Sprites\\title%d.txt", i + 1);
        g_TitleKana[i] = CreateSingleSprite(
            temp,
            POSITION_2D(0, 0), 20, 10
        );
        g_KanaPos[i] = POSITION_2D(20 * (i + 1), -10);
    }

    g_TimeCountTKS = 0;
    g_TimeCountLoadWaitTKS = 0;
    g_FinishWaitTKS = 0;
    g_FallDistance = 0.f;
}

void UpdateTitleKanaShower()
{
    if (g_TimeCountLoadWaitTKS > 65)
    {
        g_FinishWaitTKS = 1;
    }

    if (!g_FinishWaitTKS)
    {
        ++g_TimeCountLoadWaitTKS;
    }
    else
    {
        g_FallDistance = 0.5f * 9.8f *
            (0.016f * (float)g_TimeCountTKS) *
            (0.016f * (float)g_TimeCountTKS) * 30.f;

        for (int i = 0; i < 7; i++)
        {
            DrawSingleSpriteToCamBuffer(
                GetSceneNodeByName("title")->GetCamAddr(),
                g_TitleKana + i,
                POSITION_2D(g_KanaPos[i].posX,
                    g_KanaPos[i].posY + (int)g_FallDistance)
            );
        }

        if ((int)g_FallDistance < 25)
        {
            ++g_TimeCountTKS;
        }
        else
        {
            if (!GetCanShowStandBuilderFlg())
            {
                SetCanShowStandBuilderFlg(1);
            }
        }
    }
}

void TurnOffTitleKanaShower()
{

}

void ResetTitleKanaShower()
{
    g_TimeCountTKS = 0;
    g_TimeCountLoadWaitTKS = 0;
    g_FinishWaitTKS = 0;
    g_FallDistance = 0.f;
}
