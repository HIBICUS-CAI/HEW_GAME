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
