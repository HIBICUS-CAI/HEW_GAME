#include "VisitingVisitorManager.h"

int g_VisitingMovFlg = 0;
int g_VVMTimeCount = 0;
float g_FrameTimeCount = 0.f;
int g_WaitTime = 50;

void InitVisitingVisitorManager()
{
    g_VisitingMovFlg = 0;
    g_VVMTimeCount = 0;
    g_FrameTimeCount = 0.f;
    g_WaitTime = 50;
}

void UpdateVisitingVisitorManager()
{
    if (g_VVMTimeCount > 120)
    {
        //-----------------------------------
        /*g_FrameTimeCount += 1.f;
        if (!((int)g_FrameTimeCount % 54))
        {
            g_VisitingMovFlg = 0;
            if (g_WaitTime--)
            {
                g_FrameTimeCount -= 1.033f;
            }
            else
            {
                g_VisitingMovFlg = 1;
                g_FrameTimeCount += 1.033f;
                g_WaitTime = 50;
            }
        }
        else
        {
            g_VisitingMovFlg = 1;
        }*/
        g_VisitingMovFlg = 1;
        //-----------------------------------
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
    g_FrameTimeCount = 0.f;
    g_WaitTime = 50;
}
