//------------------------------------------------------------------------
// ファイル名: AppNamingScene.h
// 機能: 名前付きシーンに関しての声明
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"
#include "AppDeclared.h"
#include "VisitorManager.h"
#include "VisitorShower.h"

int g_StartCreateVisitorFlg = 0;

void InitNamingScene()
{
    CreateSceneNode(SCENENODE("naming", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 30)));
    GetSceneNodeByName("naming")->SetBaseUIO(
        GetUIObjByName("naming"));
    ClearSceneCamBuffer(GetSceneNodeByName("naming"));

    g_StartCreateVisitorFlg = 0;
}

void UpdateNamingScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("naming"));

    if (!GetVisitorArray()->IsUsing)
    {
        ++g_StartCreateVisitorFlg;

        UIOBJECT* tempUIO = GetUIObjByName("create-visitors");
        if (tempUIO != NULL)
        {
            GetUIObjByName("naming")->AddChild(tempUIO);
            tempUIO->AddParent(GetUIObjByName("naming"));
            tempUIO->TurnOn();
            SetSelectedBtn(tempUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
    if (g_StartCreateVisitorFlg > 5)
    {
        g_StartCreateVisitorFlg = 0;
        CreateVisitors();
        SetShowVisitorFlg(1);

        UIOBJECT* tempUIO = GetUIObjByName("create-visitors");
        if (tempUIO != NULL)
        {
            tempUIO->TurnOff();
            SetSelectedBtn(tempUIO->ParentUIO->Buttons);
        }
        else
        {
            ErrorLog("cannot find this UI object");
        }
    }
}

void TurnOffNamingScene()
{

}
