#include "AppBtnEvent.h"
#include "GameAppStructs.h"
#include "AppDeclared.h"
#include "UIObject.h"
#include "DeclaredValues.h"
#include "SceneManager.h"
#include "DialogShower.h"
#include "PlayingStageManager.h"
#include "VisitorManager.h"
#include "VisitorShower.h"
#include "SceneNode.h"
#include "ResortNameManager.h"
#include "BuilderManager.h"
#include "BuildBackgroundShower.h"
#include "BuildingManager.h"
#include "BuildingShower.h"
#include "VisitingBackgroundShower.h"
#include "VisitingVisitorShower.h"
#include "VisitingBuildShower.h"
#include "VisitingVisitorManager.h"
#include "ThoughtListManager.h"
#include "ResultFinalThought.h"

void TitleSceneBtnEvent(int value)
{
    UIOBJECT* tempUIO = NULL;

    if (value == START_NEW_GAME)
    {
        DebugLog("ready to start game");
        SetDialogEvent(DIALOG_NEW_GAME);
        SwitchSceneToName("dialog");
    }
    else if (value == LOAD_GAME_DATA)
    {
        DebugLog("ready to load data");
        tempUIO = GetUIObjByName("load-data");
        if (tempUIO != NULL)
        {
            GetUIObjByName("title")->AddChild(tempUIO);
            tempUIO->AddParent(GetUIObjByName("title"));
            tempUIO->TurnOn();
            SetSelectedBtn(tempUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == LOAD_DATA_1)
    {
        DebugLog("ready to load data1");
    }
    else if (value == LOAD_DATA_2)
    {
        DebugLog("ready to load data2");
    }
    else if (value == LOAD_DATA_3)
    {
        DebugLog("ready to load data3");
    }
    else if (value == GAME_SIMPLY_MANUAL)
    {
        DebugLog("ready to show manual");
        tempUIO = GetUIObjByName("manual");
        if (tempUIO != NULL)
        {
            GetUIObjByName("title")->AddChild(tempUIO);
            tempUIO->AddParent(GetUIObjByName("title"));
            tempUIO->TurnOn();
            SetSelectedBtn(tempUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == THIS_GAME_LINK)
    {
        DebugLog("ready to show link");
        tempUIO = GetUIObjByName("link");
        if (tempUIO != NULL)
        {
            GetUIObjByName("title")->AddChild(tempUIO);
            tempUIO->AddParent(GetUIObjByName("title"));
            tempUIO->TurnOn();
            SetSelectedBtn(tempUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == CLOSE_SAVE_DATA)
    {
        DebugLog("ready to close save-data");
        tempUIO = GetUIObjByName("load-data");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == CLOSE_MANUAL)
    {
        DebugLog("ready to close manual");
        tempUIO = GetUIObjByName("manual");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 2);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == CLOSE_LINK)
    {
        DebugLog("ready to close link");
        tempUIO = GetUIObjByName("link");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 3);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
}

void DialogSceneBtnEvent(int value)
{
    if (value == DIALOG_NEXT)
    {
        DebugLog("ready to load next dialog or set all texts");
        int testIndex = GetDialogIndex() + 1;
        if (testIndex < DIALOG_SIZE)
        {
            char* tester = GetDiaLogEventByEventID(GetDialogEvent())->
                GetSningleDialogByOffset(testIndex)->Speaker;
            if (tester != NULL && strcmp(tester, ""))
            {
                SetDialogIndex(GetDialogIndex() + 1);
            }
            else
            {
                if (GetDialogEvent() == DIALOG_NEW_GAME)
                {
                    SwitchSceneToName("select");
                }
                ResetUsingPointerAndFlag();
            }
        }
        else
        {
            if (GetDialogEvent() == DIALOG_NEW_GAME)
            {
                SwitchSceneToName("select");
            }
            ResetUsingPointerAndFlag();
        }
    }
    else if (value == TEMP_BTN_DIALOG_1)
    {
        DebugLog("ready to temp");
        if (GetDialogEvent() == DIALOG_NEW_GAME)
        {
            SwitchSceneToName("select");
        }
        ResetUsingPointerAndFlag();
    }
}

void StageSelectSceneBtnEvent(int value)
{
    if (value == BEGIN_STAGE_1)
    {
        DebugLog("ready to load stage 1");
        SetPlayingStageByManager(STAGE_DEFAULT);
        SwitchSceneToName("naming");
    }
    else if (value == BEGIN_STAGE_2)
    {
        DebugLog("ready to load stage 2");
        SetPlayingStageByManager(STAGE_BEACH);
        SwitchSceneToName("naming");
    }
    else if (value == BEGIN_STAGE_3)
    {
        DebugLog("ready to load stage 3");
        SetPlayingStageByManager(STAGE_DESERT);
        SwitchSceneToName("naming");
    }
    ReloadBackgroundByPlayingStage();
    ResetBuilder();
    ResetBuildingManager();
    ResetBuildingShowerTimer();
    ResetResortMoveFlag();
    ResetVisitingVisitorShowerTime();
    ResetVisitingBuildShowerTimer();
    ResetThoughtQueueAndList();
    ResetResultFinalThought();
}

void NamingSceneBtnEvent(int value)
{
    UIOBJECT* tempUIO = NULL;

    if (value == NAMING_SUB_1)
    {
        DebugLog("ready to open naming sub 1");
        tempUIO = GetUIObjByName("subname1");
        if (tempUIO != NULL)
        {
            GetUIObjByName("naming")->AddChild(tempUIO);
            tempUIO->AddParent(GetUIObjByName("naming"));
            tempUIO->TurnOn();
            SetSelectedBtn(tempUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == NAMING_SUB_2)
    {
        DebugLog("ready to open naming sub 2");
        tempUIO = GetUIObjByName("subname2");
        if (tempUIO != NULL)
        {
            GetUIObjByName("naming")->AddChild(tempUIO);
            tempUIO->AddParent(GetUIObjByName("naming"));
            tempUIO->TurnOn();
            SetSelectedBtn(tempUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == CONFIRM_NAME)
    {
        DebugLog("ready to confirm this name");
        SaveConfirmedName();

        ResetAllAboutShowVisitors();
        ClearSceneCamBuffer(GetSceneNodeByName("naming"));
        char temp[17] = "  �أأأأأ�  ";
        (GetUIObjByName("naming")->Texts + 6)->
            ChangeTextTo(temp);
        (GetUIObjByName("naming")->Texts + 7)->
            ChangeTextTo(temp);
        SwitchSceneToName("build");
    }
    else if (
        value == SUB1_1_1NAME || value == SUB1_1_2NAME ||
        value == SUB1_1_3NAME || value == SUB1_1_4NAME ||
        value == SUB1_1_5NAME || value == SUB1_2_1NAME ||
        value == SUB1_2_2NAME || value == SUB1_2_3NAME ||
        value == SUB1_2_4NAME || value == SUB1_2_5NAME ||
        value == SUB1_3_1NAME || value == SUB1_3_2NAME ||
        value == SUB1_3_3NAME || value == SUB1_3_4NAME ||
        value == SUB1_3_5NAME || value == BACK_TO_NAME_1
        )
    {
        DebugLog("ready to back to main naming from sub 1");
        SetTempName1(value);
        tempUIO = GetUIObjByName("subname1");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (
        value == SUB2_1_1NAME || value == SUB2_1_2NAME ||
        value == SUB2_1_3NAME || value == SUB2_1_4NAME ||
        value == SUB2_1_5NAME || value == SUB2_2_1NAME ||
        value == SUB2_2_2NAME || value == SUB2_2_3NAME ||
        value == SUB2_2_4NAME || value == SUB2_2_5NAME ||
        value == SUB2_3_1NAME || value == SUB2_3_2NAME ||
        value == SUB2_3_3NAME || value == SUB2_3_4NAME ||
        value == SUB2_3_5NAME || value == BACK_TO_NAME_2
        )
    {
        DebugLog("ready to back to main naming from sub 2");
        SetTempName2(value);
        tempUIO = GetUIObjByName("subname2");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
}

void BuildingSceneBtnEvent(int value)
{
    UIOBJECT* tempUIO = NULL;

    if (value == SET_BUILDING_TYPE)
    {
        if (GetBuilderMovFlg() == BUILDER_STOP &&
            GetCurrBuildingPosByBuilder() != 0)
        {
            DebugLog("ready to open sub tpye ui");
            tempUIO = GetUIObjByName("build-type");
            if (tempUIO != NULL)
            {
                GetUIObjByName("build")->AddChild(tempUIO);
                tempUIO->AddParent(GetUIObjByName("build"));
                tempUIO->TurnOn();
                SetSelectedBtn(tempUIO->Buttons);
            }
            else
            {
                ErrorLog("cannot find this UI object");
            }
        }
    }
    else if (value == SET_BUILDING_EVENT)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type != B_TYPE_NOTHING)
        {
            DebugLog("ready to open sub event ui");
            tempUIO = GetUIObjByName("build-event");
            if (tempUIO != NULL)
            {
                GetUIObjByName("build")->AddChild(tempUIO);
                tempUIO->AddParent(GetUIObjByName("build"));
                tempUIO->TurnOn();
                SetSelectedBtn(tempUIO->Buttons);
            }
            else
            {
                ErrorLog("cannot find this UI object");
            }
        }
    }
    else if (value == CONFIRM_BUILDING)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status != BUILDING_STATUS::NOTHING &&
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type != B_TYPE_NOTHING &&
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event != B_EVNT_NOTHING)
        {
            DebugLog("ready to confirm this building");
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::CONFIRMED;
            ShowBuildingHammer();
        }
    }
    else if (value == BUILD_IS_END)
    {
        DebugLog("ready to go to resort scene");
        SetBuilderMovFlg(BUILDER_STOP);
        ReloadVisitingBackground();
        ResetResortBGTimerAndOffset();
        SwitchSceneToName("resort");
    }
    else if (value == BACK_TO_BUILD_TYPE)
    {
        DebugLog("ready to back to build ui from building type");
        tempUIO = GetUIObjByName("build-type");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == BACK_TO_BUILD_EVENT)
    {
        DebugLog("ready to back to build ui from building event");
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == TYPE_HOTSPRING)
    {
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status = BUILDING_STATUS::PLANING;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type = B_TYPE_HOTSPRING;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_NOTHING;
        tempUIO = GetUIObjByName("build-type");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == TYPE_FOOD)
    {
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status = BUILDING_STATUS::PLANING;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type = B_TYPE_FOOD;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_NOTHING;
        tempUIO = GetUIObjByName("build-type");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == TYPE_POOL)
    {
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status = BUILDING_STATUS::PLANING;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type = B_TYPE_POOL;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_NOTHING;
        tempUIO = GetUIObjByName("build-type");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == TYPE_DRINK)
    {
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status = BUILDING_STATUS::PLANING;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type = B_TYPE_DRINK;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_NOTHING;
        tempUIO = GetUIObjByName("build-type");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == TYPE_CINEMA)
    {
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status = BUILDING_STATUS::PLANING;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type = B_TYPE_CINEMA;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_NOTHING;
        tempUIO = GetUIObjByName("build-type");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == TYPE_KARAOKE)
    {
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status = BUILDING_STATUS::PLANING;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type = B_TYPE_KARAOKE;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_NOTHING;
        tempUIO = GetUIObjByName("build-type");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == TYPE_RESTPLACE)
    {
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status = BUILDING_STATUS::PLANING;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type = B_TYPE_RESTPLACE;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_NOTHING;
        tempUIO = GetUIObjByName("build-type");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == TYPE_MAKEBYHAND)
    {
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status = BUILDING_STATUS::PLANING;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Type = B_TYPE_MAKEBYHAND;
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_NOTHING;
        tempUIO = GetUIObjByName("build-type");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_NORMALSPR)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_NORMALSPR;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_SKINCARESPR)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_SKINCARESPR;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_WARMSPR)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_WARMSPR;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_HEALTHSPR)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_HEALTHSPR;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_EATBBQ)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_EATBBQ;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_EATLIGHTFOOD)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_EATLIGHTFOOD;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_EATUNAGI)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_EATUNAGI;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_EATRAMEN)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_EATRAMEN;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_EATCURRY)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_EATCURRY;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_EATFRIEDNOODLE)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_EATFRIEDNOODLE;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_POLNORMAL)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_POLNORMAL;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_POLFLUSH)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_POLFLUSH;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_POLNIGHT)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_POLNIGHT;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_POLINFINITY)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_POLINFINITY;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_DRKMILKTEA)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_DRKMILKTEA;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_DRKCAFE)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_DRKCAFE;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_DRKTEA)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_DRKTEA;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_DRKBAR)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_DRKBAR;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_DRKKARUPISU)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_DRKKARUPISU;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_DRKALCOHOL)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_DRKALCOHOL;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_MOVHOR)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_MOVHOR;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_MOVLOVE)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_MOVLOVE;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_MOVSF)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_MOVSF;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_MOVACT)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_MOVACT;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_MOVCOMEDY)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_MOVCOMEDY;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_MOVDOCUMENTARY)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_MOVDOCUMENTARY;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_KARASINGLE)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_KARASINGLE;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_KARAMUTLI)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_KARAMUTLI;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_RESTCAMP)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_RESTCAMP;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_RESTHOTEL)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_RESTHOTEL;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_MAKEPRESENT)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_MAKEPRESENT;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == EVNT_MAKEACSY)
    {
        if ((GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Status == BUILDING_STATUS::CONFIRMED)
        {
            (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
                Status = BUILDING_STATUS::PLANING;
        }
        (GetEditBuildingsArray() + GetCurrBuildingPos() - 1)->
            Event = B_EVNT_MAKEACSY;
        tempUIO = GetUIObjByName("build-event");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons + 1);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
}

void FinalResultSceneBtnEvent(int value)
{
    UIOBJECT* tempUIO = NULL;

    if (value == SAVE_GAME_DATA)
    {
        DebugLog("ready to save clear stage");
        tempUIO = GetUIObjByName("save-data");
        if (tempUIO != NULL)
        {
            GetUIObjByName("final-result")->AddChild(tempUIO);
            tempUIO->AddParent(GetUIObjByName("final-result"));
            tempUIO->TurnOn();
            SetSelectedBtn(tempUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    else if (value == BACK_TO_TITLE)
    {
        DebugLog("ready to back to title scene");
        ResetPlayingStageByManager();
        ResetVisitorManager();
        SwitchSceneToName("title");
    }
    else if (value == SAVE_AT_1)
    {
        DebugLog("ready to save at 1");
    }
    else if (value == SAVE_AT_2)
    {
        DebugLog("ready to save at 2");
    }
    else if (value == SAVE_AT_3)
    {
        DebugLog("ready to save at 3");
    }
    else if (value == BACK_TO_RESULT)
    {
        DebugLog("ready to back to result");
        tempUIO = GetUIObjByName("save-data");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
}
