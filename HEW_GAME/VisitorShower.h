//------------------------------------------------------------------------
// �t�@�C����: VisitorShower.h
// �@�\: �쐬���ꂽ�ό��q��\��������
//------------------------------------------------------------------------

#pragma once

#define VISITORTYPE_MAXSIZE 9 

/// <summary>
/// �ό��q�A�j���^��������������
/// </summary>
void InitVisitorShower();

/// <summary>
/// �ό��q�A�j���^�������s����
/// </summary>
void UpdateVisitorShower();

/// <summary>
/// �ό��q�A�j���^�������
/// </summary>
void TurnOffVisitorShower();

/// <summary>
/// �ό��q�X�v���C�g��\�����邩�ǂ�����ݒ�
/// </summary>
/// <param name="flag">�\���̃t���O</param>
void SetShowVisitorFlg(int flag);

/// <summary>
/// �ό��q�X�v���C�g�\���Ɋւ��Ă̓��e�����Z�b�g
/// </summary>
void ResetAllAboutShowVisitors();
