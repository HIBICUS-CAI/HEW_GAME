//------------------------------------------------------------------------
// �ե�������: ResortNameManager.h
// �C��: �꥾�`����ǰ�����ɡ�������C�ܤ��ṩ
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// �꥾�`����ǰ���v���Ƥ����ݤ���ڻ�����
/// </summary>
void InitResortNameManager();

/// <summary>
/// �꥾�`����ǰ���v���Ƥ΄I����Ф�
/// </summary>
void UpdateResortNameManager();

/// <summary>
/// �꥾�`����ǰ���v���Ƥ΄I����]����
/// </summary>
void TurnOffResortNameManager();

/// <summary>
/// �_�����줿��ǰ���v�B�����򱣴椹��
/// </summary>
void SaveConfirmedName();

/// <summary>
/// �R�r�Ĥʥץ�ե��å������O��
/// </summary>
/// <param name="value">�ܥ���</param>
void SetTempName1(int value);

/// <summary>
/// �R�r�Ĥʥ��ե��å������O��
/// </summary>
/// <param name="value">�ܥ���</param>
void SetTempName2(int value);
