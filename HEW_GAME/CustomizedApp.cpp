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
#include "VisitingBuildShower.h"
#include "VisitingVisitorManager.h"
#include "ThoughtListManager.h"
#include "ThoughtListShower.h"
#include "ResultFinalThought.h"
#include "ResultTips.h"
#include "FinalResult.h"
#include "TitleBuilderShower.h"
#include "TitleKanaShower.h"
#include "StageSelectBackShower.h"
#include "DataSyncer.h"
#include "StatisticShower.h"

void AppInit()
{
    CreateAllUIObjs();
    InitSceneNodes();
    InitAndLoadDialogEvents();
    LoadSoundFilesAlwaysUse();
    SetSwitchEffectFlag(0);
    SetRandom();
    SetSwitchEffectStyle(CreateRandomNumIn(1, 4));
    TestHewDatabaseConnect();

    InitAndLoadBGSprite();
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
    InitVisitingBuildShower();
    InitVisitingVisitorManager();
    InitThoughtListManager();
    InitThoughtListShower();
    InitResultFinalThought();
    InitResultTips();
    InitFinalResult();
    InitTitleBuilderShower();
    InitTitleKanaShower();
    InitStageSelectBackGShower();
    InitStatisticShower();


    SetDialogEvent(DIALOG_NEW_GAME);
    SwitchSceneToName("dialog");
    LoadSound(
        "Assets\\Sounds\\title.mp3",
        "title_bgm"
    );
    PlayBackgroundMusic(GetSoundFile("title_bgm"));
}

void AppUpdate()
{
    UpdateCurrScene();

    switch (GetSceneFlag())
    {
    case TITLESCENEFLAG:
        UpdateTitleBuilderShower();
        UpdateTitleKanaShower();
        break;

    case DIALOGSCENEFLAG:
        UpdateDialogShower();
        break;

    case SELECTSCENEFLAG:
        UpdatePlayingStage();
        UpdateStageSelectBackGShower();
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
        UpdateVisitingVisitorManager();
        UpdateThoughtListManager();
        UpdateVisitingBackground();
        UpdateVisitingBuildShower();
        UpdateVisitingVisitorsShower();
        UpdateThoughtListShower();
        break;

    case RESULTSCENEFLAG:
        UpdateResultFinalThought();
        UpdateResultTips();
        UpdateFinalResult();
        UpdateStatisticShower();
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
    if (keyCode == I_VALUE ||
        keyCode == J_VALUE ||
        keyCode == K_VALUE ||
        keyCode == L_VALUE)
    {
        PlayEffectSound(GetSoundFile("button_move"));
    }

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
    if (value == DIALOG_NEXT)
    {
        PlayEffectSound(GetSoundFile("dialog_next"));
    }
    else if (value == CONFIRM_BUILDING)
    {
        PlayEffectSound(GetSoundFile("build_confirm"));
    }
    else if (value == BUILD_IS_END)
    {
        PlayEffectSound(GetSoundFile("build_finish"));
    }
    else
    {
        PlayEffectSound(GetSoundFile("button_event"));
    }

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
