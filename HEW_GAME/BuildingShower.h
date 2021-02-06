//------------------------------------------------------------------------
// �ե�������: BuildingShower.h
// �C��: ʩ�O���ɤ��v���Ƥα�ʾ���ݳ��I��
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

#define SPRING_OFFSET 0
#define FOOD_OFFSET 1
#define POOL_OFFSET 2
#define DRINK_OFFSET 3
#define CINEMA_OFFSET 4
#define KARAOKE_OFFSET 5
#define HOTEL_OFFSET 6
#define CAMP_OFFSET 7
#define HANDMAKE_OFFSET 8

/// <summary>
/// ʩ�O���ɤ��v���Ƥα�ʾ���ݳ��I�����ڻ�����
/// </summary>
void InitBuildingShower();

/// <summary>
/// ʩ�O���ɤ��v���Ƥα�ʾ���ݳ��I���g�Ф���
/// </summary>
void UpdateBuildingShower();

/// <summary>
/// ʩ�O���ɤ��v���Ƥα�ʾ���ݳ��I����]����
/// </summary>
void TurnOffBuildingShower();

/// <summary>
/// �����äƤ���λ�ä˥ϥ�ޤ��ݳ����ʾ����
/// </summary>
void ShowBuildingHammer();

/// <summary>
/// ʩ�O���ɤ��v���Ƥα�ʾ���ݳ��I��Εr�g��ꥻ�åȤ���
/// </summary>
void ResetBuildingShowerTimer();

/// <summary>
/// ��ʩ�O�Υ��ץ饤�Ȥ򱣴椷�Ƥ������Ф�ȡ��
/// </summary>
/// <returns>���ץ饤�Ȥ򱣴椷�Ƥ������Ф�ָ��Υݥ���</returns>
SPRITE* GetBuildingSprites();
