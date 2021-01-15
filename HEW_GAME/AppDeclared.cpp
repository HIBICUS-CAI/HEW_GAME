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
