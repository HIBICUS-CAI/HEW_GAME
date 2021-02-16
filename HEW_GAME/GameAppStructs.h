//------------------------------------------------------------------------
// ファイル名: GameAppStructs.h
// 機能: ミドルウェアみたいな構造体
//------------------------------------------------------------------------

#pragma once

#include "Structs.h"

/// <summary>
/// シーンのカメラ構造体
/// </summary>
struct SCENECAMERA
{
    char CamBuffer[CONSOLE_HEIGHT * CONSOLE_WIDTH];

    POSITION_2D CameraPosition;
    int CameraWidth;
    int CameraHeight;

    SCENECAMERA() {}

    SCENECAMERA(POSITION_2D _pos, int _camWdt, int _camHgt)
    {
        CameraPosition = _pos;
        CameraWidth = _camWdt;
        CameraHeight = _camHgt;
    }

    char* GetCamBuffer()
    {
        return CamBuffer;
    }
};

/// <summary>
/// シーン構造体
/// </summary>
struct SCENENODE
{
    int SceneID;
    char SceneName[50];
    UIOBJECT* BaseUIObj;
    SCENECAMERA Camera;

    SCENENODE() {}

    SCENENODE(const char* _name, UIOBJECT* _baseUIO,
        SCENECAMERA _cam)
    {
        strcpy_s(SceneName, sizeof(SceneName), _name);
        BaseUIObj = _baseUIO;
        Camera = _cam;
    }

    SCENECAMERA* GetCamAddr()
    {
        return &Camera;
    }

    void SetBaseUIO(UIOBJECT* uiObj)
    {
        BaseUIObj = uiObj;
    }

    UIOBJECT* GetBaseUIOAddr()
    {
        return BaseUIObj;
    }

    void WriteStrToCamBuffer(POSITION_2D pos, const char* string)
    {
        int width = GetCamAddr()->CameraWidth;
        int height = GetCamAddr()->CameraHeight;
        char* buffer = GetCamAddr()->GetCamBuffer();
        int startX = pos.posX;
        int startY = pos.posY;
        int strLen = strlen(string);

        if (startY < height && startY >= 0)
        {
            for (int i = 0; i < strLen; i++)
            {
                if ((startX + i) >= 0 && (startX + i) < width)
                {
                    *(buffer + startY * width + startX + i) =
                        *(string + i);
                    if (startX < 0 && startX + i < 2 && i % 2)
                    {
                        *(buffer + startY * width + startX + i) = ' ';
                    }
                }
            }
        }
    }
};

/// <summary>
/// 基本な対象者構造体
/// </summary>
struct OBJECT
{
    POSITION_2D Position;
    int Width;
    int Height;
    float ColliRadius;

    int IsCollied(OBJECT obj)
    {
        float distX = ((float)(Width) / 2.f + (float)Position.posX) -
            ((float)(obj.Width) / 2.f + (float)obj.Position.posX);
        float distY = (float)(Height) / 2.f + (float)Position.posY -
            ((float)(obj.Height) / 2.f + (float)obj.Position.posY);

        return (distX * distX + distY * distY <=
            (ColliRadius + obj.ColliRadius) * (ColliRadius + obj.ColliRadius)) ?
            1 : 0;
    }

    int GetDeltaXWith(OBJECT obj)
    {
        int distX = (int)(((float)Width / 2.f + (float)Position.posX) -
            ((float)obj.Width / 2.f + (float)obj.Position.posX));
        return distX;
    }

    int GetDeltaYWith(OBJECT obj)
    {
        int distY = (int)(((float)Height / 2.f + (float)Position.posY) -
            ((float)obj.Height / 2.f + (float)obj.Position.posY));
        return distY;
    }
};

#define MAXSIZE_PER_SPRITE_FRAME 60
/// <summary>
/// 複数ありスプライトの集合体
/// </summary>
struct SPRITE_ANIME
{
    SPRITE SubSprites[MAXSIZE_PER_SPRITE_FRAME];

    SPRITE_ANIME()
    {
        for (int i = 0; i < MAXSIZE_PER_SPRITE_FRAME; i++)
        {
            SubSprites[i] = SPRITE();
        }
    }

    void SetSubSpriteByOffset(SPRITE subSprite, int offset)
    {
        SubSprites[offset] = subSprite;
    }

    SPRITE* GetSubSpriteByOffset(int offset)
    {
        return SubSprites + offset;
    }
};

#define SINGLE_SENTENCE_LEN 128
#define SINGLE_TURN_COUNT 5
/// <summary>
/// 一回の対話内容
/// </summary>
struct SINGLE_DIALOG
{
    char Speaker[32];
    char Texts[SINGLE_TURN_COUNT][SINGLE_SENTENCE_LEN];

    SINGLE_DIALOG()
    {
        strcpy_s(Speaker, sizeof(Speaker), "");
        for (int i = 0; i < SINGLE_TURN_COUNT; i++)
        {
            strcpy_s(Texts[i], sizeof(Texts[i]), "");
        }
    }

    char* GetSingleSentenceByOffset(int offset)
    {
        if (offset >= SINGLE_TURN_COUNT)
        {
            ErrorLogI1("cannot read this address", offset);
            return NULL;
        }
        return Texts[offset];
    }

    char* GetSpeaker()
    {
        return Speaker;
    }
};

#define DIALOG_SIZE 64
/// <summary>
/// 一回の対話内容を全部保存する構造体
/// </summary>
struct DIALOG_EVENT
{
    int DialogEventID;
    SINGLE_DIALOG Dialogs[DIALOG_SIZE];

    DIALOG_EVENT()
    {
        DialogEventID = -1;
        for (int i = 0; i < DIALOG_SIZE; i++)
        {
            Dialogs[i] = SINGLE_DIALOG();
        }
    }

    int GetDialogEventID()
    {
        return DialogEventID;
    }

    SINGLE_DIALOG* GetSningleDialogByOffset(int offset)
    {
        return Dialogs + offset;
    }
};

enum class VISITOR_TYPE
{
    NONE,
    STUDENTS,
    COUPLE,
    PROGRAMMER,
    ARTIST,
    OFFICER,
    FAMILY,
    RABBIT,
    WHALE,
    CAMEL
};

/// <summary>
/// 観光客情報構造体
/// </summary>
struct VISITOR_NODE
{
    int IsUsing;
    VISITOR_TYPE Type;

    VISITOR_NODE()
    {
        IsUsing = 0;
        Type = VISITOR_TYPE::NONE;
    }

    VISITOR_NODE(int _isusing, VISITOR_TYPE _type)
    {
        IsUsing = _isusing;
        Type = _type;
    }

    void SetIsUsing()
    {
        IsUsing = 1;
    }

    void SetNotUsing()
    {
        IsUsing = 0;
    }
};

#define FARBACK_SA_SIZE 9
#define FARBACK_SA_WIDTH 30
#define FARBACK_SA_HEIGHT 40
#define NEARBACK_SA_SIZE 6
#define NEARBACK_SA_WIDTH 60
#define NEARBACK_SA_HEIGHT 40

/// <summary>
/// 背景のスプライトアニメタル構造体
/// </summary>
struct STAGE_BACKGROUND_SA
{
    SPRITE_ANIME FarBack[FARBACK_SA_SIZE];
    SPRITE_ANIME NearBack[NEARBACK_SA_SIZE];
};

enum class BUILDING_STATUS
{
    NOTHING,
    PLANING,
    CONFIRMED
};

struct BUILDING
{
    BUILDING_STATUS Status;
    int Type;
    int Event;
};
