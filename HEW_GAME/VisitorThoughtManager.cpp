#include "VisitorThoughtManager.h"
#include "ThoughtListManager.h"
#include "AppDeclared.h"
#include "Tools.h"

void CreateStudentThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "�����`��ä��ؔ������~�ä���");
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "��Ф����ʤ󤫂��Ԝ������ͣ�����");
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "�����͡��������ԥ���ߤ����ˤʤ�");
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�դ�դ�ʸФ��⤤���ä���");
        }
        else if (subName2 == 3)
        {
            strcpy_s(thought, sizeof(thought), "���n���`���ߤ����ʽ�ŸУ�");
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "������ǰ���ˤäݤ��Ǥ���");
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "��äƤʤ󤫲���ä���");
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "һ�r�ĤäƤɤ��������ȤǤ���");
        }
        else if (subName2 == 1)
        {
            strcpy_s(thought, sizeof(thought), "��������äȵ�ζ�ʸФ���������");
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "������ǰ�}���Έ�����Ҋ�����Ȥ����룮����");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateCoupleThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "������ǰ�ä�˽�����Τ��Ȥ�˼���������");
        }
        else if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���뤤�͡������Τ��Ȥ⡢˽������δ����äƸФ���");
        }
        else if (subName1 == 3)
        {
            strcpy_s(thought, sizeof(thought), "�𤤤äƤ�Ф��ʤ����說�說�ˤʤ��");
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "���á����礦�ɥ��ԥ���ߤ���");
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�դ�դ�ʸФ����ä���");
        }
        else if (subName2 == 5)
        {
            strcpy_s(thought, sizeof(thought), "�˲��͡��Τ�Ӥ�Εr�g����������");
        }
        else if (subName2 == 6 || subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "���������ɤΤ褦�����h�ʸФ�");
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "���󤿤��Ĥ�ʹ�äƤ�����ɤȤԤä���Ǥ����");
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "һ�r�ĤäƤ��������櫓�ʤ����");
        }
        else if (subName1 == 9 || subName2 == 0)
        {
            strcpy_s(thought, sizeof(thought), "�ʤ�˽�����Τ��Ȥ�ʾ����ݣ�");
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "�⤦�նΤ����¤��äѤ�����");
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�ܿդΤ�ΤϤ���äȺä��ˤʤ�ʤ���");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateProgrammerThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���Ĥ��\��UI��Ҋ��Ȥ���ɤ��衢���뤤����������");
        }
        else if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "�����`��äƤ��Ф餷���衢�Х��Ηʳ���S����");
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�ܿդ���������˽�����˱�Ҫ����");
        }
        else if (subName1 == 8)
        {
            strcpy_s(thought, sizeof(thought), "�����ǥ���`�Х�Τ�Σ����������ɤ���ʹ�����");
        }
        else if (subName2 == 2 || subName2 == 6 || subName2 == 7 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�����褳����ǰ���o�ޤΥХ������Ť��줿�ݤ�����");
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "��Ȥ�����L���Ƥ�Х����Ӥ�����");
        }
        else if (subName1 == 9 || subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "���á����Τ��ȤǤ�����");
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "���ä������¤����Ӥ줿�Τˤ�");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateArtistThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���뤤�äơ����Υ꥾�`�Ȥˤ���ɫ��Ⱦ�ޤä���");
        }
        else if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "����������ζ������Τ���Ǥ��礦");
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�ܿդΤ�Τ����o�ޤʿ����Ԥ����߳������");
        }
        else if (subName2 == 2 || subName2 == 6 ||
            subName2 == 7 || subName2 == 10 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�����k������߳����뤽����ǰ�Ǥ�");
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "һ�r�ĤΤ�Τ����餳���؄e�����Ф�����ޤ���");
        }
        else if (subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�����á�������˽�Υѥ�������Ǥ��裡");
        }

        if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "���Ԥ��������~�����������߳����Τ��൱�y������");
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�����`�ޥ�äƣ���������äȤ���Ǥ����");
        }
        else if (subName2 == 1 || subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "���Ԥ��٤ʤ��͡�����ѥ��Ȥ��١����ޤ���");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateOfficerThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 0)
        {
            strcpy_s(thought, sizeof(thought), "�������äƤ����Ǥ��͡����Ĥ���װ��Ϣ�ष����");
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "�՚��i��Τ���������դ����i�ޤʤ��ˤˤʤꤿ��");
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "���Τդ�դ�Ф������֤�͡��ܤ�Ϥ��Ĥ�Ӳ����");
        }
        else if (subName2 == 1 || subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "������͡���������Ť��θФ�");
        }

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���Ĥ����뤹�������˃P���Ƥ�ΤǤ���ä������");
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "����äѤ��äƺΤǤ���äȥ��饤��ݤ����룿");
        }
        else if (subName1 == 13 || subName2 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�Τʤ����������ݤ�");
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�⤦�����������¤����ݤϿ��������ʤ���");
        }
        else if (subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "����ä�����Ť��ʤ��ͤ�����ǰ");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateFamilyThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�ۤ顢��ζ�����d����Ǥ��衫");
        }
        else if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "����ǰҊ���Фä��ѥ�����󤫤襤���Ǥ���");
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "���Τ��Ȥ�˼���������ͥѥ�");
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "��٤Ԓ�ˤ���ʸФ��Ǥ��͡�");
        }
        else if (subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "��ǰ�����Ǥ�_���Ȥ���Ƕ��ԤǤ��ޤ���");
        }

        if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "���������С�����Ӥ�Ҋ�����ʤ���ΤǤ��礦��");
        }
        else if (subName1 == 4 || subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "�ӹ��ˤϤ狼�ꤺ�餤�Ǥ��礦");
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "�ʤ󤫉�ʈ�����˼���Ĥ���������");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateRabbitThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 8 || subName1 == 10 || subName1 == 14 ||
            subName2 == 5 || subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�ʤ����g�äݤ����說�說���륦����");
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�����䤷����Υ������U���ߤ˸��x�ꤷ�Ϥ�������");
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "�����g����ͬʿ�Ȥ��Ƥ���ä���ζ����������");
        }
        else if (subName2 == 13)
        {
            strcpy_s(thought, sizeof(thought), "��ä�Σ�����Ȥ�����ʤ�������");
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�Ӥʤ��Ȥ�˼������������������");
        }
        else if (subName2 == 2 || subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "ɽ�Ȥ�ɭ�Ȥ��⤦Ҋ���������");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateWhaleThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 8 || subName1 == 10 || subName1 == 14 ||
            subName2 == 5 || subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�ʤ����g�äݤ����說�說���륯����");
        }
        else if (subName2 == 2)
        {
            strcpy_s(thought, sizeof(thought), "ɭ���䤷����Υ������U���ߤ˸��x�ꤷ�Ϥ�������");
        }
        else if (subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "ɽ���䤷����Υ������U���ߤ˸��x�ꤷ�Ϥ�������");
        }

        if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�Ӥʤ��Ȥ�˼������������������");
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "���Ϥ⤦Ҋ���������");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateCamelThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 8 || subName1 == 10 || subName1 == 14 ||
            subName2 == 5 || subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�ʤ����g�äݤ����說�說���륯����");
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�����䤷����Υ������U���ߤ˸��x�ꤷ�Ϥ�������");
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "�����g����ͬʿ�Ȥ��Ƥ���ä���ζ����������");
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�Ӥʤ��Ȥ�˼������������������");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateSingleVisitorThoughtByManager(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    switch (visitorType)
    {
    case VISITOR_TYPE::NONE:
        break;
    case VISITOR_TYPE::STUDENTS:
        CreateStudentThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::COUPLE:
        CreateCoupleThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::PROGRAMMER:
        CreateProgrammerThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::ARTIST:
        CreateArtistThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::OFFICER:
        CreateOfficerThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::FAMILY:
        CreateFamilyThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::RABBIT:
        CreateRabbitThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::WHALE:
        CreateWhaleThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::CAMEL:
        CreateCamelThought(buildType, buildEvent);
        break;
    default:
        break;
    }
}
