#include "ThoughtListShower.h"
#include "SceneNode.h"
#include "SpriteAnimator.h"
#include "Tools.h"

SPRITE g_ThoughtListSprites[30];

void InitThoughtListShower()
{
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
            (g_ThoughtListSprites + i)->Position.posX =
                (g_ThoughtListSprites + i)->Position.posX - 1;
        }
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
    DrawSingleSpriteToCamBuffer(
        GetSceneNodeByName("resort")->GetCamAddr(),
        g_ThoughtListSprites + offset,
        (g_ThoughtListSprites + offset)->Position, 1
    );
}
