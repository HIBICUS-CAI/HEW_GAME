#include "UIObjDeclarer.h"
#include "AppDeclared.h"

void CreateAllUIObjs()
{
    CreateEmptyUIObjs();
    CreateTitleUIObjs();
    CreateDialogUIObjs();
    CreateStageSelectUIObjs();
    CreateNameSetUIObjs();
    CreateBuildingUIObjs();
    CreateFinalResultUIObjs();
}

void CreateEmptyUIObjs()
{
    CreateUIO("empty", POSITION_2D(0, 0), 0, 0, UIO_DESIGN::NOTHING);
    GetUIObjByName("empty")->AddBtn(
        UI_BUTTON(0, POSITION_2D(0, 0),
            (char*)"", BTN_DESIGN::NONE));
}

void CreateTitleUIObjs()
{
    CreateUIO("title", POSITION_2D(60, 35), 60, 20,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(START_NEW_GAME, POSITION_2D(26, 3),
            (char*)"��Ҏ�_ʼ", BTN_DESIGN::LINE));
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(LOAD_GAME_DATA, POSITION_2D(27, 7),
            (char*)"��`��", BTN_DESIGN::LINE));
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(GAME_SIMPLY_MANUAL, POSITION_2D(26, 11),
            (char*)"��������", BTN_DESIGN::LINE));
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(THIS_GAME_LINK, POSITION_2D(27, 15),
            (char*)"���", BTN_DESIGN::LINE));

    CreateUIO("load-data", POSITION_2D(50, 5), 80, 50,
        UIO_DESIGN::STRAIGHT, NULL, NULL);
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(34, 1),
        (char*)"���`�֥ǩ`��"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(2, 3),
        (char*)"----------------------------------------------------------------------------"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(1, 5),
        (char*)"�ǩ`������"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 7),
        (char*)"���`�֤��줿�ո��ȕr�g��2021/01/25 11:58:25"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 9),
        (char*)"�[�Ӥޤ������Ʃ`�����ģţƣ��գ̣�"));
    GetUIObjByName("load-data")->
        AddBtn(UI_BUTTON(LOAD_DATA_1, POSITION_2D(37, 13),
            (char*)"��`��", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(2, 17),
        (char*)"----------------------------------------------------------------------------"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(1, 19),
        (char*)"�ǩ`������"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 21),
        (char*)"���`�֤��줿�ո��ȕr�g��2021/01/25 11:58:25"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 23),
        (char*)"�[�Ӥޤ������Ʃ`�����ģţƣ��գ̣ԣ�"));
    GetUIObjByName("load-data")->
        AddBtn(UI_BUTTON(LOAD_DATA_2, POSITION_2D(37, 27),
            (char*)"��`��", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(2, 31),
        (char*)"----------------------------------------------------------------------------"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(1, 33),
        (char*)"�ǩ`������"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 35),
        (char*)"���`�֤��줿�ո��ȕr�g��2021/01/25 11:58:25"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 37),
        (char*)"�[�Ӥޤ������Ʃ`�����ģţƣ��գ̣ԣ�"));
    GetUIObjByName("load-data")->
        AddBtn(UI_BUTTON(LOAD_DATA_3, POSITION_2D(37, 41),
            (char*)"��`��", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(2, 45),
        (char*)"----------------------------------------------------------------------------"));
    GetUIObjByName("load-data")->
        AddBtn(UI_BUTTON(CLOSE_SAVE_DATA, POSITION_2D(37, 48),
            (char*)"�]����", BTN_DESIGN::LINE));

    CreateUIO("manual", POSITION_2D(50, 5), 80, 50,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(36, 1),
        (char*)"��������"));
    GetUIObjByName("manual")->
        AddBtn(UI_BUTTON(CLOSE_MANUAL, POSITION_2D(37, 48),
            (char*)"�]����", BTN_DESIGN::LINE));

    CreateUIO("link", POSITION_2D(50, 35), 80, 20,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("link")->AddText(UI_TEXT(POSITION_2D(35, 1),
        (char*)"�v�B���"));
    GetUIObjByName("link")->
        AddBtn(UI_BUTTON(CLOSE_LINK, POSITION_2D(37, 18),
            (char*)"�]����", BTN_DESIGN::LINE));
}

void CreateDialogUIObjs()
{
    CreateUIO("dialog", POSITION_2D(1, 40), 150, 19,
        UIO_DESIGN::NOTHING, NULL, NULL, 1);
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(2, 2),
        (char*)"੤äƤ�����"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(2, 3),
        (char*)"------------"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 6),
        (char*)"���~����һ������������������������������������������������������������������������������������������������������������������������������������"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 8),
        (char*)"���~���ζ�������������������������������������������������������������������������������������������������������������������������������������"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 10),
        (char*)"���~������������������������������������������������������������������������������������������������������������������������������������������"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 12),
        (char*)"���~�����ġ�����������������������������������������������������������������������������������������������������������������������������������"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 14),
        (char*)"���~�����塣����������������������������������������������������������������������������������������������������������������������������������"));
    GetUIObjByName("dialog")->
        AddBtn(UI_BUTTON(DIALOG_NEXT, POSITION_2D(50, 17),
            (char*)"", BTN_DESIGN::NONE));
}

