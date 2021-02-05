//------------------------------------------------------------------------
// �ե�������: DeclaredValues.h
// �C��: ����ʥ���`�Х��������������
//------------------------------------------------------------------------

#pragma once

#include "DefinedValues.h"
#include "Structs.h"

/// <summary>
/// ���`�ब�A���뤫�ɤ������O��
/// </summary>
/// <param name="value">���ʤ饲�`�ब�A���ʤ�</param>
void SetGameRunFlag(int value);

/// <summary>
/// ���`�ब�A���뤫�ɤ�����ȡ��
/// </summary>
/// <returns>�A����Τ��뤷</returns>
int GetGameRunFlag();

#define DELTATIME 16

/// <summary>
/// �O�����줿�ե�`���r�g��ȡ��
/// </summary>
/// <returns>�O�����줿�ե�`���r�g</returns>
int GetDeclaredDeltaTime();

/// <summary>
/// �ե�`���r�g���O������
/// </summary>
/// <param name="value">�ե�`���r�g</param>
void SetDeclaredDeltaTime(int value);

/// <summary>
/// �����ϥ�ɥ��ȡ��
/// </summary>
/// <returns>���������ϥ�ɥ�</returns>
HANDLE GetPrintHandle();

/// <summary>
/// �����ϥ�ɥ���O��
/// </summary>
/// <param name="handle">���������ϥ�ɥ�</param>
void SetPrintHandle(HANDLE handle);

/// <summary>
/// �����åХåե��ȳ����åХåե��򽻓Q
/// </summary>
void SwapPrintChain();

/// <summary>
/// �����åХåե���ȡ��
/// </summary>
/// <returns>�����åХåե���ָ��Υݥ���</returns>
char* GetOutputBufferToUpdate();

/// <summary>
/// �����åХåե���ȡ��
/// </summary>
/// <returns>�����åХåե���ָ��Υݥ���</returns>
char* GetOutputBufferToPrint();

#define UIOBJSIZE 32

/// <summary>
/// �գɥ����ƥ����Ф�ȡ��
/// </summary>
/// <returns>�գɥ����ƥ����ФΥإåɥݥ���</returns>
UIOBJECT* GetUIObj();

/// <summary>
/// �գɥ����ƥ����ФάF�ڷ���
/// </summary>
/// <returns>�F�ڤη���</returns>
int* GetUIOIndex();

/// <summary>
/// �գɥ����ƥ����ФάF�ڷ��Ť��O��
/// </summary>
/// <param name="value">���Ť΂�</param>
void SetUIOIndex(int value);

/// <summary>
/// �գɥ����ƥ����ФάF�ڷ��Ť򣱤��㤹
/// </summary>
void AddUIOIndex();

/// <summary>
/// �F��������A�ʣգɥ����ƥ��ȡ��
/// </summary>
/// <returns>�����A�Σգɥ����ƥ��ָ��Υݥ���</returns>
UIOBJECT* GetTopUIO();

/// <summary>
/// �����A�Σգɥ����ƥ���O��
/// </summary>
/// <param name="uiObj">�գɥ����ƥ�ָ��Υݥ���</param>
void SetTopUIO(UIOBJECT* uiObj);

/// <summary>
/// �Хåե����Q������������ȡ��
/// </summary>
/// <returns>�����å����ƥ�</returns>
CRITICAL_SECTION* GetSwapChainCS();

/// <summary>
/// ���x�k���줿�ܥ����ȡ��
/// </summary>
/// <returns>�x�k���줿�ܥ����ָ��Υݥ���</returns>
UI_BUTTON* GetSelectedBtn();

/// <summary>
/// �x�k�����ܥ�����O��
/// </summary>
/// <param name="btn">�ܥ����ָ��Υݥ���</param>
void SetSelectedBtn(UI_BUTTON* btn);

/// <summary>
/// �ԄӵĤ˥ܥ�����O������ӛ�Ť�ȡ��
/// </summary>
/// <returns>ӛ�Ť�ָ��Υݥ���</returns>
int* GetAutoSelectBtnFlag();

/// <summary>
/// �Ԅӵĥܥ�����O�������ӛ�Ť��O��
/// </summary>
/// <param name="value">ӛ�Ť΂�</param>
void SetAutoSelectBtnFlag(int value);

#define SOUNDFILE_SIZE 64

#ifdef SOUNDBYHAL
/// <summary>
/// ��{���줿�������ե��������Ф�ȡ��
/// </summary>
/// <returns>��{���줿�������ե���������ָ��Υݥ���</returns>
SOUNDFILE_LOADED* GetSoundFilesInMemBitesArray();
#else
/// <summary>
/// ��{���줿�������ե��������Ф�ȡ��
/// </summary>
/// <returns>��{���줿�������ե���������ָ��Υݥ���</returns>
SOUNDFILE_IN_MEMBITE* GetSoundFilesInMemBitesArray();
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// ��ǰ�ˤ�äƸ�{���줿�������ե������ȡ��
/// </summary>
/// <param name="fileName">��{���줿�����ե��������ǰ</param>
/// <returns>��{���줿�����ե�����ָ��Υݥ���</returns>
SOUNDFILE_LOADED* GetSoundFilesInMemBites(const char* soundName);
#else
/// <summary>
/// ��ǰ�ˤ�äƸ�{���줿�������ե������ȡ��
/// </summary>
/// <param name="fileName">��{���줿�����ե��������ǰ</param>
/// <returns>��{���줿�����ե�����ָ��Υݥ���</returns>
SOUNDFILE_IN_MEMBITE* GetSoundFilesInMemBites(const char* fileName);
#endif // SOUNDBYHAL

#ifndef SOUNDBYHAL

#define SOUNDHANDLE_SIZE 8

/// <summary>
/// �����ϥ�ɥ����Ф�ȡ��
/// </summary>
/// <returns>�����ϥ�ɥ����Ф�ָ��Υݥ���</returns>
SOUND_THREAD_HANDLE* GetSoundHandleArray();

/// <summary>
/// ʹ�äƤ��ʤ������ϥ�ɥ��ȡ��
/// </summary>
/// <returns>ʹ�äƤ��ʤ������ϥ�ɥ똋����ָ��Υݥ���</returns>
SOUND_THREAD_HANDLE* GetSoundHandleThatNotUsing();

#endif // !SOUNDBYHAL
