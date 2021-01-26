//------------------------------------------------------------------------
// ¥Õ¥¡¥¤¥ëÃû: AppSwitchEffectScene.h
// ™CÄÜ: ‰ä“Q¥¨¥Õ¥§¥¯¥È¥·©`¥ó¤Ëév¤·¤Æ¤ÎÉùÃ÷
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"
#include "SceneManager.h"

//-----------------------------------
int g_test = 0;

void InitSwitchEffectScene()
{
    CreateSceneNode(SCENENODE("switch-effect", NULL,
        SCENECAMERA(POSITION_2D(1, 0), 178, 60)));
    CreateUIO("switch", POSITION_2D(0, 0), 0, 0, UIO_DESIGN::NOTHING);
    GetUIObjByName("switch")->AddBtn(
        UI_BUTTON(0, POSITION_2D(0, 0),
            (char*)"", BTN_DESIGN::NONE));
    GetSceneNodeByName("switch-effect")->SetBaseUIO(GetUIObjByName("switch"));
}

void UpdateSwitchEffectScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("switch-effect"));

    if (GetSwitchEffectFlag())
    {
        DebugLogI1("now", g_test++);
        if (g_test > 50)
        {
            g_test = 0;
            SetSwitchEffectFlag(0);
            InitCurrScene();
        }
    }
    else
    {
        InitCurrScene();
    }
}

void TurnOffSwitchEffectScene()
{

}
