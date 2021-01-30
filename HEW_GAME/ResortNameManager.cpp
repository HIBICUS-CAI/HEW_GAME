#include "ResortNameManager.h"
#include "UIObject.h"
#include "DeclaredValues.h"
#include "AppDeclared.h"

int g_TempSubName1 = 0;
int g_TempSubName2 = 0;

void InitResortNameManager()
{
    g_TempSubName1 = -1;
    g_TempSubName2 = -1;

    SetConfirmedSubName1(-1);
    SetConfirmedSubName2(-1);

    strcpy_s(GetSubName1ArrayByOffset(0), 17, "涼しい");
    strcpy_s(GetSubName1ArrayByOffset(1), 17, "明るい");
    strcpy_s(GetSubName1ArrayByOffset(2), 17, "甘酸っぱい");
    strcpy_s(GetSubName1ArrayByOffset(3), 17, "尊い");
    strcpy_s(GetSubName1ArrayByOffset(4), 17, "深い");
    strcpy_s(GetSubName1ArrayByOffset(5), 17, "イコール");
    strcpy_s(GetSubName1ArrayByOffset(6), 17, "一時的");
    strcpy_s(GetSubName1ArrayByOffset(7), 17, "架空");
    strcpy_s(GetSubName1ArrayByOffset(8), 17, "グローバル");
    strcpy_s(GetSubName1ArrayByOffset(9), 17, "空気読めない");
    strcpy_s(GetSubName1ArrayByOffset(10), 17, "タピオカ");
    strcpy_s(GetSubName1ArrayByOffset(11), 17, "わたあめ");
    strcpy_s(GetSubName1ArrayByOffset(12), 17, "パンダ");
    strcpy_s(GetSubName1ArrayByOffset(13), 17, "世界");
    strcpy_s(GetSubName1ArrayByOffset(14), 17, "サラリーマン");
    strcpy_s(GetSubName2ArrayByOffset(0), 17, "空気");
    strcpy_s(GetSubName2ArrayByOffset(1), 17, "リゾート");
    strcpy_s(GetSubName2ArrayByOffset(2), 17, "森");
    strcpy_s(GetSubName2ArrayByOffset(3), 17, "ラーメン屋");
    strcpy_s(GetSubName2ArrayByOffset(4), 17, "英雄");
    strcpy_s(GetSubName2ArrayByOffset(5), 17, "喫茶店");
    strcpy_s(GetSubName2ArrayByOffset(6), 17, "山");
    strcpy_s(GetSubName2ArrayByOffset(7), 17, "海");
    strcpy_s(GetSubName2ArrayByOffset(8), 17, "キャンプ場");
    strcpy_s(GetSubName2ArrayByOffset(9), 17, "事務所");
    strcpy_s(GetSubName2ArrayByOffset(10), 17, "荘");
    strcpy_s(GetSubName2ArrayByOffset(11), 17, "島");
    strcpy_s(GetSubName2ArrayByOffset(12), 17, "パレス");
    strcpy_s(GetSubName2ArrayByOffset(13), 17, "村");
    strcpy_s(GetSubName2ArrayByOffset(14), 17, "パラダイス");
}

void UpdateResortNameManager()
{
    char temp[17] = "  ＸＸＸＸＸＸ  ";

    if (GetUIObjByName("subname1")->Visiblity)
    {
        if (!strcmp(GetSelectedBtn()->Text, "閉じる"))
        {
            (GetUIObjByName("naming")->Texts + 6)->
                ChangeTextTo(temp);
            return;
        }
        (GetUIObjByName("naming")->Texts + 6)->
            ChangeTextTo(GetSelectedBtn()->Text);
    }
    else if (GetUIObjByName("subname2")->Visiblity)
    {
        if (!strcmp(GetSelectedBtn()->Text, "閉じる"))
        {
            (GetUIObjByName("naming")->Texts + 7)->
                ChangeTextTo(temp);
            return;
        }
        (GetUIObjByName("naming")->Texts + 7)->
            ChangeTextTo(GetSelectedBtn()->Text);
    }
}

void TurnOffResortNameManager()
{

}

void SaveConfirmedName()
{
    SetConfirmedSubName1(g_TempSubName1);
    SetConfirmedSubName2(g_TempSubName2);

    g_TempSubName1 = -1;
    g_TempSubName2 = -1;

    DebugLogI2("[name1, name2]",
        GetConfirmedSubName1And2()[0],
        GetConfirmedSubName1And2()[1]);

    char name[34];
    sprintf_s(name, sizeof(name), "%s%s",
        GetSubName1ArrayByOffset(GetConfirmedSubName1And2()[0]),
        GetSubName2ArrayByOffset(GetConfirmedSubName1And2()[1]));
    DebugLog(name);
}

void SetTempName1(int value)
{
    g_TempSubName1 = value - SUB1_1_1NAME;
}

void SetTempName2(int value)
{
    g_TempSubName2 = value - SUB2_1_1NAME;
}
