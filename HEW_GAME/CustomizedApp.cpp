#include "CustomizedApp.h"
#include "SceneNode.h"
#include "SceneManager.h"
#include "SpriteAnimator.h"
#include "SoundManager.h"

void AppInit()
{
    InitSceneNodes();

    //---------------------------------------------------------------------
    LoadWavSoundToSoundInBitesArray("loop100404.wav", "testbgm");
    ChangeSoundFileVolume("testbgm", 0.1);
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
    
}

void AppButtonEvent(int value)
{
    
}
