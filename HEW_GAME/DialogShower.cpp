#include "DialogShower.h"
#include "AppDeclared.h"
#include "SceneNode.h"

int g_DialogIndex = 0;
DIALOG_EVENT* gp_GoingDialogEvent = NULL;

void InitDialogShower()
{
    SetIsDialogFinish(1);
    SetDialogEvent(DIALOG_NOTHING);
    SetDialogIndex(0);
    gp_GoingDialogEvent = NULL;
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
        (dialog->Texts)->ChangeTextTo(
            gp_GoingDialogEvent->GetSningleDialogByOffset(
                GetDialogIndex())->GetSpeaker());
        for (int i = 0; i < SINGLE_TURN_COUNT; i++)
        {
            (dialog->Texts + i + 2)->ChangeTextTo(
                gp_GoingDialogEvent->GetSningleDialogByOffset(
                    GetDialogIndex())->GetSingleSentenceByOffset(i));
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