void CreateStageSelectUIObjs()
{
    CreateUIO("stage-select", POSITION_2D(1, 1), 178, 9,
        UIO_DESIGN::NOTHING, NULL, NULL, 1);
    GetUIObjByName("stage-select")->AddText(UI_TEXT(POSITION_2D(78, 3),
        (char*)"���Ʃ`���x�k���ޤ��礦��"));
    GetUIObjByName("stage-select")->
        AddBtn(UI_BUTTON(BEGIN_STAGE_1, POSITION_2D(41, 7),
            (char*)"�ǥե����", BTN_DESIGN::LINE));
    GetUIObjByName("stage-select")->
        AddBtn(UI_BUTTON(BEGIN_STAGE_2, POSITION_2D(91, 7),
            (char*)"���", BTN_DESIGN::LINE));
    GetUIObjByName("stage-select")->
        AddBtn(UI_BUTTON(BEGIN_STAGE_3, POSITION_2D(135, 7),
            (char*)"ɰĮ", BTN_DESIGN::LINE));
}

void CreateNameSetUIObjs()
{
    CreateUIO("naming", POSITION_2D(1, 30), 178, 28,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(23, 5),
        (char*)"���͘������ޤȤ᣺"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(23, 7),
        (char*)"�����`�ޥ�10��"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(62, 7),
        (char*)"�����`�ޥ�10��"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(101, 7),
        (char*)"�����`�ޥ�10��"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(140, 7),
        (char*)"�����`�ޥ�10��"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(23, 15),
        (char*)"�꥾�`�Ȥ���ǰ�򸶤��ޤ��礦��"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(72, 18),
        (char*)"  �أأأأأ�  "));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(92, 18),
        (char*)"  �أأأأأ�  "));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(72, 19),
        (char*)"----------------"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(92, 19),
        (char*)"----------------"));
    GetUIObjByName("naming")->
        AddBtn(UI_BUTTON(NAMING_SUB_1, POSITION_2D(78, 21),
            (char*)"����", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("naming")->
        AddBtn(UI_BUTTON(NAMING_SUB_2, POSITION_2D(98, 21),
            (char*)"����", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("naming")->
        AddBtn(UI_BUTTON(CONFIRM_NAME, POSITION_2D(120, 21),
            (char*)"����ǥ��å��`", BTN_DESIGN::LINE));

    CreateUIO("create-visitors", POSITION_2D(1, 13), 178, 5,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("create-visitors")->AddText(
        UI_TEXT(POSITION_2D(80, 2), (char*)"���͘����x�У�����"));
    GetUIObjByName("create-visitors")->
        AddBtn(UI_BUTTON(0, POSITION_2D(0, 0),
            (char*)"", BTN_DESIGN::NONE));

    CreateUIO("subname1", POSITION_2D(38, 15), 104, 30,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_1_1NAME, POSITION_2D(4, 7),
            (char*)"     ������     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_1_2NAME, POSITION_2D(24, 7),
            (char*)"     ���뤤     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_1_3NAME, POSITION_2D(44, 7),
            (char*)"   ����äѤ�   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_1_4NAME, POSITION_2D(64, 7),
            (char*)"      ��      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_1_5NAME, POSITION_2D(84, 7),
            (char*)"      �      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_1NAME, POSITION_2D(4, 14),
            (char*)"    �����`��    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_2NAME, POSITION_2D(24, 14),
            (char*)"     һ�r��     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_3NAME, POSITION_2D(44, 14),
            (char*)"      �ܿ�      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_4NAME, POSITION_2D(64, 14),
            (char*)"   ����`�Х�   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_5NAME, POSITION_2D(84, 14),
            (char*)"  �՚��i��ʤ�  ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_1NAME, POSITION_2D(4, 21),
            (char*)"    ���ԥ���    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_2NAME, POSITION_2D(24, 21),
            (char*)"    �錄����    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_3NAME, POSITION_2D(44, 21),
            (char*)"     �ѥ��     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_4NAME, POSITION_2D(64, 21),
            (char*)"      ����      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_5NAME, POSITION_2D(84, 21),
            (char*)"  �����`�ޥ�  ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(BACK_TO_NAME_1, POSITION_2D(49, 27),
            (char*)"�]����", BTN_DESIGN::LINE));

    CreateUIO("subname2", POSITION_2D(38, 15), 104, 30,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_1NAME, POSITION_2D(4, 7),
            (char*)"      �՚�      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_2NAME, POSITION_2D(24, 7),
            (char*)"    �꥾�`��    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_3NAME, POSITION_2D(44, 7),
            (char*)"       ɭ       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_4NAME, POSITION_2D(64, 7),
            (char*)"   ��`�����   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_5NAME, POSITION_2D(84, 7),
            (char*)"      Ӣ��      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_1NAME, POSITION_2D(4, 14),
            (char*)"     �˲��     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_2NAME, POSITION_2D(24, 14),
            (char*)"       ɽ       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_3NAME, POSITION_2D(44, 14),
            (char*)"       ��       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_4NAME, POSITION_2D(64, 14),
            (char*)"   �����׈�   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_5NAME, POSITION_2D(84, 14),
            (char*)"     ����     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_1NAME, POSITION_2D(4, 21),
            (char*)"       �P       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_2NAME, POSITION_2D(24, 21),
            (char*)"       �u       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_3NAME, POSITION_2D(44, 21),
            (char*)"     �ѥ쥹     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_4NAME, POSITION_2D(64, 21),
            (char*)"       ��       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_5NAME, POSITION_2D(84, 21),
            (char*)"   �ѥ������   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(BACK_TO_NAME_2, POSITION_2D(49, 27),
            (char*)"�]����", BTN_DESIGN::LINE));
}

void CreateBuildingUIObjs()
{
    CreateUIO("build", POSITION_2D(121, 1), 58, 59,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 3),
        (char*)"�Ф���Y��999999999���饢��"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 7),
        (char*)"�����趨ʩ�O�����"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 9),
        (char*)"ʩ�O�ηN�xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 11),
        (char*)"ʩ�O�����ݣ�xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(4, 14),
        (char*)"--------------------------------------------------"));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(SET_BUILDING_TYPE, POSITION_2D(24, 21),
            (char*)"ʩ�O�ηN�", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(4, 28),
        (char*)"--------------------------------------------------"));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(SET_BUILDING_EVENT, POSITION_2D(24, 36),
            (char*)"ʩ�O������", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(4, 43),
        (char*)"--------------------------------------------------"));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(CONFIRM_BUILDING, POSITION_2D(27, 51),
            (char*)"�_��", BTN_DESIGN::LINE));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(BUILD_IS_END, POSITION_2D(27, 53),
            (char*)"����", BTN_DESIGN::LINE));

    CreateUIO("build-type", POSITION_2D(121, 1), 58, 59,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("build-type")->AddText(UI_TEXT(POSITION_2D(25, 1),
        (char*)"ʩ�O�N�"));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_HOTSPRING, POSITION_2D(9, 8),
            (char*)"      ��Ȫ      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_FOOD, POSITION_2D(33, 8),
            (char*)"     ʳ�µ�     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_POOL, POSITION_2D(9, 15),
            (char*)"     �ש`��     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_DRINK, POSITION_2D(33, 15),
            (char*)"    ����    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_CINEMA, POSITION_2D(9, 22),
            (char*)"     ӳ���^     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_KARAOKE, POSITION_2D(33, 22),
            (char*)"    ���饪��    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_RESTPLACE, POSITION_2D(9, 29),
            (char*)"     �޲���     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_MAKEBYHAND, POSITION_2D(33, 29),
            (char*)"    �������    ", BTN_DESIGN::STRAIGHT));
    /*GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 36),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 36),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 43),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 43),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));*/
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(BACK_TO_BUILD_TYPE, POSITION_2D(38, 50),
            (char*)"�]����", BTN_DESIGN::LINE));

    CreateUIO("build-event", POSITION_2D(121, 1), 58, 59,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("build-event")->AddText(UI_TEXT(POSITION_2D(25, 1),
        (char*)"ʩ�O����"));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 8),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 8),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 15),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 15),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 22),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 22),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 29),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 29),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 36),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 36),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 43),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 43),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(BACK_TO_BUILD_EVENT, POSITION_2D(38, 50),
            (char*)"�]����", BTN_DESIGN::LINE));
}

