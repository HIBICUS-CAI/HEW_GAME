//------------------------------------------------------------------------
// �ե�������: ConsolePrint.h
// �C��: �����åХåե������ݤ򥳥󥽩`��˳�������
//------------------------------------------------------------------------

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"

/// <summary>
/// ���󥽩`��δ󤭤��ȥХåե�����ڻ�����
/// </summary>
void InitOutputBuffer();

/// <summary>
/// ǰ�س����åХåե��˕����z������ݤ����
/// </summary>
void ClearOutputBuffer();

/// <summary>
/// �����åХåե������ݤ��������Ф��Τǳ�������
/// </summary>
void PrintOutputBuffer();

/// <summary>
/// �����åХåե��˱�Ҫ�ʸ�����헤��Ф�
/// </summary>
void UpdateOutputBuffer();

/// <summary>
/// ����λ�ä����ݤ�ֱ�Ӥ˕����z��
/// </summary>
/// <param name="position">�����z������</param>
/// <param name="text">�����z�ߤ�������</param>
void WriteCharIntoOutputBuffer(POSITION_2D position, const char text);

/// <summary>
/// ����λ�ä������������ݤ�����z��
/// </summary>
/// <param name="startPos">�����z������</param>
/// <param name="text">�����z�ߤ�����������</param>
void WriteStrIntoOutputBufferByPos(POSITION_2D startPos, const char* text);

/// <summary>
/// ����λ�ä��������Ф�����������z��
/// </summary>
/// <param name="startPos">�����z������</param>
/// <param name="text">�����z�ߤ�����������</param>
/// <param name="value">�����z�ߤ�����</param>
void WriteStrInt1IntoOutputBufferByPos(POSITION_2D startPos, const char* text, int value);

/// <summary>
/// ���������ϥ�ɥ���]����
/// </summary>
void CloseMTPrint();
