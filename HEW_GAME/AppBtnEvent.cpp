#include "AppBtnEvent.h"
#include "GameAppStructs.h"
#include "AppDeclared.h"
#include "UIObject.h"
#include "DeclaredValues.h"

void TitleSceneBtnEvent(int value)
{
    UIOBJECT* tempUIO = NULL;

    if (value == START_NEW_GAME)
    {
        DebugLog("ready to start game");
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
    }
}

void StageSelectSceneBtnEvent(int value)
{
    if (value == BEGIN_STAGE_1)
    {
        DebugLog("ready to load stage 1");
    }
    else if (value == BEGIN_STAGE_2)
    {
        DebugLog("ready to load stage 2");
    }
    else if (value == BEGIN_STAGE_3)
    {
        DebugLog("ready to load stage 3");
    }
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
    }
    else if (value == BACK_TO_NAME_1)
    {
        DebugLog("ready to back to main naming from sub 1");
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
    else if (value == BACK_TO_NAME_2)
    {
        DebugLog("ready to back to main naming from sub 2");
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
    else if (value == SET_BUILDING_EVENT)
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
    else if (value == CONFIRM_BUILDING)
    {
        DebugLog("ready to confirm this building");
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
}

void FinalResultSceneBtnEvent(int value)
{
    if (value == SAVE_GAME_DATA)
    {
        DebugLog("ready to save clear stage");
    }
    else if (value == BACK_TO_TITLE)
    {
        DebugLog("ready to back to title scene");
    }
}
