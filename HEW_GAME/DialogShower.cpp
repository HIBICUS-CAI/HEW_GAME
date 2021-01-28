#include "DialogShower.h"
#include "AppDeclared.h"
#include "SceneNode.h"
#include "SpriteAnimator.h"

int g_DialogIndex = 0;
DIALOG_EVENT* gp_GoingDialogEvent = NULL;
SPRITE g_TalkPeopleSprites[PEOPLE_SPRITE_SIZE];
SPRITE_ANIME g_TalkPeopleSprAni[PEOPLE_SPRITE_SIZE];
SPRITE* g_UsingTalkPeopleSprites = NULL;
SPRITE_ANIME* g_UsingTalkPeopleSprAni = NULL;
int g_TimeCount = 0;
int g_LoadedIndex = 0;
int g_SAFlag = 0;

#define CHARA_YUKICHI 0
#define CHARA_LUXUN 1
#define CHARA_EINSTEIN 2

void InitDialogShower()
{
    SetIsDialogFinish(1);
    SetDialogEvent(DIALOG_NOTHING);
    SetDialogIndex(0);
    gp_GoingDialogEvent = NULL;
    g_SAFlag = 0;
    g_TalkPeopleSprites[g_LoadedIndex] = CreateSingleSprite("Assets\\Sprites\\yukichi.txt",
        POSITION_2D(0, 0), 58, 35);
    g_TalkPeopleSprAni[g_LoadedIndex] = CreateSpriteAnimator(8,
        "Assets\\SpriteAnimators\\yukichi\\yukichi", POSITION_2D(0, 0), 58, 38);
    ++g_LoadedIndex;

    g_TalkPeopleSprites[g_LoadedIndex] = CreateSingleSprite("Assets\\Sprites\\luxun.txt",
        POSITION_2D(0, 0), 57, 35);
    g_TalkPeopleSprAni[g_LoadedIndex] = CreateSpriteAnimator(8,
        "Assets\\SpriteAnimators\\luxun\\luxun", POSITION_2D(0, 0), 57, 38);
    ++g_LoadedIndex;

    g_TalkPeopleSprites[g_LoadedIndex] = CreateSingleSprite("Assets\\Sprites\\einstein.txt",
        POSITION_2D(0, 0), 57, 35);
    g_TalkPeopleSprAni[g_LoadedIndex] = CreateSpriteAnimator(8,
        "Assets\\SpriteAnimators\\einstein\\einstein", POSITION_2D(0, 0), 57, 38);
    ++g_LoadedIndex;

    g_LoadedIndex = 0;
}

