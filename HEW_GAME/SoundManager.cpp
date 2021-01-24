#include "SoundManager.h"
#include "DeclaredValues.h"
#include "Tools.h"

#pragma comment(lib, "Winmm.lib")

void InitSoundInBitesArray()
{
    for (int i = 0; i < SOUNDHANDLE_SIZE; i++)
    {
        *(GetSoundHandleArray() + i) = SOUND_THREAD_HANDLE();
    }

    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        *(GetSoundFilesInMemBitesArray() + i) = SOUNDFILE_IN_MEMBITE();
    }
}

void LoadWavSoundToSoundInBitesArray(const char* fileName, const char* soundName)
{
    SOUNDFILE_IN_MEMBITE* soundNotLoaded = NULL;
    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        if (!(GetSoundFilesInMemBitesArray() + i)->IsUsing)
        {
            soundNotLoaded = GetSoundFilesInMemBitesArray() + i;
            soundNotLoaded->IsUsing = 1;
            break;
        }
    }
    if (soundNotLoaded == NULL)
    {
        ErrorLog("all items in sound array have been used");
        return;
    }

    strcpy_s(soundNotLoaded->SoundName, sizeof(soundNotLoaded->SoundName), soundName);
    ReadWavFileIntoMemory(fileName, &(soundNotLoaded->SoundFileInBites), &(soundNotLoaded->SoundFileInBitesWithVolume),
        &(soundNotLoaded->SoundFileSize));
    ChangeSoundFileVolume(soundNotLoaded, 0.2);
}

SOUNDFILE_IN_MEMBITE* GetSoundFile(const char* soundName)
{
    return GetSoundFilesInMemBites(soundName);
}

void ChangeSoundFileVolume(const char* soundName, float vol)
{
    SOUNDFILE_IN_MEMBITE* sound = GetSoundFile(soundName);
    *(sound->SoundFileInBitesWithVolume) = *(sound->SoundFileInBites);
    BYTE* pDataOffset = (sound->SoundFileInBitesWithVolume + 40);

    __int16* p = (__int16*)(pDataOffset + 8);
    for (unsigned int i = 80 / sizeof(*p); i < sound->SoundFileSize / sizeof(*p); i++)
    {
        p[i] = (float)p[i] * vol;
    }
}

void ChangeSoundFileVolume(SOUNDFILE_IN_MEMBITE* sound, float vol)
{
    (sound->SoundFileInBitesWithVolume) = (sound->SoundFileInBites);
    BYTE* pDataOffset = (sound->SoundFileInBitesWithVolume + 40);

    __int16* p = (__int16*)(pDataOffset + 8);
    for (unsigned int i = 80 / sizeof(*p); i < sound->SoundFileSize / sizeof(*p); i++)
    {
        p[i] = (float)p[i] * vol;
    }
}

void PlayBackgroundMusic(SOUNDFILE_IN_MEMBITE* sound)
{
    // TODO also fixed this by running a new process
    if (sound == NULL)
    {
        DebugLog("this sound doesn't exist, ready to stop what is playing now");
        PlaySound(NULL, NULL, SND_MEMORY);
    }
    else
    {
        PlaySound((LPCSTR)sound->SoundFileInBitesWithVolume, NULL, SND_MEMORY | SND_ASYNC | SND_LOOP);
    }
}

void PlayEffectSound(SOUNDFILE_IN_MEMBITE* sound)
{
    // TODO fixed this by running a new process
    SOUND_THREAD_HANDLE* temp = NULL;
    temp = GetSoundHandleThatNotUsing();

    temp->IsUsing = 1;
    temp->SoundHandle = CreateThread(NULL, 0,
        (LPTHREAD_START_ROUTINE)PlaySingleSoundOnce, sound, 0, NULL);
}

void PlaySingleSoundOnce(SOUNDFILE_IN_MEMBITE* sound)
{
    // TODO fixed this by running a new process
    if (sound == NULL)
    {
        DebugLog("this sound doesn't exist");
        PlaySound(NULL, NULL, SND_MEMORY);
    }
    else
    {
        PlaySound((LPCSTR)sound->SoundFileInBitesWithVolume, NULL, SND_MEMORY);
    }
}

void TurnOffSoundInBites()
{
    PlayBackgroundMusic(NULL);
    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        delete[](GetSoundFilesInMemBitesArray() + i)->SoundFileInBites;
        delete[](GetSoundFilesInMemBitesArray() + i)->SoundFileInBitesWithVolume;
        *(GetSoundFilesInMemBitesArray() + i) = SOUNDFILE_IN_MEMBITE();
    }
}
