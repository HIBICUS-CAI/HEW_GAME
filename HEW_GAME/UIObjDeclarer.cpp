#include "UIObjDeclarer.h"
#include "AppDeclared.h"

void CreateAllUIObjs()
{
    CreateTitleUIObjs();
    CreateDialogUIObjs();
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
    CreateUIO("dialog", POSITION_2D(1, 40), 178, 19,
        UIO_DESIGN::STAR, NULL, NULL, 1);
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
        AddBtn(UI_BUTTON(DIALOG_NEXT, POSITION_2D(175, 17),
            (char*)"", BTN_DESIGN::NONE));
}
