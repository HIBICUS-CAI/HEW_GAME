#include "FinalResult.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"

#define S_RANK_OFFSET 0
#define A_RANK_OFFSET 1
#define B_RANK_OFFSET 2
#define C_RANK_OFFSET 3

int g_Score = 50;
SPRITE_ANIME g_RankSA[4];

//-------------------------
int g_tttt = 0;

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

    LoadRankS();
    LoadRankA();
    LoadRankB();
    LoadRankC();
}

void UpdateFinalResult()
{
    DrawSpriteAnimatorToCamBuffer(
        GetSceneNodeByName("result")->GetCamAddr(),
        g_RankSA + 3, (g_tttt++) % 60, POSITION_2D(1, 1)
    );
}

void ResetFinalResult()
{
    g_Score = 50;
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
