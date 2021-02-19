//------------------------------------------------------------------------
// ファイル名: AppSwitchEffectScene.h
// 機能: 変換エフェクトシーンに関しての声明
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
    ClearSceneCamBuffer(GetSceneNodeByName("switch-effect"));
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

        int halfOfDistance = 0;

        if (GetSwitchEffectStyle() == UP2DOWN ||
            GetSwitchEffectStyle() == DOWN2UP)
        {
            halfOfDistance = height / 2;
        }
        else
        {
            halfOfDistance = width / 6;
        }

        if (g_test <= halfOfDistance)
        {
            if (GetSwitchEffectStyle() == UP2DOWN)
            {
                int i = g_test;
                while (i > 0)
                {
                    for (int j = 0; j < i; j++)
                    {
                        for (int k = 0; k < width / 2; k++)
                        {
                            *(cam + 2 * j *
                                width + 2 * k) = '|';
                            *(cam + (2 * j + 1) *
                                width + 2 * k) = '|';
                        }
                    }
                    --i;
                }
            }
            else if (GetSwitchEffectStyle() == DOWN2UP)
            {
                int i = g_test;
                while (i > 0)
                {
                    for (int j = 0; j < i; j++)
                    {
                        for (int k = 0; k < width / 2; k++)
                        {
                            *(cam + (height - 2 * j - 1) *
                                width + 2 * k) = '|';
                            *(cam + (height - 2 * j - 2) *
                                width + 2 * k) = '|';
                        }
                    }
                    --i;
                }
            }
            else if (GetSwitchEffectStyle() == LEFT2RIGHT)
            {
                int i = g_test;
                while (i > 0)
                {
                    for (int j = 0; j < height; j++)
                    {
                        for (int k = 0; k < i; k++)
                        {
                            *(cam + j * width + 6 * k) = '-';
                            *(cam + j * width + 6 * k + 1) = '-';
                            *(cam + j * width + 6 * k + 2) = '-';
                            *(cam + j * width + 6 * k + 3) = '-';
                            *(cam + j * width + 6 * k + 4) = '-';
                            *(cam + j * width + 6 * k + 5) = '-';
                        }
                    }
                    --i;
                }
            }
            else if (GetSwitchEffectStyle() == RIGHT2LEFT)
            {
                int i = g_test;
                while (i > 0)
                {
                    for (int j = 0; j < height; j++)
                    {
                        for (int k = 0; k < i; k++)
                        {
                            *(cam + j * width +
                                width - 6 * k - 1) = '-';
                            *(cam + j * width +
                                width - 6 * k - 2) = '-';
                            *(cam + j * width +
                                width - 6 * k - 3) = '-';
                            *(cam + j * width +
                                width - 6 * k - 4) = '-';
                            *(cam + j * width +
                                width - 6 * k - 5) = '-';
                            *(cam + j * width +
                                width - 6 * k - 6) = '-';
                        }
                    }
                    --i;
                }
            }
            else
            {
                ErrorLogI1("cannot find this style",
                    GetSwitchEffectStyle());
            }
        }
        else
        {
            if (GetSwitchEffectStyle() == UP2DOWN)
            {
                int i = 2 * halfOfDistance - g_test;
                while (i > 0)
                {
                    for (int j = 0; j < i; j++)
                    {
                        for (int k = 0; k < width / 2; k++)
                        {
                            *(cam + (height - 2 * j - 1) *
                                width + 2 * k) = '|';
                            *(cam + (height - 2 * j - 2) *
                                width + 2 * k) = '|';
                        }
                    }
                    --i;
                }
            }
            else if (GetSwitchEffectStyle() == DOWN2UP)
            {
                int i = 2 * halfOfDistance - g_test;
                while (i > 0)
                {
                    for (int j = 0; j < i; j++)
                    {
                        for (int k = 0; k < width / 2; k++)
                        {
                            *(cam + (2 * j) *
                                width + 2 * k) = '|';
                            *(cam + (2 * j + 1) *
                                width + 2 * k) = '|';
                        }
                    }
                    --i;
                }
            }
            else if (GetSwitchEffectStyle() == LEFT2RIGHT)
            {
                int i = 2 * halfOfDistance - g_test;
                while (i > 0)
                {
                    for (int j = 0; j < height; j++)
                    {
                        for (int k = 0; k < i; k++)
                        {
                            *(cam + j * width +
                                (width - 6 * k) - 1) = '-';
                            *(cam + j * width +
                                (width - 6 * k) - 2) = '-';
                            *(cam + j * width +
                                (width - 6 * k) - 3) = '-';
                            *(cam + j * width +
                                (width - 6 * k) - 4) = '-';
                            *(cam + j * width +
                                (width - 6 * k) - 5) = '-';
                            *(cam + j * width +
                                (width - 6 * k) - 6) = '-';
                        }
                    }
                    --i;
                }
            }
            else if (GetSwitchEffectStyle() == RIGHT2LEFT)
            {
                int i = 2 * halfOfDistance - g_test;
                while (i > 0)
                {
                    for (int j = 0; j < height; j++)
                    {
                        for (int k = 0; k < i; k++)
                        {
                            *(cam + j * width +
                                6 * k) = '-';
                            *(cam + j * width +
                                6 * k + 1) = '-';
                            *(cam + j * width +
                                6 * k + 2) = '-';
                            *(cam + j * width +
                                6 * k + 3) = '-';
                            *(cam + j * width +
                                6 * k + 4) = '-';
                            *(cam + j * width +
                                6 * k + 5) = '-';
                        }
                    }
                    --i;
                }
            }
            else
            {
                ErrorLogI1("cannot find this style",
                    GetSwitchEffectStyle());
            }
        }

        if (g_test > height)
        {
            g_test = 0;
            SetRandom();
            SetSwitchEffectStyle(CreateRandomNumIn(1, 4));
            SetSwitchEffectFlag(0);
            InitCurrScene();
        }
    }
}

void TurnOffSwitchEffectScene()
{

}
