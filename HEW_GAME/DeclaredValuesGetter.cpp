#include "DeclaredValues.h"

int g_GameRunFlag = 1;

void SetGameRunFlag(int value)
{
    if (g_GameRunFlag == NULL)
    {
        int temp = 1;
        g_GameRunFlag = temp;
    }

    if (value == 0)
    {
        g_GameRunFlag = 0;
    }
    else
    {
        g_GameRunFlag = 1;
    }
}

int GetGameRunFlag()
{
    return g_GameRunFlag;
}

int g_DeltaTime = DELTATIME;

int GetDeclaredDeltaTime()
{
    return g_DeltaTime;
}

void SetDeclaredDeltaTime(int value)
{
    g_DeltaTime = value;
}

char g_OutputBuffer[2][CONSOLE_HEIGHT * CONSOLE_WIDTH];
int g_SwapFlag = 0;
static HANDLE g_HandlePrint = NULL;

HANDLE GetPrintHandle()
{
    return g_HandlePrint;
}

void SetPrintHandle(HANDLE handle)
{
    g_HandlePrint = handle;
}

void SwapPrintChain()
{
    if (g_SwapFlag == 1)
    {
        g_SwapFlag = 0;
    }
    else if (g_SwapFlag == 0)
    {
        g_SwapFlag = 1;
    }
}

char* GetOutputBufferToPrint()
{
    return g_OutputBuffer[g_SwapFlag];
}

char* GetOutputBufferToUpdate()
{
    if (g_SwapFlag)
    {
        return g_OutputBuffer[g_SwapFlag - 1];
    }
    else
    {
        return g_OutputBuffer[g_SwapFlag + 1];
    }
}

UIOBJECT g_UIObjs[UIOBJSIZE];
int g_UIObjIndex;

UIOBJECT* GetUIObj()
{
    return g_UIObjs;
}

int* GetUIOIndex()
{
    return &g_UIObjIndex;
}

void SetUIOIndex(int value)
{
    *GetUIOIndex() = value;
}

void AddUIOIndex()
{
    ++g_UIObjIndex;
}

UIOBJECT* g_TopUIObj;

UIOBJECT* GetTopUIO()
{
    return g_TopUIObj;
}

void SetTopUIO(UIOBJECT* uiObj)
{
    g_TopUIObj = uiObj;
}

UI_BUTTON* g_SelectedBtn = NULL;
int g_AutoSelectBtnFlag = 0;

UI_BUTTON* GetSelectedBtn()
{
    return g_SelectedBtn;
}

void SetSelectedBtn(UI_BUTTON* btn)
{
    if (btn == NULL)
    {
        return;
    }
    g_SelectedBtn = btn;
}

int* GetAutoSelectBtnFlag()
{
    return &g_AutoSelectBtnFlag;
}

void SetAutoSelectBtnFlag(int value)
{
    g_AutoSelectBtnFlag = value;
}

SOUNDFILE_IN_MEMBITE g_LoadedSoundInBites[SOUNDFILE_SIZE];

SOUNDFILE_IN_MEMBITE* GetSoundFilesInMemBitesArray()
{
    return g_LoadedSoundInBites;
}

SOUNDFILE_IN_MEMBITE* GetSoundFilesInMemBites(const char* fileName)
{
    for (int i = 0; i < SOUNDFILE_SIZE; i++)
    {
        if (!(strcmp(g_LoadedSoundInBites[i].SoundName, fileName)) && g_LoadedSoundInBites[i].IsUsing)
        {
            return g_LoadedSoundInBites + i;
        }
    }

    ErrorLog("cannot find this sound bites, plz try angin");
    return NULL;
}
