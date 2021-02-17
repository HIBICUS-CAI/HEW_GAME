#include "FinalResult.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"
#include "UIObject.h"

#define S_RANK_OFFSET 0
#define A_RANK_OFFSET 1
#define B_RANK_OFFSET 2
#define C_RANK_OFFSET 3

int g_Score = 50;
SPRITE_ANIME g_RankSA[4];
int g_RankOffset = 0;
int g_TimeCountFR = 0;
int g_IsGoingToShow = 0;

void LoadRankS()
{
    SPRITE_ANIME* temp = new SPRITE_ANIME();
    *temp = CreateSpriteAnimator(
        60, "Assets\\SpriteAnimators\\result\\S",
        POSITION_2D(-71, 2), 70, 35
    );
    g_RankSA[S_RANK_OFFSET] = *temp;
    delete temp;
}

void LoadRankA()
{
    SPRITE_ANIME* temp = new SPRITE_ANIME();
    *temp = CreateSpriteAnimator(
        60, "Assets\\SpriteAnimators\\result\\A",
        POSITION_2D(-71, 2), 70, 35
    );
    g_RankSA[A_RANK_OFFSET] = *temp;
    delete temp;
}

void LoadRankB()
{
    SPRITE_ANIME* temp = new SPRITE_ANIME();
    *temp = CreateSpriteAnimator(
        60, "Assets\\SpriteAnimators\\result\\B",
        POSITION_2D(-71, 2), 70, 35
    );
    g_RankSA[B_RANK_OFFSET] = *temp;
    delete temp;
}

void LoadRankC()
{
    SPRITE_ANIME* temp = new SPRITE_ANIME();
    *temp = CreateSpriteAnimator(
        60, "Assets\\SpriteAnimators\\result\\C",
        POSITION_2D(-71, 2), 70, 35
    );
    g_RankSA[C_RANK_OFFSET] = *temp;
    delete temp;
}

void InitFinalResult()
{
    g_Score = 50;
    g_RankOffset = 0;
    g_TimeCountFR = 0;
    g_IsGoingToShow = 0;

    LoadRankS();
    LoadRankA();
    LoadRankB();
    LoadRankC();
}

void CountFinalRank()
{
    g_RankOffset = 0;

    if (g_Score <= 60)
    {
        g_RankOffset = C_RANK_OFFSET;
    }
    else if (g_Score <= 75)
    {
        g_RankOffset = B_RANK_OFFSET;
    }
    else
    {
        int canBeS = 0;
        for (int i = 0; i < VISITOR_MAX_SIZE; i++)
        {
            if ((GetVisitorArray() + i)->Type ==
                VISITOR_TYPE::RABBIT ||
                (GetVisitorArray() + i)->Type ==
                VISITOR_TYPE::WHALE ||
                (GetVisitorArray() + i)->Type ==
                VISITOR_TYPE::CAMEL)
            {
                canBeS = 1;
                break;
            }
        }

        if (canBeS)
        {
            g_RankOffset = S_RANK_OFFSET;
        }
        else
        {
            g_RankOffset = A_RANK_OFFSET;
        }
    }
}

void UpdateFinalResult()
{
    if (g_IsGoingToShow)
    {
        DrawSpriteAnimatorToCamBuffer(
            GetSceneNodeByName("result")->GetCamAddr(),
            g_RankSA + g_RankOffset, (g_TimeCountFR++) % 60,
            (g_RankSA + g_RankOffset)->SubSprites->Position
        );

        if (g_TimeCountFR >= 120)
        {
            g_TimeCountFR = 0;
        }

        if ((g_RankSA + g_RankOffset)->SubSprites->Position.posX <
            GetSceneNodeByName("result")->GetCamAddr()->CameraWidth / 2 -
            (g_RankSA + g_RankOffset)->SubSprites->Width / 2)
        {
            ++(g_RankSA + g_RankOffset)->SubSprites->Position.posX;
        }
    }
}

void ResetFinalResult()
{
    if ((g_RankSA + g_RankOffset)->SubSprites->Visible)
    {
        for (int j = 0; j < MAXSIZE_PER_SPRITE_FRAME; j++)
        {
            g_RankSA[g_RankOffset].GetSubSpriteByOffset(j)->Position =
                POSITION_2D(-71, 2);
        }
    }

    g_Score = 50;
    g_RankOffset = 0;
    g_TimeCountFR = 0;
    g_IsGoingToShow = 0;

    if (GetSceneNodeByName("result") != NULL)
    {
        ClearSceneCamBuffer(GetSceneNodeByName("result"));
        GetSceneNodeByName("result")->SetBaseUIO(GetUIObjByName("empty"));
        SetSelectedBtn(GetUIObjByName("empty")->Buttons);
    }
}

void TurnOffFinalResult()
{

}

int GetVisitorsCountByType(VISITOR_TYPE type)
{
    int count = 0;
    for (int i = 0; i < VISITOR_MAX_SIZE; i++)
    {
        if ((GetVisitorArray() + i)->IsUsing &&
            (GetVisitorArray() + i)->Type == type)
        {
            ++count;
        }
    }

    return count;
}

void VisitorFeelVeryGood(VISITOR_TYPE visitorType)
{
    if (visitorType != VISITOR_TYPE::NONE)
    {
        int count = GetVisitorsCountByType(visitorType);
        g_Score += count * 4;
    }
    else
    {
        g_Score += 4;
    }
}

void VisitorFeelGood(VISITOR_TYPE visitorType)
{
    if (visitorType != VISITOR_TYPE::NONE)
    {
        int count = GetVisitorsCountByType(visitorType);
        g_Score += count * 2;
    }
    else
    {
        g_Score += 2;
    }
}

void VisitorFeelAlright(VISITOR_TYPE visitorType)
{
    if (visitorType != VISITOR_TYPE::NONE)
    {
        int count = GetVisitorsCountByType(visitorType);
        g_Score += count * 1;
    }
    else
    {
        g_Score += 1;
    }
}

void VisitorFeelBad(VISITOR_TYPE visitorType)
{
    if (visitorType != VISITOR_TYPE::NONE)
    {
        int count = GetVisitorsCountByType(visitorType);
        g_Score -= count * 2;
    }
    else
    {
        g_Score -= 2;
    }
}

void VisitorFeelVeryBad(VISITOR_TYPE visitorType)
{
    if (visitorType != VISITOR_TYPE::NONE)
    {
        int count = GetVisitorsCountByType(visitorType);
        g_Score -= 4;
    }
    else
    {
        g_Score -= 4;
    }
}

int GetShowRankFlg()
{
    return g_IsGoingToShow;
}

void SetShowRankFlg(int value)
{
    if (value)
    {
        g_IsGoingToShow = 1;
    }
    else
    {
        g_IsGoingToShow = 0;
    }
}
