#include "StatisticShower.h"
#include "DataSyncer.h"
#include "UIObject.h"
#include "AppDeclared.h"

void InitStatisticShower()
{

}

void UpdateStatisticShower()
{
    if (CanUseDataBase())
    {
        if (IsDBResultNewest())
        {
            int rankS = GetDBRankArray()[0];
            int rankA = GetDBRankArray()[1];
            int rankB = GetDBRankArray()[2];
            int rankC = GetDBRankArray()[3];
            int sum = rankS + rankA + rankB + rankC;
            rankS = (int)((float)rankS / (float)sum * 100.f);
            rankA = (int)((float)rankA / (float)sum * 100.f);
            rankB = (int)((float)rankB / (float)sum * 100.f);
            rankC = (int)((float)rankC / (float)sum * 100.f);

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
        else
        {
            (GetUIObjByName("save-data")->Texts + 0)->
                ChangeTextTo("�������f�[�^�x�[�X�ɐڑ����Ă��܂�");
            (GetUIObjByName("save-data")->Texts + 1)->
                ChangeTextTo("���΂炭���҂���������");
            (GetUIObjByName("save-data")->Texts + 2)->
                ChangeTextTo("");
            (GetUIObjByName("save-data")->Texts + 3)->
                ChangeTextTo("");
            (GetUIObjByName("save-data")->Texts + 4)->
                ChangeTextTo("");
        }
    }
    else
    {
        (GetUIObjByName("save-data")->Texts + 0)->
            ChangeTextTo("�l�b�g�@�\���g���܂���");
        (GetUIObjByName("save-data")->Texts + 1)->
            ChangeTextTo("�������̋@�\�g�������ꍇ�ɂ�");
        (GetUIObjByName("save-data")->Texts + 2)->
            ChangeTextTo("Assets\\Configs\\database_config.txt�̓��e��");
        (GetUIObjByName("save-data")->Texts + 3)->
            ChangeTextTo("������m�F�̏��");
        (GetUIObjByName("save-data")->Texts + 4)->
            ChangeTextTo("�Q�[����������x���s���Ă�������");
    }
}

void TurnOffStatisticShower()
{

}
