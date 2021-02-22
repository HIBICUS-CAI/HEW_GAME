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
        else
        {
            (GetUIObjByName("save-data")->Texts + 0)->
                ChangeTextTo("ただ今データベースに接続しています");
            (GetUIObjByName("save-data")->Texts + 1)->
                ChangeTextTo("しばらくお待ちください");
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
            ChangeTextTo("ネット機能が使えません");
        (GetUIObjByName("save-data")->Texts + 1)->
            ChangeTextTo("もしこの機能使えたい場合には");
        (GetUIObjByName("save-data")->Texts + 2)->
            ChangeTextTo("Assets\\Configs\\database_config.txtの内容と");
        (GetUIObjByName("save-data")->Texts + 3)->
            ChangeTextTo("回線を確認の上で");
        (GetUIObjByName("save-data")->Texts + 4)->
            ChangeTextTo("ゲームをもう一度実行してください");
    }
}

void TurnOffStatisticShower()
{

}
