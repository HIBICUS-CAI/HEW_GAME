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
        ResetBuilder();
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
    else if (value == TEMP_BTN_BUILDING_1)
    {
        DebugLog("ready to go to resort scene");
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
