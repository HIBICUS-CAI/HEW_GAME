#include "ThoughtListManager.h"
#include "AppDeclared.h"
#include "Tools.h"
#include "VisitingVisitorManager.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"
#include "ThoughtListShower.h"
#include "VisitorThoughtManager.h"
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
    CreateSingleTypeThoughtByStage(buildType, buildEvent);
    VISITOR_TYPE preType = VISITOR_TYPE::NONE;
    for (int i = 0; i < VISITOR_MAX_SIZE; i++)
    {
        if ((GetVisitorArray() + i)->IsUsing &&
            (GetVisitorArray() + i)->Type != preType)
        {
            preType = (GetVisitorArray() + i)->Type;
            CreateSingleTypeVisitorThought(preType, buildType, buildEvent);
        }
    }
}

void CreateSingleTypeVisitorThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    // 普通の名前好きかどうか

    // 客に対して特別イベント(好きのみ)
    // 普通に好きかどうか

    CreateSingleVisitorThoughtByManager(visitorType, buildType, buildEvent);
}

void CreateSingleTypeThoughtByStage(int buildType, int buildEvent)
{
    // 特別のゲートイベント
    if (buildType == -1 || buildEvent == -1)
    {
        int stageID = GetPlayingStage();
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];
        char thought[50] = "";

        switch (stageID)
        {
        case STAGE_DEFAULT:
            if (subName2 == 6)
            {
                strcpy_s(thought, sizeof(thought), "多分遠いところにも山があるから？面白い");
            }
            else if (subName2 == 8)
            {
                strcpy_s(thought, sizeof(thought), "ここの環境キャンプ場と相性ぴったりだね！");
            }
            else if (subName2 == 13)
            {
                strcpy_s(thought, sizeof(thought), "確か村みたい特別な落ち着ける感じ");
            }
            else if (subName1 == 1)
            {
                strcpy_s(thought, sizeof(thought), "明るいって確かに似合うんですね");
            }
            break;

        case STAGE_BEACH:
            if (subName2 == 11)
            {
                strcpy_s(thought, sizeof(thought), "海があれば島、島があれば海、いい名前ですね");
            }
            else if (subName1 == 6)
            {
                strcpy_s(thought, sizeof(thought), "日の出が一時的もんね、美しいのはこれあるかも");
            }
            else if (subName1 == 0)
            {
                strcpy_s(thought, sizeof(thought), "海浜の風が確か涼しいね");
            }
            else if (subName2 == 7)
            {
                strcpy_s(thought, sizeof(thought), "ま、そもそもここはうみだね");
            }
            break;

        case STAGE_DESERT:
            if (subName2 == 11)
            {
                strcpy_s(thought, sizeof(thought), "漠々たる砂漠、ここはまさに島、本当にいい名前だ");
            }
            else if (subName2 == 7)
            {
                strcpy_s(thought, sizeof(thought), "広い砂漠、まさに海みたい");
            }
            else if (subName1 == 4)
            {
                strcpy_s(thought, sizeof(thought), "ボーダーライン見えない砂漠、深さ満々だね");
            }
            else if (subName2 == 2)
            {
                strcpy_s(thought, sizeof(thought), "確かここってオアシスみたいな感じ！");
            }
            break;

        default:
            break;
        }
        if (subName1 == -1 || subName2 == -1)
        {
            strcpy_s(thought, sizeof(thought), "何なんだこのＸＸＸＸって、意味わからんわ");
        }
        if (strcmp(thought, ""))
        {
            AddSingleThoughtToQueue(thought);
        }
    }
    else
    {
        char thought[50] = "";
        int stageID = GetPlayingStage();

        switch (stageID)
        {
        case STAGE_DEFAULT:
            if (buildEvent==B_EVNT_EATBBQ)
            {
                strcpy_s(thought, sizeof(thought), 
                    "この風景でバーベキューするって心地よいね！");
            }
            else if (buildEvent==B_EVNT_DRKTEA)
            {
                strcpy_s(thought, sizeof(thought), 
                    "川の流れを見ながらお茶、素晴らしい");
            }
            else if (buildEvent == B_EVNT_RESTCAMP)
            {
                strcpy_s(thought, sizeof(thought),
                    "良い風景とキャンプ場、相性ぴったりですね");
            }
            else if (buildEvent == B_EVNT_POLNIGHT)
            {
                strcpy_s(thought, sizeof(thought),
                    "今は昼ですけど、夜になるまでなんか役に立たないね");
            }
            break;

        case STAGE_BEACH:
            if (buildType == B_TYPE_HOTSPRING)
            {
                strcpy_s(thought, sizeof(thought),
                    "海浜に来た以上やっぱり海に行きたいよ");
            }
            else if (buildEvent == B_EVNT_POLINFINITY)
            {
                strcpy_s(thought, sizeof(thought),
                    "おおこのプールの広さ、もはや海のレベルじゃない？");
            }
            else if (buildEvent == B_EVNT_DRKALCOHOL)
            {
                strcpy_s(thought, sizeof(thought),
                    "ここで酒飲むのは楽だな");
            }
            else if (buildType == B_TYPE_MAKEBYHAND)
            {
                strcpy_s(thought, sizeof(thought),
                    "いいね、海浜には色んな素材がありますので");
            }
            else if (buildEvent == B_EVNT_EATUNAGI)
            {
                strcpy_s(thought, sizeof(thought),
                    "運送費免除あとウナギも安いで美味しいになった！");
            }
            else if (buildEvent == B_EVNT_POLNIGHT)
            {
                strcpy_s(thought, sizeof(thought),
                    "いまは朝じゃない？それも海の隣ですよ？");
            }
            break;

        case STAGE_DESERT:
            if (buildType == B_TYPE_HOTSPRING)
            {
                strcpy_s(thought, sizeof(thought),
                    "いいね、夜は寒いし乾燥だし、温泉まじいい！");
            }
            else if (buildEvent == B_EVNT_POLNORMAL)
            {
                strcpy_s(thought, sizeof(thought),
                    "普通のプールは夜になると閉めちゃうね？勿体ないな");
            }
            else if (buildEvent == B_EVNT_POLINFINITY)
            {
                strcpy_s(thought, sizeof(thought),
                    "おお、砂漠の中にインフィニティプールで最高です！");
            }
            else if (buildEvent == B_EVNT_POLNIGHT)
            {
                strcpy_s(thought, sizeof(thought),
                    "夜のでナイトプール最高っす！");
            }
            else if (buildEvent == B_EVNT_DRKBAR)
            {
                strcpy_s(thought, sizeof(thought),
                    "窓の外の風景見ながら一杯の品って贅沢ですよ");
            }
            else if (buildEvent == B_EVNT_MOVHOR)
            {
                strcpy_s(thought, sizeof(thought),
                    "ここはもう十分怖いですよ、夜だし他の人もいないし");
            }
            else if (buildEvent == B_EVNT_RESTCAMP)
            {
                strcpy_s(thought, sizeof(thought),
                    "え？ここでキャンプすると砂と埃だらけじゃん？");
            }
            break;

        default:
            break;
        }

        if (strcmp(thought, ""))
        {
            AddSingleThoughtToQueue(thought);
        }
    }

    // ステージに対して特別イベント(好き嫌い両方)
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
