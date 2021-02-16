#include "ResultFinalThought.h"
#include "AppDeclared.h"
#include "SceneNode.h"

#define FINAL_THOUGHTS_SIZE 6
char g_FinalThought[FINAL_THOUGHTS_SIZE][128] = { "","","","","","" };
int g_GoingToShowFinalThought = 1;
int g_FinalThoughtShowingTime = 120;
int g_TimeCountRFT = 0;
POSITION_2D g_StrPosition[FINAL_THOUGHTS_SIZE];

void InitResultFinalThought()
{
    for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
    {
        strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]), "");
        g_StrPosition[i] = POSITION_2D(-20, 14 + 2 * i);
    }
    g_GoingToShowFinalThought = 1;
    g_FinalThoughtShowingTime = 120;
    g_TimeCountRFT = 0;
}

void CreateResultFinalThought()
{
    // 宿泊地がない
    // 空けてる場所が長い
    // 施設が多すぎ
    // 食事or飲み物がない
    // 同じ種類の施設が多すぎ
}

void UpdateResultFinalThought()
{
    if (g_GoingToShowFinalThought)
    {
        if (g_StrPosition->posX <=
            (GetSceneNodeByName("result")->
                GetCamAddr()->CameraWidth / 2))
        {
            for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
            {
                if (strcmp(g_FinalThought[i], ""))
                {
                    GetSceneNodeByName("result")->
                        WriteStrToCamBuffer(g_StrPosition[i], g_FinalThought[i]);
                    ++g_StrPosition[i].posX;
                }
            }
        }
        else
        {
            if (g_TimeCountRFT <= g_FinalThoughtShowingTime)
            {
                ++g_TimeCountRFT;
                for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
                {
                    if (strcmp(g_FinalThought[i], ""))
                    {
                        GetSceneNodeByName("result")->
                            WriteStrToCamBuffer(g_StrPosition[i], g_FinalThought[i]);
                    }
                }
            }
            else if (g_StrPosition->posX <=
                GetSceneNodeByName("result")->
                GetCamAddr()->CameraWidth)
            {
                for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
                {
                    if (strcmp(g_FinalThought[i], ""))
                    {
                        GetSceneNodeByName("result")->
                            WriteStrToCamBuffer(g_StrPosition[i], g_FinalThought[i]);
                        ++g_StrPosition[i].posX;
                    }
                }
            }
            else
            {
                g_GoingToShowFinalThought = 0;
            }
        }

    }
}

void ResetResultFinalThought()
{
    for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
    {
        strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]), "");
        g_StrPosition[i] = POSITION_2D(-20, 14 + 2 * i);
    }
    g_GoingToShowFinalThought = 1;
    g_FinalThoughtShowingTime = 120;
    g_TimeCountRFT = 0;
}

void TurnOffResultFinalThought()
{

}
