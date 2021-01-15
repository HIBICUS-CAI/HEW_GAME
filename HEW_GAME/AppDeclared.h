//------------------------------------------------------------------------
// �ե�������: AppDeclared.h
// �C��: ����Ҫ�ؤ��v���Ƥ΂�������
//------------------------------------------------------------------------

#pragma once
#include "GameAppStructs.h"

#define SCENENODESIZE 20

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
