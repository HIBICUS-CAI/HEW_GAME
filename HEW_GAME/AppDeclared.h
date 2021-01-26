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
#define NAMING_SUB_1 0x000e
#define NAMING_SUB_2 0x000f
#define CONFIRM_NAME 0x0010
#define BACK_TO_NAME_1 0x0011
#define BACK_TO_NAME_2 0x0012
#define SET_BUILDING_TYPE 0x0013
#define SET_BUILDING_EVENT 0x0014
#define CONFIRM_BUILDING 0x0015
#define BACK_TO_BUILD_TYPE 0x0016
#define BACK_TO_BUILD_EVENT 0x0017
#define SAVE_GAME_DATA 0x0018
#define BACK_TO_TITLE 0x0019
#define BEGIN_STAGE_1 0x001a
#define BEGIN_STAGE_2 0x001b
#define BEGIN_STAGE_3 0x001c

#define DIALOG_NOTHING 0x01
#define DIALOG_NEW_GAME 0x02

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

/// <summary>
/// ��Ԓ�¼��η��Ť�ȡ��
/// </summary>
/// <returns>��Ԓ�¼��η���</returns>
int GetDialogEvent();

/// <summary>
/// ��Ԓ�¼��η��Ť��O��
/// </summary>
/// <param name="id">��Ԓ�¼��η���</param>
void SetDialogEvent(int id);

/// <summary>
/// ����Ԓ�ϽK��ä���
/// </summary>
/// <returns>�K��ä����ɤ����Θ��R</returns>
int IsDialogFinish();

/// <summary>
/// ����Ԓ�¼��ϽK��ä������O��
/// </summary>
/// <param name="id">���R</param>
void SetIsDialogFinish(int value);
