#include "SceneManager.h"
#include "AppDeclared.h"

#define TITLESCENEFLAG 1
#define SELECTIONSCENEFLAG 2
#define MAZESCENEFLAG 3
#define BATTLESCENEFLAG 4
#define INPUTSCENEFLAG 5
int g_SceneFlag;

void SetSceneFlag(int flag)
{
    g_SceneFlag = flag;
}

int GetSceneFlag()
{
    return g_SceneFlag;
}

void SetManagedCurrScene(SCENENODE* sceneNode)
{
    SetCurrScene(sceneNode);
}

SCENENODE* GetManagedCurrScene()
{
    return GetCurrScene();
}

void InitCurrScene()
{
    
}

void UpdateCurrScene()
{
    
}

void SwitchSceneToName(const char* sceneName)
{
    
}
