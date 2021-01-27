#include "SceneManager.h"
#include "SceneNode.h"
#include "DeclaredValues.h"
#include "AppDeclared.h"
#include "AppTestScene.h"
#include "AppTitleScene.h"
#include "AppDialogScene.h"
#include "AppSwitchEffectScene.h"
#include "AppSelectStageScene.h"
#include "AppNamingScene.h"
#include "AppBuildScene.h"
#include "AppResortScene.h"
#include "AppEventScene.h"
#include "AppFeelingScene.h"
#include "AppResultScene.h"

int g_SceneFlag;

void SetSceneFlag(int flag)
{
    g_SceneFlag = flag;
}

int GetSceneFlag()
{
    return g_SceneFlag;
}

void SetManagedCurrScene(SCENENODE* sceneNode)
{
    SetCurrScene(sceneNode);
}

SCENENODE* GetManagedCurrScene()
{
    return GetCurrScene();
}

void InitCurrScene()
{
    if (GetSwitchEffectFlag())
    {
        if (!strcmp(GetManagedCurrScene()->SceneName, "test"))
        {
            SetSceneFlag(TESTSCENEFLAG);
        }
        else if (!strcmp(GetManagedCurrScene()->SceneName, "title"))
        {
            SetSceneFlag(TITLESCENEFLAG);
        }
        else if (!strcmp(GetManagedCurrScene()->SceneName, "dialog"))
        {
            SetSceneFlag(DIALOGSCENEFLAG);
        }
        else if (!strcmp(GetManagedCurrScene()->SceneName, "select"))
        {
            SetSceneFlag(SELECTSCENEFLAG);
        }
        else if (!strcmp(GetManagedCurrScene()->SceneName, "naming"))
        {
            SetSceneFlag(NAMINGSCENEFLAG);
        }
        else if (!strcmp(GetManagedCurrScene()->SceneName, "build"))
        {
            SetSceneFlag(BUILDINGSCENEFLAG);
        }
        else if (!strcmp(GetManagedCurrScene()->SceneName, "resort"))
        {
            SetSceneFlag(RESORTSCENEFLAG);
        }
        else if (!strcmp(GetManagedCurrScene()->SceneName, "event"))
        {
            SetSceneFlag(EVENTSCENEFLAG);
        }
        else if (!strcmp(GetManagedCurrScene()->SceneName, "feeling"))
        {
            SetSceneFlag(FEELINGSCENEFLAG);
        }
        else if (!strcmp(GetManagedCurrScene()->SceneName, "result"))
        {
            SetSceneFlag(RESULTSCENEFLAG);
        }

        if (GetSceneNodeByName("switch-effect") == NULL)
        {
            InitSwitchEffectScene();
        }
        GetSceneNodeByName("switch-effect")->SetBaseUIO(GetUIObjByName("empty"));
        SetManagedCurrScene(GetSceneNodeByName("switch-effect"));
        SetSelectedBtn(GetSceneNodeByName("switch-effect")->BaseUIObj->Buttons);
    }
    else
    {
        switch (GetSceneFlag())
        {
        case TESTSCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("test"));
            SetSelectedBtn(GetSceneNodeByName("test")->
                BaseUIObj->Buttons);
            break;

        case TITLESCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("title"));
            SetSelectedBtn(GetSceneNodeByName("title")->
                BaseUIObj->Buttons);
            break;

        case DIALOGSCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("dialog"));
            SetSelectedBtn(GetSceneNodeByName("dialog")->
                BaseUIObj->Buttons);
            break;

        case SELECTSCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("select"));
            SetSelectedBtn(GetSceneNodeByName("select")->
                BaseUIObj->Buttons);
            break;

        case NAMINGSCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("naming"));
            SetSelectedBtn(GetSceneNodeByName("naming")->
                BaseUIObj->Buttons);
            break;

        case BUILDINGSCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("build"));
            SetSelectedBtn(GetSceneNodeByName("build")->
                BaseUIObj->Buttons);
            break;

        case RESORTSCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("resort"));
            SetSelectedBtn(GetSceneNodeByName("resort")->
                BaseUIObj->Buttons);
            break;

        case EVENTSCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("event"));
            SetSelectedBtn(GetSceneNodeByName("event")->
                BaseUIObj->Buttons);
            break;

        case FEELINGSCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("feeling"));
            SetSelectedBtn(GetSceneNodeByName("feeling")->
                BaseUIObj->Buttons);
            break;

        case RESULTSCENEFLAG:
            SetManagedCurrScene(GetSceneNodeByName("result"));
            SetSelectedBtn(GetSceneNodeByName("result")->
                BaseUIObj->Buttons);
            break;

        default:
            break;
        }
    }
}

void UpdateCurrScene()
{
    if (GetSwitchEffectFlag())
    {
        UpdateSwitchEffectScene();
    }
    else
    {
        switch (GetSceneFlag())
        {
        case TESTSCENEFLAG:
            UpdateTestScene();
            break;

        case TITLESCENEFLAG:
            UpdateTitleScene();
            break;

        case DIALOGSCENEFLAG:
            UpdateDialogScene();
            break;

        case SELECTSCENEFLAG:
            UpdateSelectStageScene();
            break;

        case NAMINGSCENEFLAG:
            UpdateNamingScene();
            break;

        case BUILDINGSCENEFLAG:
            UpdateBuildScene();
            break;

        case RESORTSCENEFLAG:
            UpdateResortScene();
            break;

        case EVENTSCENEFLAG:
            UpdateEventScene();
            break;

        case FEELINGSCENEFLAG:
            UpdateFeelingScene();
            break;

        case RESULTSCENEFLAG:
            UpdateResultScene();
            break;

        default:
            ErrorLogI1("you don't have a scene flag witch is", GetSceneFlag());
            break;
        }
    }
}

void SwitchSceneToName(const char* sceneName)
{
    SCENENODE* scene = GetSceneNodeByName(sceneName);
    if (scene == NULL)
    {
        if (!strcmp(sceneName, "test"))
        {
            InitTestScene();
        }
        else if (!strcmp(sceneName, "title"))
        {
            InitTitleScene();
        }
        else if (!strcmp(sceneName, "dialog"))
        {
            InitDialogScene();
        }
        else if (!strcmp(sceneName, "select"))
        {
            InitSelectStageScene();
        }
        else if (!strcmp(sceneName, "naming"))
        {
            InitNamingScene();
        }
        else if (!strcmp(sceneName, "build"))
        {
            InitBuildScene();
        }
        else if (!strcmp(sceneName, "resort"))
        {
            InitResortScene();
        }
        else if (!strcmp(sceneName, "event"))
        {
            InitEventScene();
        }
        else if (!strcmp(sceneName, "feeling"))
        {
            InitFeelingScene();
        }
        else if (!strcmp(sceneName, "result"))
        {
            InitResultScene();
        }

        scene = GetSceneNodeByName(sceneName);
    }
    SetManagedCurrScene(scene);
    SetSwitchEffectFlag(1);
    InitCurrScene();
}
