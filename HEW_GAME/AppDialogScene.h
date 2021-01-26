//------------------------------------------------------------------------
// ファイル名: AppDialogScene.h
// 機能: 話し合いシーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"

void InitDialogScene()
{
    CreateSceneNode(SCENENODE("dialog", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 40)));
    GetSceneNodeByName("dialog")->SetBaseUIO(GetUIObjByName("dialog"));
    ClearSceneCamBuffer(GetSceneNodeByName("dialog"));
}

void UpdateDialogScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("dialog"));

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
            SetIsDialogFinish(0);
        }
        else
        {
            ErrorLogI1("cannot find this dialog ID", dialogEventID);
        }
    }
}

void TurnOffDialogScene()
{

}
