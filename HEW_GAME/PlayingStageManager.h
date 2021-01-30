//------------------------------------------------------------------------
// �ե�������: PlayingStageManager.h
// �C��: �����Ʃ`���������C�ܤ��ṩ
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// ���Ʃ`������C�ܤ���ڻ�����
/// </summary>
void InitPlayingStage();

/// <summary>
/// ���Ʃ`������C�ܤ�g��
/// </summary>
void UpdatePlayingStage();

/// <summary>
/// ���Ʃ`������C�ܤ��]����
/// </summary>
void TurnOffPlayingStage();

/// <summary>
/// ���x�k����Ƥ��륹�Ʃ`����ȡ��
/// </summary>
/// <returns>���Ʃ`������</returns>
int GetPlayingStageByManager();

/// <summary>
/// �x�k���줿���Ʃ`���򱣴�
/// </summary>
/// <param name="stageID">�x�k���줿���Ʃ`���η���</param>
void SetPlayingStageByManager(int stageID);

/// <summary>
/// ���椵�줿���Ʃ`����ꥻ�å�
/// </summary>
void ResetPlayingStageByManager();
