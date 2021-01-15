//------------------------------------------------------------------------
// �ե�������: SceneManager.h
// �C��: ȫ�ƤΥ��`��������C��
//------------------------------------------------------------------------

#pragma once
#include "GameAppStructs.h"

/// <summary>
/// ��ʹ�äƤ��륷�`����O��
/// </summary>
/// <param name="sceneNode">���`��ָ��Υݥ���</param>
void SetManagedCurrScene(SCENENODE* sceneNode);

/// <summary>
/// ��ʹ�äƤ��륷�`���ȡ��
/// </summary>
/// <returns>���`��ָ��Υݥ���</returns>
SCENENODE* GetManagedCurrScene();

/// <summary>
/// ʹ�äƤ��륷�`�����ڻ�����
/// </summary>
void InitCurrScene();

/// <summary>
/// ʹ�äƤ��륷�`�����¤���
/// </summary>
void UpdateCurrScene();

/// <summary>
/// ���륷�`��ˉ�Q����
/// </summary>
/// <param name="sceneName">���`�����ǰ</param>
void SwitchSceneToName(const char* sceneName);
