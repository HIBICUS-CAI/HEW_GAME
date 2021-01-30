#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "SpriteAnimator.h"
#include "SoundManager.h"
#include "UIObjDeclarer.h"
#include "AppBtnEvent.h"
#include "Tools.h"

#include "DialogShower.h"
#include "PlayingStageManager.h"
#include "VisitorManager.h"

void AppInit()
{
    CreateAllUIObjs();
    InitSceneNodes();
    InitAndLoadDialogEvents();
    SetSwitchEffectFlag(0);
    SetRandom();
    SetSwitchEffectStyle(CreateRandomNumIn(1, 4));

    InitDialogShower();
    InitPlayingStage();
    InitVisitorManager();

    SwitchSceneToName("title");
}

void AppUpdate()
{
    UpdateCurrScene();

    switch (GetSceneFlag())
    {
    case DIALOGSCENEFLAG:
        UpdateDialogShower();
        break;

    case SELECTSCENEFLAG:
        UpdatePlayingStage();
        break;

    default:
        break;
    }

    DrawScene(GetManagedCurrScene());
}

void AppTurnOff()
{

}

void AppPostPrint()
{

}

void AppKeyboardEvent(int keyCode)
{

}

void AppButtonEvent(int value)
{
    switch (GetSceneFlag())
    {
    case TESTSCENEFLAG:
        //TitleSceneBtnEvent(value);
        //DialogSceneBtnEvent(value);
        //StageSelectSceneBtnEvent(value);
        //NamingSceneBtnEvent(value);
        //BuildingSceneBtnEvent(value);
        //FinalResultSceneBtnEvent(value);
        break;

    case TITLESCENEFLAG:
        TitleSceneBtnEvent(value);
        break;

    case DIALOGSCENEFLAG:
        DialogSceneBtnEvent(value);
        break;

    case SELECTSCENEFLAG:
        StageSelectSceneBtnEvent(value);
        break;

    case NAMINGSCENEFLAG:
        NamingSceneBtnEvent(value);
        break;

    case BUILDINGSCENEFLAG:
        BuildingSceneBtnEvent(value);
        break;

    case RESULTSCENEFLAG :
        FinalResultSceneBtnEvent(value);
        break;

    default:
        break;
    }
}
