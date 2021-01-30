#include "VisitorManager.h"
#include "AppDeclared.h"
#include "Tools.h"
#include "PlayingStageManager.h"
#include "UIObject.h"

int g_TextOffset = 0;

void InitVisitorManager()
{
    ResetVisitorManager();
}

void ResetVisitorManager()
{
    for (int i = 0; i < VISITOR_MAX_SIZE; i++)
    {
        *(GetVisitorArray() + i) = VISITOR_NODE();
    }
    g_TextOffset = 1;
    for (int i = 0; i < 4; i++)
    {
        (GetUIObjByName("naming")->Texts + (i + 1))->
            ChangeTextTo("");
    }
}

void AddAVisitorToArray(VISITOR_NODE node)
{
    for (int i = 0; i < VISITOR_MAX_SIZE; i++)
    {
        if (!(GetVisitorArray() + i)->IsUsing)
        {
            *(GetVisitorArray() + i) = node;
            return;
        }
    }

    ErrorLog("you've used all the visitor nodes");
}

void CreateVisitors()
{
    SetRandom();
    int special = (CreateRandomNumIn(1, 100) > 90);
    int typeNum = 0;
    SetRandom();
    if (special)
    {
        typeNum = CreateRandomNumIn(2, 3);
    }
    else
    {
        typeNum = CreateRandomNumIn(3, 4);
    }
    int usedTpye[3] = { 0,0,0 };

    for (int i = 0; i < typeNum; i++)
    {
        SetRandom();
        int type = CreateRandomNumIn(1, 6);
        while (type == usedTpye[0] ||
            type == usedTpye[1] ||
            type == usedTpye[2])
        {
            SetRandom();
            type = CreateRandomNumIn(1, 6);
        }
        for (int j = 0; j < 3; j++)
        {
            if (usedTpye[i] == 0)
            {
                usedTpye[i] = type;
                break;
            }
        }
        SetRandom();
        int num = CreateRandomNumIn(1, 3);
        VISITOR_TYPE visitorType = VISITOR_TYPE::NONE;
        char temp[512] = "";
        switch (type)
        {
        case 1:
            visitorType = VISITOR_TYPE::STUDENTS;
            sprintf_s(temp, sizeof(temp), "%s%d",
                "学生：", num);
            (GetUIObjByName("naming")->Texts + (g_TextOffset++))->
                ChangeTextTo(temp);
            break;
        case 2:
            visitorType = VISITOR_TYPE::COUPLE;
            sprintf_s(temp, sizeof(temp), "%s%d",
                "カップル：", num);
            (GetUIObjByName("naming")->Texts + (g_TextOffset++))->
                ChangeTextTo(temp);
            break;
        case 3:
            visitorType = VISITOR_TYPE::PROGRAMMER;
            sprintf_s(temp, sizeof(temp), "%s%d",
                "プログラマー：", num);
            (GetUIObjByName("naming")->Texts + (g_TextOffset++))->
                ChangeTextTo(temp);
            break;
        case 4:
            visitorType = VISITOR_TYPE::ARTIST;
            sprintf_s(temp, sizeof(temp), "%s%d",
                "アーティスト：", num);
            (GetUIObjByName("naming")->Texts + (g_TextOffset++))->
                ChangeTextTo(temp);
            break;
        case 5:
            visitorType = VISITOR_TYPE::OFFICER;
            sprintf_s(temp, sizeof(temp), "%s%d",
                "事務員：", num);
            (GetUIObjByName("naming")->Texts + (g_TextOffset++))->
                ChangeTextTo(temp);
            break;
        case 6:
            visitorType = VISITOR_TYPE::FAMILY;
            sprintf_s(temp, sizeof(temp), "%s%d",
                "家族：", num);
            (GetUIObjByName("naming")->Texts + (g_TextOffset++))->
                ChangeTextTo(temp);
            break;

        default:
            ErrorLogI1("you cannot use this type", type);
            break;
        }

        for (int j = 0; j < num; j++)
        {
            AddAVisitorToArray(VISITOR_NODE(1, visitorType));
        }

        //---------------------
        DebugLogI2("[type, num]", (const int)visitorType, num);
    }

    if (special)
    {
        SetRandom();
        int spNum = CreateRandomNumIn(1, 3);
        VISITOR_TYPE spType = VISITOR_TYPE::NONE;

        char temp[512] = "";
        switch (GetPlayingStageByManager())
        {
        case STAGE_DEFAULT:
            spType = VISITOR_TYPE::RABBIT;
            sprintf_s(temp, sizeof(temp), "%s%d",
                "うさぎ：", spNum);
            (GetUIObjByName("naming")->Texts + (g_TextOffset++))->
                ChangeTextTo(temp);
            break;
        case STAGE_BEACH:
            spType = VISITOR_TYPE::WHALE;
            sprintf_s(temp, sizeof(temp), "%s%d",
                "くじら：", spNum);
            (GetUIObjByName("naming")->Texts + (g_TextOffset++))->
                ChangeTextTo(temp);
            break;
        case STAGE_DESERT:
            spType = VISITOR_TYPE::CAMEL;
            sprintf_s(temp, sizeof(temp), "%s%d",
                "らくだ：", spNum);
            (GetUIObjByName("naming")->Texts + (g_TextOffset++))->
                ChangeTextTo(temp);
            break;

        default:
            ErrorLogI1("you cannot go with this stage",
                GetPlayingStageByManager());
            break;
        }

        for (int i = 0; i < spNum; i++)
        {
            AddAVisitorToArray(VISITOR_NODE(1, spType));
        }
        //---------------------
        DebugLogI2("SP[type, num]", (const int)spType, spNum);
    }
}
