#include "ThoughtListManager.h"
#include "AppDeclared.h"
#include "Tools.h"
#include "VisitingVisitorManager.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"
#include "ThoughtListShower.h"
#include "VisitorThoughtManager.h"
#include "ResultTips.h"
#include "FinalResult.h"
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
    // ���ʂ̖��O�D�����ǂ���

    // �q�ɑ΂��ē��ʃC�x���g(�D���̂�)
    // ���ʂɍD�����ǂ���

    CreateSingleVisitorThoughtByManager(visitorType, buildType, buildEvent);
}

void CreateSingleTypeThoughtByStage(int buildType, int buildEvent)
{
    // ���ʂ̃Q�[�g�C�x���g
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
                strcpy_s(thought, sizeof(thought), "���������Ƃ���ɂ��R�����邩��H�ʔ���");
                VisitorFeelAlright(VISITOR_TYPE::NONE);
            }
            else if (subName2 == 8)
            {
                strcpy_s(thought, sizeof(thought), "�����̊��L�����v��Ƒ����҂����肾�ˁI");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            else if (subName2 == 13)
            {
                strcpy_s(thought, sizeof(thought), "�m�����݂������ʂȗ��������銴��");
                VisitorFeelAlright(VISITOR_TYPE::NONE);
            }
            else if (subName1 == 1)
            {
                strcpy_s(thought, sizeof(thought), "���邢���Ċm���Ɏ�������ł���");
                VisitorFeelAlright(VISITOR_TYPE::NONE);
            }
            break;

        case STAGE_BEACH:
            if (subName2 == 11)
            {
                strcpy_s(thought, sizeof(thought), "�C������Γ��A��������ΊC�A�������O�ł���");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
            }
            else if (subName1 == 6)
            {
                strcpy_s(thought, sizeof(thought), "���̏o���ꎞ�I����ˁA�������̂͂��ꂠ�邩��");
                VisitorFeelAlright(VISITOR_TYPE::NONE);
            }
            else if (subName1 == 0)
            {
                strcpy_s(thought, sizeof(thought), "�C�l�̕����m����������");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            else if (subName2 == 7)
            {
                strcpy_s(thought, sizeof(thought), "�܁A�������������͂��݂���");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            break;

        case STAGE_DESERT:
            if (subName2 == 11)
            {
                strcpy_s(thought, sizeof(thought), "���X���鍻���A�����͂܂��ɓ��A�{���ɂ������O��");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
            }
            else if (subName2 == 7)
            {
                strcpy_s(thought, sizeof(thought), "�L�������A�܂��ɊC�݂���");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
            }
            else if (subName1 == 4)
            {
                strcpy_s(thought, sizeof(thought), "�{�[�_�[���C�������Ȃ������A�[�����X����");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
            }
            else if (subName2 == 2)
            {
                strcpy_s(thought, sizeof(thought), "�m���������ăI�A�V�X�݂����Ȋ����I");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
            }
            break;

        default:
            break;
        }
        if (subName1 == -1 || subName2 == -1)
        {
            strcpy_s(thought, sizeof(thought), "���Ȃ񂾂��̂w�w�w�w���āA�Ӗ��킩����");
            VisitorFeelVeryBad(VISITOR_TYPE::NONE);
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
            if (buildEvent == B_EVNT_EATBBQ)
            {
                strcpy_s(thought, sizeof(thought),
                    "���̕��i�Ńo�[�x�L���[������ĐS�n�悢�ˁI");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_DRKTEA)
            {
                strcpy_s(thought, sizeof(thought),
                    "��̗�������Ȃ��炨���A�f���炵��");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_RESTCAMP)
            {
                strcpy_s(thought, sizeof(thought),
                    "�ǂ����i�ƃL�����v��A�����҂�����ł���");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_POLNIGHT)
            {
                strcpy_s(thought, sizeof(thought),
                    "���͒��ł����ǁA��ɂȂ�܂łȂ񂩖��ɗ����Ȃ���");
                SetResultTipsTo("���̃X�e�[�W�ɂ͒��ł�");
                VisitorFeelBad(VISITOR_TYPE::NONE);
            }
            break;

        case STAGE_BEACH:
            if (buildType == B_TYPE_HOTSPRING)
            {
                strcpy_s(thought, sizeof(thought),
                    "�C�l�ɗ����ȏ����ς�C�ɍs��������");
                VisitorFeelBad(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_POLINFINITY)
            {
                strcpy_s(thought, sizeof(thought),
                    "�������̃v�[���̍L���A���͂�C�̃��x������Ȃ��H");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_DRKALCOHOL)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����Ŏ����ނ̂͊y����");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            else if (buildType == B_TYPE_MAKEBYHAND)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����ˁA�C�l�ɂ͐F��ȑf�ނ�����܂��̂�");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_EATUNAGI)
            {
                strcpy_s(thought, sizeof(thought),
                    "�^����Ə����ƃE�i�M�������Ŕ��������ɂȂ����I");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_POLNIGHT)
            {
                strcpy_s(thought, sizeof(thought),
                    "���܂͒�����Ȃ��H������C�ׂ̗ł���H");
                SetResultTipsTo("���o���̊C�l�̓i�C�g�v�[���Ƒ��������ł��傤");
                VisitorFeelBad(VISITOR_TYPE::NONE);
            }
            break;

        case STAGE_DESERT:
            if (buildType == B_TYPE_HOTSPRING)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����ˁA��͊��������������A����܂������I");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_POLNORMAL)
            {
                strcpy_s(thought, sizeof(thought),
                    "���ʂ̃v�[���͖�ɂȂ�ƕ߂��Ⴄ�ˁH�ܑ̂Ȃ���");
                VisitorFeelBad(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_POLINFINITY)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����A�����̒��ɃC���t�B�j�e�B�v�[���ōō��ł��I");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_POLNIGHT)
            {
                strcpy_s(thought, sizeof(thought),
                    "��̂Ńi�C�g�v�[���ō������I");
                VisitorFeelVeryGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_DRKBAR)
            {
                strcpy_s(thought, sizeof(thought),
                    "���̊O�̕��i���Ȃ����t�̕i�����ґ�ł���");
                VisitorFeelGood(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_MOVHOR)
            {
                strcpy_s(thought, sizeof(thought),
                    "�����͂����\���|���ł���A�邾�����̐l�����Ȃ���");
                SetResultTipsTo("��̍����͂����\���|����������܂���");
                VisitorFeelBad(VISITOR_TYPE::NONE);
            }
            else if (buildEvent == B_EVNT_RESTCAMP)
            {
                strcpy_s(thought, sizeof(thought),
                    "���H�����ŃL�����v����ƍ��ƚ����炯�����H");
                SetResultTipsTo("�����ɃL�����v����̂͂�����Ɣ����ł��傤");
                VisitorFeelVeryBad(VISITOR_TYPE::NONE);
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

    // �X�e�[�W�ɑ΂��ē��ʃC�x���g(�D����������)
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

    if (GetSceneNodeByName("resort") != NULL)
    {
        ClearSceneCamBuffer(GetSceneNodeByName("resort"));
    }
}
