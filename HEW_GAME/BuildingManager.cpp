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
    sprintf_s(time, sizeof(time), "%s%d", "残り時間：",
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
            sizeof((event->Buttons + 0)->Text), "    単純温泉    ");
        (event->Buttons + 1)->Event = EVNT_SKINCARESPR;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     重曹泉     ");
        (event->Buttons + 2)->Event = EVNT_WARMSPR;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "    塩化物泉    ");
        (event->Buttons + 3)->Event = EVNT_HEALTHSPR;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "     硫黄泉     ");
        break;

    case B_TYPE_FOOD:
        (event->Buttons + 0)->Event = EVNT_EATBBQ;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "  バーベキュー  ");
        (event->Buttons + 1)->Event = EVNT_EATLIGHTFOOD;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     喫茶店     ");
        (event->Buttons + 2)->Event = EVNT_EATUNAGI;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "    うなぎ屋    ");
        (event->Buttons + 3)->Event = EVNT_EATRAMEN;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "   ラーメン屋   ");
        (event->Buttons + 4)->Event = EVNT_EATCURRY;
        strcpy_s((event->Buttons + 4)->Text,
            sizeof((event->Buttons + 4)->Text), "    カレー屋    ");
        (event->Buttons + 5)->Event = EVNT_EATFRIEDNOODLE;
        strcpy_s((event->Buttons + 5)->Text,
            sizeof((event->Buttons + 5)->Text), "    焼きそば    ");
        break;

    case B_TYPE_POOL:
        (event->Buttons + 0)->Event = EVNT_POLNORMAL;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "  普通のプール  ");
        (event->Buttons + 1)->Event = EVNT_POLFLUSH;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "   流水プール   ");
        (event->Buttons + 2)->Event = EVNT_POLNIGHT;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "  ナイトプール  ");
        (event->Buttons + 3)->Event = EVNT_POLINFINITY;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), " infiniteプール ");
        break;

    case B_TYPE_DRINK:
        (event->Buttons + 0)->Event = EVNT_DRKMILKTEA;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "    タピオカ    ");
        (event->Buttons + 1)->Event = EVNT_DRKCAFE;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     カフェ     ");
        (event->Buttons + 2)->Event = EVNT_DRKTEA;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "      茶室      ");
        (event->Buttons + 3)->Event = EVNT_DRKBAR;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "      バー      ");
        (event->Buttons + 4)->Event = EVNT_DRKKARUPISU;
        strcpy_s((event->Buttons + 4)->Text,
            sizeof((event->Buttons + 4)->Text), "  カルピス放題  ");
        (event->Buttons + 5)->Event = EVNT_DRKALCOHOL;
        strcpy_s((event->Buttons + 5)->Text,
            sizeof((event->Buttons + 5)->Text), "      酒場      ");
        break;

    case B_TYPE_CINEMA:
        (event->Buttons + 0)->Event = EVNT_MOVHOR;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "     ホラー     ");
        (event->Buttons + 1)->Event = EVNT_MOVLOVE;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "    れんあい    ");
        (event->Buttons + 2)->Event = EVNT_MOVSF;
        strcpy_s((event->Buttons + 2)->Text,
            sizeof((event->Buttons + 2)->Text), "      ＳＦ      ");
        (event->Buttons + 3)->Event = EVNT_MOVACT;
        strcpy_s((event->Buttons + 3)->Text,
            sizeof((event->Buttons + 3)->Text), "   アクション   ");
        (event->Buttons + 4)->Event = EVNT_MOVCOMEDY;
        strcpy_s((event->Buttons + 4)->Text,
            sizeof((event->Buttons + 4)->Text), "    コメディ    ");
        (event->Buttons + 5)->Event = EVNT_MOVDOCUMENTARY;
        strcpy_s((event->Buttons + 5)->Text,
            sizeof((event->Buttons + 5)->Text), "      伝記      ");
        break;

    case B_TYPE_KARAOKE:
        (event->Buttons + 0)->Event = EVNT_KARASINGLE;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), " 一人でカラオケ ");
        (event->Buttons + 1)->Event = EVNT_KARAMUTLI;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "  皆でカラオケ  ");
        break;

    case B_TYPE_RESTPLACE:
        (event->Buttons + 0)->Event = EVNT_RESTCAMP;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "   キャンプ場   ");
        (event->Buttons + 1)->Event = EVNT_RESTHOTEL;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "     ホテル     ");
        break;

    case B_TYPE_MAKEBYHAND:
        (event->Buttons + 0)->Event = EVNT_RESTCAMP;
        strcpy_s((event->Buttons + 0)->Text,
            sizeof((event->Buttons + 0)->Text), "  手作りお土産  ");
        (event->Buttons + 1)->Event = EVNT_RESTHOTEL;
        strcpy_s((event->Buttons + 1)->Text,
            sizeof((event->Buttons + 1)->Text), "手作アクセサリー");
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
        (temp->Texts + 2)->ChangeTextTo("施設の種類：温泉");
        break;
    case B_TYPE_FOOD:
        (temp->Texts + 2)->ChangeTextTo("施設の種類：食事店");
        break;
    case B_TYPE_POOL:
        (temp->Texts + 2)->ChangeTextTo("施設の種類：プール");
        break;
    case B_TYPE_DRINK:
        (temp->Texts + 2)->ChangeTextTo("施設の種類：飲み物店");
        break;
    case B_TYPE_CINEMA:
        (temp->Texts + 2)->ChangeTextTo("施設の種類：映画館");
        break;
    case B_TYPE_KARAOKE:
        (temp->Texts + 2)->ChangeTextTo("施設の種類：カラオケ");
        break;
    case B_TYPE_RESTPLACE:
        (temp->Texts + 2)->ChangeTextTo("施設の種類：宿泊地");
        break;
    case B_TYPE_MAKEBYHAND:
        (temp->Texts + 2)->ChangeTextTo("施設の種類：手作り店");
        break;
    default:
        (temp->Texts + 2)->ChangeTextTo("施設の種類：");
        break;
    }
    switch (currEvent)
    {
    case B_EVNT_NORMALSPR:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：単純温泉");
        break;
    case B_EVNT_SKINCARESPR:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：重曹泉");
        break;
    case B_EVNT_WARMSPR:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：塩化物泉");
        break;
    case B_EVNT_HEALTHSPR:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：硫黄泉");
        break;
    case B_EVNT_EATBBQ:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：バーベキュー");
        break;
    case B_EVNT_EATLIGHTFOOD:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：喫茶店");
        break;
    case B_EVNT_EATUNAGI:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：うなぎ屋");
        break;
    case B_EVNT_EATRAMEN:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：ラーメン屋");
        break;
    case B_EVNT_EATCURRY:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：カレー");
        break;
    case B_EVNT_EATFRIEDNOODLE:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：焼きそば");
        break;
    case B_EVNT_POLNORMAL:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：普通のプール");
        break;
    case B_EVNT_POLFLUSH:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：流水プール");
        break;
    case B_EVNT_POLNIGHT:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：ナイトプール");
        break;
    case B_EVNT_POLINFINITY:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：インフィニティプール");
        break;
    case B_EVNT_DRKMILKTEA:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：タピオカ店");
        break;
    case B_EVNT_DRKCAFE:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：カフェ");
        break;
    case B_EVNT_DRKTEA:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：茶室");
        break;
    case B_EVNT_DRKBAR:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：バー");
        break;
    case B_EVNT_DRKKARUPISU:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：カルピス放題");
        break;
    case B_EVNT_DRKALCOHOL:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：酒場");
        break;
    case B_EVNT_MOVHOR:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：ホラー");
        break;
    case B_EVNT_MOVLOVE:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：れんあい");
        break;
    case B_EVNT_MOVSF:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：ＳＦ");
        break;
    case B_EVNT_MOVACT:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：アクション");
        break;
    case B_EVNT_MOVCOMEDY:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：コメディ");
        break;
    case B_EVNT_MOVDOCUMENTARY:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：伝記");
        break;
    case B_EVNT_KARASINGLE:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：一人でカラオケ");
        break;
    case B_EVNT_KARAMUTLI:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：皆でカラオケ");
        break;
    case B_EVNT_RESTCAMP:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：キャンプ場");
        break;
    case B_EVNT_RESTHOTEL:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：ホテル");
        break;
    case B_EVNT_MAKEPRESENT:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：手作りお土産");
        break;
    case B_EVNT_MAKEACSY:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：手作アクセサリー");
        break;
    default:
        (temp->Texts + 3)->ChangeTextTo("施設の内容：");
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
