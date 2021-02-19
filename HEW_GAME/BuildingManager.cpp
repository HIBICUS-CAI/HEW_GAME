#include "BuilderManager.h"
#include "AppDeclared.h"
#include "UIObject.h"
#include "SceneManager.h"
#include "VisitingBackgroundShower.h"

float g_TimeCountBUILDM = 0.f;

void InitBuildingManager()
{
    for (int i = 0; i < BUILDINGS_SIZE; i++)
    {
        GetEditBuildingsArray()[i].Status = BUILDING_STATUS::NOTHING;
        GetEditBuildingsArray()[i].Type = B_TYPE_NOTHING;
        GetEditBuildingsArray()[i].Event = B_EVNT_NOTHING;
    }
    g_TimeCountBUILDM = 0.f;
}

void ResetAllEventBtn()
{
    UIOBJECT* event = GetUIObjByName("build-event");
    for (int i = 0; i < 6; i++)
    {
        (event->Buttons + i)->Event = 0;
        strcpy_s((event->Buttons + i)->Text,
            sizeof((event->Buttons + i)->Text), "                ");
    }
}

void UpdateBuildingManager()
{
    g_TimeCountBUILDM += 1.3f;
    char time[64];
    sprintf_s(time, sizeof(time), "%s%d", "�c�莞�ԁF",
        60 - (int)g_TimeCountBUILDM / 60);
    (GetUIObjByName("build")->Texts)->ChangeTextTo(time);
    if (g_TimeCountBUILDM > 3600.f)
    {
        SetBuilderMovFlg(BUILDER_STOP);
        ReloadVisitingBackground();
        ResetResortBGTimerAndOffset();
        SwitchSceneToName("resort");
        GetUIObjByName("build")->ChildUIO = NULL;
        GetUIObjByName("build-type")->TurnOff();
        GetUIObjByName("build-event")->TurnOff();
    }

    ResetAllEventBtn();
    UIOBJECT* event = GetUIObjByName("build-event");
    switch ((GetEditBuildingsArray() +
        GetCurrBuildingPos() - 1)->Type)
    {
    case B_TYPE_HOTSPRING:
        (event->Buttons + 0)->Event = EVNT_NORMALSPR;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "    �P������    ");
        (event->Buttons + 1)->Event = EVNT_SKINCARESPR;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     �d����     ");
        (event->Buttons + 2)->Event = EVNT_WARMSPR;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "    ��������    ");
        (event->Buttons + 3)->Event = EVNT_HEALTHSPR;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "     ������     ");
        break;

    case B_TYPE_FOOD:
        (event->Buttons + 0)->Event = EVNT_EATBBQ;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "  �o�[�x�L���[  ");
        (event->Buttons + 1)->Event = EVNT_EATLIGHTFOOD;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     �i���X     ");
        (event->Buttons + 2)->Event = EVNT_EATUNAGI;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "    ���Ȃ���    ");
        (event->Buttons + 3)->Event = EVNT_EATRAMEN;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "   ���[������   ");
        (event->Buttons + 4)->Event = EVNT_EATCURRY;
        strcpy_s((event->Buttons + 4)->Text,
            sizeof((event->Buttons + 4)->Text), "    �J���[��    ");
        (event->Buttons + 5)->Event = EVNT_EATFRIEDNOODLE;
        strcpy_s((event->Buttons + 5)->Text,
            sizeof((event->Buttons + 5)->Text), "    �Ă�����    ");
        break;

    case B_TYPE_POOL:
        (event->Buttons + 0)->Event = EVNT_POLNORMAL;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "  ���ʂ̃v�[��  ");
        (event->Buttons + 1)->Event = EVNT_POLFLUSH;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "   �����v�[��   ");
        (event->Buttons + 2)->Event = EVNT_POLNIGHT;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "  �i�C�g�v�[��  ");
        (event->Buttons + 3)->Event = EVNT_POLINFINITY;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), " infinite�v�[�� ");
        break;

    case B_TYPE_DRINK:
        (event->Buttons + 0)->Event = EVNT_DRKMILKTEA;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "    �^�s�I�J    ");
        (event->Buttons + 1)->Event = EVNT_DRKCAFE;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     �J�t�F     ");
        (event->Buttons + 2)->Event = EVNT_DRKTEA;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "      ����      ");
        (event->Buttons + 3)->Event = EVNT_DRKBAR;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "      �o�[      ");
        (event->Buttons + 4)->Event = EVNT_DRKKARUPISU;
        strcpy_s((event->Buttons + 4)->Text,
            sizeof((event->Buttons + 4)->Text), "  �J���s�X����  ");
        (event->Buttons + 5)->Event = EVNT_DRKALCOHOL;
        strcpy_s((event->Buttons + 5)->Text,
            sizeof((event->Buttons + 5)->Text), "      ����      ");
        break;

    case B_TYPE_CINEMA:
        (event->Buttons + 0)->Event = EVNT_MOVHOR;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "     �z���[     ");
        (event->Buttons + 1)->Event = EVNT_MOVLOVE;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "    ��񂠂�    ");
        (event->Buttons + 2)->Event = EVNT_MOVSF;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "      �r�e      ");
        (event->Buttons + 3)->Event = EVNT_MOVACT;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "   �A�N�V����   ");
        (event->Buttons + 4)->Event = EVNT_MOVCOMEDY;
        strcpy_s((event->Buttons + 4)->Text,
            sizeof((event->Buttons + 4)->Text), "    �R���f�B    ");
        (event->Buttons + 5)->Event = EVNT_MOVDOCUMENTARY;
        strcpy_s((event->Buttons + 5)->Text,
            sizeof((event->Buttons + 5)->Text), "      �`�L      ");
        break;

    case B_TYPE_KARAOKE:
        (event->Buttons + 0)->Event = EVNT_KARASINGLE;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), " ��l�ŃJ���I�P ");
        (event->Buttons + 1)->Event = EVNT_KARAMUTLI;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "  �F�ŃJ���I�P  ");
        break;

    case B_TYPE_RESTPLACE:
        (event->Buttons + 0)->Event = EVNT_RESTCAMP;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "   �L�����v��   ");
        (event->Buttons + 1)->Event = EVNT_RESTHOTEL;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     �z�e��     ");
        break;

    case B_TYPE_MAKEBYHAND:
        (event->Buttons + 0)->Event = EVNT_RESTCAMP;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "  ���肨�y�Y  ");
        (event->Buttons + 1)->Event = EVNT_RESTHOTEL;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "���A�N�Z�T���[");
        break;

    default:
        break;
    }

    int currType = (GetEditBuildingsArray() +
        GetCurrBuildingPos() - 1)->Type;
    int currEvent = (GetEditBuildingsArray() +
        GetCurrBuildingPos() - 1)->Event;

    UIOBJECT* temp = GetUIObjByName("build");
    switch (currType)
    {
    case B_TYPE_HOTSPRING:
        (temp->Texts + 2)->ChangeTextTo("�{�݂̎�ށF����");
        break;
    case B_TYPE_FOOD:
        (temp->Texts + 2)->ChangeTextTo("�{�݂̎�ށF�H���X");
        break;
    case B_TYPE_POOL:
        (temp->Texts + 2)->ChangeTextTo("�{�݂̎�ށF�v�[��");
        break;
    case B_TYPE_DRINK:
        (temp->Texts + 2)->ChangeTextTo("�{�݂̎�ށF���ݕ��X");
        break;
    case B_TYPE_CINEMA:
        (temp->Texts + 2)->ChangeTextTo("�{�݂̎�ށF�f���");
        break;
    case B_TYPE_KARAOKE:
        (temp->Texts + 2)->ChangeTextTo("�{�݂̎�ށF�J���I�P");
        break;
    case B_TYPE_RESTPLACE:
        (temp->Texts + 2)->ChangeTextTo("�{�݂̎�ށF�h���n");
        break;
    case B_TYPE_MAKEBYHAND:
        (temp->Texts + 2)->ChangeTextTo("�{�݂̎�ށF����X");
        break;
    default:
        (temp->Texts + 2)->ChangeTextTo("�{�݂̎�ށF");
        break;
    }
    switch (currEvent)
    {
    case B_EVNT_NORMALSPR:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�P������");
        break;
    case B_EVNT_SKINCARESPR:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�d����");
        break;
    case B_EVNT_WARMSPR:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F��������");
        break;
    case B_EVNT_HEALTHSPR:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F������");
        break;
    case B_EVNT_EATBBQ:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�o�[�x�L���[");
        break;
    case B_EVNT_EATLIGHTFOOD:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�i���X");
        break;
    case B_EVNT_EATUNAGI:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F���Ȃ���");
        break;
    case B_EVNT_EATRAMEN:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F���[������");
        break;
    case B_EVNT_EATCURRY:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�J���[");
        break;
    case B_EVNT_EATFRIEDNOODLE:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�Ă�����");
        break;
    case B_EVNT_POLNORMAL:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F���ʂ̃v�[��");
        break;
    case B_EVNT_POLFLUSH:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�����v�[��");
        break;
    case B_EVNT_POLNIGHT:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�i�C�g�v�[��");
        break;
    case B_EVNT_POLINFINITY:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�C���t�B�j�e�B�v�[��");
        break;
    case B_EVNT_DRKMILKTEA:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�^�s�I�J�X");
        break;
    case B_EVNT_DRKCAFE:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�J�t�F");
        break;
    case B_EVNT_DRKTEA:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F����");
        break;
    case B_EVNT_DRKBAR:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�o�[");
        break;
    case B_EVNT_DRKKARUPISU:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�J���s�X����");
        break;
    case B_EVNT_DRKALCOHOL:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F����");
        break;
    case B_EVNT_MOVHOR:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�z���[");
        break;
    case B_EVNT_MOVLOVE:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F��񂠂�");
        break;
    case B_EVNT_MOVSF:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�r�e");
        break;
    case B_EVNT_MOVACT:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�A�N�V����");
        break;
    case B_EVNT_MOVCOMEDY:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�R���f�B");
        break;
    case B_EVNT_MOVDOCUMENTARY:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�`�L");
        break;
    case B_EVNT_KARASINGLE:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F��l�ŃJ���I�P");
        break;
    case B_EVNT_KARAMUTLI:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�F�ŃJ���I�P");
        break;
    case B_EVNT_RESTCAMP:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�L�����v��");
        break;
    case B_EVNT_RESTHOTEL:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F�z�e��");
        break;
    case B_EVNT_MAKEPRESENT:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F���肨�y�Y");
        break;
    case B_EVNT_MAKEACSY:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F���A�N�Z�T���[");
        break;
    default:
        (temp->Texts + 3)->ChangeTextTo("�{�݂̓��e�F");
        break;
    }
}

void TurnOffBuildingManager()
{

}

void  ResetBuildingManager()
{
    InitBuildingManager();
}
