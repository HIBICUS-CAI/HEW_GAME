#include "VisitingVisitorManager.h"

int g_VisitingMovFlg = 0;
int g_VVMTimeCount = 0;

void InitVisitingVisitorManager()
{
    g_VisitingMovFlg = 0;
    g_VVMTimeCount = 0;
}

void UpdateVisitingVisitorManager()
{
    if (g_VVMTimeCount > 120)
    {
        g_VisitingMovFlg = 1;
    }
    else
    {
        g_VisitingMovFlg = 0;
    }

    g_VVMTimeCount += 1;
}

void TurnOffVisitingVisitorManager()
{

}

int ResortCanMove()
{
    return g_VisitingMovFlg;
}

void ResetResortMoveFlag()
{
    g_VisitingMovFlg = 0;
    g_VVMTimeCount = 0;
}
