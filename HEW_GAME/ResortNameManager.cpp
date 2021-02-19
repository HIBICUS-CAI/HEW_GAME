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

    strcpy_s(GetSubName1ArrayByOffset(0), 17, "—Á‚µ‚¢");
    strcpy_s(GetSubName1ArrayByOffset(1), 17, "–¾‚é‚¢");
    strcpy_s(GetSubName1ArrayByOffset(2), 17, "ŠÃŽ_‚Á‚Ï‚¢");
    strcpy_s(GetSubName1ArrayByOffset(3), 17, "‘¸‚¢");
    strcpy_s(GetSubName1ArrayByOffset(4), 17, "[‚¢");
    strcpy_s(GetSubName1ArrayByOffset(5), 17, "ƒCƒR[ƒ‹");
    strcpy_s(GetSubName1ArrayByOffset(6), 17, "ˆêŽž“I");
    strcpy_s(GetSubName1ArrayByOffset(7), 17, "‰Ë‹ó");
    strcpy_s(GetSubName1ArrayByOffset(8), 17, "ƒOƒ[ƒoƒ‹");
    strcpy_s(GetSubName1ArrayByOffset(9), 17, "‹ó‹C“Ç‚ß‚È‚¢");
    strcpy_s(GetSubName1ArrayByOffset(10), 17, "ƒ^ƒsƒIƒJ");
    strcpy_s(GetSubName1ArrayByOffset(11), 17, "‚í‚½‚ ‚ß");
    strcpy_s(GetSubName1ArrayByOffset(12), 17, "ƒpƒ“ƒ_");
    strcpy_s(GetSubName1ArrayByOffset(13), 17, "¢ŠE");
    strcpy_s(GetSubName1ArrayByOffset(14), 17, "ƒTƒ‰ƒŠ[ƒ}ƒ“");
    strcpy_s(GetSubName2ArrayByOffset(0), 17, "‹ó‹C");
    strcpy_s(GetSubName2ArrayByOffset(1), 17, "ƒŠƒ][ƒg");
    strcpy_s(GetSubName2ArrayByOffset(2), 17, "X");
    strcpy_s(GetSubName2ArrayByOffset(3), 17, "ƒ‰[ƒƒ“‰®");
    strcpy_s(GetSubName2ArrayByOffset(4), 17, "‰p—Y");
    strcpy_s(GetSubName2ArrayByOffset(5), 17, "‹i’ƒ“X");
    strcpy_s(GetSubName2ArrayByOffset(6), 17, "ŽR");
    strcpy_s(GetSubName2ArrayByOffset(7), 17, "ŠC");
    strcpy_s(GetSubName2ArrayByOffset(8), 17, "ƒLƒƒƒ“ƒvê");
    strcpy_s(GetSubName2ArrayByOffset(9), 17, "Ž––±Š");
    strcpy_s(GetSubName2ArrayByOffset(10), 17, "‘‘");
    strcpy_s(GetSubName2ArrayByOffset(11), 17, "“‡");
    strcpy_s(GetSubName2ArrayByOffset(12), 17, "ƒpƒŒƒX");
    strcpy_s(GetSubName2ArrayByOffset(13), 17, "‘º");
    strcpy_s(GetSubName2ArrayByOffset(14), 17, "ƒpƒ‰ƒ_ƒCƒX");
}

void UpdateResortNameManager()
{
    char temp[17] = "  ‚w‚w‚w‚w‚w‚w  ";

    if (GetUIObjByName("subname1")->Visiblity)
    {
        if (!strcmp(GetSelectedBtn()->Text, "•Â‚¶‚é"))
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
        if (!strcmp(GetSelectedBtn()->Text, "•Â‚¶‚é"))
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
