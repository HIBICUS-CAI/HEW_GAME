#include "TitleBuilderShower.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"

SPRITE_ANIME g_TitleWalkBuilder[4];
SPRITE_ANIME g_TitleStandBuilder;
int g_TimeCountTBS = 0;
POSITION_2D g_PosToShow[4];
float g_PosOffsetDelta = 0.f;
int g_SwitchFlg = 1;
int g_TimeCountLoadWait = 0;
int g_FinishWait = 0;
int g_CanShowStandBuilder = 0;
float g_StandBuilderFallDis = 0.f;
int g_TimeCountTBSFall = 0;

void InitTitleBuilderShower()
{
    SPRITE_ANIME* temp = new SPRITE_ANIME();
    *temp = CreateSpriteAnimator(
        30, "Assets\\SpriteAnimators\\builder\\builder-walk",
        POSITION_2D(0, 0), 20, 10
    );
    for (int i = 0; i < 4; i++)
    {
        g_TitleWalkBuilder[i] = *temp;
    }
    *temp = CreateSpriteAnimator(
        8, "Assets\\SpriteAnimators\\builder\\builder-stand",
        POSITION_2D(140, -10), 20, 10
    );
    g_TitleStandBuilder = *temp;
    delete temp;

    int titleSceneWidth = 178;
    int titleSceneHeight = 59;
    for (int i = 0; i < 4; i++)
    {
        if (i % 2)
        {
            g_PosToShow[i] = POSITION_2D(-21, titleSceneHeight - (i + 1) * 10);
        }
        else
        {
            g_PosToShow[i] = POSITION_2D(titleSceneWidth, titleSceneHeight - (i + 1) * 10);
        }
    }

    g_TimeCountTBS = 0;
    g_PosOffsetDelta = 0.f;
    g_SwitchFlg = 1;
    g_TimeCountLoadWait = 0;
    g_FinishWait = 0;
    g_CanShowStandBuilder = 0;
    g_StandBuilderFallDis = 0.f;
    g_TimeCountTBSFall = 0;
}

void UpdateTitleBuilderShower()
{
    if (g_CanShowStandBuilder)
    {
        g_StandBuilderFallDis = 0.5f * 9.8f *
            (0.016f * (float)g_TimeCountTBSFall) *
            (0.016f * (float)g_TimeCountTBSFall) * 30.f;

        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("title")->GetCamAddr(),
            &g_TitleStandBuilder, g_TimeCountTBS % 60,
            POSITION_2D(
                g_TitleStandBuilder.SubSprites->Position.posX,
                g_TitleStandBuilder.SubSprites->Position.posY+
                (int)g_StandBuilderFallDis
            )
        );

        if ((int)g_StandBuilderFallDis < 20)
        {
            ++g_TimeCountTBSFall;
        }
    }

    if (g_TimeCountLoadWait>65)
    {
        g_FinishWait = 1;
    }

    if (!g_FinishWait)
    {
        ++g_TimeCountLoadWait;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (i % 2)
            {
                int offset = 0;
                if (g_SwitchFlg)
                {
                    offset = g_TimeCountTBS % 60;
                }
                else
                {
                    offset = 60 - g_TimeCountTBS % 60 - 1;
                }
                DrawSpriteAnimatorToCamBuffer(
                    GetSceneNodeByName("title")->GetCamAddr(),
                    g_TitleWalkBuilder + i, offset,
                    g_PosToShow[i] + POSITION_2D((int)g_PosOffsetDelta, 0)
                );
            }
            else
            {
                int offset = 0;
                if (g_SwitchFlg)
                {
                    offset = 60 - g_TimeCountTBS % 60 - 1;
                }
                else
                {
                    offset = g_TimeCountTBS % 60;
                }
                DrawSpriteAnimatorToCamBuffer(
                    GetSceneNodeByName("title")->GetCamAddr(),
                    g_TitleWalkBuilder + i, offset,
                    g_PosToShow[i] - POSITION_2D((int)g_PosOffsetDelta, 0)
                );
            }
        }

        ++g_TimeCountTBS;
        if (g_TimeCountTBS >= 120)
        {
            g_TimeCountTBS = 0;
        }


        if (g_SwitchFlg)
        {
            g_PosOffsetDelta += 0.9f;
        }
        else
        {
            g_PosOffsetDelta -= 0.9f;
        }

        if (g_PosOffsetDelta > 200.f)
        {
            g_SwitchFlg = 0;
        }
        else if (g_PosOffsetDelta < -1.f)
        {
            g_SwitchFlg = 1;
        }
    }
}

void TurnOffTitleBuilderShower()
{

}

void ResetTitleBuilderShower()
{
    g_TimeCountTBS = 0;
    g_PosOffsetDelta = 0.f;
    g_SwitchFlg = 1;
    g_TimeCountLoadWait = 0;
    g_FinishWait = 0;
    g_CanShowStandBuilder = 0;
    g_StandBuilderFallDis = 0.f;
    g_TimeCountTBSFall = 0;

    ClearSceneCamBuffer(GetSceneNodeByName("title"));
}

int GetCanShowStandBuilderFlg()
{
    return g_CanShowStandBuilder;
}

void SetCanShowStandBuilderFlg(int value)
{
    if (value)
    {
        g_CanShowStandBuilder = 1;
    }
    else
    {
        g_CanShowStandBuilder = 0;
    }
}
