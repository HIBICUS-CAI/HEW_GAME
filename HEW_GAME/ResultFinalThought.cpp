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

    // 宿泊地がない
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
                    "このリゾートなぜ泊まる場所何一つもないですか？");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // 空けてる場所が長い
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
                    "連続未利用場所が多いね、バランスがよくないかもしれません");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // 施設が多すぎ
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
                    "施設の数が多くない？ここは遊園地ではないし");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // 食事がない
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
                    "食事処がないね、腹はペコペコになっています");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // 飲み物がない
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
                    "飲み物がないか、喉が焼いていますよ．．．");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // 同じ種類の施設が多すぎ
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
                    "温泉系の施設の数が多くない？");
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
                    "食事系の施設の数が多くない？");
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
                    "プール系の施設の数が多くない？");
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
                    "飲み物系の施設の数が多くない？");
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
                    "映画系の施設の数が多くない？");
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
                    "カラオケ系の施設の数が多くない？");
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
                    "宿泊地系の施設の数が多くない？");
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
                    "手作り系の施設の数が多くない？");
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
                    "このリゾートなかなか楽しいですね");
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
                            "当ステージＳランク　%s %d%%",
                            lenS,
                            rankS);
                        (GetUIObjByName("save-data")->Texts + 0)->
                            ChangeTextTo(rankRate);
                        sprintf_s(rankRate, sizeof(rankRate),
                            "当ステージＡランク　%s %d%%",
                            lenA,
                            rankA);
                        (GetUIObjByName("save-data")->Texts + 1)->
                            ChangeTextTo(rankRate);
                        sprintf_s(rankRate, sizeof(rankRate),
                            "当ステージＢランク　%s %d%%",
                            lenB,
                            rankB);
                        (GetUIObjByName("save-data")->Texts + 2)->
                            ChangeTextTo(rankRate);
                        sprintf_s(rankRate, sizeof(rankRate),
                            "当ステージＣランク　%s %d%%",
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
                                    "温泉");
                                break;
                            case B_TYPE_FOOD:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "食事処");
                                break;
                            case B_TYPE_POOL:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "プール");
                                break;
                            case B_TYPE_DRINK:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "飲み物店");
                                break;
                            case B_TYPE_CINEMA:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "映画館");
                                break;
                            case B_TYPE_KARAOKE:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "カラオケ");
                                break;
                            case B_TYPE_RESTPLACE:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "宿泊地");
                                break;
                            case B_TYPE_MAKEBYHAND:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "手作り店");
                                break;

                            default:
                                break;
                            }

                            char mostType[64];
                            sprintf_s(
                                mostType, sizeof(mostType),
                                "最も使われた施設 %s %s %s",
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
