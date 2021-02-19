//------------------------------------------------------------------------
// �t�@�C����: DialogShower.h
// �@�\: �Θb���s�������s���ׂ��̏���
//------------------------------------------------------------------------

#pragma once

#define PEOPLE_SPRITE_SIZE 16

/// <summary>
/// �Θb�����@�\������������
/// </summary>
void InitDialogShower();

/// <summary>
/// �Θb�����@�\�����s����
/// </summary>
void UpdateDialogShower();

/// <summary>
/// �Θb�����@�\�����
/// </summary>
void TurnOffDialogShower();

/// <summary>
/// �Θb�C���f�b�N�X���擾
/// </summary>
/// <returns>�Θb�C���f�b�N�X</returns>
int GetDialogIndex();

/// <summary>
/// �Θb�C���f�b�N�X��ݒ�
/// </summary>
/// <param name="value">�ݒ肳�������l</param>
void SetDialogIndex(int value);

/// <summary>
/// �Θb�C�x���g���I��钼��֘A�ϐ������Z�b�g
/// </summary>
void ResetUsingPointerAndFlag();

/// <summary>
/// ���������Ă���l���ς������X�v���C�g���ς���Ă���
/// </summary>
/// <param name="thisName">�������Ă���l</param>
/// <param name="preName">�O�񒝂����l</param>
void SwitchSprite(char* thisName, char* preName);

/// <summary>
/// �X�v���C�g�A�j���^���t���O�ɂ���ăX�v���C�g���X�V
/// </summary>
void DrawTalkingSprite();
