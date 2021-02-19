#include "ConsolePrint.h"
#include "DefinedValues.h"
#include "LogsOutput.h"
#include "Tools.h"
#include "DeclaredValues.h"
#include "UIObject.h"

#include "CustomizedApp.h"

CRITICAL_SECTION g_CSPrint;

CRITICAL_SECTION* GetPrintCS()
{
    return &g_CSPrint;
}

void InitOutputBuffer()
{
    CONSOLE_CURSOR_INFO cur;
    cur.dwSize = 1;
    cur.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);

    char changeConsoleSize[512];
    sprintf_s(changeConsoleSize, sizeof(changeConsoleSize),
        "mode con cols=%d lines=%d", CONSOLE_WIDTH, CONSOLE_HEIGHT + 1);
    system(changeConsoleSize);

#ifdef MUTIPRINT
    InitializeCriticalSection(GetSwapChainCS());
    InitializeCriticalSection(GetPrintCS());

    DWORD dw;
    SetPrintHandle(CreateThread(NULL, 0,
        (LPTHREAD_START_ROUTINE)PrintOutputBuffer,
        NULL, CREATE_SUSPENDED, &dw));
#endif // MUTIPRINT

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH - 1; j++)
        {
            *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + j) = '_';
        }
        *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + CONSOLE_WIDTH - 1) = '\0';
    }

    //----------------------------------------------------
    /*CreateUIO("parent", POSITION_2D(3, 20), 60, 15, UIO_DESIGN::STRAIGHT);
    GetUIObjByID(10000)->AddText(UI_TEXT(POSITION_2D(1, 1),
        (char*)"アホマン"));
    GetUIObjByName("parent")->TurnOn();
    GetUIObjByName("parent")->AddBtn(UI_BUTTON(TEST_OPENSUB, POSITION_2D(3, 3),
        (char*)"開く", BTN_DESIGN::LINE));
    GetUIObjByName("parent")->AddBtn(UI_BUTTON(0, POSITION_2D(10, 7),
        (char*)"閉じる", BTN_DESIGN::STRAIGHT));
    SetSelectedBtn(GetUIObjByName("parent")->Buttons + 0);*/
}

void ClearOutputBuffer()
{
    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH - 1; j++)
        {
            *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + j) = ' ';
        }
        *(GetOutputBufferToUpdate() + i * CONSOLE_WIDTH + CONSOLE_WIDTH - 1) = '\0';
    }
}

void PrintOutputBuffer()
{
#ifdef MUTIPRINT
    EnterCriticalSection(GetPrintCS());

    while (1)
    {
        int start = clock();
        //system("cls");
        COORD ppp;
        ppp.X = 0;
        ppp.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ppp);
        if (GetSelectedBtn() != NULL &&
            GetSelectedBtn()->ID != -1)
        {
            UI_BUTTON temp = *(GetSelectedBtn());
            for (int i = 0; i < CONSOLE_HEIGHT; i++)
            {
                printf("%s\n", GetOutputBufferToPrint() + i * CONSOLE_WIDTH);
            }

            if (temp.BorderDesign == BTN_DESIGN::LINE)
            {
                COORD position;
                position.X = temp.Position.posX - 2;
                position.Y = temp.Position.posY;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
                ChangeColorInConsole(WHITE_BLACK);
                printf("--%s--", temp.Text);
                ResetColorInConsole();
            }
            else if (temp.BorderDesign == BTN_DESIGN::STRAIGHT)
            {
                COORD position;
                position.X = temp.Position.posX - 2;
                position.Y = temp.Position.posY;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
                printf("【%s】", temp.Text);
            }
        }
        else
        {
            for (int i = 0; i < CONSOLE_HEIGHT; i++)
            {
                printf("%s\n", GetOutputBufferToPrint() +
                    i * CONSOLE_WIDTH);
            }
        }

        AppPostPrint();

        LeaveCriticalSection(GetPrintCS());

        int end = clock();
        //DebugLogI1("time:", end - start);

        if (end - start < DELTATIME)
        {
            Sleep(DELTATIME - end + start);
        }
        SuspendThread(GetPrintHandle());
    }
#else
    system("cls");

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        printf("%s\n", GetOutputBufferToPrint() + i * CONSOLE_WIDTH);
    }
#endif // MUTIPRINT

    return;
}

void CloseMTPrint()
{
    DeleteCriticalSection(GetPrintCS());
    CloseHandle(GetPrintHandle());
}

void UpdateOutputBuffer()
{
    ClearOutputBuffer();
}

#ifdef MY_DEBUG_INFO
void ShowFPSAtScreen()
{
    int deltaTime = GetDeltaTime();
    if (!deltaTime)
    {
        ++deltaTime;
    }

    int fps = 1000 / deltaTime;
    if (fps <= 100)
    {
        WriteStrInt1IntoOutputBufferByPos(POSITION_2D(0, 0),
            "更新用FPS", fps);
    }
    else
    {
        WriteStrIntoOutputBufferByPos(POSITION_2D(0, 0),
            "更新用FPS: 100+");
    }
}
#endif // SHOWFPS

void WriteCharIntoOutputBuffer(POSITION_2D position, const char text)
{
    if (position.posX > CONSOLE_WIDTH)
    {
        ErrorLogI2(
            "overflow when writing string into ouput buffer at position",
            position.posX, position.posY);
    }
    *(GetOutputBufferToUpdate() + position.posY * CONSOLE_WIDTH + position.posX) = text;
}

void WriteStrIntoOutputBufferByPos(POSITION_2D startPos, const char* text)
{
    int size = 0;
    while (text[size] != '\0')
    {
        ++size;
    }
    for (int i = 0; i < size; i++)
    {
        if (startPos.posX + i > CONSOLE_WIDTH)
        {
            ErrorLogI2(
                "overflow when writing string into ouput buffer at position",
                startPos.posX, startPos.posY);
        }
        *(GetOutputBufferToUpdate() + startPos.posY * CONSOLE_WIDTH + startPos.posX + i) = text[i];
    }
}

void WriteStrInt1IntoOutputBufferByPos(POSITION_2D startPos, const char* text, int value)
{
    char temp[512];
    sprintf_s(temp, sizeof(temp), "%s : %d", text, value);

    int size = 0;
    while (temp[size] != '\0')
    {
        ++size;
    }
    for (int i = 0; i < size; i++)
    {
        if (startPos.posX + i > CONSOLE_WIDTH)
        {
            ErrorLogI2(
                "overflow when writing string into ouput buffer at position",
                startPos.posX, startPos.posY);
        }
        *(GetOutputBufferToUpdate() + startPos.posY * CONSOLE_WIDTH + startPos.posX + i) = temp[i];
    }
}
