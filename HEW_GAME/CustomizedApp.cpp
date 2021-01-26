#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "SpriteAnimator.h"
#include "SoundManager.h"
#include "UIObjDeclarer.h"
#include "AppBtnEvent.h"

void AppInit()
{
    CreateAllUIObjs();
    InitSceneNodes();

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

    default:
        break;
    }
}