void UpdateDialogShower()
{
    if (IsDialogFinish())
    {
        int dialogEventID = GetDialogEvent();
        if (dialogEventID == DIALOG_NOTHING)
        {
            ErrorLog("you should not load dialog scene without a meanful event");
        }
        else if (dialogEventID == DIALOG_NEW_GAME)
        {
            DebugLog("ready to go to new game dialog");
            gp_GoingDialogEvent = GetDiaLogEventByEventID(DIALOG_NEW_GAME);
            if (gp_GoingDialogEvent != NULL)
            {
                SetIsDialogFinish(0);
            }
        }
        else
        {
            ErrorLogI1("cannot find this dialog ID", dialogEventID);
        }
    }
    else
    {
        UIOBJECT* dialog = GetSceneNodeByName("dialog")->GetBaseUIOAddr();
        char preName[16] = "";
        strcpy_s(preName, sizeof(dialog->Texts->Text), dialog->Texts->Text);
        (dialog->Texts)->ChangeTextTo(
            gp_GoingDialogEvent->GetSningleDialogByOffset(
                GetDialogIndex())->GetSpeaker());
        for (int i = 0; i < SINGLE_TURN_COUNT; i++)
        {
            (dialog->Texts + i + 2)->ChangeTextTo(
                gp_GoingDialogEvent->GetSningleDialogByOffset(
                    GetDialogIndex())->GetSingleSentenceByOffset(i));
        }

        if (!strcmp(dialog->Texts->Text, "���ʤ�"))
        {
            if (strcmp(preName, dialog->Texts->Text))
            {
                if (g_SAFlag)
                {
                    g_SAFlag = 0;
                }
                else
                {
                    g_SAFlag = 1;
                }
                g_UsingTalkPeopleSprAni = g_TalkPeopleSprAni + CHARA_LUXUN;
                if (!strcmp(preName, "������"))
                {
                    g_UsingTalkPeopleSprites = g_TalkPeopleSprites + CHARA_YUKICHI;
                }
                else if (!strcmp(preName, "��ʹ"))
                {
                    g_UsingTalkPeopleSprites = g_TalkPeopleSprites + CHARA_EINSTEIN;
                }
            }
        }
        else if (!strcmp(dialog->Texts->Text, "������"))
        {
            if (strcmp(preName, dialog->Texts->Text))
            {
                if (g_SAFlag)
                {
                    g_SAFlag = 0;
                }
                else
                {
                    g_SAFlag = 1;
                }
                g_UsingTalkPeopleSprAni = g_TalkPeopleSprAni + CHARA_YUKICHI;
                if (!strcmp(preName, "���ʤ�"))
                {
                    g_UsingTalkPeopleSprites = g_TalkPeopleSprites + CHARA_LUXUN;
                }
                else if (!strcmp(preName, "��ʹ"))
                {
                    g_UsingTalkPeopleSprites = g_TalkPeopleSprites + CHARA_EINSTEIN;
                }
            }
        }
        else if (!strcmp(dialog->Texts->Text, "��ʹ"))
        {
            if (strcmp(preName, dialog->Texts->Text))
            {
                if (g_SAFlag)
                {
                    g_SAFlag = 0;
                }
                else
                {
                    g_SAFlag = 1;
                }
                g_UsingTalkPeopleSprAni = g_TalkPeopleSprAni + CHARA_EINSTEIN;
                if (!strcmp(preName, "���ʤ�"))
                {
                    g_UsingTalkPeopleSprites = g_TalkPeopleSprites + CHARA_LUXUN;
                }
                else if (!strcmp(preName, "������"))
                {
                    g_UsingTalkPeopleSprites = g_TalkPeopleSprites + CHARA_YUKICHI;
                }
            }
        }

        // �Х��������ˤ��뤫��
        if (g_SAFlag)
        {
            if (g_UsingTalkPeopleSprites != NULL)
            {
                DrawSingleSpriteToCamBuffer(GetSceneNodeByName("dialog")->GetCamAddr(),
                    g_UsingTalkPeopleSprites, POSITION_2D(105, 2));
            }
            if (g_UsingTalkPeopleSprAni != NULL)
            {
                DrawSpriteAnimatorToCamBuffer(GetSceneNodeByName("dialog")->GetCamAddr(),
                    g_UsingTalkPeopleSprAni, (g_TimeCount++) % 60, POSITION_2D(15, 1));
            }
        }
        else
        {
            if (g_UsingTalkPeopleSprites != NULL)
            {
                DrawSingleSpriteToCamBuffer(GetSceneNodeByName("dialog")->GetCamAddr(),
                    g_UsingTalkPeopleSprites, POSITION_2D(15, 2));
            }
            if (g_UsingTalkPeopleSprAni != NULL)
            {
                DrawSpriteAnimatorToCamBuffer(GetSceneNodeByName("dialog")->GetCamAddr(),
                    g_UsingTalkPeopleSprAni, (g_TimeCount++) % 60, POSITION_2D(105, 1));
            }
        }
    }
}

void TurnOffDialogShower()
{

}

int GetDialogIndex()
{
    return g_DialogIndex;
}

void SetDialogIndex(int value)
{
    g_DialogIndex = value;
}

void ResetUsingPointerAndFlag()
{
    // �Х��������ˤ��뤫��
    g_UsingTalkPeopleSprites = NULL;
    g_UsingTalkPeopleSprAni = NULL;
    g_SAFlag = 0;
    SetDialogIndex(0);
    SetIsDialogFinish(1);
    SetDialogEvent(DIALOG_NOTHING);
}
