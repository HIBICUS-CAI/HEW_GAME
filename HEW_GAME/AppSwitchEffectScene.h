//------------------------------------------------------------------------
// ¥Õ¥¡¥¤¥ëÃû: AppSwitchEffectScene.h
// ™CÄÜ: ‰ä“Q¥¨¥Õ¥§¥¯¥È¥·©`¥ó¤Ëév¤·¤Æ¤ÎÉùÃ÷
//------------------------------------------------------------------------

#pragma once

#include "SceneNode.h"
#include "SceneManager.h"
#include "Tools.h"

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
}

void UpdateSwitchEffectScene()
{
    ClearSceneCamBuffer(GetSceneNodeByName("switch-effect"));

    if (GetSwitchEffectFlag())
    {
        char* cam = GetSceneNodeByName("switch-effect")->GetCamAddr()->GetCamBuffer();
        int width = GetSceneNodeByName("switch-effect")->GetCamAddr()->CameraWidth;
        int height = GetSceneNodeByName("switch-effect")->GetCamAddr()->CameraHeight;

        ++g_test;
        // TODO make switch effect here
        char temp[3] = "¡ö";
        int i = g_test;
        int lineCount = 0;
        while (i > 0)
        {
            // TODO fix here
            if (i <= height)
            {
                for (int j = 0; j < i; j++)
                {
                    for (int k = 0; k < width; k++)
                    {
                        *(cam + j * width + k) = '|';
                    }
                }
            }
            else
            {
                for (int j = 0; j < i - height; j++)
                {
                    for (int k = 0; k < width; k++)
                    {
                        *(cam + (height - j) * width + k) = '|';
                    }
                }
            }

            --i;
        }

        /*if (g_test <= height)
        {
            char temp[3] = "¡ö";
            int i = g_test;
            int lineCount = 0;
            while (i > 0)
            {
                int length = 1 + (i - 1) * 3;
                int startX = (178 - length) / 2;

                for (int j = 0; j < length / 2; j++)
                {
                    *(cam + lineCount * width + startX + 2 * j) = *(temp);
                    *(cam + lineCount * width + startX + 2 * j + 1) = *(temp + 1);
                }
                ++lineCount;
                --i;
            }
        }
        else
        {
            char temp[3] = "¡ö";
            int i = g_test - height;
            int lineCount = 0;
            while (i > 0)
            {
                int length = (178 - (1 + (i - 1) * 3)) / 2;
                int startX1 = 0;
                int startX2 = (178 - length) / 2;

                for (int j = 0; j < length / 2; j++)
                {
                    *(cam + lineCount * width + startX1 + 2 * j) = *(temp);
                    *(cam + lineCount * width + startX1 + 2 * j + 1) = *(temp + 1);
                    *(cam + lineCount * width + startX2 + 2 * j) = *(temp);
                    *(cam + lineCount * width + startX2 + 2 * j + 1) = *(temp + 1);
                }
                ++lineCount;
                --i;
            }
        }*/

        DebugLogI1("now", g_test);
        if (g_test > 120)
        {
            g_test = 0;
            SetSwitchEffectFlag(0);
            InitCurrScene();
        }
    }
}

void TurnOffSwitchEffectScene()
{

}
