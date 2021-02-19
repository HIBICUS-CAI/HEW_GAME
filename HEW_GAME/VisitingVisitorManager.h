//------------------------------------------------------------------------
// �t�@�C����: VisitingVisitorManager.h
// �@�\: �ό��q���V�Ԏ��Ɋւ��Ă̏���
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// �ό��q���V�Ԏ��Ɋւ��Ă̏�����������
/// </summary>
void InitVisitingVisitorManager();

/// <summary>
/// �ό��q���V�Ԏ��Ɋւ��Ă̏��������s����
/// </summary>
void UpdateVisitingVisitorManager();

/// <summary>
/// �ό��q���V�Ԏ��Ɋւ��Ă̏��������
/// </summary>
void TurnOffVisitingVisitorManager();

/// <summary>
/// �ό��q�A�{�݂Ɣw�i�������邩�ǂ���
/// </summary>
/// <returns>�����邩�ǂ���</returns>
int ResortCanMove();

/// <summary>
/// �ړ��t���O�����Z�b�g����
/// </summary>
void ResetResortMoveFlag();

/// <summary>
/// ���~�܂��Ă���ʒu�Ɏ{�݂̎��
/// </summary>
/// <returns>�{�݂̎��</returns>
int GetCurrColliedBuildingType();

/// <summary>
/// ���~�܂��Ă���ʒu�Ɏ{�݂̓��e
/// </summary>
/// <returns>�{�݂̓��e</returns>
int GetCurrColliedBuildingEvent();

/// <summary>
/// ���̃��]�[�g�̖��O���擾
/// </summary>
/// <returns>���]�[�g�̖��O�Ɏw���̃|�C���^</returns>
char* GetResortName();
