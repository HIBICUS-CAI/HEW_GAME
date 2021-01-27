#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "SpriteAnimator.h"
#include "SoundManager.h"
#include "UIObjDeclarer.h"
#include "AppBtnEvent.h"
#include "Tools.h"

void AppInit()
{
    CreateAllUIObjs();
    InitSceneNodes();
    SetSwitchEffectFlag(0);
    SetRandom();
    SetSwitchEffectStyle(CreateRandomNumIn(1, 4));
    SetIsDialogFinish(1);
    SetDialogEvent(DIALOG_NOTHING);

    SwitchSceneToName("title");
}

void AppUpdate()
{
    UpdateCurrScene();

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
