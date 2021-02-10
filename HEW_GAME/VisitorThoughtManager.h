//------------------------------------------------------------------------
// �ե�������: VisitorThoughtManager.h
// �C��: ���Q��ͤ��[�֕r���������
//------------------------------------------------------------------------

#pragma once

#include "GameAppStructs.h"

/// <summary>
/// ����C�ܤˤ�ä�һ�ķN��Q��ͤ�һ�Ĥθ��������
/// </summary>
/// <param name="visitorType">�Q��ͤηN�</param>
/// <param name="buildType">ʩ�O�ηN�</param>
/// <param name="buildEvent">ʩ�O������</param>
void CreateSingleVisitorThoughtByManager(VISITOR_TYPE visitorType, int buildType, int buildEvent);
