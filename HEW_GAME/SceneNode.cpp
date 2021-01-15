#include "SceneNode.h"

SCENENODE* GetSceneNodeByID(int id)
{
    if ((GetSceneNodeArray() + id)->SceneID != -1)
    {
        return GetSceneNodeArray() + id;
    }
    else
    {
        ErrorLogI1("you don't have a Scene Node which id is", id);
        return NULL;
    }
}

SCENENODE* GetSceneNodeByName(const char* name)
{
    int i = 0;
    while ((GetSceneNodeArray() + i)->SceneID != -1)
    {
        if (!strcmp((GetSceneNodeArray() + i)->SceneName, (char*)name))
        {
            return GetSceneNodeArray() + i;
        }
        ++i;
    }
    char log[512] = "you don't have a Scene Node which name is ";
    strcat_s(log, sizeof(log), (const char*)name);
    DebugLog((const char*)log);
    return NULL;
}

void InitSceneNodes()
{
    for (int i = 0; i < SCENENODESIZE; i++)
    {
        (GetSceneNodeArray() + i)->SceneID = -1;
        (GetSceneNodeArray() + i)->BaseUIObj = NULL;
        (GetSceneNodeArray() + i)->Camera =
            SCENECAMERA(POSITION_2D(0, 0), 0, 0);
    }
}

void ClearSceneCamBuffer(SCENENODE* sceneNode)
{
    char* temp = sceneNode->GetCamAddr()->GetCamBuffer();
    int width = sceneNode->GetCamAddr()->CameraWidth;
    int height = sceneNode->GetCamAddr()->CameraHeight;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(temp + i * width + j) = ' ';
        }
    }
}

void CreateSceneNode(SCENENODE sceneNode)
{
    int index = 0;
    while (index < SCENENODESIZE)
    {
        if ((GetSceneNodeArray() + index)->SceneID == -1)
        {
            sceneNode.SceneID = index;
            SetSceneNodeArray(index, sceneNode);
            break;
        }
        ++index;
    }
}

void DrawScene(SCENENODE* sceneNode)
{
    POSITION_2D startPos = sceneNode->GetCamAddr()->CameraPosition;
    int width = sceneNode->GetCamAddr()->CameraWidth;
    int height = sceneNode->GetCamAddr()->CameraHeight;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            *(GetOutputBufferToUpdate() +
                CONSOLE_WIDTH * startPos.posY + startPos.posX +
                i * CONSOLE_WIDTH + j) =
                *(sceneNode->GetCamAddr()->GetCamBuffer() +
                    i * width + j);
        }
    }

    if (sceneNode->BaseUIObj != NULL)
    {
        DrawUIO(sceneNode->BaseUIObj);
    }
}
