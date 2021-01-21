#include <fstream>
#include "Tools.h"
#include "DeclaredValues.h"

void SetDeltaTime(int time)
{
    SetDeclaredDeltaTime(time);
}

int GetDeltaTime()
{
    return GetDeclaredDeltaTime();
}

int GetRealDeltaTime()
{
    if (GetDeltaTime() < 16)
    {
        return DELTATIME;
    }
    else
    {
        return GetDeltaTime();
    }
}

void ShowFPSMT()
{
    while (1)
    {
        char command[100];
        int deltaTime = GetDeltaTime();
        if (deltaTime == 0)
        {
            ++deltaTime;
        }
        sprintf_s(command, sizeof(command),
            "title ¤È¤¢¤ë¥²©`¥à¡¡FPS: %d", 1000 / deltaTime);
        system(command);
        Sleep(64);
    }
}

void InitTitle()
{
    system("title ¤È¤¢¤ë¥²©`¥à");

    /*DWORD dw;
    g_HandleTitle = CreateThread(NULL, 0,
        (LPTHREAD_START_ROUTINE)ShowFPSMT, NULL, 0, &dw);*/
}

void CloseTitle()
{
    //CloseHandle(g_HandleTitle);
}

int GetIntValueBit(int value)
{
    int flag = 0;
    int bits = 0;
    int baseNum = 1;
    while (flag == 0)
    {
        flag = value / baseNum;
        if (flag != 0)
        {
            ++bits;
            baseNum *= 10;
        }
    }

    return bits;
}

QSINGLENODE* CreateQueue()
{
    QSINGLENODE* queue = (QSINGLENODE*)malloc(sizeof(QSINGLENODE));
    queue->Next = NULL;

    QUEUE_INT queueFlagNode{ queue,queue };

    return queue;
}

QSINGLENODE* EnQueue(QSINGLENODE* end, int data)
{
    QSINGLENODE* enElem = (QSINGLENODE*)malloc(sizeof(QSINGLENODE));
    enElem->Data = data;
    enElem->Next = NULL;
    end->Next = enElem;
    end = enElem;

    return end;
}

int DeQueue(QSINGLENODE* top, QSINGLENODE* end)
{
    if (top->Next == NULL)
    {
        return -1;
    }
    QSINGLENODE* node = top->Next;
    int temp = node->Data;
    top->Next = node->Next;
    if (end == node)
    {
        end = top;
    }
    free(node);

    return temp;
}

void SetRandomBySeed(int seedNum)
{
    srand(seedNum);
}

void SetRandom()
{
    srand((int)time(NULL));
}

int CreateRandomNumIn(int minNum, int maxNum)
{
    return rand() % (maxNum - minNum + 1) + minNum;
}

void ChangeColorInConsole(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ResetColorInConsole()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK_WHITE);
}

int RoundFloatToInt(float value)
{
    float decimal = value - (float)((int)value);
    if (decimal < 0.5f)
    {
        return (int)value;
    }
    else
    {
        return (int)value + 1;
    }
}

void ReadWavFileIntoMemory(const char* fname, BYTE** pMemBites, DWORD* fileSize)
{
    std::ifstream file(fname, std::ios::binary);

    file.seekg(0, std::ios::end);
    int lim = file.tellg();
    *fileSize = lim;

    *pMemBites = new BYTE[lim];
    file.seekg(0, std::ios::beg);

    file.read((char*)*pMemBites, lim);

    file.close();
}
