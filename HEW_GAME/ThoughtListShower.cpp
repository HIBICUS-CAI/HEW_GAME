#include "ThoughtListShower.h"
#include "SceneNode.h"
#include "SpriteAnimator.h"
#include "Tools.h"

SPRITE g_ThoughtListSprites[30];
int g_TimeCountTLS = 0;

void InitThoughtListShower()
{
    g_TimeCountTLS = 0;
    SPRITE* temp = new SPRITE();
    for (int i = 0; i < 30; i++)
    {
        g_ThoughtListSprites[i] = *temp;
    }
    delete temp;
}

void UpdateThoughtListShower()
{
    for (int i = 0; i < 30; i++)
    {
        if ((g_ThoughtListSprites + i)->Visible)
        {
            DrawThoughtSpriteByOffset(i);
            if (g_TimeCountTLS % 2)
            {
                (g_ThoughtListSprites + i)->Position.posX =
                    (g_ThoughtListSprites + i)->Position.posX - 1;
            }
        }
    }

    if (g_TimeCountTLS == 61)
    {
        g_TimeCountTLS = 0;
    }
    else
    {
        ++g_TimeCountTLS;
    }
}

void TurnOffThoughtListShower()
{

}

SPRITE* GetThoughtListSprites()
{
    return g_ThoughtListSprites;
}

void DrawThoughtSpriteByOffset(int offset)
{
    if ((g_ThoughtListSprites + offset)->Position.posX < -2)
    {
        if (!((g_ThoughtListSprites + offset)->Position.posX % 2))
        {
            *((g_ThoughtListSprites + offset)->
                GetSpriteBuffer() + (g_ThoughtListSprites + offset)->Width -
                (g_ThoughtListSprites + offset)->Position.posX + 1) = ' ';
        }
    }

    DrawSingleSpriteToCamBuffer(
        GetSceneNodeByName("resort")->GetCamAddr(),
        g_ThoughtListSprites + offset,
        (g_ThoughtListSprites + offset)->Position, 1
    );
}
