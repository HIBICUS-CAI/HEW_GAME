#include "SpriteAnimator.h"
#include "DeclaredValues.h"

SPRITE CreateSingleSprite(const char* fileName, POSITION_2D position, int width, int height)
{
    SPRITE* tempSingleSprite=new SPRITE(position, width, height, 1);
    FILE* asciiDrawFile = NULL;
    fopen_s(&asciiDrawFile, fileName, "r");

    if (asciiDrawFile == NULL)
    {
        ErrorLog("cannot open file when loading single sprite");
        SPRITE* nullS = new SPRITE();
        return *nullS;
    }

    char asciiChar = '\\';
    for (int i = 0; i < width * height; i++)
    {
        asciiChar = fgetc(asciiDrawFile);
        if (asciiChar == EOF)
        {
            break;
        }
        if (asciiChar == '\n')
        {
            --i;
            continue;
        }
        *(tempSingleSprite->GetSpriteBuffer() + i) = asciiChar;
    }
    fclose(asciiDrawFile);
    return *tempSingleSprite;
}

void DrawSingleSpriteToUpdateBuffer(SPRITE* sprite)
{
    POSITION_2D startPos = sprite->Position;
    int startIndex = startPos.posY * CONSOLE_WIDTH + startPos.posX;

    for (int i = 0; i < sprite->Height; i++)
    {
        for (int j = 0; j < sprite->Width; j++)
        {
            if (*(sprite->GetSpriteBuffer() + i * sprite->Width + j) == ' ')
            {
                continue;
            }
            *(GetOutputBufferToUpdate() + startIndex + i * CONSOLE_WIDTH + j) =
                *(sprite->GetSpriteBuffer() + i * sprite->Width + j);
        }
    }
}

void DrawSingleSpriteToCamBuffer(SCENECAMERA* camBuffer, SPRITE* sprite, POSITION_2D posInCam, int showSpace)
{
    POSITION_2D startPos = posInCam;
    int startIndex = startPos.posY * camBuffer->CameraWidth + startPos.posX;

    for (int i = 0; i < sprite->Height; i++)
    {
        for (int j = 0; j < sprite->Width; j++)
        {
            if (showSpace)
            {
                if (startPos.posX + j >= camBuffer->CameraWidth ||
                    startPos.posY + i >= camBuffer->CameraHeight ||
                    startPos.posX + j <= 0 || startPos.posY + i <= 0)
                {
                    continue;
                }
                *((camBuffer->GetCamBuffer()) + startIndex + i * camBuffer->CameraWidth + j) =
                    *(sprite->GetSpriteBuffer() + i * sprite->Width + j);
            }
            else
            {
                if (startPos.posX + j >= camBuffer->CameraWidth ||
                    startPos.posY + i >= camBuffer->CameraHeight ||
                    startPos.posX + j <= 0 || startPos.posY + i <= 0 ||
                    *(sprite->GetSpriteBuffer() + i * sprite->Width + j) == ' ')
                {
                    continue;
                }
                *((camBuffer->GetCamBuffer()) + startIndex + i * camBuffer->CameraWidth + j) =
                    *(sprite->GetSpriteBuffer() + i * sprite->Width + j);
            }
        }
    }
}

SPRITE_ANIME CreateSpriteAnimator(int frameCount, const char* fileName, POSITION_2D position, int width, int height)
{
    SPRITE_ANIME* tempSpriteAnimator = new SPRITE_ANIME();

    if (frameCount > MAXSIZE_PER_SPRITE_FRAME)
    {
        ErrorLogI1("this animator frame count has overflowed as", frameCount);
        return *tempSpriteAnimator;
    }

    char fileNameWithID[128];
    FILE* pKeyFrameFile = NULL;
    
    for (int i = 0; i < frameCount; i++)
    {
        sprintf_s(fileNameWithID, sizeof(fileNameWithID), "%s%d.txt", fileName, i + 1);
        tempSpriteAnimator->SetSubSpriteByOffset(CreateSingleSprite(fileNameWithID, position, width, height),
            i * (MAXSIZE_PER_SPRITE_FRAME / frameCount));
    }

    return *tempSpriteAnimator;
}

void DrawSpriteAnimatorToUpdateBuffer(SPRITE_ANIME* spriteAnimator, int offset)
{
    if (!spriteAnimator->GetSubSpriteByOffset(offset)->Visible)
    {
        if (!offset)
        {
            return;
        }
        DrawSpriteAnimatorToUpdateBuffer(spriteAnimator, --offset);
        return;
    }

    DrawSingleSpriteToUpdateBuffer(spriteAnimator->GetSubSpriteByOffset(offset));
}

void DrawSpriteAnimatorToCamBuffer(SCENECAMERA* camBuffer, SPRITE_ANIME* spriteAnimator, int offset, POSITION_2D posInCam, int showSpace)
{
    if (!spriteAnimator->GetSubSpriteByOffset(offset)->Visible)
    {
        if (!offset)
        {
            return;
        }
        DrawSpriteAnimatorToCamBuffer(camBuffer, spriteAnimator, --offset, posInCam, showSpace);
        return;
    }

    DrawSingleSpriteToCamBuffer(camBuffer, spriteAnimator->GetSubSpriteByOffset(offset), posInCam);
}
