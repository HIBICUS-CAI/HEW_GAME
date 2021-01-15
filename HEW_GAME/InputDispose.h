//------------------------------------------------------------------------
// �ե�������: UIObject.h
// �C��: �գɥ����ƥ���v���Ƥ΄I��
//------------------------------------------------------------------------

#pragma once

#include <conio.h>
#include <windows.h>
#include "Structs.h"

/// <summary>
/// ���������ƥ����ڻ�����
/// </summary>
void InitInputQueue();

/// <summary>
/// �����ꥹ�Ȥ�����
/// </summary>
/// <returns>�ɣΣ��ͥꥹ�ȤΘ�����ݥ���</returns>
QUEUE_INT* CreateInputQueue();

/// <summary>
/// ���������ƥ��g��
/// </summary>
void Input();

/// <summary>
/// Ѻ���줿���`�ܩ`�ɤΥܥ����ȡ��
/// </summary>
void InsertInput();

/// <summary>
/// �ޥ������åɤ�Ѻ���줿���`�ܩ`�ɤΥܥ����ȡ��
/// </summary>
void InsertInputMT();

/// <summary>
/// ���������ƥबʹ�äƤ��륹��åɤ��]����
/// </summary>
void TurnOffMTInput();

/// <summary>
/// ȡ��줿�ܥ����I����
/// </summary>
void DisposeInput();

/// <summary>
/// �ܥ���΂��ˤ�äƙC�ܤ�g��
/// </summary>
/// <param name="keyCode">�����ꥹ�Ȥ���ȡ���������</param>
void DispatchInput(int keyCode);

/// <summary>
/// �����ꥹ�Ȥ�ȡ��
/// </summary>
/// <returns>�����ꥹ��ָ��Υݥ���</returns>
QUEUE_INT* GetInputQueue();
