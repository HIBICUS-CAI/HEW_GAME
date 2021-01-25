//------------------------------------------------------------------------
// �ե�������: AppDeclared.h
// �C��: ����Ҫ�ؤ��v���Ƥ΂�������
//------------------------------------------------------------------------

#pragma once
#include "GameAppStructs.h"

#define SCENENODESIZE 20

#define START_NEW_GAME 0x0003
#define LOAD_GAME_DATA 0x0004
#define LOAD_DATA_1 0x0005
#define LOAD_DATA_2 0x0006
#define LOAD_DATA_3 0x0007
#define GAME_SIMPLY_MANUAL 0x0008
#define THIS_GAME_LINK 0x0009
#define CLOSE_SAVE_DATA 0x000a
#define CLOSE_MANUAL 0x000b
#define CLOSE_LINK 0x000c
#define DIALOG_NEXT 0x000d

/// <summary>
/// ���`�����Ф�ȡ��
/// </summary>
/// <returns>���`������</returns>
SCENENODE* GetSceneNodeArray();

/// <summary>
/// ���`�����Ф��O��
/// </summary>
/// <param name="index">���`���ƫ����</param>
/// <param name="temp">�R�r�Ĥʥ��`������</param>
void SetSceneNodeArray(int index, SCENENODE temp);

/// <summary>
/// ʹ�äƤ��륷�`����O��
/// </summary>
/// <param name="sceneNode">���`��ָ��Υݥ���</param>
void SetCurrScene(SCENENODE* sceneNode);

/// <summary>
/// ʹ�äƤ��륷�`���ȡ��
/// </summary>
/// <returns>���`��ָ��Υݥ���</returns>
SCENENODE* GetCurrScene();
