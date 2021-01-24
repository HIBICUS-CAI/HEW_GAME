#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "SpriteAnimator.h"
#include "SoundManager.h"

void AppInit()
{
    InitSceneNodes();

    //--------------------------------
    LoadSound("grass.mp3", "testbgm");
    ChangeSoundFileVolume("testbgm", 80);
    LoadSound("111222.mp3", "key", 1);
    PlayBackgroundMusic(GetSoundFile("testbgm"));
}

void AppUpdate()
{
    //UpdateCurrScene();

    //DrawScene(GetManagedCurrScene());
}

void AppTurnOff()
{

}

void AppPostPrint()
{

}

void AppKeyboardEvent(int keyCode)
{
    if (keyCode == O_VALUE)
    {
        PlayEffectSound(GetSoundFile("key"));
    }
}

void AppButtonEvent(int value)
{

}
