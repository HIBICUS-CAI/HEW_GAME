//------------------------------------------------------------------------
// ファイル名: Structs.h
// 機能: 基本な構造体を声明する
//------------------------------------------------------------------------

#pragma once

#include <string.h>
#include <stdio.h>
#include "DefinedValues.h"
#include "LogsOutput.h"

/// <summary>
/// 座標の構造体
/// </summary>
struct POSITION_2D
{
    int posX;
    int posY;

    POSITION_2D()
    {
        posX = -1;
        posY = -1;
    }

    POSITION_2D(int _x, int _y)
    {
        posX = _x;
        posY = _y;
    }

    int operator==(const POSITION_2D other) const
    {
        return (this->posX == other.posX) && (this->posY == other.posY);
    }

    int operator!=(const POSITION_2D other) const
    {
        return (this->posX != other.posX) || (this->posY != other.posY);
    }

    POSITION_2D operator+(const POSITION_2D other) const
    {
        POSITION_2D temp(0, 0);
        temp.posX = this->posX + other.posX;
        temp.posY = this->posY + other.posY;
        return temp;
    }

    POSITION_2D operator-(const POSITION_2D other) const
    {
        POSITION_2D temp(0, 0);
        temp.posX = this->posX - other.posX;
        temp.posY = this->posY - other.posY;
        return temp;
    }

    POSITION_2D operator*(const int value) const
    {
        POSITION_2D temp(0, 0);
        temp.posX = this->posX * value;
        temp.posY = this->posY * value;
        return temp;
    }

    POSITION_2D operator/(const int value) const
    {
        POSITION_2D temp(0, 0);
        temp.posX = this->posX / value;
        temp.posY = this->posY / value;
        return temp;
    }
};

/// <summary>
/// リスト要素の構造体
/// </summary>
struct QSINGLENODE
{
    int Data;
    QSINGLENODE* Next;
};

/// <summary>
/// ＩＮＴ型リストの構造体
/// </summary>
struct QUEUE_INT
{
    QSINGLENODE* Top;
    QSINGLENODE* End;
};

/// <summary>
/// ＵＩアイテム中の文字部分
/// </summary>
struct UI_TEXT
{
    TYPEID TypeID;
    int ID;
    POSITION_2D Position;
    char Text[512];

    UI_TEXT() {}

    UI_TEXT(POSITION_2D _position, char* _text)
    {
        Position = _position;
        strcpy_s(Text, 512 * sizeof(char), _text);
    }

    void ChangeTextTo(const char* text)
    {
        strcpy_s(Text, 512 * sizeof(char), text);
    }

    void ChangeTextTo(const char* text, int value)
    {
        char temp[512];
        sprintf_s(temp, sizeof(temp), "%s%d", text, value);
        strcpy_s(Text, 512 * sizeof(char), temp);
    }

    void ChangeTextTo(const char* text, int value1, int value2)
    {
        char temp[512];
        sprintf_s(temp, sizeof(temp), "%s%d, %d", text, value1, value2);
        strcpy_s(Text, 512 * sizeof(char), temp);
    }
};

enum class BTN_DESIGN
{
    LINE,
    STRAIGHT,
    NONE
};

/// <summary>
/// ＵＩアイテム中のボタン部分
/// </summary>
struct UI_BUTTON
{
    TYPEID TypeID;
    int ID;
    int Event;
    POSITION_2D Position;
    char Text[50];
    int TextLength;
    BTN_DESIGN BorderDesign;
    UI_BUTTON* LeftBtn;
    UI_BUTTON* RightBtn;
    UI_BUTTON* UpBtn;
    UI_BUTTON* DownBtn;

    UI_BUTTON() {}

    UI_BUTTON(int _event, POSITION_2D _position, char* _text,
        BTN_DESIGN _design)
    {
        Event = _event;
        Position = _position;
        strcpy_s(Text, 50 * sizeof(char), _text);
        TextLength = strlen(Text);
        BorderDesign = _design;
        LeftBtn = NULL;
        RightBtn = NULL;
        UpBtn = NULL;
        DownBtn = NULL;
    }
};

enum class UIO_DESIGN
{
    NOTHING,
    STAR,
    STRAIGHT
};

