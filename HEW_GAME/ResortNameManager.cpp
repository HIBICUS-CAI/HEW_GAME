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
    strcpy_s(GetSubName1ArrayByOffset(1), 17, "���邢");
    strcpy_s(GetSubName1ArrayByOffset(2), 17, "�Î_���ς�");
    strcpy_s(GetSubName1ArrayByOffset(3), 17, "����");
    strcpy_s(GetSubName1ArrayByOffset(4), 17, "�[��");
    strcpy_s(GetSubName1ArrayByOffset(5), 17, "�C�R�[��");
    strcpy_s(GetSubName1ArrayByOffset(6), 17, "�ꎞ�I");
    strcpy_s(GetSubName1ArrayByOffset(7), 17, "�ˋ�");
    strcpy_s(GetSubName1ArrayByOffset(8), 17, "�O���[�o��");
    strcpy_s(GetSubName1ArrayByOffset(9), 17, "��C�ǂ߂Ȃ�");
    strcpy_s(GetSubName1ArrayByOffset(10), 17, "�^�s�I�J");
    strcpy_s(GetSubName1ArrayByOffset(11), 17, "�킽����");
    strcpy_s(GetSubName1ArrayByOffset(12), 17, "�p���_");
    strcpy_s(GetSubName1ArrayByOffset(13), 17, "���E");
    strcpy_s(GetSubName1ArrayByOffset(14), 17, "�T�����[�}��");
    strcpy_s(GetSubName2ArrayByOffset(0), 17, "��C");
    strcpy_s(GetSubName2ArrayByOffset(1), 17, "���]�[�g");
    strcpy_s(GetSubName2ArrayByOffset(2), 17, "�X");
    strcpy_s(GetSubName2ArrayByOffset(3), 17, "���[������");
    strcpy_s(GetSubName2ArrayByOffset(4), 17, "�p�Y");
    strcpy_s(GetSubName2ArrayByOffset(5), 17, "�i���X");
    strcpy_s(GetSubName2ArrayByOffset(6), 17, "�R");
    strcpy_s(GetSubName2ArrayByOffset(7), 17, "�C");
    strcpy_s(GetSubName2ArrayByOffset(8), 17, "�L�����v��");
    strcpy_s(GetSubName2ArrayByOffset(9), 17, "������");
    strcpy_s(GetSubName2ArrayByOffset(10), 17, "��");
    strcpy_s(GetSubName2ArrayByOffset(11), 17, "��");
    strcpy_s(GetSubName2ArrayByOffset(12), 17, "�p���X");
    strcpy_s(GetSubName2ArrayByOffset(13), 17, "��");
    strcpy_s(GetSubName2ArrayByOffset(14), 17, "�p���_�C�X");
}

void UpdateResortNameManager()
{
    char temp[17] = "  �w�w�w�w�w�w  ";

    if (GetUIObjByName("subname1")->Visiblity)
    {
        if (!strcmp(GetSelectedBtn()->Text, "����"))
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
        if (!strcmp(GetSelectedBtn()->Text, "����"))
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
