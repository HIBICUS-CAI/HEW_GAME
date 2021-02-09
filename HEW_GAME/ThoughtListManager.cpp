#include "ThoughtListManager.h"
#include "AppDeclared.h"
#include "Tools.h"
#include "VisitingVisitorManager.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"
#include "ThoughtListShower.h"
#include <string.h>

QUEUE_INT g_ThoughtQueue;

void InitThoughtListManager()
{
    g_ThoughtQueue.Top = CreateQueue();
    g_ThoughtQueue.End = g_ThoughtQueue.Top;
}

void UpdateThoughtListManager()
{
    if (g_ThoughtQueue.Top->Next != NULL)
    {
        if ((GetThoughtListSprites() +
            g_ThoughtQueue.Top->Next->Data)->
            Position.posX < -53)
        {
            int index = DeQueue(
                g_ThoughtQueue.Top,
                g_ThoughtQueue.End
            );
            SPRITE* temp = new SPRITE();
            GetThoughtListSprites()[index] = *temp;
            delete temp;
        }
    }
}

void TurnOffThoughtListManager()
{

}

void CreateThoughtToQueue(int buildType, int buildEvent)
{
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1Offset = GetConfirmedSubName1And2()[0];
        int subName2Offset = GetConfirmedSubName1And2()[1];

        //------------------
        char name[34];
        sprintf_s(name, sizeof(name), "%s%s",
            GetSubName1ArrayByOffset(GetConfirmedSubName1And2()[0]),
            GetSubName2ArrayByOffset(GetConfirmedSubName1And2()[1]));
        char temp[512];
        sprintf_s(temp, sizeof(temp), "%s%s",
            name, "ってなに？");
        //AddSingleThoughtToQueue(temp);

        for (int i = 0; i < 3; i++)
        {
            AddSingleThoughtToQueue(temp);
            //AddSingleThoughtToQueue("abcdefghijklmnopqrstuvwxyz");
        }
    }
    else
    {
        char type[17];
        char event[17];
        switch (buildType)
        {
        case B_TYPE_HOTSPRING:
            strcpy_s(type, sizeof(type), "温泉");
            break;
        case B_TYPE_FOOD:
            strcpy_s(type, sizeof(type), "食");
            break;
        case B_TYPE_POOL:
            strcpy_s(type, sizeof(type), "プール");
            break;
        case B_TYPE_DRINK:
            strcpy_s(type, sizeof(type), "飲み物");
            break;
        case B_TYPE_CINEMA:
            strcpy_s(type, sizeof(type), "映画館");
            break;
        case B_TYPE_KARAOKE:
            strcpy_s(type, sizeof(type), "カラオケ");
            break;
        case B_TYPE_RESTPLACE:
            strcpy_s(type, sizeof(type), "休憩所");
            break;
        case B_TYPE_MAKEBYHAND:
            strcpy_s(type, sizeof(type), "手作り店");
            break;

        default:
            break;
        }

        switch (buildEvent)
        {
        case B_EVNT_NORMALSPR:
            strcpy_s(event, sizeof(event), "単純温泉");
            break;
        case B_EVNT_SKINCARESPR:
            strcpy_s(event, sizeof(event), "重曹泉");
            break;
        case B_EVNT_WARMSPR:
            strcpy_s(event, sizeof(event), "塩化物泉");
            break;
        case B_EVNT_HEALTHSPR:
            strcpy_s(event, sizeof(event), "硫黄泉");
            break;
        case B_EVNT_EATBBQ:
            strcpy_s(event, sizeof(event), "バーベキュー");
            break;
        case B_EVNT_EATLIGHTFOOD:
            strcpy_s(event, sizeof(event), "喫茶店");
            break;
        case B_EVNT_EATUNAGI:
            strcpy_s(event, sizeof(event), "うなぎ屋");
            break;
        case B_EVNT_EATRAMEN:
            strcpy_s(event, sizeof(event), "ラーメン屋");
            break;
        case B_EVNT_EATCURRY:
            strcpy_s(event, sizeof(event), "カレー");
            break;
        case B_EVNT_EATFRIEDNOODLE:
            strcpy_s(event, sizeof(event), "焼きそば");
            break;
        case B_EVNT_POLNORMAL:
            strcpy_s(event, sizeof(event), "普通のプール");
            break;
        case B_EVNT_POLFLUSH:
            strcpy_s(event, sizeof(event), "流水プール");
            break;
        case B_EVNT_POLNIGHT:
            strcpy_s(event, sizeof(event), "ナイトプール");
            break;
        case B_EVNT_POLINFINITY:
            strcpy_s(event, sizeof(event), "infiniteプール");
            break;
        case B_EVNT_DRKMILKTEA:
            strcpy_s(event, sizeof(event), "タピオカ店");
            break;
        case B_EVNT_DRKCAFE:
            strcpy_s(event, sizeof(event), "カフェ");
            break;
        case B_EVNT_DRKTEA:
            strcpy_s(event, sizeof(event), "茶室");
            break;
        case B_EVNT_DRKBAR:
            strcpy_s(event, sizeof(event), "バー");
            break;
        case B_EVNT_DRKKARUPISU:
            strcpy_s(event, sizeof(event), "カルピス放題");
            break;
        case B_EVNT_DRKALCOHOL:
            strcpy_s(event, sizeof(event), "酒場");
            break;
        case B_EVNT_MOVHOR:
            strcpy_s(event, sizeof(event), "ホラー");
            break;
        case B_EVNT_MOVLOVE:
            strcpy_s(event, sizeof(event), "れんあい");
            break;
        case B_EVNT_MOVSF:
            strcpy_s(event, sizeof(event), "ＳＦ");
            break;
        case B_EVNT_MOVACT:
            strcpy_s(event, sizeof(event), "アクション");
            break;
        case B_EVNT_MOVCOMEDY:
            strcpy_s(event, sizeof(event), "コメディ");
            break;
        case B_EVNT_MOVDOCUMENTARY:
            strcpy_s(event, sizeof(event), "伝記");
            break;
        case B_EVNT_KARASINGLE:
            strcpy_s(event, sizeof(event), "一人でカラオケ");
            break;
        case B_EVNT_KARAMUTLI:
            strcpy_s(event, sizeof(event), "皆でカラオケ");
            break;
        case B_EVNT_RESTCAMP:
            strcpy_s(event, sizeof(event), "キャンプ場");
            break;
        case B_EVNT_RESTHOTEL:
            strcpy_s(event, sizeof(event), "ホテル");
            break;
        case B_EVNT_MAKEPRESENT:
            strcpy_s(event, sizeof(event), "手作りお土産");
            break;
        case B_EVNT_MAKEACSY:
            strcpy_s(event, sizeof(event), "手作アクセサリー");
            break;

        default:
            break;
        }
        char temp[512];
        sprintf_s(temp, sizeof(temp), "%s%s%s",
            type, event, "ってなに？");
        //AddSingleThoughtToQueue(temp);

        for (int i = 0; i < 2; i++)
        {
            AddSingleThoughtToQueue(temp);
        }
    }
}

void CreateSingleTypeVisitorThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    // 特別のゲートイベント
    // 普通の名前好きかどうか

    // ステージに対して特別イベント(好き嫌い両方)
    // 客に対して特別イベント(好きのみ)
    // 普通に好きかどうか
}

void AddSingleThoughtToQueue(const char* thought)
{
    int index = 0;
    while ((GetThoughtListSprites() + index)->Visible)
    {
        ++index;
        if (index == 30)
        {
            ErrorLog("you have uesd all of the thought nodes");
            return;
        }
    }

    int widthOffset = 0;
    int heightOffset = 0;
    int canShowFlg[6] = { 1,1,1,1,1,1 };
    QSINGLENODE* node = g_ThoughtQueue.Top;
    do
    {
        if (node->Next != NULL)
        {
            if ((GetThoughtListSprites() +
                node->Next->Data)->
                Position.posX > 128)
            {
                widthOffset += 6;
                int indexY = ((GetThoughtListSprites() +
                    node->Next->Data)->
                    Position.posY - 42) / 3;
                canShowFlg[indexY] = 0;
            }
            node = node->Next;
        }
    } while (node->Next != NULL);

    for (int i = 0; i < 6; i++)
    {
        if (canShowFlg[i])
        {
            heightOffset = 3 * i;
            break;
        }
    }

    GetThoughtListSprites()[index] = CreateSingleSprite(
        "Assets\\Sprites\\thought.txt",
        POSITION_2D(180 + widthOffset, 42 + heightOffset), 52, 3
    );

    int length = strlen(thought);
    for (int i = 0; i < length; i++)
    {
        *(GetThoughtListSprites()[index].GetSpriteBuffer() +
            GetThoughtListSprites()[index].Width + 2 + i) =
            thought[i];
    }

    g_ThoughtQueue.End = EnQueue(g_ThoughtQueue.End, index);
}

void ResetThoughtQueueAndList()
{
    while (g_ThoughtQueue.Top->Next != NULL)
    {
        int index = DeQueue(
            g_ThoughtQueue.Top,
            g_ThoughtQueue.End
        );
        SPRITE* temp = new SPRITE();
        GetThoughtListSprites()[index] = *temp;
        delete temp;
    }

    if (g_ThoughtQueue.Top != NULL && g_ThoughtQueue.End != NULL)
    {
        free(g_ThoughtQueue.Top);
    }
    g_ThoughtQueue.Top = CreateQueue();
    g_ThoughtQueue.End = g_ThoughtQueue.Top;
}
