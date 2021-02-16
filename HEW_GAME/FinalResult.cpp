#include "FinalResult.h"
#include "AppDeclared.h"

int g_Score = 50;

void InitFinalResult()
{
    g_Score = 50;
}

void UpdateFinalResult()
{

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
