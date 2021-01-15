//------------------------------------------------------------------------
// �ե�������: UIObject.h
// �C��: �գɥ����ƥ���v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

#include <stdlib.h>
#include "DefinedValues.h"
#include "Structs.h"

/// <summary>
/// �գɥ����ƥ����Ф���ڻ�����
/// </summary>
void InitUIObj();

/// <summary>
/// �����ƥ�η��ŤǤ���գɥ����ƥ��ȡ�����
/// </summary>
/// <param name="id">�������գɥ����ƥ�η���</param>
/// <returns>���Ťˏꤸ�Ƥ���գɥ����ƥ�</returns>
UIOBJECT* GetUIObjByID(int id);

/// <summary>
/// �����ƥ����ǰ�Ǥ���գɥ����ƥ��ȡ�����
/// </summary>
/// <param name="name">�������գɥ����ƥ����ǰ</param>
/// <returns>��ǰ�ˏꤸ�Ƥ���գɥ����ƥ�</returns>
UIOBJECT* GetUIObjByName(const char* name);

/// <summary>
/// �գɥ����ƥ���������
/// </summary>
/// <param name="name">�����ƥ����ǰ</param>
/// <param name="startPoint">�����ƥ��ʼ������</param>
/// <param name="width">�����ƥ���L��</param>
/// <param name="height">�����ƥ�θߤ�</param>
/// <param name="design">�����ƥ����Υǥ�����</param>
/// <param name="parent">���Υ����ƥ���H�����ƥ�</param>
/// <param name="child">���Υ����ƥ���ӥ����ƥ�</param>
/// <param name="visiblity">�����ƥ�ο�ҕ��</param>
/// <returns>���줿�����ƥ�Υݥ���</returns>
UIOBJECT* CreateUIO(const char* name, POSITION_2D startPoint, int width, int height,
    UIO_DESIGN design, UIOBJECT* parent = NULL, UIOBJECT* child = NULL,
    int visiblity = 0);

/// <summary>
/// �գɥ����ƥ������åХåե��˕����z��
/// </summary>
/// <param name="uiObject">�����z�ߤ��������ƥ��ָ��Υݥ���</param>
void DrawUIO(UIOBJECT* uiObject);

/// <summary>
/// �����ƥ��Ф��������ݤ�����åХåե��˕����z��
/// </summary>
/// <param name="uiObject">�����z�ߤ��������ƥ��ָ��Υݥ���</param>
void DrawTextInUIO(UIOBJECT* uiObject);

/// <summary>
/// �����ƥ��ФΥܥ������ݤ�����åХåե��˕����z��
/// </summary>
/// <param name="uiObject">�����z�ߤ��������ƥ��ָ��Υݥ���</param>
void DrawBtnInUIO(UIOBJECT* uiObject);
