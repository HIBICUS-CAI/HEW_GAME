#include "SpriteAnimator.h"
#include "DeclaredValues.h"

SPRITE CreateSingleSprite(const char* fileName, POSITION_2D position, int width, int height)
{
    SPRITE tempSingleSprite = SPRITE(position, width, height, 1);
    FILE* asciiDrawFile = NULL;
    fopen_s(&asciiDrawFile, fileName, "r");

    if (asciiDrawFile == NULL)
    {
        ErrorLog("cannot open file when loading single sprite");
        return SPRITE();
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
        *(tempSingleSprite.GetSpriteBuffer() + i) = asciiChar;
    }

    return tempSingleSprite;
}

void DrawSingleSpriteToUpdateBuffer(SPRITE* sprite)
{
    POSITION_2D startPos = sprite->Position;
    int startIndex = startPos.posY * CONSOLE_WIDTH + startPos.posX;

    for (int i = 0; i < sprite->Height; i++)
    {
        for (int j = 0; j < sprite->Width; j++)
        {
            *(GetOutputBufferToUpdate() + startIndex + i * CONSOLE_WIDTH + j) =
                *(sprite->GetSpriteBuffer() + i * sprite->Width + j);
        }
    }
}

SPRITE_ANIME CreateSpriteAnimator(int frameCount, const char* fileName, POSITION_2D position, int width, int height)
{

}
