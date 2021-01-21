//------------------------------------------------------------------------
// �ե�������: Tools.h
// �C��: �j�ʙC�ܤ��ṩ����
//------------------------------------------------------------------------

#pragma once

#include <stdlib.h>
#include <time.h>
#include "Structs.h"
#include "DeclaredValues.h"

/// <summary>
/// �����������Ƥ΄I��һ��ѭ�h�����Ƥ����ä��Εr�g���O��
/// </summary>
/// <param name="time">һ�ؤ�ѭ�h�������ä��r�g</param>
void SetDeltaTime(int time);

/// <summary>
/// ǰ�ؤ�ѭ�h�����ä��Εr�g��ȡ��
/// </summary>
/// <returns>ǰ�ؤ�ѭ�h�����ä��Εr�g</returns>
int GetDeltaTime();

/// <summary>
/// �F�g��ǰ�ؤ�ѭ�h�����ä��Εr�g��ȡ��
/// </summary>
/// <returns>�F�g��ǰ�ؤ�ѭ�h�����ä��Εr�g</returns>
int GetRealDeltaTime();

/// <summary>
/// ǰ�ؤ�ѭ�h�r�g�ˤ�äƣƣУӤ�Ӌ�㡢��������
/// </summary>
void ShowFPSMT();

/// <summary>
/// �g�п��ܥץ����Υ����ȥ���O��
/// </summary>
void InitTitle();

/// <summary>
/// �����ȥ���]����
/// </summary>
void CloseTitle();

/// <summary>
/// ����ɣΣ���������������Ӌ�㤹��
/// </summary>
/// <param name="value">Ӌ�㤵����������</param>
/// <returns>����������</returns>
int GetIntValueBit(int value);

/// <summary>
/// �ɣΣ��ͤΥꥹ�Ȥ��������
/// </summary>
/// <returns>���Υꥹ�ȤΥإåɥݥ���</returns>
QSINGLENODE* CreateQueue();

/// <summary>
/// ����ꥹ�Ȥ�����������
/// </summary>
/// <param name="end">�ꥹ�ȤΥ���ɥݥ���</param>
/// <param name="data">��줿������</param>
/// <returns>�¤�������ɥݥ���</returns>
QSINGLENODE* EnQueue(QSINGLENODE* end, int data);

/// <summary>
/// ����ꥹ�Ȥ���������ȡ�����
/// </summary>
/// <param name="top">�ꥹ�ȤΥإåɥݥ���</param>
/// <param name="end">�ꥹ�ȤΥ���ɥݥ���</param>
/// <returns>ȡ������줿����</returns>
int DeQueue(QSINGLENODE* top, QSINGLENODE* end);

/// <summary>
/// �ض��ʷN�������N���O��
/// </summary>
/// <param name="seedNum">�N������</param>
void SetRandomBySeed(int seedNum);

/// <summary>
/// �r�g�������N���O��
/// </summary>
void SetRandom();

/// <summary>
/// ���빠����Ф������ͤ����������ɤ���
/// </summary>
/// <param name="minNum">������Ф�һ��С������</param>
/// <param name="maxNum">������Ф�һ���󤭤���</param>
/// <returns>���ɤ��줿����</returns>
int CreateRandomNumIn(int minNum, int maxNum);

/// <summary>
/// ���󥽩`���ɫ��仯������
/// </summary>
/// <param name="color">�������줿ɫ�΂���һ��</param>
void ChangeColorInConsole(int color);

/// <summary>
/// ���󥽩`���ɫ��ꥻ�å�
/// </summary>
void ResetColorInConsole();

/// <summary>
/// �ե�`���ͤ΂���󤭤��ˤ�äƥ�����ͤˉ������
/// </summary>
/// <param name="value">�������������</param>
/// <returns>������줿�΂�</returns>
int RoundFloatToInt(float value);

/// <summary>
/// �ף��֥ե�����������Ф˕����z��
/// </summary>
/// <param name="fname">�����ե�������</param>
/// <param name="pMemBites">�����z���줿����ָ��Υݥ���</param>
/// <param name="pMemBitesWithVol">�������������z���줿����ָ��Υݥ���</param>
/// <param name="fileSize">�����ե�����Υ�����</param>
void ReadWavFileIntoMemory(const char* fname, BYTE** pMemBites, BYTE** pMemBitesWithVol, DWORD* fileSize);

void TestBGM();
