//------------------------------------------------------------------------
// �t�@�C����: PlayingStageManager.h
// �@�\: �e�X�e�[�W���Ǘ�����@�\���
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// �X�e�[�W�Ǘ��@�\������������
/// </summary>
void InitPlayingStage();

/// <summary>
/// �X�e�[�W�Ǘ��@�\�����s
/// </summary>
void UpdatePlayingStage();

/// <summary>
/// �X�e�[�W�Ǘ��@�\�����
/// </summary>
void TurnOffPlayingStage();

/// <summary>
/// ���I������Ă���X�e�[�W���擾
/// </summary>
/// <returns>�X�e�[�W�ԍ�</returns>
int GetPlayingStageByManager();

/// <summary>
/// �I�����ꂽ�X�e�[�W��ۑ�
/// </summary>
/// <param name="stageID">�I�����ꂽ�X�e�[�W�̔ԍ�</param>
void SetPlayingStageByManager(int stageID);

/// <summary>
/// �ۑ����ꂽ�X�e�[�W�����Z�b�g
/// </summary>
void ResetPlayingStageByManager();
