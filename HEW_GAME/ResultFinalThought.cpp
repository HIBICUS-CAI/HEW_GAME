#include "ResultFinalThought.h"
#include "AppDeclared.h"
#include "SceneNode.h"
#include "ResultTips.h"
#include "FinalResult.h"

#define FINAL_THOUGHTS_SIZE 7
char g_FinalThought[FINAL_THOUGHTS_SIZE][128] = { "","","","","","","" };
int g_GoingToShowFinalThought = 1;
int g_FinalThoughtShowingTime = 120;
int g_TimeCountRFT = 0;
POSITION_2D g_StrPosition[FINAL_THOUGHTS_SIZE];

void InitResultFinalThought()
{
    for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
    {
        strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]), "");
        g_StrPosition[i] = POSITION_2D(-100, 14 + 2 * i);
    }
    g_GoingToShowFinalThought = 1;
    g_FinalThoughtShowingTime = 120;
    g_TimeCountRFT = 0;
}

void CreateResultFinalThought()
{
    BUILDING* buildingsArray = GetEditBuildingsArray();
    int thoughtFlg = 0;

    // h”‘’n‚ª‚È‚¢
    thoughtFlg = 1;
    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        if ((buildingsArray + i)->Status == BUILDING_STATUS::CONFIRMED &&
            (buildingsArray + i)->Type == B_TYPE_RESTPLACE)
        {
            thoughtFlg = 0;
            break;
        }
    }
    if (thoughtFlg)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "‚±‚ÌƒŠƒ][ƒg‚È‚º”‘‚Ü‚éêŠ‰½ˆê‚Â‚à‚È‚¢‚Å‚·‚©H");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // ‹ó‚¯‚Ä‚éêŠ‚ª’·‚¢
    thoughtFlg = 0;
    int emptyLen = 0;
    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        emptyLen = 0;
        if ((buildingsArray + i)->Status != BUILDING_STATUS::CONFIRMED)
        {
            for (int j = 0; j < BUILDINGS_SIZE - i; j++)
            {
                if ((buildingsArray + i + j)->Status != BUILDING_STATUS::CONFIRMED)
                {
                    ++emptyLen;
                }
                else
                {
                    break;
                }
            }
        }
        if (emptyLen >= 4)
        {
            thoughtFlg = 1;
            break;
        }
    }
    if (thoughtFlg)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "˜A‘±–¢—˜—pêŠ‚ª‘½‚¢‚ËAƒoƒ‰ƒ“ƒX‚ª‚æ‚­‚È‚¢‚©‚à‚µ‚ê‚Ü‚¹‚ñ");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // Ž{Ý‚ª‘½‚·‚¬
    thoughtFlg = 0;
    int confirmedCount = 0;
    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        if ((buildingsArray + i)->Status == BUILDING_STATUS::CONFIRMED)
        {
            ++confirmedCount;
        }
    }
    if (confirmedCount > 7)
    {
        thoughtFlg = 1;
    }
    if (thoughtFlg)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "Ž{Ý‚Ì”‚ª‘½‚­‚È‚¢H‚±‚±‚Í—V‰€’n‚Å‚Í‚È‚¢‚µ");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // HŽ–‚ª‚È‚¢
    thoughtFlg = 1;
    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        if ((buildingsArray + i)->Status == BUILDING_STATUS::CONFIRMED &&
            (buildingsArray + i)->Type == B_TYPE_FOOD)
        {
            thoughtFlg = 0;
            break;
        }
    }
    if (thoughtFlg)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "HŽ–ˆ‚ª‚È‚¢‚ËA• ‚ÍƒyƒRƒyƒR‚É‚È‚Á‚Ä‚¢‚Ü‚·");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // ˆù‚Ý•¨‚ª‚È‚¢
    thoughtFlg = 1;
    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        if ((buildingsArray + i)->Status == BUILDING_STATUS::CONFIRMED &&
            (buildingsArray + i)->Type == B_TYPE_DRINK)
        {
            thoughtFlg = 0;
            break;
        }
    }
    if (thoughtFlg)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "ˆù‚Ý•¨‚ª‚È‚¢‚©AA‚ªÄ‚¢‚Ä‚¢‚Ü‚·‚æDDD");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // “¯‚¶Ží—Þ‚ÌŽ{Ý‚ª‘½‚·‚¬
    int countByType[9] = { 0,0,0,0,0,0,0,0,0 };
    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        if ((buildingsArray + i)->Status == BUILDING_STATUS::CONFIRMED)
        {
            ++countByType[(buildingsArray + i)->Type];
        }
    }
    if (countByType[B_TYPE_HOTSPRING] >= 4)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "‰·òŒn‚ÌŽ{Ý‚Ì”‚ª‘½‚­‚È‚¢H");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }
    if (countByType[B_TYPE_FOOD] >= 4)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "HŽ–Œn‚ÌŽ{Ý‚Ì”‚ª‘½‚­‚È‚¢H");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }
    if (countByType[B_TYPE_POOL] >= 4)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "ƒv[ƒ‹Œn‚ÌŽ{Ý‚Ì”‚ª‘½‚­‚È‚¢H");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }
    if (countByType[B_TYPE_DRINK] >= 4)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "ˆù‚Ý•¨Œn‚ÌŽ{Ý‚Ì”‚ª‘½‚­‚È‚¢H");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }
    if (countByType[B_TYPE_CINEMA] >= 4)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "‰f‰æŒn‚ÌŽ{Ý‚Ì”‚ª‘½‚­‚È‚¢H");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }
    if (countByType[B_TYPE_KARAOKE] >= 4)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "ƒJƒ‰ƒIƒPŒn‚ÌŽ{Ý‚Ì”‚ª‘½‚­‚È‚¢H");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }
    if (countByType[B_TYPE_RESTPLACE] >= 4)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "h”‘’nŒn‚ÌŽ{Ý‚Ì”‚ª‘½‚­‚È‚¢H");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }
    if (countByType[B_TYPE_MAKEBYHAND] >= 4)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "Žèì‚èŒn‚ÌŽ{Ý‚Ì”‚ª‘½‚­‚È‚¢H");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    thoughtFlg = 1;
    for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
    {
        if (strcmp(g_FinalThought[i], ""))
        {
            thoughtFlg = 0;
            break;
        }
    }
    if (thoughtFlg)
    {
        for (int i = 0; i < FINAL_THOUGHTS_SIZE; i++)
        {
            if (!strcmp(g_FinalThought[i], ""))
            {
                strcpy_s(g_FinalThought[i], sizeof(g_FinalThought[i]),
                    "‚±‚ÌƒŠƒ][ƒg‚È‚©‚È‚©Šy‚µ‚¢‚Å‚·‚Ë");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    CountFinalRank();
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
                if (!GetCanShowTipsFlg())
                {
                    SetCanShowTipsFlg(1);
                }
                if (!GetShowRankFlg())
                {
                    SetShowRankFlg(1);
                }
                if (GetSceneNodeByName("result")->GetBaseUIOAddr() ==
                    GetUIObjByName("empty"))
                {
                    GetSceneNodeByName("result")->
                        SetBaseUIO(GetUIObjByName("final-result"));
                    SetSelectedBtn(GetUIObjByName("final-result")->Buttons);
                }
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
        g_StrPosition[i] = POSITION_2D(-100, 14 + 2 * i);
    }
    g_GoingToShowFinalThought = 1;
    g_FinalThoughtShowingTime = 120;
    g_TimeCountRFT = 0;
}

void TurnOffResultFinalThought()
{

}
