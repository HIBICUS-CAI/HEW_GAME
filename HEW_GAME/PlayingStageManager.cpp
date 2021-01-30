#include "PlayingStageManager.h"
#include "AppDeclared.h"

void InitPlayingStage()
{
    ResetPlayingStage();
}

void UpdatePlayingStage()
{
    // ready to add stage effect here
}

void TurnOffPlayingStage()
{

}

int GetPlayingStageByManager()
{
    return GetPlayingStage();
}

void SetPlayingStageByManager(int stageID)
{
    SetPlayingStage(stageID);
}

void ResetPlayingStageByManager()
{
    ResetPlayingStage();
}
