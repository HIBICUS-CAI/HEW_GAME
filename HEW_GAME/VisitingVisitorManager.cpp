#include "VisitingVisitorManager.h"
#include "AppDeclared.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "ThoughtListManager.h"
#include "ResultFinalThought.h"

int g_VisitingMovFlg = 0;
int g_VVMTimeCount = 0;
float g_FrameTimeCount = 0.f;
int g_WaitTime = 50;
OBJECT g_BuildingBaseColl[11];
OBJECT g_VisitorsColl;
int g_IsStop = 0;
int g_CurrColliedOffset = 0;
int g_CurrOffset = 0;
int g_FinalTime = 300;
int g_ShowedNameFlg = 0;

void InitVisitingVisitorManager()
{
    g_VisitingMovFlg = 0;
    g_VVMTimeCount = 0;
    g_FrameTimeCount = 0.f;
    g_WaitTime = 50;
    g_IsStop = 0;
    g_CurrColliedOffset = 0;
    g_CurrOffset = 0;
    g_FinalTime = 300;
    g_ShowedNameFlg = 0;

    for (int i = 0; i < 11; i++)
    {
        g_BuildingBaseColl[i].Position =
            POSITION_2D(90 + 54 * i, 0);
        g_BuildingBaseColl[i].Width = 1;
        g_BuildingBaseColl[i].Height = 1;
        g_BuildingBaseColl[i].ColliRadius = 2.f;
    }

    g_VisitorsColl.Position = POSITION_2D(85, 0);
    g_VisitorsColl.Width = 10;
    g_VisitorsColl.Height = 1;
    g_VisitorsColl.ColliRadius = 1.5f;
}

void UpdateVisitingVisitorManager()
{
    if (!g_WaitTime)
    {
        g_VisitingMovFlg = 1;
    }

    if (g_VVMTimeCount > 120)
    {
        for (int i = 0; i < 11; i++)
        {
            if (!g_IsStop &&
                g_VisitorsColl.IsCollied(g_BuildingBaseColl[i]))
            {
                if (!i && !g_ShowedNameFlg)
                {
                    g_ShowedNameFlg = 1;

                    CreateThoughtToQueue(
                        GetCurrColliedBuildingType(),
                        GetCurrColliedBuildingEvent()
                    );
                }

                if (i > 0 &&
                    (GetEditBuildingsArray() + i - 1)->Status ==
                    BUILDING_STATUS::CONFIRMED)
                {
                    g_IsStop = 1;
                    g_VisitingMovFlg = 0;
                    g_WaitTime = 50;
                    g_CurrColliedOffset = i;
                    DebugLogI1("this type:",
                        GetCurrColliedBuildingType());
                    DebugLogI1("this event:",
                        GetCurrColliedBuildingEvent());

                    CreateThoughtToQueue(
                        GetCurrColliedBuildingType(),
                        GetCurrColliedBuildingEvent()
                    );
                }

                g_CurrOffset = i;
                break;
            }
        }

        if (!g_VisitingMovFlg)
        {
            --g_WaitTime;
        }
        else
        {
            g_FrameTimeCount += 0.985f * SPEED_ZOOM;
            for (int i = 0; i < 11; i++)
            {
                g_BuildingBaseColl[i].Position =
                    POSITION_2D(90 + 54 * i, 0) -
                    POSITION_2D((int)g_FrameTimeCount, 0);
            }
        }

        if (!g_WaitTime)
        {
            g_VisitingMovFlg = 1;
            if (!g_VisitorsColl.IsCollied(
                g_BuildingBaseColl[g_CurrColliedOffset]))
            {
                g_WaitTime = 50;
                g_IsStop = 0;
            }
        }

        if (g_CurrOffset == 10)
        {
            g_VisitingMovFlg = 0;
            if (!(--g_FinalTime))
            {
                SwitchSceneToName("result");
                CreateResultFinalThought();
                LoadSound(
                    "Assets\\Sounds\\result.mp3",
                    "result"
                );
                if (GetPlayingStage()==STAGE_DEFAULT)
                {
                    UninstallSound(GetSoundFile("stage_default"));
                }
                else if (GetPlayingStage()==STAGE_BEACH)
                {
                    UninstallSound(GetSoundFile("stage_beach"));
                }
                else if (GetPlayingStage()==STAGE_DESERT)
                {
                    UninstallSound(GetSoundFile("stage_desert"));
                }
                PlayBackgroundMusic(GetSoundFile("result"));
            }
        }
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
    g_IsStop = 0;
    g_CurrColliedOffset = 0;
    g_CurrOffset = 0;
    g_FinalTime = 300;
    g_ShowedNameFlg = 0;

    for (int i = 0; i < 11; i++)
    {
        g_BuildingBaseColl[i].Position =
            POSITION_2D(90 + 54 * i, 0);
        g_BuildingBaseColl[i].Width = 1;
        g_BuildingBaseColl[i].Height = 1;
        g_BuildingBaseColl[i].ColliRadius = 2.f;
    }

    g_VisitorsColl.Position = POSITION_2D(85, 0);
    g_VisitorsColl.Width = 10;
    g_VisitorsColl.Height = 1;
    g_VisitorsColl.ColliRadius = 1.5f;
}

int GetCurrColliedBuildingType()
{
    if (g_CurrColliedOffset > 0)
    {
        return (GetEditBuildingsArray() +
            g_CurrColliedOffset - 1)->Type;
    }
    else
    {
        return -1;
    }
}

int GetCurrColliedBuildingEvent()
{
    if (g_CurrColliedOffset > 0)
    {
        return (GetEditBuildingsArray() +
            g_CurrColliedOffset - 1)->Event;
    }
    else
    {
        return -1;
    }
}

char* GetResortName()
{
    char name[34];
    sprintf_s(name, sizeof(name), "%s%s",
        GetSubName1ArrayByOffset(GetConfirmedSubName1And2()[0]),
        GetSubName2ArrayByOffset(GetConfirmedSubName1And2()[1]));
    DebugLog(name);
    return name;
}