/// <summary>
/// ＵＩアイテムの構造体
/// </summary>
struct UIOBJECT
{
#define TEXTSIZEINUIO 20
#define BTNSIZEINUIO 200
    TYPEID TypeID;
    int ID;
    char UIName[50];
    POSITION_2D StartPoint;
    int Width;
    int Height;
    UIO_DESIGN BorderDesign;
    UIOBJECT* ParentUIO;
    UIOBJECT* ChildUIO;
    int Visiblity;
    UI_TEXT Texts[TEXTSIZEINUIO];
    UI_BUTTON Buttons[BTNSIZEINUIO];

    UIOBJECT() {}

    UIOBJECT(TYPEID _typeID, int _id, char* _name,
        POSITION_2D _startPoint, int _width, int _height,
        UIO_DESIGN _design, UIOBJECT* _parent, UIOBJECT* _child,
        int _visiblity)
    {
        TypeID = _typeID;
        ID = _id;
        strcpy_s(UIName, sizeof(UIName), _name);
        StartPoint = _startPoint;
        Width = _width;
        Height = _height;
        BorderDesign = _design;
        ParentUIO = _parent;
        ChildUIO = _child;
        Visiblity = _visiblity;
        for (int i = 0; i < TEXTSIZEINUIO; i++)
        {
            Texts[i].ID = -1;
        }
        for (int i = 0; i < BTNSIZEINUIO; i++)
        {
            Buttons[i].ID = -1;
            Buttons[i].LeftBtn = NULL;
            Buttons[i].RightBtn = NULL;
            Buttons[i].UpBtn = NULL;
            Buttons[i].DownBtn = NULL;
        }
    }

    void AddParent(UIOBJECT* parent)
    {
        ParentUIO = parent;
    }

    void AddChild(UIOBJECT* child)
    {
        ChildUIO = child;
    }

    /// <summary>
    /// このアイテムに文字内容を添付する
    /// </summary>
    /// <param name="text">文字内容</param>
    void AddText(UI_TEXT text)
    {
        int index = 0;
        while (index < TEXTSIZEINUIO)
        {
            if (Texts[index].ID == -1)
            {
                text.TypeID = TYPEID::TextObj;
                text.ID = 20000 + index;
                text.Position.posX += GetPosition().posX;
                text.Position.posY += GetPosition().posY;
                Texts[index] = text;
                break;
            }
            ++index;
        }
    }

    UI_TEXT* GetTextByID(int id)
    {
        if (Texts[id - 20000].ID != -1)
        {
            return &Texts[id - 20000];
        }
        else
        {
            ErrorLogI1("you don't have a text object which id is", id);
            return NULL;
        }
    }

    /// <summary>
    /// このアイテムにボタン内容を添付する
    /// </summary>
    /// <param name="btn">ボタン内容</param>
    void AddBtn(UI_BUTTON btn)
    {
        int index = 0;
        int leastXPlus = 200;
        int leastXMinus = -200;
        int leastYPlus = 100;
        int leastYMinus = -100;

        btn.Position.posX += GetPosition().posX;
        btn.Position.posY += GetPosition().posY;

        while (index < BTNSIZEINUIO)
        {
            if (Buttons[index].ID == -1)
            {
                btn.TypeID = TYPEID::ButtonObj;
                btn.ID = 30000 + index;
                Buttons[index] = btn;

                if (Buttons[index].UpBtn != NULL)
                {
                    Buttons[index].UpBtn->DownBtn = &Buttons[index];
                }
                if (Buttons[index].DownBtn != NULL)
                {
                    Buttons[index].DownBtn->UpBtn = &Buttons[index];
                }
                if (Buttons[index].LeftBtn != NULL)
                {
                    Buttons[index].LeftBtn->RightBtn = &Buttons[index];
                }
                if (Buttons[index].RightBtn != NULL)
                {
                    Buttons[index].RightBtn->LeftBtn = &Buttons[index];
                }

                break;
            }

            // ボタンの間で位置関係を自動的に確定する
            int deltaX = (btn.Position.posX - Buttons[index].Position.posX) / 2;
            int deltaY = btn.Position.posY - Buttons[index].Position.posY;
            int deltaXY = deltaX * deltaX - deltaY * deltaY;
            if (deltaXY >= 0)
            {
                // 左右
                if (deltaX >= 0 && deltaX <= leastXPlus)
                {
                    btn.LeftBtn = &Buttons[index];
                    leastXPlus = deltaX;
                }
                else if (deltaX <= leastXMinus)
                {
                    btn.RightBtn = &Buttons[index];
                    leastXMinus = deltaX;
                }
            }
            else
            {
                // 上下
                if (deltaY >= 0 && deltaY <= leastYPlus)
                {
                    btn.UpBtn = &Buttons[index];
                    leastYPlus = deltaY;
                }
                else if (deltaY <= leastYMinus)
                {
                    btn.DownBtn = &Buttons[index];
                    leastYMinus = deltaY;
                }
            }

            ++index;
        }
    }

