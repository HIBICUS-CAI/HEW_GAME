#include "AppDeclared.h"

SCENENODE g_SceneNodes[SCENENODESIZE];

SCENENODE* GetSceneNodeArray()
{
    return g_SceneNodes;
}

void SetSceneNodeArray(int index, SCENENODE temp)
{
    g_SceneNodes[index] = temp;
}

SCENENODE* gp_CurrScene = NULL;

void SetCurrScene(SCENENODE* sceneNode)
{
    gp_CurrScene = sceneNode;
}

SCENENODE* GetCurrScene()
{
    return gp_CurrScene;
}

int g_DiaglogEventID = 0;

int GetDialogEvent()
{
    return g_DiaglogEventID;
}

void SetDialogEvent(int id)
{
    g_DiaglogEventID = id;
}

int g_IsDialogFinish = 0;

int IsDialogFinish()
{
    return g_IsDialogFinish;
}

void SetIsDialogFinish(int value)
{
    g_IsDialogFinish = value;
}

int g_SwitchEffectFlag = 0;

int GetSwitchEffectFlag()
{
    return g_SwitchEffectFlag;
}

void SetSwitchEffectFlag(int value)
{
    g_SwitchEffectFlag = value;
}

int g_SwitchEffectStyle = 0;

int GetSwitchEffectStyle()
{
    return g_SwitchEffectStyle;
}

void SetSwitchEffectStyle(int value)
{
    g_SwitchEffectStyle = value;
}

DIALOG_EVENT g_DialogEvents[DIALOG_EVENT_SIZE];

void InitAndLoadDialogEvents()
{
    DIALOG_EVENT temp = DIALOG_EVENT();
    for (int i = 0; i < DIALOG_EVENT_SIZE; i++)
    {
        *(g_DialogEvents + i) = temp;
    }

    // ¤³¤³¤Ç¥Õ¥¡¥¤¥ë¥í©`¥É¤òÐÐ¤¦
    LoadSingleDialogEvnetFromID(DIALOG_NEW_GAME, "Assets\\DialogTexts\\new_game.txt");
}

void LoadSingleDialogEvnetFromID(int id, const char* path)
{
    DIALOG_EVENT* readyToWrite = NULL;
    for (int i = 0; i < DIALOG_EVENT_SIZE; i++)
    {
        if (g_DialogEvents[i].GetDialogEventID() == -1)
        {
            readyToWrite = g_DialogEvents + i;
            break;
        }
    }

    if (readyToWrite == NULL)
    {
        ErrorLog("you have used all of dialog event");
        return;
    }

    FILE* pFile = NULL;
    fopen_s(&pFile, path, "r");
    if (pFile == NULL)
    {
        ErrorLogI1("cannot load this file witch id is", id);
        return;
    }

    readyToWrite->DialogEventID = id;

    char tempStr[128] = "";
    int tempFlg = 0;
    int firstIndex = 0;
    int secondIndex = 0;
    while (1)
    {
        fscanf_s(pFile, "%s", tempStr, sizeof(tempStr));
        fscanf_s(pFile, "%d", &tempFlg);
        if (tempFlg == 1)
        {
            DebugLog("speaker: ");
            DebugLog(tempStr);
            strcpy_s(readyToWrite->GetSningleDialogByOffset(firstIndex)->GetSpeaker(),
                sizeof(tempStr), tempStr);
        }
        else if (tempFlg == 2)
        {
            DebugLog("sentence: ");
            DebugLog(tempStr);
            strcpy_s(readyToWrite->GetSningleDialogByOffset(firstIndex)->GetSingleSentenceByOffset(secondIndex),
                sizeof(tempStr), tempStr);
            ++secondIndex;
        }
        else if (tempFlg == 3)
        {
            DebugLog("final sentence but not end: ");
            DebugLog(tempStr);
            strcpy_s(readyToWrite->GetSningleDialogByOffset(firstIndex)->GetSingleSentenceByOffset(secondIndex),
                sizeof(tempStr), tempStr);
            secondIndex = 0;
            ++firstIndex;
        }
        else if (tempFlg == 4)
        {
            DebugLog("final sentence and end: ");
            DebugLog(tempStr);
            strcpy_s(readyToWrite->GetSningleDialogByOffset(firstIndex)->GetSingleSentenceByOffset(secondIndex),
                sizeof(tempStr), tempStr);
            secondIndex = 0;
            firstIndex = 0;
            break;
        }
        else
        {
            ErrorLogI1("cannot use this flag", tempFlg);
        }
    }
    fclose(pFile);
}

DIALOG_EVENT* GetDiaLogEventByEventID(int id)
{
    for (int i = 0; i < DIALOG_EVENT_SIZE; i++)
    {
        if (id == g_DialogEvents[i].GetDialogEventID())
        {
            return g_DialogEvents + i;
        }
    }

    ErrorLogI1("cannot find this event id", id);
    return NULL;
}

int g_PlayingStageID = 0;

int GetPlayingStage()
{
    return g_PlayingStageID;
}

void SetPlayingStage(int stageID)
{
    g_PlayingStageID = stageID;
}

void ResetPlayingStage()
{
    g_PlayingStageID = 0;
}

VISITOR_NODE g_VisitorsArray[VISITOR_MAX_SIZE];

VISITOR_NODE* GetVisitorArray()
{
    return g_VisitorsArray;
}

char g_SubName1[15][17];
char g_SubName2[15][17];
char g_Nothing[17]="£Ø£Ø£Ø£Ø£Ø£Ø";

char* GetSubName1ArrayByOffset(int offset)
{
    if (offset < 15 && offset >= 0)
    {
        return g_SubName1[offset];
    }
    else if (offset == -1)
    {
        return g_Nothing;
    }
    else
    {
        ErrorLogI1("this offset overflow:", offset);
    }
}

char* GetSubName2ArrayByOffset(int offset)
{
    if (offset < 15 && offset >= 0)
    {
        return g_SubName2[offset];
    }
    else if (offset == -1)
    {
        return g_Nothing;
    }
    else
    {
        ErrorLogI1("this offset overflow:", offset);
    }
}

int g_ConfirmedName[2];

int* GetConfirmedSubName1And2()
{
    return g_ConfirmedName;
}

void SetConfirmedSubName1(int value)
{
    g_ConfirmedName[0] = value;
}

void SetConfirmedSubName2(int value)
{
    g_ConfirmedName[1] = value;
}
