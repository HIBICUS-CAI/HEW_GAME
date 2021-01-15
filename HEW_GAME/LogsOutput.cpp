#include "LogsOutput.h"

void DebugLog(const char* text)
{
    char logText[512];
    sprintf_s(logText, sizeof(logText), "[DebugLog]::%s\n", text);
    OutputDebugStringA(logText);
}

void DebugLogI1(const char* text, const int value)
{
    char logText[512];
    sprintf_s(logText, sizeof(logText), "[DebugLog]::%s _ %d\n", 
        text, value);
    OutputDebugStringA(logText);
}

void DebugLogI2(const char* text, const int value1, const int value2)
{
    char logText[512];
    sprintf_s(logText, sizeof(logText), "[DebugLog]::%s _ %d _ %d\n", 
        text, value1, value2);
    OutputDebugStringA(logText);
}

void ErrorLog(const char* text)
{
    char logText[512];
    sprintf_s(logText, sizeof(logText), "[[ErrorLog]]::%s\n", text);
    OutputDebugStringA(logText);
}

void ErrorLogI1(const char* text, const int value)
{
    char logText[512];
    sprintf_s(logText, sizeof(logText), "[[ErrorLog]]::%s _ %d\n", 
        text, value);
    OutputDebugStringA(logText);
}

void ErrorLogI2(const char* text, const int value1, const int value2)
{
    char logText[512];
    sprintf_s(logText, sizeof(logText), "[[ErrorLog]]::%s _ %d _ %d\n", 
        text, value1, value2);
    OutputDebugStringA(logText);
}

void DebugLogToFile(const char* text)
{

}
