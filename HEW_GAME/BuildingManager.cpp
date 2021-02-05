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
    sprintf_s(time, sizeof(time), "%s%d", "�Ф�r�g��",
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
            sizeof((event->Buttons + 0)->Text), "    �g����Ȫ    ");
        (event->Buttons + 1)->Event = EVNT_SKINCARESPR;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     �ز�Ȫ     ");
        (event->Buttons + 2)->Event = EVNT_WARMSPR;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "    �c����Ȫ    ");
        (event->Buttons + 3)->Event = EVNT_HEALTHSPR;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "     ���Ȫ     ");
        break;

    case B_TYPE_FOOD:
        (event->Buttons + 0)->Event = EVNT_EATBBQ;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "  �Щ`�٥���`  ");
        (event->Buttons + 1)->Event = EVNT_EATLIGHTFOOD;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     �˲��     ");
        (event->Buttons + 2)->Event = EVNT_EATUNAGI;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "    ���ʤ���    ");
        (event->Buttons + 3)->Event = EVNT_EATRAMEN;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "   ��`�����   ");
        (event->Buttons + 4)->Event = EVNT_EATCURRY;
        strcpy_s((event->Buttons + 4)->Text,
            sizeof((event->Buttons + 4)->Text), "    ����`��    ");
        (event->Buttons + 5)->Event = EVNT_EATFRIEDNOODLE;
        strcpy_s((event->Buttons + 5)->Text,
            sizeof((event->Buttons + 5)->Text), "    ��������    ");
        break;

    case B_TYPE_POOL:
        (event->Buttons + 0)->Event = EVNT_POLNORMAL;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "  ��ͨ�Υש`��  ");
        (event->Buttons + 1)->Event = EVNT_POLFLUSH;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "   ��ˮ�ש`��   ");
        (event->Buttons + 2)->Event = EVNT_POLNIGHT;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "  �ʥ��ȥש`��  ");
        (event->Buttons + 3)->Event = EVNT_POLINFINITY;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), " infinite�ש`�� ");
        break;

    case B_TYPE_DRINK:
        (event->Buttons + 0)->Event = EVNT_DRKMILKTEA;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "    ���ԥ���    ");
        (event->Buttons + 1)->Event = EVNT_DRKCAFE;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     ���ե�     ");
        (event->Buttons + 2)->Event = EVNT_DRKTEA;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "      ����      ");
        (event->Buttons + 3)->Event = EVNT_DRKBAR;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "      �Щ`      ");
        (event->Buttons + 4)->Event = EVNT_DRKKARUPISU;
        strcpy_s((event->Buttons + 4)->Text,
            sizeof((event->Buttons + 4)->Text), "  ����ԥ����}  ");
        (event->Buttons + 5)->Event = EVNT_DRKALCOHOL;
        strcpy_s((event->Buttons + 5)->Text,
            sizeof((event->Buttons + 5)->Text), "      �ƈ�      ");
        break;

    case B_TYPE_CINEMA:
        (event->Buttons + 0)->Event = EVNT_MOVHOR;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "     �ۥ�`     ");
        (event->Buttons + 1)->Event = EVNT_MOVLOVE;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "    ��󤢤�    ");
        (event->Buttons + 2)->Event = EVNT_MOVSF;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "      �ӣ�      ");
        (event->Buttons + 3)->Event = EVNT_MOVACT;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "   ���������   ");
        (event->Buttons + 4)->Event = EVNT_MOVCOMEDY;
        strcpy_s((event->Buttons + 4)->Text,
            sizeof((event->Buttons + 4)->Text), "    ����ǥ�    ");
        (event->Buttons + 5)->Event = EVNT_MOVDOCUMENTARY;
        strcpy_s((event->Buttons + 5)->Text,
            sizeof((event->Buttons + 5)->Text), "      ��ӛ      ");
        break;

    case B_TYPE_KARAOKE:
        (event->Buttons + 0)->Event = EVNT_KARASINGLE;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), " һ�ˤǥ��饪�� ");
        (event->Buttons + 1)->Event = EVNT_KARAMUTLI;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "  �Ԥǥ��饪��  ");
        break;

    case B_TYPE_RESTPLACE:
        (event->Buttons + 0)->Event = EVNT_RESTCAMP;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "   �����׈�   ");
        (event->Buttons + 1)->Event = EVNT_RESTHOTEL;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     �ۥƥ�     ");
        break;

    case B_TYPE_MAKEBYHAND:
        (event->Buttons + 0)->Event = EVNT_RESTCAMP;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "  �����ꤪ���b  ");
        (event->Buttons + 1)->Event = EVNT_RESTHOTEL;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "��������������`");
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
        (temp->Texts + 2)->ChangeTextTo("ʩ�O�ηN���Ȫ");
        break;
    case B_TYPE_FOOD:
        (temp->Texts + 2)->ChangeTextTo("ʩ�O�ηN�ʳ�µ�");
        break;
    case B_TYPE_POOL:
        (temp->Texts + 2)->ChangeTextTo("ʩ�O�ηN��ש`��");
        break;
    case B_TYPE_DRINK:
        (temp->Texts + 2)->ChangeTextTo("ʩ�O�ηN�����");
        break;
    case B_TYPE_CINEMA:
        (temp->Texts + 2)->ChangeTextTo("ʩ�O�ηN�ӳ���^");
        break;
    case B_TYPE_KARAOKE:
        (temp->Texts + 2)->ChangeTextTo("ʩ�O�ηN����饪��");
        break;
    case B_TYPE_RESTPLACE:
        (temp->Texts + 2)->ChangeTextTo("ʩ�O�ηN��޲���");
        break;
    case B_TYPE_MAKEBYHAND:
        (temp->Texts + 2)->ChangeTextTo("ʩ�O�ηN��������");
        break;
    default:
        (temp->Texts + 2)->ChangeTextTo("ʩ�O�ηN�");
        break;
    }
    switch (currEvent)
    {
    case B_EVNT_NORMALSPR:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��g����Ȫ");
        break;
    case B_EVNT_SKINCARESPR:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��ز�Ȫ");
        break;
    case B_EVNT_WARMSPR:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��c����Ȫ");
        break;
    case B_EVNT_HEALTHSPR:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ����Ȫ");
        break;
    case B_EVNT_EATBBQ:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��Щ`�٥���`");
        break;
    case B_EVNT_EATLIGHTFOOD:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��˲��");
        break;
    case B_EVNT_EATUNAGI:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ����ʤ���");
        break;
    case B_EVNT_EATRAMEN:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ���`�����");
        break;
    case B_EVNT_EATCURRY:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ�����`");
        break;
    case B_EVNT_EATFRIEDNOODLE:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ���������");
        break;
    case B_EVNT_POLNORMAL:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ���ͨ�Υש`��");
        break;
    case B_EVNT_POLFLUSH:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ���ˮ�ש`��");
        break;
    case B_EVNT_POLNIGHT:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��ʥ��ȥש`��");
        break;
    case B_EVNT_POLINFINITY:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ�����ե��˥ƥ��ש`��");
        break;
    case B_EVNT_DRKMILKTEA:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ����ԥ�����");
        break;
    case B_EVNT_DRKCAFE:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ����ե�");
        break;
    case B_EVNT_DRKTEA:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ�����");
        break;
    case B_EVNT_DRKBAR:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��Щ`");
        break;
    case B_EVNT_DRKKARUPISU:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ�����ԥ����}");
        break;
    case B_EVNT_DRKALCOHOL:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��ƈ�");
        break;
    case B_EVNT_MOVHOR:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��ۥ�`");
        break;
    case B_EVNT_MOVLOVE:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ���󤢤�");
        break;
    case B_EVNT_MOVSF:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��ӣ�");
        break;
    case B_EVNT_MOVACT:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ����������");
        break;
    case B_EVNT_MOVCOMEDY:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ�����ǥ�");
        break;
    case B_EVNT_MOVDOCUMENTARY:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ���ӛ");
        break;
    case B_EVNT_KARASINGLE:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ�һ�ˤǥ��饪��");
        break;
    case B_EVNT_KARAMUTLI:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��Ԥǥ��饪��");
        break;
    case B_EVNT_RESTCAMP:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ������׈�");
        break;
    case B_EVNT_RESTHOTEL:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ��ۥƥ�");
        break;
    case B_EVNT_MAKEPRESENT:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ������ꤪ���b");
        break;
    case B_EVNT_MAKEACSY:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ���������������`");
        break;
    default:
        (temp->Texts + 3)->ChangeTextTo("ʩ�O�����ݣ�");
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
