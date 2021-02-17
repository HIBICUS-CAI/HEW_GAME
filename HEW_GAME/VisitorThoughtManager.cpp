#include "VisitorThoughtManager.h"
#include "ThoughtListManager.h"
#include "AppDeclared.h"
#include "Tools.h"
#include "ResultTips.h"
#include "FinalResult.h"

void CreateStudentThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "�����`��ä��ؔ������~�ä���");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "��Ф����ʤ󤫂��Ԝ������ͣ�����");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "�����͡��������ԥ���ߤ����ˤʤ�");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�դ�դ�ʸФ��⤤���ä���");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 3)
        {
            strcpy_s(thought, sizeof(thought), "���n���`���ߤ����ʽ�ŸУ�");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "������ǰ���ˤäݤ��Ǥ���");
            VisitorFeelGood(visitorType);
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "��äƤʤ󤫲���ä���");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "һ�r�ĤäƤɤ��������ȤǤ���");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 1)
        {
            strcpy_s(thought, sizeof(thought), "��������äȵ�ζ�ʸФ���������");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "������ǰ�}���Έ�����Ҋ�����Ȥ����룮����");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�Щ`�٥���`�����Է֤��֤Ǥ������ΤϘS������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ΈR���Ĥʥ�`���У��������ΈR���Ĥʥ�`���У�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "�Τ����ä�����פ�����ͨ�Υש`����S������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "���ԥ�������������Ҥ��������Ϥ�����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "����ӳ���Ϥ��Ĥ���ˤʤ�ʤ���");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "����ʤ��ä��������g�F�g�ˤ�g�F�ۤ����Ǥ���");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�������Υ��å���������餷����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "��äѤ�һ�w�˸褦�ΤϘS�������Τ��������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "�ƥ�ȳ����Ϥ�����_�ɸФ�����");
            VisitorFeelGood(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���΄�����Ф��ʤ���");
            SetResultTipsTo("���Ȫ�΄����������ˤˌ����Ƥ���äȏ��Ҥ����뤫�⤷��ޤ���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ��նΤ��͵���˼����������������ζ��������");
            SetResultTipsTo("ѧ���ˌ����ƥ���`���ճ������뤫�⤷��ޤ���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ӹ��äݤ��ä�����");
            SetResultTipsTo("���Εr�ڤ������ˤ��ӹ��äݤ���Τ��ä��ǤϤ���ޤ���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�ۥ�`����äȿ��֤�ޤ���");
            SetResultTipsTo("����ɤ��ʤ������Ȥ�����ͽ�ϥۥ�`ӳ���ˤ��������֤ʤΤ�");
            VisitorFeelVeryBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateCoupleThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "������ǰ�ä�˽�����Τ��Ȥ�˼���������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���뤤�͡������Τ��Ȥ⡢˽������δ����äƸФ���");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 3)
        {
            strcpy_s(thought, sizeof(thought), "�𤤤äƤ�Ф��ʤ����說�說�ˤʤ��");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "���á����礦�ɥ��ԥ���ߤ���");
            VisitorFeelVeryGood(visitorType);
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�դ�դ�ʸФ����ä���");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 5)
        {
            strcpy_s(thought, sizeof(thought), "�˲��͡��Τ�Ӥ�Εr�g����������");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 6 || subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "���������ɤΤ褦�����h�ʸФ�");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "���󤿤��Ĥ�ʹ�äƤ�����ɤȤԤä���Ǥ����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "һ�r�ĤäƤ��������櫓�ʤ����");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 9 || subName2 == 0)
        {
            strcpy_s(thought, sizeof(thought), "�ʤ�˽�����Τ��Ȥ�ʾ����ݣ�");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "�⤦�նΤ����¤��äѤ�����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�ܿդΤ�ΤϤ���äȺä��ˤʤ�ʤ���");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "������Ȫ���˃����������ޤ�����");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "��������ů�������ݳ֤��������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "��ͨ�Υǩ`�ȸФ⤤���Ǥ����");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ󤫼���˘S����Ǥ���ߤ�����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�����������Οo�ޤʎڤ���Ф��ʤ���");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNORMAL)
        {
            strcpy_s(thought, sizeof(thought),
                "��ͨ�Υǩ`�ȸФ⤤���Ǥ����");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�����Ҥ��θʤ��Ǥ�ä��㤤�����Ĥˤ��ߤ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "��ͨ�Υǩ`�ȸФ⤤���Ǥ����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "��������һƷ⤦����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ󤫤�������ζ�ǥ說�說�����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ͤ������Z�����ˤ�һ�w�ˤ��äƤ���Ƥ褫�ä�");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "���챾���ˤ��⤷���Ǥ����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "һ�w��ӛ��Υ���������`������ޤ��礦��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ѥ����Τ�����؄e�ʤ����b������ޤ��礦��");
            VisitorFeelGood(visitorType);
        }

        if (buildEvent == B_EVNT_EATBBQ ||
            buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "����������������äȤͣ�����");
            SetResultTipsTo("��������������Ȥ���˥ǩ`�Ȥ��ʤ��Ǥۤ��������Ǥ���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "��äȤ������ʵ꤬������");
            SetResultTipsTo("�ƈ��Τ��١��X�����������ʤΤ�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "���ã��Τ��Υ���ԥ����}�ä�");
            SetResultTipsTo("����ԥ��ϥ��åץ�ˤϤ���ä�΢���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "��äȤ����x�k������Ϥ������");
            SetResultTipsTo("�������}���ˤˤ�äƺä��Ӥ�������ޤ�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ˤ�һ�w�˸褤������⤦");
            SetResultTipsTo("���åץ�ˌ�������ͨ�Υ��饪���Τۤ����������⤷��ޤ���");
            VisitorFeelVeryBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateProgrammerThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���Ĥ��\��UI��Ҋ��Ȥ���ɤ��衢���뤤����������");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "�����`��äƤ��Ф餷���衢�Х��Ηʳ���S����");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�ܿդ���������˽�����˱�Ҫ����");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 8)
        {
            strcpy_s(thought, sizeof(thought), "�����ǥ���`�Х�Τ�Σ����������ɤ���ʹ�����");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 2 || subName2 == 6 || subName2 == 7 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�����褳����ǰ���o�ޤΥХ������Ť��줿�ݤ�����");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "��Ȥ�����L���Ƥ�Х����Ӥ�����");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 9 || subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "���á����Τ��ȤǤ�����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "���ä������¤����Ӥ줿�Τˤ�");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "ů�����ˤʤä��͡��⤦�䷿�ˤϺΤ�����ʤ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�夫�������ɤ�ɤ�F��Ƥ��롢�������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�Щ`�٥���`�Τϳ��ä��֤���͡��S���ߤˤ��Ƥ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "���Τ��ޤ��������͡��ɤ�ʥХ��Ǥ�����ʤ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "ˮ�����Ф�Ӿ���Τ��������ϘS������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKTEA ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����͡��նΤϤ���ʵꤢ��ޤ����ʤ����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "���g�Ϥ����ޤǤǤ��뤫����äѤ�δ�����ڴ��Ǥ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "���Ο�Ѫ�Ф����֤�ä��֤��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "��������פ��Ǥ��͡����Υ���ǥ�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "һ�ˤǸ褦�ΤϚݘS�ʤ��Ȥ�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "�ۥƥ������Ť��ФϤ����͡��ѥ������ʹ���뤷");
            VisitorFeelAlright(visitorType);
        }
        else if (buildType == B_TYPE_MAKEBYHAND)
        {
            strcpy_s(thought, sizeof(thought),
                "������Τ�Τ˽��ξ������٤���ޤ���");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "���¤Εr��Ϥ⤦��`��󤤤äѤ�����");
            SetResultTipsTo("�ɤ����ץ���ީ`����ϳ��˥�`���Ǥ���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ������ʤ����ԥ����ä�");
            SetResultTipsTo("����ɤ��ʤ����ץ���ީ`�Ϥɤ���饿�ԥ����ä��ǤϤ���ޤ���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ӥ���˾��ޤ�����줿ӛ�����K�ä�");
            SetResultTipsTo("ң�������Ȥ���ץ���ީ`����˾�˟o��ʸ��ޤ�����줿���Ȥ�����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "���ä����Υ꥾�`�Ȥˤ�äȷg�䤫�ˤʤꤿ����");
            SetResultTipsTo("�󤷤����Ȥʤ��󤬡����Υץ���ީ`�ϥۥ�`���֤Ǥ�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "���ã�����ʤ����Ԥä��餪���ޤ������");
            SetResultTipsTo("���Υץ���ީ`�Ϥ��Ĥ����Ĥʤ�Τ�׷�󤷤Ƥ��ޤ�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ԥ�ǰ�˸褦�Τ��٤��u���������ʤ��");
            SetResultTipsTo("�ɤ���餳�Υץ���ީ`���ˤ�ǰ�˸褦�¤��Ӥ��Ǥ�");
            VisitorFeelBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateArtistThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���뤤�äơ����Υ꥾�`�Ȥˤ���ɫ��Ⱦ�ޤä���");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "����������ζ������Τ���Ǥ��礦");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�ܿդΤ�Τ����o�ޤʿ����Ԥ����߳������");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 2 || subName2 == 6 ||
            subName2 == 7 || subName2 == 10 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�����k������߳����뤽����ǰ�Ǥ�");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "һ�r�ĤΤ�Τ����餳���؄e�����Ф�����ޤ���");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�����á�������˽�Υѥ�������Ǥ��裡");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "���Ԥ��������~�����������߳����Τ��൱�y������");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�����`�ޥ�äƣ���������äȤ���Ǥ����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 1 || subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "���Ԥ��٤ʤ��͡�����ѥ��Ȥ��١����ޤ���");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "��Ȫ���ߤߤ줿�饢���ǥ����ɤ�ɤ���Ƥ����ޤ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "���ʥ��ݤ����������֤äƤޤ��͡��������ۤɤ�ּ��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "�ճ��Ф��äפ�Ǥ�������������Ф��𤳤��һ�Ĥ�");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�o�ޤ��Ӥ٤Ƥ�ܩ`���`�饤���ɫ��ʿ����Ԥ�����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "������Ф�������Ϥ⤦�o������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�ˡ��Κݳ֤�����餬ȫ�Ƥ���������Τθ�Դ����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ˤˤ�����֪�R��U�Y�ʤɵä��ޤ���");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "��Ȼ��Ԓ���Ϥ����Է֤�{�äǤ���褦�ˤʤä�");
            VisitorFeelGood(visitorType);
        }

        if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����μ���Εr˼�����������S����˼��������ʤ���");
            SetResultTipsTo("������Ԓ�Ǥ��������`�ƥ����Ȥ�������������˱��Ϥ˥ե�줿�ߤ���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����褦�ΤϿ��֤Ǥ��裮����");
            SetResultTipsTo("�����΂��Ԥʤ�Ǥ����ɡ����`�ƥ����Ȥ���ϸ褦���Ȥ��Ӥߤ���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ󤫳������Ƥ�ݤ����룿");
            SetResultTipsTo("���`�ƥ����Ȥ���Ϥ��Ĥ�~�m��լ�ڄդ��Ƥ��뤽���Ǥ�");
            VisitorFeelBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateOfficerThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 0)
        {
            strcpy_s(thought, sizeof(thought), "�������äƤ����Ǥ��͡����Ĥ���װ��Ϣ�ष����");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "�՚��i��Τ���������դ����i�ޤʤ��ˤˤʤꤿ��");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "���Τդ�դ�Ф������֤�͡��ܤ�Ϥ��Ĥ�Ӳ����");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 1 || subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "������͡���������Ť��θФ�");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���Ĥ����뤹�������˃P���Ƥ�ΤǤ���ä������");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "����äѤ��äƺΤǤ���äȥ��饤��ݤ����룿");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 13 || subName2 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�Τʤ����������ݤ�");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�⤦�����������¤����ݤϿ��������ʤ���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "����ä�����Ť��ʤ��ͤ�����ǰ");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���켡�ˤ����������Ĥ����ޤ�����");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����͡�����äݤ��ʸФ�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�Է֤��֤Ǥ������ΤϤ��Τ��Τ�����");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ʤ���ʤ�����Ύڤ�����������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "ҹ�Υש`�뤳�����ؤ���פ�������ȤϤ�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "���ԥ�����ζ���ˤ�Ԫ�ݤˤ������������룡");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "��ä����һ��⤦��냇�ݤ�����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "��äѽԤǥ��饪�����Ƥη����S������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "�त������äơ����������޶������Ȥ������Ȥ����");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�նΤϤ���ޤ�ۥ�`Ҋ�Ƥʤ��󤬤ʤ����r�ʸФ�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF ||
            buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�����������Ф��ʤ��������ˤ��ä�������");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "����󡢅g������Ȫ�äƤʤ󤫤���äȤĤޤ��");
            SetResultTipsTo("�ɤ�����ՆT������ճ����`�����Y��̽���Ƥ��ޤ�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "��ä��؄e�ʤ�Τ���������");
            SetResultTipsTo("�ɤ�����ՆT������ճ����`�����Y��̽���Ƥ��ޤ�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "��������½K����߻ᤫ����");
            SetResultTipsTo("�ՆT����ˌ����ƶ���������߻�Ϥ⤦����Ǥ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "���˵Ĥˤϥ���ѥ��Ȥ���������");
            SetResultTipsTo("�Y����Ҋͨ���䤹���ʤ��Ȥ��ՆT����̽���Ƥ����ΤǤϤ���ޤ���");
            VisitorFeelBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateFamilyThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�ۤ顢��ζ�����d����Ǥ��衫");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "����ǰҊ���Фä��ѥ�����󤫤襤���Ǥ���");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "���Τ��Ȥ�˼���������ͥѥ�");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "��٤Ԓ�ˤ���ʸФ��Ǥ��͡�");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "��ǰ�����Ǥ�_���Ȥ���Ƕ��ԤǤ��ޤ���");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "���������С�����Ӥ�Ҋ�����ʤ���ΤǤ��礦��");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 4 || subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "�ӹ��ˤϤ狼�ꤺ�餤�Ǥ��礦");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "�ʤ󤫉�ʈ�����˼���Ĥ���������");
            VisitorFeelVeryBad(visitorType);
        }
    }
    else
    {
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "�Τμ������Ф���Ȫ�����ޤ��礦��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "�ɤ�ʕr�Ǥ������ש`��äƤ������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "����ע�⤷��һ�w����ζ�����������ޤ��礦��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "ͬ����ζ������ĸ�����Υ���`�Ȥ��`���Lζ������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�������Ф���Τ�����꣡");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ĸ����󥫥�ԥ�ߤ�����");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "������g�Ǥ���ʤ�ä���Εr�g��һ������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "��̫�ɡ����Υ���餫�ä������Ǥ��礦��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "����ӳ����פ��ͥޥ�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "������󡢽������Τ褦�����ɤ����g�ˤʤꤿ����");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "�����һ�w�˥��饪�����Ƥ�ʤ��ʤ��S���������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ĸ����󥭥��פä��य�S������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "�Է֤Ǥ����b������Τ⤤����");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "һ�����ʡ���ˮ�ש`��Ϥޤ�Σꓤ�����������");
            SetResultTipsTo("�ӹ��ˌ�������ˮ�ש`��Ϥޤ��ޤ��礤");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������`�`�ɤ��ˤ���Ω`�`�`�`");
            SetResultTipsTo("�ӹ����Է֤��ܤ�˿`�ꤿ���ʤ����ڤ����������Ӥˤʤ�����Ԥ��ǳ��˸ߤ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR ||
            buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "����������δ���꤬����Ǥ��礦��");
            SetResultTipsTo("δ����ˌ����ƾƤϥ���Ǥ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ʤ������ʤ����ۥ�`�äƤޤ��Ф�äʤ���");
            SetResultTipsTo("�ۥ�`ӳ�����ӹ��ˌ����Ʋ��m�Фʤ�ΤǤ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ӥ�Ѫ�����Ƥ롣����");
            SetResultTipsTo("���������ӳ���α������ݤ��ӹ��ˌ����Ʋ��m�Фʤ�ΤǤ�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�虜�虜˽�����֤��Ʊ�Ҫ�ʤ������");
            SetResultTipsTo("������Щ`��һ�w�ˤ��뤳�Ȥ����ФʤΤǤ�");
            VisitorFeelVeryBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateRabbitThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
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
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�����䤷����Υ������U���ߤ˸��x�ꤷ�Ϥ�������");
            VisitorFeelGood(visitorType);
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "�����g����ͬʿ�Ȥ��Ƥ���ä���ζ����������");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 13)
        {
            strcpy_s(thought, sizeof(thought), "��ä�Σ�����Ȥ�����ʤ�������");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�Ӥʤ��Ȥ�˼������������������");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 2 || subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "ɽ�Ȥ�ɭ�Ȥ��⤦Ҋ���������");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "��������������ů����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������챾������ζ����������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "���ε��य������쥦��");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "�c�䤫�ˤ��Ҥ�������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�ЄӤ��줿����������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "������פ�������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "���������Τ����g������������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "����ɭ����������������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ѥ����˺Τ����ä��Ϥ��뤬��������");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���΄����⤦���ᥦ��������");
            SetResultTipsTo("����ˌ��������Ȫ�΄���������äȏ��Ҥ����ޤ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ҥá��Ҥɤ�����������");
            SetResultTipsTo("ͬ�������g��ʳ�٤���ͬʿ�ʤΤǡ������Ĥ�ʳ���ΤϤ���äȲп�ʤ��ȤǤ�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "һ���Ǥ�ʤ��ݤ����륦��������");
            SetResultTipsTo("��ˮ�ש`�뤫���ѳ��Τϥ����������Է֤����ǤǤ��뤳�ȤǤϤ���ޤ���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "������Ѫ��Ѫ���ã�");
            SetResultTipsTo("���襤������������ˌ����ƥۥ�`�ϴ̼������ޤ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "���֤ʤ���褳�Υ����ף�����");
            SetResultTipsTo("���襤������������ˌ����ƥ��������ӳ���ϴ̼������ޤ�");
            VisitorFeelBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateWhaleThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
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
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 2)
        {
            strcpy_s(thought, sizeof(thought), "ɭ���䤷����Υ������U���ߤ˸��x�ꤷ�Ϥ�������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "ɽ���䤷����Υ������U���ߤ˸��x�ꤷ�Ϥ�������");
            VisitorFeelVeryGood(visitorType);
        }

        if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�Ӥʤ��Ȥ�˼������������������");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "���Ϥ⤦Ҋ���������");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�������夬��ȫ���¤ޤä���������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�����Ȿ����ּ��������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�~�äƤ������ζ������Τ��ä���");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "��ζ�������������Τ̤�̤�Τ��");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "С�������ߤ�����С������������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "��פ�����������äѤ���ˮ��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "���Τʤ��ʤ��Υ���ѥ��Ȥ����륯������פ�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����襯�������θ���äѤ��ʸФ�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "�ϥϥϥϥϤ��쳬��פ�������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "˽��������������͡�һ�w�˸褦�Τ�һ���S����");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "˽�⤳��ʾ_���ʥ���������`����륯����");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���������΄��������ˤ��ޤ�ʤ�����");
            SetResultTipsTo("����ˌ��������Ȫ�΄���������äȏ��Ҥ����ޤ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNORMAL ||
            buildEvent == B_EVNT_POLFLUSH ||
            buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "�������Υש`��С��������Ǥ��礦��");
            SetResultTipsTo("���Ĥ��������ڤ�Ӿ���Ǥ��뤯����ˌ����ƥש`��Ϥۤ�С���������ޤ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ƥ��١����֥���������");
            SetResultTipsTo("�⤷�߈R�κ����Ф��E�ÒB���ˤʤ���^�Ϥ����㤴����ˤʤ�ޤ�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�������褦�ΤϽ�һ�w�Ǥ����S�����Ǥ��礦��");
            SetResultTipsTo("��������罻���R���������ʤΤǡ���ǥ��ߥ�˥��`�������Ф���Ҫ������ޤ�");
            VisitorFeelVeryBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateCamelThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
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
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�����䤷����Υ������U���ߤ˸��x�ꤷ�Ϥ�������");
            VisitorFeelVeryGood(visitorType);
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "�����g����ͬʿ�Ȥ��Ƥ���ä���ζ����������");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�Ӥʤ��Ȥ�˼������������������");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "��ȫ���¤ޤä�����ҹ��ɰĮ�Ǥ�����ʤ�������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "���ε��य������쥯��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������챾������ζ����������");
            VisitorFeelGood(visitorType);
        }
        else if (buildType == B_TYPE_POOL)
        {
            strcpy_s(thought, sizeof(thought),
                "ˮ���Ф�Ӿ���Τ��य�S����������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ͤ��Τ�������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "���󡢤������ε�ˤ�������һƷ����������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�������त�褳��ӳ��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "������פ�������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "����ɰĮ����������������");
            VisitorFeelVeryGood(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�Τʤ�����΄���");
            SetResultTipsTo("����ˌ��������Ȫ�΄���������äȏ��Ҥ����ޤ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ҥá��Ҥɤ�����������");
            SetResultTipsTo("ֲʳ����ˌ��������ʳ���Τϲп�ʤ��ȤǤ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ԥۤ���򟆤��Ƥ륯����");
            SetResultTipsTo("ֲʳ����ˌ��������ʳ���Τϲп�ʤ��ȤǤ�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "ɰĮ�Ϥ⤦ʮ�֤��襤�Τˤ���");
            SetResultTipsTo("ҹ�ˤʤ��ɰĮ��ɫ��ʄ��郎���Ƥ��ޤ����񄤵��ˌ����Ƥ����ʮ�֥ۥ�`�Ǥ���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "�ܤ��褦�ΤϿ��֥���������");
            SetResultTipsTo("����ɤ��ʤ����餯������ϸ褨�ޤ���ߤ���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ󤫤���ɤ���ɰĮ�����˼������������");
            SetResultTipsTo("�ۤ�ȫ�Ƥβ������ˌ�����ɰĮ��ĺ�餷�Ĥ餤�����Ǥ���");
            VisitorFeelVeryBad(visitorType);
        }
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
        CreateStudentThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::COUPLE:
        CreateCoupleThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::PROGRAMMER:
        CreateProgrammerThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::ARTIST:
        CreateArtistThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::OFFICER:
        CreateOfficerThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::FAMILY:
        CreateFamilyThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::RABBIT:
        CreateRabbitThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::WHALE:
        CreateWhaleThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::CAMEL:
        CreateCamelThought(visitorType, buildType, buildEvent);
        break;
    default:
        break;
    }
}
