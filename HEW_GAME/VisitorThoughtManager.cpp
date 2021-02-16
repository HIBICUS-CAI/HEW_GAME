#include "VisitorThoughtManager.h"
#include "ThoughtListManager.h"
#include "AppDeclared.h"
#include "Tools.h"
#include "ResultTips.h"

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
        if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�Щ`�٥���`�����Է֤��֤Ǥ������ΤϘS������");
        }
        else if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ΈR���Ĥʥ�`���У��������ΈR���Ĥʥ�`���У�");
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "�Τ����ä�����פ�����ͨ�Υש`����S������");
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "���ԥ�������������Ҥ��������Ϥ�����");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "����ӳ���Ϥ��Ĥ���ˤʤ�ʤ���");
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "����ʤ��ä��������g�F�g�ˤ�g�F�ۤ����Ǥ���");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�������Υ��å���������餷����");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "��äѤ�һ�w�˸褦�ΤϘS�������Τ��������");
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "�ƥ�ȳ����Ϥ�����_�ɸФ�����");
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���΄�����Ф��ʤ���");
            SetResultTipsTo("���Ȫ�΄����������ˤˌ����Ƥ���äȏ��Ҥ����뤫�⤷��ޤ���");
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ��նΤ��͵���˼����������������ζ��������");
            SetResultTipsTo("ѧ���ˌ����ƥ���`���ճ������뤫�⤷��ޤ���");
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ӹ��äݤ��ä�����");
            SetResultTipsTo("���Εr�ڤ������ˤ��ӹ��äݤ���Τ��ä��ǤϤ���ޤ���");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�ۥ�`����äȿ��֤�ޤ���");
            SetResultTipsTo("����ɤ��ʤ������Ȥ�����ͽ�ϥۥ�`ӳ���ˤ��������֤ʤΤ�");
        }
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
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "������Ȫ���˃����������ޤ�����");
        }
        else if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "��������ů�������ݳ֤��������");
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "��ͨ�Υǩ`�ȸФ⤤���Ǥ����");
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ󤫼���˘S����Ǥ���ߤ�����");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�����������Οo�ޤʎڤ���Ф��ʤ���");
        }
        else if (buildEvent == B_EVNT_POLNORMAL)
        {
            strcpy_s(thought, sizeof(thought),
                "��ͨ�Υǩ`�ȸФ⤤���Ǥ����");
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�����Ҥ��θʤ��Ǥ�ä��㤤�����Ĥˤ��ߤ���");
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "��ͨ�Υǩ`�ȸФ⤤���Ǥ����");
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "��������һƷ⤦����");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ󤫤�������ζ�ǥ說�說�����");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ͤ������Z�����ˤ�һ�w�ˤ��äƤ���Ƥ褫�ä�");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "���챾���ˤ��⤷���Ǥ����");
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "һ�w��ӛ��Υ���������`������ޤ��礦��");
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ѥ����Τ�����؄e�ʤ����b������ޤ��礦��");
        }

        if (buildEvent == B_EVNT_EATBBQ ||
            buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "����������������äȤͣ�����");
            SetResultTipsTo("��������������Ȥ���˥ǩ`�Ȥ��ʤ��Ǥۤ��������Ǥ���");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "��äȤ������ʵ꤬������");
            SetResultTipsTo("�ƈ��Τ��١��X�����������ʤΤ�");
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "���ã��Τ��Υ���ԥ����}�ä�");
            SetResultTipsTo("����ԥ��ϥ��åץ�ˤϤ���ä�΢���");
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "��äȤ����x�k������Ϥ������");
            SetResultTipsTo("�������}���ˤˤ�äƺä��Ӥ�������ޤ�");
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ˤ�һ�w�˸褤������⤦");
            SetResultTipsTo("���åץ�ˌ�������ͨ�Υ��饪���Τۤ����������⤷��ޤ���");
        }
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
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "ů�����ˤʤä��͡��⤦�䷿�ˤϺΤ�����ʤ���");
        }
        else if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�夫�������ɤ�ɤ�F��Ƥ��롢�������");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�Щ`�٥���`�Τϳ��ä��֤���͡��S���ߤˤ��Ƥ���");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "���Τ��ޤ��������͡��ɤ�ʥХ��Ǥ�����ʤ���");
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "ˮ�����Ф�Ӿ���Τ��������ϘS������");
        }
        else if (buildEvent == B_EVNT_DRKTEA ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����͡��նΤϤ���ʵꤢ��ޤ����ʤ����");
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "���g�Ϥ����ޤǤǤ��뤫����äѤ�δ�����ڴ��Ǥ���");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "���Ο�Ѫ�Ф����֤�ä��֤��");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "��������פ��Ǥ��͡����Υ���ǥ�");
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "һ�ˤǸ褦�ΤϚݘS�ʤ��Ȥ�");
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "�ۥƥ������Ť��ФϤ����͡��ѥ������ʹ���뤷");
        }
        else if (buildType == B_TYPE_MAKEBYHAND)
        {
            strcpy_s(thought, sizeof(thought),
                "������Τ�Τ˽��ξ������٤���ޤ���");
        }

        if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "���¤Εr��Ϥ⤦��`��󤤤äѤ�����");
            SetResultTipsTo("�ɤ����ץ���ީ`����ϳ��˥�`���Ǥ���");
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ������ʤ����ԥ����ä�");
            SetResultTipsTo("����ɤ��ʤ����ץ���ީ`�Ϥɤ���饿�ԥ����ä��ǤϤ���ޤ���");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ӥ���˾��ޤ�����줿ӛ�����K�ä�");
            SetResultTipsTo("ң�������Ȥ���ץ���ީ`����˾�˟o��ʸ��ޤ�����줿���Ȥ�����");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "���ä����Υ꥾�`�Ȥˤ�äȷg�䤫�ˤʤꤿ����");
            SetResultTipsTo("�󤷤����Ȥʤ��󤬡����Υץ���ީ`�ϥۥ�`���֤Ǥ�");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "���ã�����ʤ����Ԥä��餪���ޤ������");
            SetResultTipsTo("���Υץ���ީ`�Ϥ��Ĥ����Ĥʤ�Τ�׷�󤷤Ƥ��ޤ�");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ԥ�ǰ�˸褦�Τ��٤��u���������ʤ��");
            SetResultTipsTo("�ɤ���餳�Υץ���ީ`���ˤ�ǰ�˸褦�¤��Ӥ��Ǥ�");
        }
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
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "��Ȫ���ߤߤ줿�饢���ǥ����ɤ�ɤ���Ƥ����ޤ���");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "���ʥ��ݤ����������֤äƤޤ��͡��������ۤɤ�ּ��");
        }
        else if (buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "�ճ��Ф��äפ�Ǥ�������������Ф��𤳤��һ�Ĥ�");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�o�ޤ��Ӥ٤Ƥ�ܩ`���`�饤���ɫ��ʿ����Ԥ�����");
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "������Ф�������Ϥ⤦�o������");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�ˡ��Κݳ֤�����餬ȫ�Ƥ���������Τθ�Դ����");
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ˤˤ�����֪�R��U�Y�ʤɵä��ޤ���");
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "��Ȼ��Ԓ���Ϥ����Է֤�{�äǤ���褦�ˤʤä�");
        }

        if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����μ���Εr˼�����������S����˼��������ʤ���");
            SetResultTipsTo("������Ԓ�Ǥ��������`�ƥ����Ȥ�������������˱��Ϥ˥ե�줿�ߤ���");
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����褦�ΤϿ��֤Ǥ��裮����");
            SetResultTipsTo("�����΂��Ԥʤ�Ǥ����ɡ����`�ƥ����Ȥ���ϸ褦���Ȥ��Ӥߤ���");
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ󤫳������Ƥ�ݤ����룿");
            SetResultTipsTo("���`�ƥ����Ȥ���Ϥ��Ĥ�~�m��լ�ڄդ��Ƥ��뤽���Ǥ�");
        }
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
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���켡�ˤ����������Ĥ����ޤ�����");
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����͡�����äݤ��ʸФ�");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�Է֤��֤Ǥ������ΤϤ��Τ��Τ�����");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ʤ���ʤ�����Ύڤ�����������");
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "ҹ�Υש`�뤳�����ؤ���פ�������ȤϤ�");
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "���ԥ�����ζ���ˤ�Ԫ�ݤˤ������������룡");
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "��ä����һ��⤦��냇�ݤ�����");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "��äѽԤǥ��饪�����Ƥη����S������");
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "�त������äơ����������޶������Ȥ������Ȥ����");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�նΤϤ���ޤ�ۥ�`Ҋ�Ƥʤ��󤬤ʤ����r�ʸФ�");
        }
        else if (buildEvent == B_EVNT_MOVSF ||
            buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�����������Ф��ʤ��������ˤ��ä�������");
        }

        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "����󡢅g������Ȫ�äƤʤ󤫤���äȤĤޤ��");
            SetResultTipsTo("�ɤ�����ՆT������ճ����`�����Y��̽���Ƥ��ޤ�");
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "��ä��؄e�ʤ�Τ���������");
            SetResultTipsTo("�ɤ�����ՆT������ճ����`�����Y��̽���Ƥ��ޤ�");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "��������½K����߻ᤫ����");
            SetResultTipsTo("�ՆT����ˌ����ƶ���������߻�Ϥ⤦����Ǥ�");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "���˵Ĥˤϥ���ѥ��Ȥ���������");
            SetResultTipsTo("�Y����Ҋͨ���䤹���ʤ��Ȥ��ՆT����̽���Ƥ����ΤǤϤ���ޤ���");
        }
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
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "�Τμ������Ф���Ȫ�����ޤ��礦��");
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "�ɤ�ʕr�Ǥ������ש`��äƤ������");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "����ע�⤷��һ�w����ζ�����������ޤ��礦��");
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "ͬ����ζ������ĸ�����Υ���`�Ȥ��`���Lζ������");
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�������Ф���Τ�����꣡");
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ĸ����󥫥�ԥ�ߤ�����");
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "������g�Ǥ���ʤ�ä���Εr�g��һ������");
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "��̫�ɡ����Υ���餫�ä������Ǥ��礦��");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "����ӳ����פ��ͥޥ�");
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "������󡢽������Τ褦�����ɤ����g�ˤʤꤿ����");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "�����һ�w�˥��饪�����Ƥ�ʤ��ʤ��S���������");
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ĸ����󥭥��פä��य�S������");
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "�Է֤Ǥ����b������Τ⤤����");
        }

        if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "һ�����ʡ���ˮ�ש`��Ϥޤ�Σꓤ�����������");
            SetResultTipsTo("�ӹ��ˌ�������ˮ�ש`��Ϥޤ��ޤ��礤");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������`�`�ɤ��ˤ���Ω`�`�`�`");
            SetResultTipsTo("�ӹ����Է֤��ܤ�˿`�ꤿ���ʤ����ڤ����������Ӥˤʤ�����Ԥ��ǳ��˸ߤ�");
        }
        else if (buildEvent == B_EVNT_DRKBAR ||
            buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "����������δ���꤬����Ǥ��礦��");
            SetResultTipsTo("δ����ˌ����ƾƤϥ���Ǥ�");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ʤ������ʤ����ۥ�`�äƤޤ��Ф�äʤ���");
            SetResultTipsTo("�ۥ�`ӳ�����ӹ��ˌ����Ʋ��m�Фʤ�ΤǤ�");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ӥ�Ѫ�����Ƥ롣����");
            SetResultTipsTo("���������ӳ���α������ݤ��ӹ��ˌ����Ʋ��m�Фʤ�ΤǤ�");
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�虜�虜˽�����֤��Ʊ�Ҫ�ʤ������");
            SetResultTipsTo("������Щ`��һ�w�ˤ��뤳�Ȥ����ФʤΤǤ�");
        }
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
        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "��������������ů����");
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������챾������ζ����������");
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "���ε��य������쥦��");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "�c�䤫�ˤ��Ҥ�������");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�ЄӤ��줿����������");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "������פ�������");
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "���������Τ����g������������");
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "����ɭ����������������");
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ѥ����˺Τ����ä��Ϥ��뤬��������");
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���΄����⤦���ᥦ��������");
            SetResultTipsTo("����ˌ��������Ȫ�΄���������äȏ��Ҥ����ޤ�");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ҥá��Ҥɤ�����������");
            SetResultTipsTo("ͬ�������g��ʳ�٤���ͬʿ�ʤΤǡ������Ĥ�ʳ���ΤϤ���äȲп�ʤ��ȤǤ�");
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "һ���Ǥ�ʤ��ݤ����륦��������");
            SetResultTipsTo("��ˮ�ש`�뤫���ѳ��Τϥ����������Է֤����ǤǤ��뤳�ȤǤϤ���ޤ���");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "������Ѫ��Ѫ���ã�");
            SetResultTipsTo("���襤������������ˌ����ƥۥ�`�ϴ̼������ޤ�");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "���֤ʤ���褳�Υ����ף�����");
            SetResultTipsTo("���襤������������ˌ����ƥ��������ӳ���ϴ̼������ޤ�");
        }
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
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�������夬��ȫ���¤ޤä���������");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�����Ȿ����ּ��������");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�~�äƤ������ζ������Τ��ä���");
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "��ζ�������������Τ̤�̤�Τ��");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "С�������ߤ�����С������������");
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "��פ�����������äѤ���ˮ��");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "���Τʤ��ʤ��Υ���ѥ��Ȥ����륯������פ�");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����襯�������θ���äѤ��ʸФ�");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "�ϥϥϥϥϤ��쳬��פ�������");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "˽��������������͡�һ�w�˸褦�Τ�һ���S����");
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "˽�⤳��ʾ_���ʥ���������`����륯����");
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���������΄��������ˤ��ޤ�ʤ�����");
            SetResultTipsTo("����ˌ��������Ȫ�΄���������äȏ��Ҥ����ޤ�");
        }
        else if (buildEvent == B_EVNT_POLNORMAL ||
            buildEvent == B_EVNT_POLFLUSH ||
            buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "�������Υש`��С��������Ǥ��礦��");
            SetResultTipsTo("���Ĥ��������ڤ�Ӿ���Ǥ��뤯����ˌ����ƥש`��Ϥۤ�С���������ޤ�");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ƥ��١����֥���������");
            SetResultTipsTo("�⤷�߈R�κ����Ф��E�ÒB���ˤʤ���^�Ϥ����㤴����ˤʤ�ޤ�");
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�������褦�ΤϽ�һ�w�Ǥ����S�����Ǥ��礦��");
            SetResultTipsTo("��������罻���R���������ʤΤǡ���ǥ��ߥ�˥��`�������Ф���Ҫ������ޤ�");
        }
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
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "��ȫ���¤ޤä�����ҹ��ɰĮ�Ǥ�����ʤ�������");
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "���ε��य������쥯��");
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������챾������ζ����������");
        }
        else if (buildType == B_TYPE_POOL)
        {
            strcpy_s(thought, sizeof(thought),
                "ˮ���Ф�Ӿ���Τ��य�S����������");
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ͤ��Τ�������");
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "���󡢤������ε�ˤ�������һƷ����������");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�������त�褳��ӳ��");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "������פ�������");
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "����ɰĮ����������������");
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�Τʤ�����΄���");
            SetResultTipsTo("����ˌ��������Ȫ�΄���������äȏ��Ҥ����ޤ�");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ҥá��Ҥɤ�����������");
            SetResultTipsTo("ֲʳ����ˌ��������ʳ���Τϲп�ʤ��ȤǤ�");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ԥۤ���򟆤��Ƥ륯����");
            SetResultTipsTo("ֲʳ����ˌ��������ʳ���Τϲп�ʤ��ȤǤ�");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "ɰĮ�Ϥ⤦ʮ�֤��襤�Τˤ���");
            SetResultTipsTo("ҹ�ˤʤ��ɰĮ��ɫ��ʄ��郎���Ƥ��ޤ����񄤵��ˌ����Ƥ����ʮ�֥ۥ�`�Ǥ���");
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "�ܤ��褦�ΤϿ��֥���������");
            SetResultTipsTo("����ɤ��ʤ����餯������ϸ褨�ޤ���ߤ���");
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʤ󤫤���ɤ���ɰĮ�����˼������������");
            SetResultTipsTo("�ۤ�ȫ�Ƥβ������ˌ�����ɰĮ��ĺ�餷�Ĥ餤�����Ǥ���");
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
