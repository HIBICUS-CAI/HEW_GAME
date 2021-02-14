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
    // ��ͨ����ǰ�ä����ɤ���

    // �ͤˌ������؄e���٥��(�ä��Τ�)
    // ��ͨ�˺ä����ɤ���

    CreateSingleVisitorThoughtByManager(visitorType, buildType, buildEvent);
}

void CreateSingleTypeThoughtByStage(int buildType, int buildEvent)
{
    // �؄e�Υ��`�ȥ��٥��
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
                strcpy_s(thought, sizeof(thought), "����h���Ȥ���ˤ�ɽ�����뤫�飿��פ�");
            }
            else if (subName2 == 8)
            {
                strcpy_s(thought, sizeof(thought), "�����έh�������׈������ԤԤä�����ͣ�");
            }
            else if (subName2 == 13)
            {
                strcpy_s(thought, sizeof(thought), "�_����ߤ����؄e������Ť���Ф�");
            }
            else if (subName1 == 1)
            {
                strcpy_s(thought, sizeof(thought), "���뤤�äƴ_�����ƺϤ���Ǥ���");
            }
            break;

        case STAGE_BEACH:
            if (subName2 == 11)
            {
                strcpy_s(thought, sizeof(thought), "��������Ѝu���u������к���������ǰ�Ǥ���");
            }
            else if (subName1 == 6)
            {
                strcpy_s(thought, sizeof(thought), "�դγ���һ�r�Ĥ��͡��������ΤϤ��줢�뤫��");
            }
            else if (subName1 == 0)
            {
                strcpy_s(thought, sizeof(thought), "��交��L���_����������");
            }
            else if (subName2 == 7)
            {
                strcpy_s(thought, sizeof(thought), "�ޡ����⤽�⤳���Ϥ��ߤ���");
            }
            break;

        case STAGE_DESERT:
            if (subName2 == 11)
            {
                strcpy_s(thought, sizeof(thought), "Į������ɰĮ�������Ϥޤ��ˍu�������ˤ�����ǰ��");
            }
            else if (subName2 == 7)
            {
                strcpy_s(thought, sizeof(thought), "�ڤ�ɰĮ���ޤ��˺��ߤ���");
            }
            else if (subName1 == 4)
            {
                strcpy_s(thought, sizeof(thought), "�ܩ`���`�饤��Ҋ���ʤ�ɰĮ�����������");
            }
            else if (subName2 == 2)
            {
                strcpy_s(thought, sizeof(thought), "�_�������äƥ��������ߤ����ʸФ���");
            }
            break;

        default:
            break;
        }
        if (subName1 == -1 || subName2 == -1)
        {
            strcpy_s(thought, sizeof(thought), "�Τʤ�����Σأأأؤäơ���ζ�狼����");
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
                    "�����L���ǥЩ`�٥���`����ä��ĵؤ褤�ͣ�");
            }
            else if (buildEvent==B_EVNT_DRKTEA)
            {
                strcpy_s(thought, sizeof(thought), 
                    "���������Ҋ�ʤ��餪�衢����餷��");
            }
            else if (buildEvent == B_EVNT_RESTCAMP)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����L���ȥ����׈������ԤԤä���Ǥ���");
            }
            else if (buildEvent == B_EVNT_POLNIGHT)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����Ǥ����ɡ�ҹ�ˤʤ�ޤǤʤ��ۤ������ʤ���");
            }
            break;

        case STAGE_BEACH:
            if (buildType == B_TYPE_HOTSPRING)
            {
                strcpy_s(thought, sizeof(thought),
                    "��交��������Ϥ�äѤ꺣���Ф�������");
            }
            else if (buildEvent == B_EVNT_POLINFINITY)
            {
                strcpy_s(thought, sizeof(thought),
                    "�������Υש`��Ύڤ�����Ϥ亣�Υ�٥뤸��ʤ���");
            }
            else if (buildEvent == B_EVNT_DRKALCOHOL)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����Ǿ��ΤϘS����");
            }
            else if (buildType == B_TYPE_MAKEBYHAND)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����͡���交ˤ�ɫ����زĤ�����ޤ��Τ�");
            }
            else if (buildEvent == B_EVNT_EATUNAGI)
            {
                strcpy_s(thought, sizeof(thought),
                    "�\���M������ȥ��ʥ��ⰲ������ζ�����ˤʤä���");
            }
            else if (buildEvent == B_EVNT_POLNIGHT)
            {
                strcpy_s(thought, sizeof(thought),
                    "���ޤϳ�����ʤ�������⺣���O�Ǥ��裿");
            }
            break;

        case STAGE_DESERT:
            if (buildType == B_TYPE_HOTSPRING)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����͡�ҹ�Ϻ�����Ǭ���������Ȫ�ޤ�������");
            }
            else if (buildEvent == B_EVNT_POLNORMAL)
            {
                strcpy_s(thought, sizeof(thought),
                    "��ͨ�Υש`���ҹ�ˤʤ���]����㤦�ͣ�����ʤ���");
            }
            else if (buildEvent == B_EVNT_POLINFINITY)
            {
                strcpy_s(thought, sizeof(thought),
                    "������ɰĮ���Ф˥���ե��˥ƥ��ש`�����ߤǤ���");
            }
            else if (buildEvent == B_EVNT_POLNIGHT)
            {
                strcpy_s(thought, sizeof(thought),
                    "ҹ�Τǥʥ��ȥש`����ߤä���");
            }
            else if (buildEvent == B_EVNT_DRKBAR)
            {
                strcpy_s(thought, sizeof(thought),
                    "��������L��Ҋ�ʤ���һ����Ʒ�ä�٘�g�Ǥ���");
            }
            else if (buildEvent == B_EVNT_MOVHOR)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����Ϥ⤦ʮ�ֲ����Ǥ��衢ҹ���������ˤ⤤�ʤ���");
            }
            else if (buildEvent == B_EVNT_RESTCAMP)
            {
                strcpy_s(thought, sizeof(thought),
                    "���������ǥ����פ����ɰ�Ȱ����餱�����");
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

    // ���Ʃ`���ˌ������؄e���٥��(�ä��Ӥ��I��)
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
