//------------------------------------------------------------------------
// �ե�������: LogsOutput.h
// �C��: ɫ��ʥ��򥢥��ȥץåșڤ˳�������
//------------------------------------------------------------------------

#pragma once

#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

/// <summary>
/// �g�������֥���ڤ˳�������
/// </summary>
/// <param name="text">��������</param>
void DebugLog(const char* text);

/// <summary>
/// �ɣΣ������ݤ������Ƥ������ڤ˳�������
/// </summary>
/// <param name="text">������������</param>
/// <param name="value">�ɣΣ��ͤ�����</param>
void DebugLogI1(const char* text, const int value);

/// <summary>
/// �ɣΣ������ݤ������Ƥ������ڤ˳�������
/// </summary>
/// <param name="text">������������</param>
/// <param name="value1">�ɣΣ��ͤ�����</param>
/// <param name="value2">�ɣΣ��ͤ�����</param>
void DebugLogI2(const char* text, const int value1, const int value2);

/// <summary>
/// ����ե�����˕����z��
/// </summary>
/// <param name="text">��������</param>
void DebugLogToFile(const char* text);

/// <summary>
/// �g���ʥ���`����ڤ˳�������
/// </summary>
/// <param name="text">������������</param>
void ErrorLog(const char* text);

/// <summary>
/// �ɣΣ������ݤ������Ƥ��륨��`����ڤ˳�������
/// </summary>
/// <param name="text">������������</param>
/// <param name="value">�ɣΣ��ͤ�����</param>
void ErrorLogI1(const char* text, const int value);

/// <summary>
/// �ɣΣ������ݤ������Ƥ��륨��`����ڤ˳�������
/// </summary>
/// <param name="text">������������</param>
/// <param name="value1">�ɣΣ��ͤ�����</param>
/// <param name="value2">�ɣΣ��ͤ�����</param>
void ErrorLogI2(const char* text, const int value1, const int value2);
