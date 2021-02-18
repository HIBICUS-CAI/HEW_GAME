//------------------------------------------------------------------------
// �ե�������: AppDeclared.h
// �C��: ����Ҫ�ؤ��v���Ƥ΂�������
//------------------------------------------------------------------------

#pragma once
#include "GameAppStructs.h"

#define SCENENODESIZE 20

//------------------------------
#define TEMP_BTN_DIALOG_1 0x1000

#define START_NEW_GAME 0x0003
#define LOAD_GAME_DATA 0x0004
#define LOAD_DATA_1 0x0005
#define LOAD_DATA_2 0x0006
#define LOAD_DATA_3 0x0007
#define GAME_SIMPLY_MANUAL 0x0008
#define THIS_GAME_LINK 0x0009
#define CLOSE_SAVE_DATA 0x000a
#define CLOSE_MANUAL 0x000b
#define CLOSE_LINK 0x000c
#define DIALOG_NEXT 0x000d
#define NAMING_SUB_1 0x000e
#define NAMING_SUB_2 0x000f
#define CONFIRM_NAME 0x0010
#define BACK_TO_NAME_1 0x0011
#define BACK_TO_NAME_2 0x0012
#define SET_BUILDING_TYPE 0x0013
#define SET_BUILDING_EVENT 0x0014
#define CONFIRM_BUILDING 0x0015
#define BACK_TO_BUILD_TYPE 0x0016
#define BACK_TO_BUILD_EVENT 0x0017
#define SAVE_GAME_DATA 0x0018
#define BACK_TO_TITLE 0x0019
#define BEGIN_STAGE_1 0x001a
#define BEGIN_STAGE_2 0x001b
#define BEGIN_STAGE_3 0x001c
#define SAVE_AT_1 0x001d
#define SAVE_AT_2 0x001e
#define SAVE_AT_3 0x001f
#define BACK_TO_RESULT 0x0020
#define SUB1_1_1NAME 0x0021
#define SUB1_1_2NAME 0x0022
#define SUB1_1_3NAME 0x0023
#define SUB1_1_4NAME 0x0024
#define SUB1_1_5NAME 0x0025
#define SUB1_2_1NAME 0x0026
#define SUB1_2_2NAME 0x0027
#define SUB1_2_3NAME 0x0028
#define SUB1_2_4NAME 0x0029
#define SUB1_2_5NAME 0x002a
#define SUB1_3_1NAME 0x002b
#define SUB1_3_2NAME 0x002c
#define SUB1_3_3NAME 0x002d
#define SUB1_3_4NAME 0x002e
#define SUB1_3_5NAME 0x002f
#define SUB2_1_1NAME 0x0030
#define SUB2_1_2NAME 0x0031
#define SUB2_1_3NAME 0x0032
#define SUB2_1_4NAME 0x0033
#define SUB2_1_5NAME 0x0034
#define SUB2_2_1NAME 0x0035
#define SUB2_2_2NAME 0x0036
#define SUB2_2_3NAME 0x0037
#define SUB2_2_4NAME 0x0038
#define SUB2_2_5NAME 0x0039
#define SUB2_3_1NAME 0x003a
#define SUB2_3_2NAME 0x003b
#define SUB2_3_3NAME 0x003c
#define SUB2_3_4NAME 0x003d
#define SUB2_3_5NAME 0x003e
#define TYPE_HOTSPRING 0x003f
#define TYPE_FOOD 0x0040
#define TYPE_POOL 0x0041
#define TYPE_DRINK 0x0042
#define TYPE_CINEMA 0x0043
#define TYPE_KARAOKE 0x0044
#define TYPE_RESTPLACE 0x0045
#define TYPE_MAKEBYHAND 0x0046
#define EVNT_NOTHING 0x0047
#define EVNT_NORMALSPR 0x0048
#define EVNT_SKINCARESPR 0x0049
#define EVNT_WARMSPR 0x004a
#define EVNT_HEALTHSPR 0x004b
#define EVNT_EATBBQ 0x004c
#define EVNT_EATLIGHTFOOD 0x004d
#define EVNT_EATUNAGI 0x004e
#define EVNT_EATRAMEN 0x004f
#define EVNT_EATCURRY 0x0050
#define EVNT_EATFRIEDNOODLE 0x0051
#define EVNT_POLNORMAL 0x0052
#define EVNT_POLFLUSH 0x0053
#define EVNT_POLNIGHT 0x0054
#define EVNT_POLINFINITY 0x0055
#define EVNT_DRKMILKTEA 0x0056
#define EVNT_DRKCAFE 0x0057
#define EVNT_DRKTEA 0x0058
#define EVNT_DRKBAR 0x0059
#define EVNT_DRKKARUPISU 0x005a
#define EVNT_DRKALCOHOL 0x005b
#define EVNT_MOVHOR 0x005c
#define EVNT_MOVLOVE 0x005d
#define EVNT_MOVSF 0x005e
#define EVNT_MOVACT 0x005f
#define EVNT_MOVCOMEDY 0x0060
#define EVNT_MOVDOCUMENTARY 0x0061
#define EVNT_KARASINGLE 0x0062
#define EVNT_KARAMUTLI 0x0063
#define EVNT_RESTCAMP 0x0064
#define EVNT_RESTHOTEL 0x0065
#define EVNT_MAKEPRESENT 0x0066
#define EVNT_MAKEACSY 0x0067
#define BUILD_IS_END 0x0068

