#include "SoundManager.h"
#include "DeclaredValues.h"

#ifdef SOUNDBYHAL
#include "conioex.h"
#else
#include "Tools.h"
#pragma comment(lib, "Winmm.lib")
#endif // SOUNDBYHAL

void InitSoundSys()
{
#ifdef SOUNDBYHAL
    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        *(GetSoundFilesInMemBitesArray() + i) = SOUNDFILE_LOADED();
    }
#else
    for (int i = 0; i < SOUNDHANDLE_SIZE; i++)
    {
        *(GetSoundHandleArray() + i) = SOUND_THREAD_HANDLE();
    }

    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        *(GetSoundFilesInMemBitesArray() + i) = SOUNDFILE_IN_MEMBITE();
    }
#endif // SOUNDBYHAL
}

void LoadSound(const char* fileName, const char* soundName,
    int isAlwaysNeed)
{
#ifndef NOTSOUND
#ifdef SOUNDBYHAL
    SOUNDFILE_LOADED* soundNotLoaded = NULL;
    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        if (!(GetSoundFilesInMemBitesArray() + i)->IsUsing)
        {
            soundNotLoaded = GetSoundFilesInMemBitesArray() + i;
            soundNotLoaded->Handle = opensound((char*)fileName);
            if (soundNotLoaded->Handle != 0)
            {
                strcpy_s(soundNotLoaded->SoundName,
                    sizeof(soundNotLoaded->SoundName), soundName);
                soundNotLoaded->IsUsing = 1;
                soundNotLoaded->AlwaysNeed = isAlwaysNeed;
                break;
            }
            else
            {
                ErrorLog("cannot load this sound");
                return;
            }
        }
    }
    if (soundNotLoaded == NULL)
    {
        ErrorLog("all items in sound array have been used");
        return;
    }

    ChangeSoundFileVolume(soundNotLoaded, 20);
#else
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
#endif // SOUNDBYHAL
#endif // !NOTSOUND
}

#ifdef SOUNDBYHAL
SOUNDFILE_LOADED* GetSoundFile(const char* soundName)
#else
SOUNDFILE_IN_MEMBITE* GetSoundFile(const char* soundName)
#endif // SOUNDBYHAL
{
#ifndef NOTSOUND
    return GetSoundFilesInMemBites(soundName);
#else
    return NULL;
#endif // !NOTSOUND
}

#ifdef SOUNDBYHAL
void ChangeSoundFileVolume(const char* soundName, int vol)
#else
void ChangeSoundFileVolume(const char* soundName, float vol)
#endif // SOUNDBYHAL
{
#ifndef NOTSOUND
#ifdef SOUNDBYHAL
    SOUNDFILE_LOADED* sound = GetSoundFile(soundName);
    setvolume(sound->Handle, vol);
#else
    SOUNDFILE_IN_MEMBITE* sound = GetSoundFile(soundName);
    *(sound->SoundFileInBitesWithVolume) = *(sound->SoundFileInBites);
    BYTE* pDataOffset = (sound->SoundFileInBitesWithVolume + 40);

    __int16* p = (__int16*)(pDataOffset + 8);
    for (unsigned int i = 80 / sizeof(*p); i < sound->SoundFileSize / sizeof(*p); i++)
    {
        p[i] = (float)p[i] * vol;
    }
#endif // SOUNDBYHAL
#endif // !NOTSOUND
}

#ifdef SOUNDBYHAL
void ChangeSoundFileVolume(SOUNDFILE_LOADED* sound, int vol)
#else
void ChangeSoundFileVolume(SOUNDFILE_IN_MEMBITE* sound, float vol)
#endif // SOUNDBYHAL
{
#ifndef NOTSOUND
#ifdef SOUNDBYHAL
    setvolume(sound->Handle, vol);
#else
    (sound->SoundFileInBitesWithVolume) = (sound->SoundFileInBites);
    BYTE* pDataOffset = (sound->SoundFileInBitesWithVolume + 40);

    __int16* p = (__int16*)(pDataOffset + 8);
    for (unsigned int i = 80 / sizeof(*p); i < sound->SoundFileSize / sizeof(*p); i++)
    {
        p[i] = (float)p[i] * vol;
    }
#endif // SOUNDBYHAL
#endif // !NOTSOUND
}

#ifdef SOUNDBYHAL
void PlayBackgroundMusic(SOUNDFILE_LOADED* sound)
#else
void PlayBackgroundMusic(SOUNDFILE_IN_MEMBITE* sound)
#endif // SOUNDBYHAL
{
#ifndef NOTSOUND
#ifdef SOUNDBYHAL
    if (sound == NULL)
    {
        ErrorLog("this sound doesn't exist");
    }
    else
    {
        playsound(sound->Handle, 1);
    }
#else
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
#endif // SOUNDBYHAL
#endif // !NOTSOUND
}

#ifdef SOUNDBYHAL
void PlayEffectSound(SOUNDFILE_LOADED* sound)
#else
void PlayEffectSound(SOUNDFILE_IN_MEMBITE* sound)
#endif // SOUNDBYHAL
{
#ifndef NOTSOUND
#ifdef SOUNDBYHAL
    if (sound == NULL)
    {
        ErrorLog("this sound doesn't exist");
    }
    else
    {
        playsound(sound->Handle, 0);
    }
#else
    // TODO fixed this by running a new process
    SOUND_THREAD_HANDLE* temp = NULL;
    temp = GetSoundHandleThatNotUsing();

    temp->IsUsing = 1;
    temp->SoundHandle = CreateThread(NULL, 0,
        (LPTHREAD_START_ROUTINE)PlaySingleSoundOnce, sound, 0, NULL);
#endif // SOUNDBYHAL
#endif // !NOTSOUND
}

#ifndef SOUNDBYHAL
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
#endif // !SOUNDBYHAL

void CheckAllSoundHasEnded()
{
#ifndef NOTSOUND
#ifdef SOUNDBYHAL
    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        if ((GetSoundFilesInMemBitesArray() + i)->IsUsing &&
            !(GetSoundFilesInMemBitesArray() + i)->AlwaysNeed &&
            !checksound(
                (GetSoundFilesInMemBitesArray() + i)->Handle))
        {
            UninstallSound(GetSoundFilesInMemBitesArray() + i);
        }
    }
#endif // SOUNDBYHAL
#endif // !NOTSOUND
}

#ifdef SOUNDBYHAL
void UninstallSound(SOUNDFILE_LOADED* sound)
#else
void UninstallSound(SOUNDFILE_IN_MEMBITE* sound)
#endif // SOUNDBYHAL
{
#ifndef NOTSOUND
#ifdef SOUNDBYHAL
    closesound(sound->Handle);
    *sound = SOUNDFILE_LOADED();
#else

#endif // SOUNDBYHAL
#endif // !NOTSOUND
}

void TurnOffSoundSys()
{
#ifndef NOTSOUND
#ifdef SOUNDBYHAL
    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        if ((GetSoundFilesInMemBitesArray() + i)->IsUsing)
        {
            stopsound((GetSoundFilesInMemBitesArray() + i)->Handle);
            UninstallSound(GetSoundFilesInMemBitesArray() + i);
        }
    }
#else
    PlayBackgroundMusic(NULL);
    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        delete[](GetSoundFilesInMemBitesArray() + i)->SoundFileInBites;
        delete[](GetSoundFilesInMemBitesArray() + i)->SoundFileInBitesWithVolume;
        *(GetSoundFilesInMemBitesArray() + i) = SOUNDFILE_IN_MEMBITE();
    }
#endif // SOUNDBYHAL
#endif // !NOTSOUND
}
