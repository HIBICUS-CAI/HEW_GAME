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
#include "VisitorShower.h"
#include "ResortNameManager.h"
#include "BuilderManager.h"
#include "BuildBackgroundShower.h"
#include "BuildingManager.h"
#include "BuildingShower.h"
#include "VisitingVisitorShower.h"
#include "VisitingBackgroundShower.h"

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
    InitVisitorShower();
    InitResortNameManager();
    InitBuilder();
    InitBuildBackground();
    InitBuildingManager();
    InitBuildingShower();
    InitVisitingVisitorShower();
    InitVisitingBackground();

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

    case NAMINGSCENEFLAG:
        UpdateVisitorShower();
        UpdateResortNameManager();
        break;

    case BUILDINGSCENEFLAG:
        UpdateBuildingManager();
        UpdateBuildBackground();
        UpdateBuildingShower();
        UpdateBuilder();
        break;

    case RESORTSCENEFLAG:
        UpdateVisitingBackground();
        UpdateVisitingVisitorsShower();
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
    if (GetSceneFlag() == BUILDINGSCENEFLAG)
    {
        if (GetBuilderMovFlg() == BUILDER_STOP &&
            !GetUIObjByName("build-type")->Visiblity)
        {
            if (keyCode == A_VALUE)
            {
                DebugLog("go left");
                SetBuilderMovFlg(BUILDER_GO_LEFT);
            }
            else if (keyCode == D_VALUE)
            {
                DebugLog("go right");
                SetBuilderMovFlg(BUILDER_GO_RIGHT);
            }
        }

    }
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

    case RESULTSCENEFLAG:
        FinalResultSceneBtnEvent(value);
        break;

    default:
        break;
    }
}