    UI_BUTTON* GetBtnByID(int id)
    {
        if (Buttons[id - 30000].ID != -1)
        {
            return &Buttons[id - 30000];
        }
        else
        {
            ErrorLogI1("you don't have a button object which id is", id);
            return NULL;
        }
    }

    void TurnOn()
    {
        Visiblity = 1;
    }

    void TurnOff()
    {
        Visiblity = 0;
    }

    POSITION_2D GetPosition()
    {
        return StartPoint;
    }
};

/// <summary>
/// 位置を示す構造体
/// </summary>
struct Object
{
    POSITION_2D Position;

    POSITION_2D GetPosition()
    {
        return Position;
    }
};

#define SPRITE_MAX_WIDTH 80
#define SPRITE_MAX_HEIGHT 40
/// <summary>
/// スプライト構造体
/// </summary>
struct SPRITE
{
    POSITION_2D Position;
    int Width;
    int Height;
    char SpriteBuffer[SPRITE_MAX_HEIGHT * SPRITE_MAX_WIDTH];
    int Visible;

    SPRITE()
    {
        Position = POSITION_2D(0, 0);
        Width = 0;
        Height = 0;
        for (int i = 0; i < SPRITE_MAX_HEIGHT * SPRITE_MAX_WIDTH; i++)
        {
            SpriteBuffer[i] = 0;
        }
        Visible = 0;
    }

    SPRITE(POSITION_2D _startPos, int _width, int _height, int _visible)
    {
        Position = _startPos;
        Width = _width;
        Height = _height;
        for (int i = 0; i < SPRITE_MAX_WIDTH * SPRITE_MAX_HEIGHT; i++)
        {
            SpriteBuffer[i] = 0;
        }
        if (_visible)
        {
            Visible = 1;
        }
        else
        {
            Visible = 0;
        }
    }

    char* GetSpriteBuffer()
    {
        return SpriteBuffer;
    }

    void TurnOn()
    {
        Visible = 1;
    }

    void TurnOff()
    {
        Visible = 0;
    }

    POSITION_2D GetPixelPositionInSprite(int index)
    {
        int posX = index % Width;
        int posY = index / Width;

        return POSITION_2D(posX, posY);
    }

    void Clear()
    {
        for (int i = 0; i < SPRITE_MAX_HEIGHT * SPRITE_MAX_WIDTH; i++)
        {
            SpriteBuffer[i] = ' ';
        }
    }
};

#ifdef SOUNDBYHAL
struct SOUNDFILE_LOADED
{
    int IsUsing;
    int AlwaysNeed;
    int Handle;
    char SoundName[64];

    SOUNDFILE_LOADED()
    {
        IsUsing = 0;
        AlwaysNeed = 0;
        Handle = 0;
        strcpy_s(SoundName, sizeof(SoundName), "");
    }
};
#else
struct SOUNDFILE_IN_MEMBITE
{
    int IsUsing;
    char SoundName[64];
    BYTE* SoundFileInBites;
    BYTE* SoundFileInBitesWithVolume;
    DWORD SoundFileSize;

    SOUNDFILE_IN_MEMBITE()
    {
        IsUsing = 0;
        strcpy_s(SoundName, sizeof(SoundName), "");
        SoundFileInBites = NULL;
        SoundFileInBitesWithVolume = NULL;
        SoundFileSize = 0;
    }
};

struct SOUND_THREAD_HANDLE
{
    int IsUsing;
    HANDLE SoundHandle;

    SOUND_THREAD_HANDLE()
    {
        IsUsing = 0;
        SoundHandle = NULL;
    }
};
#endif // SOUNDBYHAL
