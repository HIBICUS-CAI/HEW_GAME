//------------------------------------------------------------------------
// �ե�������: GameApp.h
// �C��: ���`��λ���ѭ�h
//------------------------------------------------------------------------

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Structs.h"

/// <summary>
/// ���`�ब��Ҫ�ʤ�Τ�ȫ�����ڻ�����
/// </summary>
/// <returns>�ɹ����ɤ�����ʾ��</returns>
int Init();

/// <summary>
/// ���`���g�Ф���
/// </summary>
void RunGame();

/// <summary>
/// ���`����]����
/// </summary>
void TurnOff();

/// <summary>
/// ���`���Ҫ�ؤ���¤���
/// </summary>
void Update();

/// <summary>
/// �����åХåե����������ФΤ褦�˳�������
/// </summary>
void Draw();
