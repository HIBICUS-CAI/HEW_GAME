#include "ResultFinalThought.h"
#include "AppDeclared.h"
#include "SceneNode.h"
#include "ResultTips.h"
#include "FinalResult.h"
#include "DataSyncer.h"

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
                    if (CanUseDataBase())
                    {
                        CloseUpdateStageRankThread();
                        int stage = GetPlayingStage();
                        Sleep(1000);
                        GetStageRankAndBuildCount(&stage);

                        int rankS = GetDBRankArray()[0];
                        int rankA = GetDBRankArray()[1];
                        int rankB = GetDBRankArray()[2];
                        int rankC = GetDBRankArray()[3];
                        int sum = rankS + rankA + rankB + rankC;
                        rankS =
                            (int)((float)rankS /
                                (float)sum * 100.f);
                        rankA =
                            (int)((float)rankA /
                                (float)sum * 100.f);
                        rankB =
                            (int)((float)rankB /
                                (float)sum * 100.f);
                        rankC =
                            (int)((float)rankC /
                                (float)sum * 100.f);

                        char lenS[11];
                        char lenA[11];
                        char lenB[11];
                        char lenC[11];
                        char temp[2];
                        strcpy_s(temp, sizeof(temp), "-");
                        strcpy_s(lenS, sizeof(lenS), "");
                        strcpy_s(lenA, sizeof(lenA), "");
                        strcpy_s(lenB, sizeof(lenB), "");
                        strcpy_s(lenC, sizeof(lenC), "");
                        for (int i = 0; i < rankS / 10; i++)
                        {
                            strcat_s(lenS, sizeof(lenS), temp);
                        }
                        for (int i = 0; i < rankA / 10; i++)
                        {
                            strcat_s(lenA, sizeof(lenA), temp);
                        }
                        for (int i = 0; i < rankB / 10; i++)
                        {
                            strcat_s(lenB, sizeof(lenB), temp);
                        }
                        for (int i = 0; i < rankC / 10; i++)
                        {
                            strcat_s(lenC, sizeof(lenC), temp);
                        }

                        char rankRate[128];
                        sprintf_s(rankRate, sizeof(rankRate),
                            "“–ƒXƒe[ƒW‚rƒ‰ƒ“ƒN@%s %d%%",
                            lenS,
                            rankS);
                        (GetUIObjByName("save-data")->Texts + 0)->
                            ChangeTextTo(rankRate);
                        sprintf_s(rankRate, sizeof(rankRate),
                            "“–ƒXƒe[ƒW‚`ƒ‰ƒ“ƒN@%s %d%%",
                            lenA,
                            rankA);
                        (GetUIObjByName("save-data")->Texts + 1)->
                            ChangeTextTo(rankRate);
                        sprintf_s(rankRate, sizeof(rankRate),
                            "“–ƒXƒe[ƒW‚aƒ‰ƒ“ƒN@%s %d%%",
                            lenB,
                            rankB);
                        (GetUIObjByName("save-data")->Texts + 2)->
                            ChangeTextTo(rankRate);
                        sprintf_s(rankRate, sizeof(rankRate),
                            "“–ƒXƒe[ƒW‚bƒ‰ƒ“ƒN@%s %d%%",
                            lenC,
                            rankC);
                        (GetUIObjByName("save-data")->Texts + 3)->
                            ChangeTextTo(rankRate);

                        char builds[3][32];
                        for (int i = 0; i < 3; i++)
                        {
                            switch (GetDBBuildArray()[i] + 1)
                            {
                            case B_TYPE_HOTSPRING:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "‰·ò");
                                break;
                            case B_TYPE_FOOD:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "HŽ–ˆ");
                                break;
                            case B_TYPE_POOL:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "ƒv[ƒ‹");
                                break;
                            case B_TYPE_DRINK:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "ˆù‚Ý•¨“X");
                                break;
                            case B_TYPE_CINEMA:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "‰f‰æŠÙ");
                                break;
                            case B_TYPE_KARAOKE:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "ƒJƒ‰ƒIƒP");
                                break;
                            case B_TYPE_RESTPLACE:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "h”‘’n");
                                break;
                            case B_TYPE_MAKEBYHAND:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "Žèì‚è“X");
                                break;

                            default:
                                break;
                            }

                            char mostType[64];
                            sprintf_s(
                                mostType, sizeof(mostType),
                                "Å‚àŽg‚í‚ê‚½Ž{Ý %s %s %s",
                                builds[0], builds[1], builds[2]
                            );
                            (GetUIObjByName("save-data")->Texts + 4)->
                                ChangeTextTo(mostType);
                        }
                    }
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
