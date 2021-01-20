#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "SpriteAnimator.h"


//---------------------
SPRITE g_TestSprite;

void AppInit()
{
    InitSceneNodes();


    g_TestSprite = CreateSingleSprite("AsciiDraw.txt", POSITION_2D(5, 5), 30, 13);
}

void AppUpdate()
{
    //UpdateCurrScene();

    //DrawScene(GetManagedCurrScene());

    DrawSingleSpriteToUpdateBuffer(&g_TestSprite);
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

}
