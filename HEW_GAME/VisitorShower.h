//------------------------------------------------------------------------
// �ե�������: VisitorShower.h
// �C��: ���ɤ��줿�Q��ͤ��ʾ������
//------------------------------------------------------------------------

#pragma once

#define VISITORTYPE_MAXSIZE 9 

/// <summary>
/// �Q��ͥ��˥᥿�����ڻ�����
/// </summary>
void InitVisitorShower();

/// <summary>
/// �Q��ͥ��˥᥿���g�Ф���
/// </summary>
void UpdateVisitorShower();

/// <summary>
/// �Q��ͥ��˥᥿����]����
/// </summary>
void TurnOffVisitorShower();

/// <summary>
/// �Q��ͥ��ץ饤�Ȥ��ʾ���뤫�ɤ������O��
/// </summary>
/// <param name="flag">��ʾ�Υե饰</param>
void SetShowVisitorFlg(int flag);

/// <summary>
/// �Q��ͥ��ץ饤�ȱ�ʾ���v���Ƥ����ݤ�ꥻ�å�
/// </summary>
void ResetAllAboutShowVisitors();
