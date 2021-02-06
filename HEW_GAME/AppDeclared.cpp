#include "AppDeclared.h"
#include "SpriteAnimator.h"

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
char g_Nothing[17] = "£Ø£Ø£Ø£Ø£Ø£Ø";

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
        return NULL;
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
        return NULL;
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

int g_CurrBuildingPos;
BUILDING g_EditBuildingsArray[BUILDINGS_SIZE];

void SetCurrBuildingPos(int value)
{
    if (value > BUILDINGS_SIZE || value < 0)
    {
        ErrorLogI1("this pos has overflowed:", value);
        return;
    }
    g_CurrBuildingPos = value;
}

int GetCurrBuildingPos()
{
    return g_CurrBuildingPos;
}

BUILDING* GetEditBuildingsArray()
{
    return g_EditBuildingsArray;
}

SPRITE g_HillsInStage1[2];
SPRITE_ANIME g_SunCloudInStage1[4];
SPRITE_ANIME g_SunCloudInStage2[4];
SPRITE_ANIME g_MoonCloudInStage3[4];
SPRITE_ANIME g_Lake[9];
SPRITE_ANIME g_Beach[9];
SPRITE_ANIME g_Desert[9];
SPRITE g_BuildSceneBase[10];
SPRITE g_ResortSceneBase[11];

void LoadHill()
{
    g_HillsInStage1[0] = CreateSingleSprite(
        "Assets\\Sprites\\hill1.txt", POSITION_2D(0, 0),
        30, 10);
    g_HillsInStage1[1] = CreateSingleSprite(
        "Assets\\Sprites\\hill2.txt", POSITION_2D(150, 0),
        30, 10);
}

void LoadSunMoonCloud1()
{
    g_SunCloudInStage1[0] = CreateSpriteAnimator(4,
        "Assets\\SpriteAnimators\\sun\\sun",
        POSITION_2D(100, -2), 20, 10);
    g_SunCloudInStage1[1] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud1-",
        POSITION_2D(40, 2), 17, 5);
}

void LoadSunMoonCloud2()
{
    g_SunCloudInStage1[2] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud3-",
        POSITION_2D(80, 4), 17, 5);
    g_SunCloudInStage1[3] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud5-",
        POSITION_2D(130, 1), 20, 5);
}

void LoadSunMoonCloud3()
{
    g_SunCloudInStage2[0] = CreateSpriteAnimator(4,
        "Assets\\SpriteAnimators\\sun\\sun",
        POSITION_2D(70, 14), 20, 10);
    g_SunCloudInStage2[1] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud1-",
        POSITION_2D(40, 2), 17, 5);
}

void LoadSunMoonCloud4()
{
    g_SunCloudInStage2[2] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud3-",
        POSITION_2D(80, 4), 17, 5);
    g_SunCloudInStage2[3] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud5-",
        POSITION_2D(130, 1), 20, 5);
}

void LoadSunMoonCloud5()
{
    g_MoonCloudInStage3[0] = CreateSpriteAnimator(10,
        "Assets\\SpriteAnimators\\moon\\moon",
        POSITION_2D(90, 0), 20, 10);
    g_MoonCloudInStage3[1] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud1-",
        POSITION_2D(10, 2), 17, 5);
}

void LoadSunMoonCloud6()
{
    g_MoonCloudInStage3[2] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud3-",
        POSITION_2D(40, 4), 17, 5);
    g_MoonCloudInStage3[3] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\cloud\\cloud5-",
        POSITION_2D(130, 1), 20, 5);
}

void LoadBase1()
{
    for (int i = 0; i < 10; i++)
    {
        g_BuildSceneBase[i] = CreateSingleSprite(
            "Assets\\Sprites\\building-base.txt",
            POSITION_2D(100 + i * 60, 38),
            40, 2
        );
    }
}

void LoadBase2()
{
    for (int i = 0; i < 11; i++)
    {
        g_ResortSceneBase[i] = CreateSingleSprite(
            "Assets\\Sprites\\building-base.txt",
            POSITION_2D(70 + i * 54, 38),
            40, 2
        );
    }
}

void LoadLakePart1()
{
    g_Lake[0] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake1-",
        POSITION_2D(0, 0), 30, 30);
    g_Lake[1] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake2-",
        POSITION_2D(30, 0), 30, 30);
    g_Lake[2] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake3-",
        POSITION_2D(60, 0), 30, 30);
}

void LoadLakePart2()
{
    g_Lake[3] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake4-",
        POSITION_2D(90, 0), 30, 30);
    g_Lake[4] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake5-",
        POSITION_2D(120, 0), 30, 30);
    g_Lake[5] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake6-",
        POSITION_2D(150, 0), 30, 30);
}

