//------------------------------------------------------------------------
// �ե�������: SceneManager.h
// �C��: ȫ�ƤΥ��`��������C��
//------------------------------------------------------------------------

#pragma once
#include "GameAppStructs.h"

#define TESTSCENEFLAG 1
#define TITLESCENEFLAG 2
#define DIALOGSCENEFLAG 3
#define SELECTSCENEFLAG 4
#define NAMINGSCENEFLAG 5
#define BUILDINGSCENEFLAG 6
#define RESORTSCENEFLAG 7
#define EVENTSCENEFLAG 8
#define FEELINGSCENEFLAG 9
#define RESULTSCENEFLAG 10

/// <summary>
/// ���`��Τ��뤷ȡ��
/// </summary>
/// <returns>���`���ӛ��</returns>
int GetSceneFlag();

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
