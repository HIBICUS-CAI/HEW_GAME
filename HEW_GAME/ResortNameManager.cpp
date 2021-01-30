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

    strcpy_s(GetSubName1ArrayByOffset(0), 17, "������");
    strcpy_s(GetSubName1ArrayByOffset(1), 17, "���뤤");
    strcpy_s(GetSubName1ArrayByOffset(2), 17, "����äѤ�");
    strcpy_s(GetSubName1ArrayByOffset(3), 17, "��");
    strcpy_s(GetSubName1ArrayByOffset(4), 17, "�");
    strcpy_s(GetSubName1ArrayByOffset(5), 17, "�����`��");
    strcpy_s(GetSubName1ArrayByOffset(6), 17, "һ�r��");
    strcpy_s(GetSubName1ArrayByOffset(7), 17, "�ܿ�");
    strcpy_s(GetSubName1ArrayByOffset(8), 17, "����`�Х�");
    strcpy_s(GetSubName1ArrayByOffset(9), 17, "�՚��i��ʤ�");
    strcpy_s(GetSubName1ArrayByOffset(10), 17, "���ԥ���");
    strcpy_s(GetSubName1ArrayByOffset(11), 17, "�錄����");
    strcpy_s(GetSubName1ArrayByOffset(12), 17, "�ѥ��");
    strcpy_s(GetSubName1ArrayByOffset(13), 17, "����");
    strcpy_s(GetSubName1ArrayByOffset(14), 17, "�����`�ޥ�");
    strcpy_s(GetSubName2ArrayByOffset(0), 17, "�՚�");
    strcpy_s(GetSubName2ArrayByOffset(1), 17, "�꥾�`��");
    strcpy_s(GetSubName2ArrayByOffset(2), 17, "ɭ");
    strcpy_s(GetSubName2ArrayByOffset(3), 17, "��`�����");
    strcpy_s(GetSubName2ArrayByOffset(4), 17, "Ӣ��");
    strcpy_s(GetSubName2ArrayByOffset(5), 17, "�˲��");
    strcpy_s(GetSubName2ArrayByOffset(6), 17, "ɽ");
    strcpy_s(GetSubName2ArrayByOffset(7), 17, "��");
    strcpy_s(GetSubName2ArrayByOffset(8), 17, "�����׈�");
    strcpy_s(GetSubName2ArrayByOffset(9), 17, "����");
    strcpy_s(GetSubName2ArrayByOffset(10), 17, "�P");
    strcpy_s(GetSubName2ArrayByOffset(11), 17, "�u");
    strcpy_s(GetSubName2ArrayByOffset(12), 17, "�ѥ쥹");
    strcpy_s(GetSubName2ArrayByOffset(13), 17, "��");
    strcpy_s(GetSubName2ArrayByOffset(14), 17, "�ѥ������");
}

void UpdateResortNameManager()
{
    char temp[17] = "  �أأأأأ�  ";

    if (GetUIObjByName("subname1")->Visiblity)
    {
        if (!strcmp(GetSelectedBtn()->Text, "�]����"))
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
        if (!strcmp(GetSelectedBtn()->Text, "�]����"))
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
