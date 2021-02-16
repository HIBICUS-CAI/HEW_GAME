#include "ResultFinalThought.h"
#include "AppDeclared.h"
#include "SceneNode.h"
#include "ResultTips.h"

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

    // �޲��ؤ��ʤ�
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
                    "���Υ꥾�`�Ȥʤ����ޤ������һ�Ĥ�ʤ��Ǥ�����");
                break;
            }
        }
    }

    // �դ��Ƥ�������L��
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
                    "�B�Aδ���È������त�͡��Х�󥹤��褯�ʤ����⤷��ޤ���");
                break;
            }
        }
    }

    // ʩ�O���ह��
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
                    "ʩ�O�������य�ʤ����������[�@�ؤǤϤʤ���");
                break;
            }
        }
    }

    // ʳ�¤��ʤ�
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
                    "ʳ�I���ʤ��͡����ϥڥ��ڥ��ˤʤäƤ��ޤ�");
                break;
            }
        }
    }

    // ��郎�ʤ�
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
                    "��郎�ʤ������������Ƥ��ޤ��裮����");
                break;
            }
        }
    }

    // ͬ���N�ʩ�O���ह��
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
                    "��Ȫϵ��ʩ�O�������य�ʤ���");
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
                    "ʳ��ϵ��ʩ�O�������य�ʤ���");
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
                    "�ש`��ϵ��ʩ�O�������य�ʤ���");
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
                    "���ϵ��ʩ�O�������य�ʤ���");
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
                    "ӳ��ϵ��ʩ�O�������य�ʤ���");
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
                    "���饪��ϵ��ʩ�O�������य�ʤ���");
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
                    "�޲���ϵ��ʩ�O�������य�ʤ���");
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
                    "������ϵ��ʩ�O�������य�ʤ���");
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
                    "���Υ꥾�`�Ȥʤ��ʤ��S�����Ǥ���");
                break;
            }
        }
    }
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
