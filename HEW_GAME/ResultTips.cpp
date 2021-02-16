#include "ResultTips.h"
#include "SceneNode.h"

char g_Tips[2][80] = { "","" };
int g_WriteInFlg = 0;
int g_CanShowTips = 0;

void InitResultTips()
{
    for (int i = 0; i < 2; i++)
    {
        strcpy_s(g_Tips[i], sizeof(g_Tips[i]), "");
    }
    g_WriteInFlg = 0;
    g_CanShowTips = 0;
}

void SetResultTipsTo(const char* string)
{
    int canWrite = 1;
    for (int i = 0; i < 2; i++)
    {
        if (!strcmp(g_Tips[i], string))
        {
            canWrite = 0;
            break;
        }
    }

    if (canWrite)
    {
        strcpy_s(g_Tips[g_WriteInFlg], sizeof(g_Tips[g_WriteInFlg]), string);

        if (g_WriteInFlg)
        {
            g_WriteInFlg = 0;
        }
        else
        {
            g_WriteInFlg = 1;
        }
    }
}

void SetCanShowTipsFlg(int value)
{
    g_CanShowTips = value;
}

int GetCanShowTipsFlg()
{
    return g_CanShowTips;
}

void UpdateResultTips()
{
    if (g_CanShowTips)
    {
        GetSceneNodeByName("result")->WriteStrToCamBuffer(
            POSITION_2D(6, 38),
            g_Tips[0]
        );
        GetSceneNodeByName("result")->WriteStrToCamBuffer(
            POSITION_2D(92, 38),
            g_Tips[1]
        );
    }
}

void ResetResultTips()
{
    for (int i = 0; i < 2; i++)
    {
        strcpy_s(g_Tips[i], sizeof(g_Tips[i]), "");
    }
    g_WriteInFlg = 0;
    g_CanShowTips = 0;
}

void TurnOffResulttips()
{

}
