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
    LoadWavSoundToSoundInBitesArray("se_mob02.wav", "buriburi");
    ChangeSoundFileVolume("buriburi", 0.2);
    LoadWavSoundToSoundInBitesArray("se_mob04.wav", "shippai");
    ChangeSoundFileVolume("shippai", 0.2);
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
    if (keyCode == A_VALUE)
    {
        PlayEffectSound(GetSoundFile("buriburi"));
    }
    else if (keyCode == D_VALUE)
    {
        PlayEffectSound(GetSoundFile("shippai"));
    }
}

void AppButtonEvent(int value)
{

}