#define DIALOG_NOTHING 0x01
#define DIALOG_NEW_GAME 0x02
#define DIALOG_TIPS_STUDENT 0x03
#define DIALOG_TIPS_COUPLE 0x04
#define DIALOG_TIPS_PROGRAMMER 0x05
#define DIALOG_TIPS_ARTIST 0x06
#define DIALOG_TIPS_OFFICER 0x07
#define DIALOG_TIPS_FAMILY 0x08
#define DIALOG_TIPS_RABBIT 0x09
#define DIALOG_TIPS_WHALE 0x0a
#define DIALOG_TIPS_CAMEL 0x0b

/// <summary>
/// ���`�����Ф�ȡ��
/// </summary>
/// <returns>���`������</returns>
SCENENODE* GetSceneNodeArray();

/// <summary>
/// ���`�����Ф��O��
/// </summary>
/// <param name="index">���`���ƫ����</param>
/// <param name="temp">�R�r�Ĥʥ��`������</param>
void SetSceneNodeArray(int index, SCENENODE temp);

/// <summary>
/// ʹ�äƤ��륷�`����O��
/// </summary>
/// <param name="sceneNode">���`��ָ��Υݥ���</param>
void SetCurrScene(SCENENODE* sceneNode);

/// <summary>
/// ʹ�äƤ��륷�`���ȡ��
/// </summary>
/// <returns>���`��ָ��Υݥ���</returns>
SCENENODE* GetCurrScene();

/// <summary>
/// ��Ԓ�¼��η��Ť�ȡ��
/// </summary>
/// <returns>��Ԓ�¼��η���</returns>
int GetDialogEvent();

/// <summary>
/// ��Ԓ�¼��η��Ť��O��
/// </summary>
/// <param name="id">��Ԓ�¼��η���</param>
void SetDialogEvent(int id);

/// <summary>
/// ����Ԓ�ϽK��ä���
/// </summary>
/// <returns>�K��ä����ɤ����Θ��R</returns>
int IsDialogFinish();

/// <summary>
/// ����Ԓ�¼��ϽK��ä������O��
/// </summary>
/// <param name="id">���R</param>
void SetIsDialogFinish(int value);

/// <summary>
/// ��Q���ե����ȤΘ��R��ȡ��
/// </summary>
/// <returns>��Q���ե����ȤΘ��R</returns>
int GetSwitchEffectFlag();

/// <summary>
/// ��Q���ե����ȤΘ��R���O��
/// </summary>
/// <param name="id">���R</param>
void SetSwitchEffectFlag(int value);

#define UP2DOWN 1
#define DOWN2UP 2
#define LEFT2RIGHT 3
#define RIGHT2LEFT 4

/// <summary>
/// ��Q���ե����ȤΥ��������ȡ��
/// </summary>
/// <returns>��Q���ե����ȤΥ�������</returns>
int GetSwitchEffectStyle();

/// <summary>
/// ��Q���ե����ȤΥ���������O��
/// </summary>
/// <param name="id">��������</param>
void SetSwitchEffectStyle(int value);

#define DIALOG_EVENT_SIZE 32

/// <summary>
/// ��Ԓ�ǩ`������ڻ����ƥ�`�ɤ���
/// </summary>
void InitAndLoadDialogEvents();

/// <summary>
/// �ե����뤫��ҤȤĤΌ�Ԓ���٥�Ȥ��ϕ�������
/// </summary>
/// <param name="id">��Ԓ���٥�Ȥη���</param>
/// <param name="path">�ե�����Υ��ɥ쥹</param>
void LoadSingleDialogEvnetFromID(int id, const char* path);

/// <summary>
/// ��Ԓ���٥�ȥǩ`����ȡ��
/// </summary>
/// <param name="id">��Ԓ���٥�Ȥη���</param>
/// <returns>��Ԓ���٥��ָ��Υݥ���</returns>
DIALOG_EVENT* GetDiaLogEventByEventID(int id);

#define STAGE_DEFAULT 1
#define STAGE_BEACH 2
#define STAGE_DESERT 3

/// <summary>
/// ���x�k����Ƥ��륹�Ʃ`����ȡ��
/// </summary>
/// <returns>���Ʃ`������</returns>
int GetPlayingStage();

/// <summary>
/// �x�k���줿���Ʃ`���򱣴�
/// </summary>
/// <param name="stageID">�x�k���줿���Ʃ`���η���</param>
void SetPlayingStage(int stageID);