void LoadLakePart3()
{
    g_Lake[6] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake7-",
        POSITION_2D(180, 0), 30, 30);
    g_Lake[7] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake8-",
        POSITION_2D(210, 0), 30, 30);
    g_Lake[8] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\lake\\lake9-",
        POSITION_2D(240, 0), 30, 30);
}

void LoadSeaPart1()
{
    g_Beach[0] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea1-",
        POSITION_2D(0, 0), 30, 30);
    g_Beach[1] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea2-",
        POSITION_2D(30, 0), 30, 30);
    g_Beach[2] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea3-",
        POSITION_2D(60, 0), 30, 30);
}

void LoadSeaPart2()
{
    g_Beach[3] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea4-",
        POSITION_2D(90, 0), 30, 30);
    g_Beach[4] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea5-",
        POSITION_2D(120, 0), 30, 30);
    g_Beach[5] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea6-",
        POSITION_2D(150, 0), 30, 30);
}

void LoadSeaPart3()
{
    g_Beach[6] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea7-",
        POSITION_2D(180, 0), 30, 30);
    g_Beach[7] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea8-",
        POSITION_2D(210, 0), 30, 30);
    g_Beach[8] = CreateSpriteAnimator(6,
        "Assets\\SpriteAnimators\\sea\\sea9-",
        POSITION_2D(240, 0), 30, 30);
}

void LoadSandPart1()
{
    g_Desert[0] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand1-",
        POSITION_2D(0, 0), 30, 30);
    g_Desert[1] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand2-",
        POSITION_2D(30, 0), 30, 30);
    g_Desert[2] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand3-",
        POSITION_2D(60, 0), 30, 30);
}

void LoadSandPart2()
{
    g_Desert[3] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand4-",
        POSITION_2D(90, 0), 30, 30);
    g_Desert[4] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand5-",
        POSITION_2D(120, 0), 30, 30);
    g_Desert[5] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand6-",
        POSITION_2D(150, 0), 30, 30);
}

void LoadSandPart3()
{
    g_Desert[6] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand7-",
        POSITION_2D(180, 0), 30, 30);
    g_Desert[7] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand8-",
        POSITION_2D(210, 0), 30, 30);
    g_Desert[8] = CreateSpriteAnimator(5,
        "Assets\\SpriteAnimators\\sand\\sand9-",
        POSITION_2D(240, 0), 30, 30);
}

void InitAndLoadBGSprite()
{
    SPRITE* temp1 = new SPRITE();
    SPRITE_ANIME* temp2 = new SPRITE_ANIME();
    for (int i = 0; i < 2; i++)
    {
        g_HillsInStage1[i] = *temp1;
    }
    for (int i = 0; i < 4; i++)
    {
        g_SunCloudInStage1[i] = *temp2;
        g_SunCloudInStage2[i] = *temp2;
        g_MoonCloudInStage3[i] = *temp2;
    }
    for (int i = 0; i < 9; i++)
    {
        g_Lake[i] = *temp2;
        g_Beach[i] = *temp2;
        g_Desert[i] = *temp2;
    }
    for (int i = 0; i < 10; i++)
    {
        g_BuildSceneBase[i] = *temp1;
    }
    for (int i = 0; i < 11; i++)
    {
        g_ResortSceneBase[i] = *temp1;
    }
    delete temp1;
    delete temp2;

    LoadHill();
    LoadSunMoonCloud1();
    LoadSunMoonCloud2();
    LoadSunMoonCloud3();
    LoadSunMoonCloud4();
    LoadSunMoonCloud5();
    LoadSunMoonCloud6();
    LoadBase1();
    LoadBase2();
    LoadLakePart1();
    LoadLakePart2();
    LoadLakePart3();
    LoadSeaPart1();
    LoadSeaPart2();
    LoadSeaPart3();
    LoadSandPart1();
    LoadSandPart2();
    LoadSandPart3();
}

SPRITE* GetHillsInStage1()
{
    return g_HillsInStage1;
}

SPRITE_ANIME* GetSunCloudInStage1()
{
    return g_SunCloudInStage1;
}

SPRITE_ANIME* GetSunCloudInStage2()
{
    return g_SunCloudInStage2;
}

SPRITE_ANIME* GetMoonCloudInStage3()
{
    return g_MoonCloudInStage3;
}

SPRITE_ANIME* GetLakeSAs()
{
    return g_Lake;
}

SPRITE_ANIME* GetBeachSAs()
{
    return g_Beach;
}

SPRITE_ANIME* GetDesertSAs()
{
    return g_Desert;
}

SPRITE* GetBuildSceneBase()
{
    return g_BuildSceneBase;
}

SPRITE* GetResortSceneBase()
{
    return g_ResortSceneBase;
}
