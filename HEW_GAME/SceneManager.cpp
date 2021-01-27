#include "SceneManager.h"
#include "SceneNode.h"
#include "DeclaredValues.h"
#include "AppDeclared.h"
#include "AppTestScene.h"
#include "AppTitleScene.h"
#include "AppDialogScene.h"
#include "AppSwitchEffectScene.h"
#include "AppSelectStageScene.h"

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

        if (GetSceneNodeByName("switch-effect") == NULL)
        {
            InitSwitchEffectScene();
        }
        GetSceneNodeByName("switch-effect")->SetBaseUIO(GetUIObjByName("switch"));
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

        scene = GetSceneNodeByName(sceneName);
    }
    SetManagedCurrScene(scene);
    SetSwitchEffectFlag(1);
    InitCurrScene();
}
