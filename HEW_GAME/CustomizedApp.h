//------------------------------------------------------------------------
// �ե�������: CustomizedApp.h
// �C��: ���`��Β���Ҫ�ؤ��v���Ƥ��a��
//------------------------------------------------------------------------

#pragma once

#include "Structs.h"

/// <summary>
/// ����Ҫ�ؤ���ڻ�����
/// </summary>
void AppInit();

/// <summary>
/// ����Ҫ�ؤ���¤���
/// </summary>
void AppUpdate();

/// <summary>
/// ����Ҫ�ؤ��]����
/// </summary>
void AppTurnOff();

/// <summary>
/// ����Ҫ�ؤΥ��`�ܩ`�ɥ��٥�Ȥ��Ф�
/// </summary>
/// <param name="keyCode">���`����</param>
void AppKeyboardEvent(int keyCode);

/// <summary>
/// ����Ҫ�ؤΥܥ��󥤥٥�Ȥ��Ф�
/// </summary>
/// <param name="value">�ܥ��󷬺�</param>
void AppButtonEvent(int value);

/// <summary>
/// ����Ҫ�ؤ����Υ��ե����Ȥǳ�������
/// </summary>
void AppPostPrint();
