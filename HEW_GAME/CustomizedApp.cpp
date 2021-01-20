#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "SpriteAnimator.h"


//---------------------
SPRITE_ANIME g_TestSprite;
int g_TestOffset = 0;

void AppInit()
{
    InitSceneNodes();


    g_TestSprite = CreateSpriteAnimator(3, "AsciiDraw", POSITION_2D(5, 5), 15, 13);
}

void AppUpdate()
{
    //UpdateCurrScene();

    //DrawScene(GetManagedCurrScene());

    DrawSpriteAnimatorToUpdateBuffer(&g_TestSprite, (g_TestOffset++) % 60);
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
