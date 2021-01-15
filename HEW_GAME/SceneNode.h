//------------------------------------------------------------------------
// �ե�������: SceneNode.h
// �C��: ���`����v���ƤΙC��
//------------------------------------------------------------------------

#pragma once

#include "AppDeclared.h"
#include "UIObject.h"
#include "DeclaredValues.h"

/// <summary>
/// ���ŤǤ��륷�`���ȡ�����
/// </summary>
/// <param name="id">���`�󷬺�</param>
/// <returns>ȡ������������`���ָ��Υݥ���</returns>
SCENENODE* GetSceneNodeByID(int id);

/// <summary>
/// ��ǰ�Ǥ��륷�`���ȡ�����
/// </summary>
/// <param name="name">���`�����ǰ</param>
/// <returns>ȡ������������`���ָ��Υݥ���</returns>
SCENENODE* GetSceneNodeByName(const char* name);

/// <summary>
/// ���`�����Ф���ڻ�����
/// </summary>
void InitSceneNodes();

/// <summary>
/// ���륷�`��Υ����Хåե���������
/// </summary>
/// <param name="sceneNode">���`��ָ��Υݥ���</param>
void ClearSceneCamBuffer(SCENENODE* sceneNode);

/// <summary>
/// ���`�����Ф��¤��ʥ��`���׷��
/// </summary>
/// <param name="sceneNode">�¤��ʥ��`�������</param>
void CreateSceneNode(SCENENODE sceneNode);

/// <summary>
/// ���륷�`������ݤ�����åХåե��˕����z��
/// </summary>
/// <param name="sceneNode">���`��ָ��Υݥ���</param>
void DrawScene(SCENENODE* sceneNode);