void CreateFinalResultUIObjs()
{
    CreateUIO("final-result", POSITION_2D(1, 40), 178, 19,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("final-result")->
        AddBtn(UI_BUTTON(SAVE_GAME_DATA, POSITION_2D(51, 9),
            (char*)"���`��", BTN_DESIGN::LINE));
    GetUIObjByName("final-result")->
        AddBtn(UI_BUTTON(BACK_TO_TITLE, POSITION_2D(111, 9),
            (char*)"�����ȥ�ˑ���", BTN_DESIGN::LINE));

    CreateUIO("save-data", POSITION_2D(60, 35), 60, 20,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("save-data")->
        AddBtn(UI_BUTTON(SAVE_AT_1, POSITION_2D(22, 3),
            (char*)"�ǩ`�����˥��`��", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("save-data")->
        AddBtn(UI_BUTTON(SAVE_AT_2, POSITION_2D(22, 7),
            (char*)"�ǩ`�����˥��`��", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("save-data")->
        AddBtn(UI_BUTTON(SAVE_AT_3, POSITION_2D(22, 11),
            (char*)"�ǩ`�����˥��`��", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("save-data")->
        AddBtn(UI_BUTTON(BACK_TO_RESULT, POSITION_2D(27, 15),
            (char*)"�]����", BTN_DESIGN::LINE));
}
