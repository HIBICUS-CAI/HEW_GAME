#include "VisitorShower.h"
#include "AppDeclared.h"
#include "SpriteAnimator.h"
#include "SceneNode.h"

SPRITE g_VisitorSprites[VISITORTYPE_MAXSIZE];
int g_SpriteOffset = 0;
int g_VisitorOffset = 0;
int g_PosX = 0;
int g_PosY = 0;
int g_ShowFlg = 0;

#define OFFSET_STUD 0
#define OFFSET_COUP 1
#define OFFSET_PRGM 2
#define OFFSET_ARTS 3
#define OFFSET_OFFC 4
#define OFFSET_FAMY 5
#define OFFSET_RABT 6
#define OFFSET_WHAL 7
#define OFFSET_CAML 8

void InitVisitorShower()
{
    g_VisitorSprites[OFFSET_STUD] = CreateSingleSprite(
        "Assets\\Sprites\\student.txt",
        POSITION_2D(0, 0), 43, 25);
    g_VisitorSprites[OFFSET_COUP] = CreateSingleSprite(
        "Assets\\Sprites\\couple.txt",
        POSITION_2D(0, 0), 50, 25);
    g_VisitorSprites[OFFSET_PRGM] = CreateSingleSprite(
        "Assets\\Sprites\\programmer.txt",
        POSITION_2D(0, 0), 64, 25);
    g_VisitorSprites[OFFSET_ARTS] = CreateSingleSprite(
        "Assets\\Sprites\\artist.txt",
        POSITION_2D(0, 0), 45, 25);
    g_VisitorSprites[OFFSET_OFFC] = CreateSingleSprite(
        "Assets\\Sprites\\officer.txt",
        POSITION_2D(0, 0), 38, 25);
    g_VisitorSprites[OFFSET_FAMY] = CreateSingleSprite(
        "Assets\\Sprites\\family.txt",
        POSITION_2D(0, 0), 51, 25);
    g_VisitorSprites[OFFSET_RABT] = CreateSingleSprite(
        "Assets\\Sprites\\rabbit.txt",
        POSITION_2D(0, 0), 28, 25);
    g_VisitorSprites[OFFSET_WHAL] = CreateSingleSprite(
        "Assets\\Sprites\\whale.txt",
        POSITION_2D(0, 0), 64, 25);
    g_VisitorSprites[OFFSET_CAML] = CreateSingleSprite(
        "Assets\\Sprites\\camel.txt",
        POSITION_2D(0, 0), 65, 25);

    g_SpriteOffset = 0;
    g_VisitorOffset = 0;
    g_PosX = -80;
    g_PosY = 2;
    g_ShowFlg = 0;
}

void ResetStartPos()
{
    g_PosX = -80;
    g_PosY = 2;
}

void ResetAllAboutShowVisitors()
{
    g_ShowFlg = 0;
    g_SpriteOffset = 0;
    g_VisitorOffset = 0;
    ResetStartPos();
}

void UpdateVisitorShower()
{
    if (g_ShowFlg)
    {
        VISITOR_NODE* tempVisitor =
            GetVisitorArray() + g_VisitorOffset;

        if (!tempVisitor->IsUsing)
        {
            ResetAllAboutShowVisitors();
            return;
        }

        switch (tempVisitor->Type)
        {
        case VISITOR_TYPE::STUDENTS:
            g_SpriteOffset = OFFSET_STUD;
            break;
        case VISITOR_TYPE::COUPLE:
            g_SpriteOffset = OFFSET_COUP;
            break;
        case VISITOR_TYPE::PROGRAMMER:
            g_SpriteOffset = OFFSET_PRGM;
            break;
        case VISITOR_TYPE::ARTIST:
            g_SpriteOffset = OFFSET_ARTS;
            break;
        case VISITOR_TYPE::OFFICER:
            g_SpriteOffset = OFFSET_OFFC;
            break;
        case VISITOR_TYPE::FAMILY:
            g_SpriteOffset = OFFSET_FAMY;
            break;
        case VISITOR_TYPE::RABBIT:
            g_SpriteOffset = OFFSET_RABT;
            break;
        case VISITOR_TYPE::WHALE:
            g_SpriteOffset = OFFSET_WHAL;
            break;
        case VISITOR_TYPE::CAMEL:
            g_SpriteOffset = OFFSET_CAML;
            break;

        default:
            ErrorLog("cannot show this visitor's sprite");
            break;
        }

        if (g_PosX <= 180)
        {
            DrawSingleSpriteToCamBuffer(
                GetSceneNodeByName("naming")->GetCamAddr(),
                g_VisitorSprites + g_SpriteOffset,
                POSITION_2D(g_PosX, g_PosY)
            );
            g_PosX += 2;
        }
        else
        {
            ResetStartPos();
            ++g_VisitorOffset;
        }
    }
    else
    {
        g_SpriteOffset = 0;
        g_VisitorOffset = 0;
        ResetStartPos();
    }
}

void TurnOffVisitorShower()
{

}

void SetShowVisitorFlg(int flag)
{
    g_ShowFlg = flag;
}