/// <summary>
/// ���椵�줿���Ʃ`����ꥻ�å�
/// </summary>
void ResetPlayingStage();

#define VISITOR_MAX_SIZE 16

/// <summary>
/// �Q���������Ф�ȡ��
/// </summary>
/// <returns>�Q����������ָ��Υݥ���</returns>
VISITOR_NODE* GetVisitorArray();

/// <summary>
/// �ץ�ե��å�����ȡ��
/// </summary>
/// <param name="offset">ƫ����</param>
/// <returns>ƫ�����ˏꤸ�����Хݥ���</returns>
char* GetSubName1ArrayByOffset(int offset);

/// <summary>
/// ���ե��å�����ȡ��
/// </summary>
/// <param name="offset">ƫ����</param>
/// <returns>ƫ�����ˏꤸ�����Хݥ���</returns>
char* GetSubName2ArrayByOffset(int offset);

/// <summary>
/// �_�J���줿��ǰ��ȡ��
/// </summary>
/// <returns>��ǰ���Ф�ָ��Υݥ���</returns>
int* GetConfirmedSubName1And2();

/// <summary>
/// �_�J���줿�ץ�ե��å������O��
/// </summary>
/// <param name="value">�ꤸ�Ƥ��뷬��</param>
void SetConfirmedSubName1(int value);

/// <summary>
/// �_�J���줿���ե��å������O��
/// </summary>
/// <param name="value">�ꤸ�Ƥ��뷬��</param>
void SetConfirmedSubName2(int value);

#define BUILDINGS_SIZE 10

/// <summary>
/// �����äƤ���λ�ä��O��
/// </summary>
/// <param name="value">λ�ä΂�</param>
void SetCurrBuildingPos(int value);

/// <summary>
/// �����äƤ���λ�ä�ȡ��
/// </summary>
/// <returns>λ�ä΂�</returns>
int GetCurrBuildingPos();

#define B_TYPE_NOTHING 0
#define B_TYPE_HOTSPRING 1
#define B_TYPE_FOOD 2
#define B_TYPE_POOL 3
#define B_TYPE_DRINK 4
#define B_TYPE_CINEMA 5
#define B_TYPE_KARAOKE 6
#define B_TYPE_RESTPLACE 7
#define B_TYPE_MAKEBYHAND 8
#define B_EVNT_NOTHING 0
#define B_EVNT_NORMALSPR 11
#define B_EVNT_SKINCARESPR 12
#define B_EVNT_WARMSPR 13
#define B_EVNT_HEALTHSPR 14
#define B_EVNT_EATBBQ 21
#define B_EVNT_EATLIGHTFOOD 22
#define B_EVNT_EATUNAGI 23
#define B_EVNT_EATRAMEN 24
#define B_EVNT_EATCURRY 25
#define B_EVNT_EATFRIEDNOODLE 26
#define B_EVNT_POLNORMAL 31
#define B_EVNT_POLFLUSH 32
#define B_EVNT_POLNIGHT 33
#define B_EVNT_POLINFINITY 34
#define B_EVNT_DRKMILKTEA 41
#define B_EVNT_DRKCAFE 42
#define B_EVNT_DRKTEA 43
#define B_EVNT_DRKBAR 44
#define B_EVNT_DRKKARUPISU 45
#define B_EVNT_DRKALCOHOL 46
#define B_EVNT_MOVHOR 51
#define B_EVNT_MOVLOVE 52
#define B_EVNT_MOVSF 53
#define B_EVNT_MOVACT 54
#define B_EVNT_MOVCOMEDY 55
#define B_EVNT_MOVDOCUMENTARY 56
#define B_EVNT_KARASINGLE 61
#define B_EVNT_KARAMUTLI 62
#define B_EVNT_RESTCAMP 71
#define B_EVNT_RESTHOTEL 72
#define B_EVNT_MAKEPRESENT 81
#define B_EVNT_MAKEACSY 82

/// <summary>
/// ���ɤ��Ƥ���ʩ�O�����Ф�ȡ��
/// </summary>
/// <returns>����ʩ�O���Ф�ָ��Υݥ���</returns>
BUILDING* GetEditBuildingsArray();

/// <summary>
/// �����Υ��ץ饤�Ȥ���ڻ����ƥ�`�ɤ���
/// </summary>
void InitAndLoadBGSprite();

SPRITE* GetHillsInStage1();

SPRITE_ANIME* GetSunCloudInStage1();

SPRITE_ANIME* GetSunCloudInStage2();

SPRITE_ANIME* GetMoonCloudInStage3();

SPRITE_ANIME* GetLakeSAs();

SPRITE_ANIME* GetBeachSAs();

SPRITE_ANIME* GetDesertSAs();

SPRITE* GetBuildSceneBase();

SPRITE* GetResortSceneBase();
