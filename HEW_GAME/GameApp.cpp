#include "GameApp.h"
#include "ConsolePrint.h"
#include "LogsOutput.h"
#include "DefinedValues.h"
#include "InputDispose.h"
#include "UIObject.h"
#include "Tools.h"
#include "CustomizedApp.h"
#include "SoundManager.h"

int Init()
{
    system("mode con cp select=932&&cls");

    SetGameRunFlag(1);

    ResetColorInConsole();

    InitUIObj();
    InitInputQueue();
    InitOutputBuffer();
    InitTitle();
    InitSoundSys();

    AppInit();

    //----------------------------------------------------
    /*GetUIObjByID(10000)->AddChild(
        CreateUIO("child", POSITION_2D(3, 3), 60, 15, UIO_DESIGN::STRAIGHT, 0));
    GetUIObjByID(10001)->AddParent(GetUIObjByID(10001));
    GetUIObjByID(10001)->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"アホアホマン"));
    GetUIObjByName("child")->AddBtn(UI_BUTTON(0, POSITION_2D(3, 3),
        (char*)"ボタン1", BTN_DESIGN::LINE));
    GetUIObjByName("child")->AddBtn(UI_BUTTON(0, POSITION_2D(9, 4),
        (char*)"ボタン2", BTN_DESIGN::LINE));
    GetUIObjByName("child")->AddBtn(UI_BUTTON(TEST_CLOSETHIS, POSITION_2D(10, 7),
        (char*)"閉じる", BTN_DESIGN::STRAIGHT));*/

    return 1;
}

void RunGame()
{
    SetGameRunFlag(1);

    while (GetGameRunFlag())
    {
        int startTime = clock();

        Input();
        if (GetGameRunFlag())
        {
#ifdef MUTIPRINT
            ResumeThread(GetPrintHandle());
            Update();
#else
            Update();
            Draw();
#endif // MUTIPRINT
#ifdef MY_DEBUG_INFO
            ShowFPSAtScreen();
#endif // SHOWFPS
            SwapPrintChain();
        }
        int endTime = clock();

        SetDeltaTime(endTime - startTime);

#ifdef LOCKFPS
        if (GetDeltaTime() < DELTATIME)
        {
            Sleep(DELTATIME - GetDeltaTime());
        }
#endif // LOCKFPS

    }
}

void TurnOff()
{
    TurnOffMTInput();
    CloseTitle();
    TurnOffSoundSys();
#ifdef MUTIPRINT
    CloseMTPrint();
    DeleteCriticalSection(GetSwapChainCS());
#endif // MUTIPRINT

    AppTurnOff();

    system("cls");
}

void Update()
{
#ifdef MUTIPRINT
    EnterCriticalSection(GetSwapChainCS());
#endif // MUTIPRINT

    UpdateOutputBuffer();
    CheckAllSoundHasEnded();
    AppUpdate();

    //----------------------------------------------------
    /*DrawUIO(GetUIObjByName("parent"));*/

#ifdef MUTIPRINT
    LeaveCriticalSection(GetSwapChainCS());
#endif // MUTIPRINT

}

void Draw()
{
    PrintOutputBuffer();
}
