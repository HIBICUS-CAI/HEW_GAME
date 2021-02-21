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

    // �h���n���Ȃ�
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
                    "���̃��]�[�g�Ȃ����܂�ꏊ������Ȃ��ł����H");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // �󂯂Ă�ꏊ������
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
                    "�A�������p�ꏊ�������ˁA�o�����X���悭�Ȃ���������܂���");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // �{�݂�������
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
                    "�{�݂̐��������Ȃ��H�����͗V���n�ł͂Ȃ���");
                VisitorFeelBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // �H�����Ȃ�
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
                    "�H�������Ȃ��ˁA���̓y�R�y�R�ɂȂ��Ă��܂�");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // ���ݕ����Ȃ�
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
                    "���ݕ����Ȃ����A�A���Ă��Ă��܂���D�D�D");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
                break;
            }
        }
    }

    // ������ނ̎{�݂�������
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
                    "����n�̎{�݂̐��������Ȃ��H");
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
                    "�H���n�̎{�݂̐��������Ȃ��H");
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
                    "�v�[���n�̎{�݂̐��������Ȃ��H");
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
                    "���ݕ��n�̎{�݂̐��������Ȃ��H");
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
                    "�f��n�̎{�݂̐��������Ȃ��H");
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
                    "�J���I�P�n�̎{�݂̐��������Ȃ��H");
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
                    "�h���n�n�̎{�݂̐��������Ȃ��H");
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
                    "����n�̎{�݂̐��������Ȃ��H");
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
                    "���̃��]�[�g�Ȃ��Ȃ��y�����ł���");
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
                            "���X�e�[�W�r�����N�@%s %d%%",
                            lenS,
                            rankS);
                        (GetUIObjByName("save-data")->Texts + 0)->
                            ChangeTextTo(rankRate);
                        sprintf_s(rankRate, sizeof(rankRate),
                            "���X�e�[�W�`�����N�@%s %d%%",
                            lenA,
                            rankA);
                        (GetUIObjByName("save-data")->Texts + 1)->
                            ChangeTextTo(rankRate);
                        sprintf_s(rankRate, sizeof(rankRate),
                            "���X�e�[�W�a�����N�@%s %d%%",
                            lenB,
                            rankB);
                        (GetUIObjByName("save-data")->Texts + 2)->
                            ChangeTextTo(rankRate);
                        sprintf_s(rankRate, sizeof(rankRate),
                            "���X�e�[�W�b�����N�@%s %d%%",
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
                                    "����");
                                break;
                            case B_TYPE_FOOD:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "�H����");
                                break;
                            case B_TYPE_POOL:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "�v�[��");
                                break;
                            case B_TYPE_DRINK:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "���ݕ��X");
                                break;
                            case B_TYPE_CINEMA:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "�f���");
                                break;
                            case B_TYPE_KARAOKE:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "�J���I�P");
                                break;
                            case B_TYPE_RESTPLACE:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "�h���n");
                                break;
                            case B_TYPE_MAKEBYHAND:
                                strcpy_s(
                                    builds[i],
                                    sizeof(builds[i]),
                                    "����X");
                                break;

                            default:
                                break;
                            }

                            char mostType[64];
                            sprintf_s(
                                mostType, sizeof(mostType),
                                "�ł��g��ꂽ�{�� %s %s %s",
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
