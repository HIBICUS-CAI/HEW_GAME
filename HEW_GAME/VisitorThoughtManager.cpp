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
            strcpy_s(thought, sizeof(thought), "�C�R�[�����đf�G�Ȍ��t������");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "���o���A�Ȃ񂩌����X���˂�����");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "�����ˁA�A���^�s�I�J���݂����ɂȂ�");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�ӂ�ӂ�Ȋ���������������");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 3)
        {
            strcpy_s(thought, sizeof(thought), "���یド�[�����݂����ȉ������");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "���̖��O��l���ۂ��ł���");
            VisitorFeelGood(visitorType);
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�[�����ĂȂ񂩕s��������");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "�ꎞ�I���Ăǂ��������Ƃł���");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���H������ƒn���Ȋ����D�D�D�H");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "���̖��O�����̏ꏊ�Ɍ������Ƃ�����D�D�D");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�o�[�x�L���[���A�����̎�ł��т����̂͊y������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "�������̈��|�I�ȃ��[�������I�������̈��|�I�ȃ��[�������I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "������߂�����ʔ����I���ʂ̃v�[�����y�����I");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�^�s�I�J��������ȍK�����o���オ����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����f��͂����O���ɂȂ�Ȃ���");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "����Ȃ����������Z�p�����ɂ������ق����ł���");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�������̃J�b�R�ǂ��f���炵���I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "����ς�ꏏ�ɉ̂��̂͊y�����I���̋Ȃ��肢�`");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "�e���g�o���オ��̒B����������");
            VisitorFeelGood(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���̓�����΂��Ȃ��H");
            SetResultTipsTo("������̓����͎Ⴂ�l�ɑ΂��Ă�����Ƌ��󂷂��邩������܂���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ȃ񂩕��i�ٓ̕����v���o�����D�D�D������������");
            SetResultTipsTo("�w���ɑ΂��ăJ���[�͓��킷���邩������܂���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "���H�q�����ۂ��������H");
            SetResultTipsTo("���̎����̎Ⴂ�l�͎q�����ۂ����̂��D���ł͂���܂���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�z���[������Ƌ���܂���");
            SetResultTipsTo("�[�����R���Ȃ����A�Ƃ��鐶�k�̓z���[�f��ɂ��������Ȃ̂�");
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
            strcpy_s(thought, sizeof(thought), "���̖��O���Ď������̂��Ƃ��v���o�����");
            VisitorFeelVeryGood(visitorType);
        }
        else if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "���邢�ˁA�����̂��Ƃ��A�������̖��������Ċ����H");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 3)
        {
            strcpy_s(thought, sizeof(thought), "�������Ă�΂��Ȃ��H���N���N�ɂȂ邗");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "�����A���傤�ǃ^�s�I�J���݂���");
            VisitorFeelVeryGood(visitorType);
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�ӂ�ӂ�Ȋ������D���I");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 5)
        {
            strcpy_s(thought, sizeof(thought), "�i���X�ˁA�̂�т�̎��Ԃ��~������");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 6 || subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�_�C�A�����h�̂悤�ȉi���Ȋ���");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "���񂽂����g���Ă�[�����R�Ƃ҂�����ł����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "�ꎞ�I���Ă��������킯�Ȃ�����I");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 9 || subName2 == 0)
        {
            strcpy_s(thought, sizeof(thought), "�Ȃ񂩎������̂��Ƃ��Î�����C�H");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "�������i�͎d�������ς�����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�ˋ�̂��̂͂�����ƍD���ɂȂ�Ȃ���");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���̉��򔧂ɗD�����ƕ����܂�����");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�������̒g�����A�C�����������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "���ʂ̃f�[�g���������ł����");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ȃ񂩍Ղ�Ɋy����ł���݂����I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������I���̖����ȍL����΂��Ȃ��H");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNORMAL)
        {
            strcpy_s(thought, sizeof(thought),
                "���ʂ̃f�[�g���������ł����");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "���̍K���̊Â��ł߂����Ⴂ���I�S�ɂ��݂���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "���ʂ̃f�[�g���������ł����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "�������̈�i���������H");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ȃ񂩂����ȈӖ��Ń��N���N�����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����˂��̕���A��l���ꏏ�ɂ����Ă���Ă悩����");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "����{���ɂ������낢�ł����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "�ꏏ�ɋL�O�̃A�N�Z�T���[�����܂��傤�I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "�F�����̂��ׂɓ��ʂȂ��y�Y�����܂��傤�I");
            VisitorFeelGood(visitorType);
        }

        if (buildEvent == B_EVNT_EATBBQ ||
            buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������D�D�D������ƂˁD�D�D");
            SetResultTipsTo("��������������Ƃ���Ƀf�[�g���Ȃ��łق��������ł���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "�����Ƃ������ȓX��������");
            SetResultTipsTo("����̂͏��X���������ꏊ�Ȃ̂�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "�����H�����̃J���s�X�������");
            SetResultTipsTo("�J���s�X�̓J�b�v���ɂ͂�����Ɣ�������");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "�����Ƃ����I��������͂������");
            SetResultTipsTo("���̎��͐l�ɂ���čD������������܂�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "���H��l�ňꏏ�ɉ̂����������");
            SetResultTipsTo("�J�b�v���ɑ΂��ĕ��ʂ̃J���I�P�̂ق���������������܂���");
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
            strcpy_s(thought, sizeof(thought), "��������UI�Ɍ���Ƃ���ǂ���A���邢����������");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "�C�R�[�����Ă��΂炵����A�o�O�̌��o���y����");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�ˋ�̑z���͎͂������ɕK�v����");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 8)
        {
            strcpy_s(thought, sizeof(thought), "�����ŃO���[�o���̂��́H���������ǂ����g���邗");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 2 || subName2 == 6 || subName2 == 7 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�����悱�̖��O�A�����̃o�O���������ꂽ�C������");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "�[���Ƃ���ɉB���Ă�o�O����������");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 9 || subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�����A���̂��Ƃł����H");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "���������d�����瓦�ꂽ�̂ɂ�");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�g�����ɂȂ����ˁA������[�ɂ͉����|���Ȃ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�̂���͂��ǂ�ǂ񌻂�Ă���A�������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�o�[�x�L���[�̂͒��v���Ԃ肾�ˁA�y���݂ɂ��Ă���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "���̂��܂��������ˁA�ǂ�ȃo�O�ł��|���Ȃ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "�����̒��ɉj���̂͗\�z�ȏ�y������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKTEA ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ˁA���i�͂���ȓX����܂藈�Ȃ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "�Z�p�͂����܂łł��邩�A����ς薢���͊��҂ł���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "���̔M���������Ԃ�v���Ԃ肾");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ʔ����ł��ˁA���̃R���f�B");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "��l�ŉ̂��̂͋C�y�Ȃ��Ƃ�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "�z�e���̗����������͂����ˁA�p�\�R�����g���邵");
            VisitorFeelAlright(visitorType);
        }
        else if (buildType == B_TYPE_MAKEBYHAND)
        {
            strcpy_s(thought, sizeof(thought),
                "����̂��̂ɏ��̐��_����������܂���");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "�d���̎����т͂������[���������ς�����");
            SetResultTipsTo("�ǂ����v���O���}�[�̒��т͏�Ƀ��[�����ł���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�Â������Ȃ��^�s�I�J����");
            SetResultTipsTo("�[�����R���Ȃ����v���O���}�[�͂ǂ����^�s�I�J�D���ł͂���܂���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "������i�Ɉ��܂�����ꂽ�L�����h����");
            SetResultTipsTo("�y���́A�Ƃ���v���O���}�[�͏�i�ɖ�������܂�����ꂽ���Ƃ�����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "���������̃��]�[�g�ɂ����Ɖ��₩�ɂȂ肽����");
            SetResultTipsTo("�債�����ƂȂ��񂪁A���̃v���O���}�[�̓z���[���ł�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����H����Ȃ��ƌ������炨���܂������H");
            SetResultTipsTo("���̃v���O���}�[�͂��������I�Ȃ��̂�ǋ����Ă��܂�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "�F�̑O�ɉ̂��̂͏����p���������Ȃ��");
            SetResultTipsTo("�ǂ���炱�̃v���O���}�[�͐l�̑O�ɉ̂����������ł�");
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
            strcpy_s(thought, sizeof(thought), "���邢���āA���̃��]�[�g�ɂ����F����܂�����");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "���l�ȑ�햡������̂Ő[���ł��傤");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�ˋ�̂��̂��������ȉ\���𐶂ݏo�����");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 2 || subName2 == 6 ||
            subName2 == 7 || subName2 == 10 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "�������z�𐶂ݏo���邻�����O�ł�");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "�ꎞ�I�̂��̂����炱�����ʂȔ���������܂���");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�������A�����Ŏ��̃p���_�C�X�ł���I");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "���������錾�t������𐶂ݏo���̂͑��������");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "�T�����[�}�����āD�D�D������Ƃ���ł����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 1 || subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "�������Ȃ��ˁA�C���p�N�g�����X����܂���");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "����ɟ��݂ꂽ��A�C�f�A���ǂ�ǂ�o�Ă����܂���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�E�i�M���͗ǂ��Z�������Ă܂��ˁA�������قǂ̎|��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "���튴�����Ղ�ł����A����������̋N����̈��");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ɉ��ׂĂ�{�[�_�[���C���ɐF��ȉ\��������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "���̍��΂��������͂������G����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�l�X�̋C�����⊴��S�Ă̔��������̂̍�������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "�̂̐l�ɂ����Ȓm����o���ȂǓ����܂���");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "���R�Ƙb�������Ǝ�����[���ł���悤�ɂȂ���");
            VisitorFeelGood(visitorType);
        }

        if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "���̂̍Ղ�̎��v���o�����A�y�����v���o����Ȃ���");
            SetResultTipsTo("�����̘b�ł����A�A�[�e�B�X�g����͐̂���Ղ�ɔގ��Ƀt���ꂽ�݂���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����̂��̂͋��ł���D�D�D");
            SetResultTipsTo("�L�����̌��Ȃ�ł����ǁA�A�[�e�B�X�g����͉̂����Ƃ����݂���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ȃ񂩏o�����Ă�C������H");
            SetResultTipsTo("�A�[�e�B�X�g����͂�����^�ݑ�Ζ����Ă��邻���ł�");
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
            strcpy_s(thought, sizeof(thought), "���������Ă����ł��ˁA���������ő��ꂵ����");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "��C�ǂނ͖̂O�����A���������ǂ܂Ȃ��l�ɂȂ肽��");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "���̂ӂ�ӂ튴�������Ԃ�ˁA����͂����d����");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 1 || subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "������ˁA���̗��������̊���");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "�������邷���ꏊ�ɓ����Ă�̂ł�����ƖO������");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "�Î_���ς����ĉ��ł�����ƃC���C���C������H");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 13 || subName2 == 4)
        {
            strcpy_s(thought, sizeof(thought), "���Ȃ񂾂��̐��ӋC��");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "���������ȏ�d���̓��e�͍l�������Ȃ���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "������Ɨ��������Ȃ��˂��̖��O");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���ꔧ�ɂ��������ʓI�ƕ����܂����I");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ˁA�Ղ���ۂ��Ȋ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�����̎�ł��т����̂͂��̂��̂����`");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�����`�Ȃ񂾂Ȃ񂾂��̍L���A�������I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "��̃v�[�������Ɠ��Ȗʔ���������Ƃ͂�");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�^�s�I�J�̖��ɐl�����C�ɂ�����͂�����I");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ƈ�t�������H���͋C������");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "����ϊF�ŃJ���I�P���Ă̕����y������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "�����A������āu�������`����`�v�Ƃ������Ƃ����");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "���i�͂���܂�z���[���ĂȂ��񂪂Ȃ񂩐V�N�Ȋ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF ||
            buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�����`�����΂��Ȃ��H�{���ɂ����������I");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����A�P���ȉ�����ĂȂ񂩂�����Ƃ܂��");
            SetResultTipsTo("�ǂ���玖��������͓���ƈႤ�̌���T���Ă��܂�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����Ɠ��ʂȂ��̂��~������");
            SetResultTipsTo("�ǂ���玖��������͓���ƈႤ�̌���T���Ă��܂�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "����͎d���I���̈��݉���I");
            SetResultTipsTo("����������ɑ΂��đ����d����̈��݉�͂����O�����ł�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�l�I�ɂ̓C���p�N�g���~������");
            SetResultTipsTo("���ʂ����ʂ��₷���Ȃ��Ƃ͎��������񂪒T���Ă�����̂ł͂���܂���");
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
            strcpy_s(thought, sizeof(thought), "�ق�A���������Ȃ��߂ł���`");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "���̑O���ɍs�����p���_���񂩂킢���ł���");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "�̂̂��Ƃ��v���o�����˃p�p");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�����b�ɂ���Ȋ����ł��ˁ`");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "���O�����ł��Y��Ƃ���Œf���ł��܂���");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "���H����͏������q�Ɍ������Ȃ����̂ł��傤�H");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 4 || subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "�q���ɂ͂킩�肸�炢�ł��傤");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "�Ȃ񂩕ςȏꏊ���v�������D�D�D");
            VisitorFeelVeryBad(visitorType);
        }
    }
    else
    {
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "���̉Ƒ����s�����򂢂��܂��傤��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "�ǂ�Ȏ��ł������v�[�����Ă������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ώ����ӂ��Ĉꏏ�ɔ����������э��܂��傤�I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "���������������ꂿ���̃J���[�Ƃ͈Ⴄ����������");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ă����΂���̂�������I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ꂿ���J���s�X���݂����I");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ƒ��̊Ԃł���Ȃ������̎��Ԃ���Ԃ���");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "�ˑ��Y�A���̃L���������������ł��傤�H");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "���̉f��ʔ����˃}�}");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ԃ����A�������̂悤�ȗ��h�Ȑl�ԂɂȂ肽���I");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ƒ��ňꏏ�ɃJ���I�P���Ă��Ȃ��Ȃ��y���������");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ꂿ���L�����v���Đ����y�����I");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "�����ł��y�Y�����̂�������");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "��Y����ȁA�����v�[���͂܂��댯������񂾂낤�H");
            SetResultTipsTo("�q���ɑ΂��ė����v�[���͂܂��܂�����");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ԃ����[�[�ǂ��ɂ���́[�[�[�[");
            SetResultTipsTo("�q���������̎���ɔ��肽���Ȃ����L���ꏊ�ɖ��q�ɂȂ�\�������ɍ���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR ||
            buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "���������A�����N������ł��傤�H");
            SetResultTipsTo("�����N�ɑ΂��Ď��̓_���ł�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�|���Ȃ��|���Ȃ��B�z���[���Ă܂��L�蓾�Ȃ���");
            SetResultTipsTo("�z���[�f��͎q���ɑ΂��ĕs�K�؂Ȃ��̂ł�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "���������o�Ă�B�B�B");
            SetResultTipsTo("�A�N�V�����f��̖\�͓��e�͎q���ɑ΂��ĕs�K�؂Ȃ��̂ł�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�킴�킴�����������ĕK�v�Ȃ������");
            SetResultTipsTo("�Ƒ������o�[�Ɉꏏ�ɂ��邱�Ƃ���؂Ȃ̂ł�");
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
            strcpy_s(thought, sizeof(thought), "�Ȃ񂩐l�Ԃ��ۂ������N���N����E�M�I");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�C�͒��������̃E�M�I�o�c�҂Ɋ��Ӑ\���グ�E�M�I");
            VisitorFeelGood(visitorType);
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "��l�ԓ������m�Ƃ��Ă�����ƌ����E�M�D�D�D");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 13)
        {
            strcpy_s(thought, sizeof(thought), "�����Ċ낤���Ƃ��낶��Ȃ��E�M�H");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "���Ȃ��Ƃ��v���o�����E�M�D�D�D");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 2 || subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "�R�Ƃ��X�Ƃ��������O�����E�M�I");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����E�M�A���̒g����");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "���A����{���ɔ��������E�M�I");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "���̓X�����������E�M");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "���₩�ɂ��������E�M");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "�������ꂽ�E�M�D�D�D");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "����ʔ����E�M�I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "���������̂��l�Ԃ��E�M�D�D�D");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "���`�X���ǂ����邾�E�M");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "�F�����ɉ�������ďグ�邪�����E�M");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���̓��������_���E�M�D�D�D");
            SetResultTipsTo("�����ɑ΂��ė�����̓�����������Ƌ��󂷂��܂�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ђ��A�Ђǂ��E�M�D�D�D");
            SetResultTipsTo("�������l�ԂɐH�ׂ��铯�m�Ȃ̂ŁA������H���̂͂�����Ǝc���Ȃ��Ƃł�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "�ꐶ�o��Ȃ��C������E�M�D�D�D");
            SetResultTipsTo("�����v�[������E�o�̂̓E�T�M���񎩕��̗͂łł��邱�Ƃł͂���܂���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����������������I");
            SetResultTipsTo("���킢������������ɑ΂��ăz���[�͎h�������܂�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "���Ȃ񂾂悱�̃^�C�v�D�D�D");
            SetResultTipsTo("���킢������������ɑ΂��ăA�N�V�����f��͎h�������܂�");
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
            strcpy_s(thought, sizeof(thought), "�Ȃ񂩐l�Ԃ��ۂ������N���N����N�W�I");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 2)
        {
            strcpy_s(thought, sizeof(thought), "�X�͒��������̃N�W�I�o�c�҂Ɋ��Ӑ\���グ�N�W�I");
            VisitorFeelVeryGood(visitorType);
        }
        else if (subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "�R�͒��������̃N�W�I�o�c�҂Ɋ��Ӑ\���グ�N�W�I");
            VisitorFeelVeryGood(visitorType);
        }

        if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "���Ȃ��Ƃ��v���o�����N�W�D�D�D");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�C�͂������O�����N�W�I");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����A�̂����S�ɉ��܂������N�W�I");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "���̓��{���Ɏ|���N�W�I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�����Ă���Ȕ����������̂������H");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "���������N�W�A���̂ʂ�ʂ�̂߂�");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "�������C�݂����I�������N�W����");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "�ʔ����N�W���̎_���ς��Ȑ��I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "���̂Ȃ��Ȃ��̃C���p�N�g������N�W�A�ʔ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "������N�W�A���̊Î_���ς��Ȋ���");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "�n�n�n�n�n���꒴�ʔ����N�W�I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "�����������炾����ˁA�ꏏ�ɉ̂��͈̂�Ԋy�N�W");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "����������Y��ȃA�N�Z�T���[����N�W�H");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����A���̓����{���ɂ��܂�Ȃ��N�W");
            SetResultTipsTo("�����ɑ΂��ė�����̓�����������Ƌ��󂷂��܂�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNORMAL ||
            buildEvent == B_EVNT_POLFLUSH ||
            buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "���H���̃v�[������������ł��傤�H");
            SetResultTipsTo("�������R���݂ɉj���ł��邭����ɑ΂��ăv�[���͂قڏ����������܂�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "���͏��X���N�W�D�D�D");
            SetResultTipsTo("���������̊C�̒��ɐ��������ɂȂ�Ɠ��͂����Ⴒ����ɂȂ�܂�");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "�����H�̂��̂͊F�ꏏ�ł����y�����ł��傤�H");
            SetResultTipsTo("������͎Ќ��ӎ������铮���Ȃ̂ŁA�̂ŃR�~���j�P�[�V�������s���K�v������܂�");
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
            strcpy_s(thought, sizeof(thought), "�Ȃ񂩐l�Ԃ��ۂ������N���N����N�_�I");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "�C�͒��������̃N�_�I�o�c�҂Ɋ��Ӑ\���グ�N�_�I");
            VisitorFeelVeryGood(visitorType);
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "��l�ԓ������m�Ƃ��Ă�����ƌ����N�_�D�D�D");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "���Ȃ��Ƃ��v���o�����N�_�D�D�D");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���S�ɉ��܂������A��̍����ł��|���Ȃ��N�_�I");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "���̓X�����������N�_");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "���A����{���ɔ��������N�_�I");
            VisitorFeelGood(visitorType);
        }
        else if (buildType == B_TYPE_POOL)
        {
            strcpy_s(thought, sizeof(thought),
                "���̒��ɉj���̂͐����y�����N�_�I");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "�����˂��̂����̍���");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "����A�������̓X�ɂ������̈�i�A�����N�_");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "�����A�����悱�̉f��");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "����ʔ����N�_�I");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "���`�������ǂ����邾�N�_");
            VisitorFeelVeryGood(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "���Ȃ񂾂��̓���");
            SetResultTipsTo("�����ɑ΂��ė�����̓�����������Ƌ��󂷂��܂�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ђ��A�Ђǂ��N�_�D�D�D");
            SetResultTipsTo("�A�H�����ɑ΂��ē���H���͎̂c���Ȃ��Ƃł�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "�F�قړ����Ă��Ă�N�_�H");
            SetResultTipsTo("�A�H�����ɑ΂��ē���H���͎̂c���Ȃ��Ƃł�");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "�����͂����\�����킢�̂ɂ��I");
            SetResultTipsTo("��ɂȂ�ƍ����ɐF��ȓ������o�Ă��܂��A�p�k����ɑ΂��Ă���͏\���z���[�ł���");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "�ڂ��̂��̂͋��N�_�D�D�D");
            SetResultTipsTo("�[�����R���Ȃ����炭������͉̂��܂���݂���");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "�Ȃ񂩂���ǂ��̍����������v���o�����N�_");
            SetResultTipsTo("�قڑS�Ă̚M�������ɑ΂��č����͕�炵�炢�ꏊ�ł���");
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
