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
            (char*)"�X�^�[�g", BTN_DESIGN::LINE));
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(LOAD_GAME_DATA, POSITION_2D(26, 7),
            (char*)"���ӎ���", BTN_DESIGN::LINE));
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(GAME_SIMPLY_MANUAL, POSITION_2D(26, 11),
            (char*)"������@", BTN_DESIGN::LINE));
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(THIS_GAME_LINK, POSITION_2D(27, 15),
            (char*)"�����N", BTN_DESIGN::LINE));

    CreateUIO("load-data", POSITION_2D(50, 5), 80, 50,
        UIO_DESIGN::STRAIGHT, NULL, NULL);
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(36, 1),
        (char*)"���ӎ���"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(6, 5),
        (char*)"���̃Q�[�����f�[�^�x�[�X�Ɛڑ�����@�\�������Ă��܂�"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(6, 7),
        (char*)"�ʐM�Ɏg���Ă���f�[�^�̓Q�[�����̊e���v�̂�"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(6, 9),
        (char*)"���̓��e�͈�ؓǂݍ��݁A�ۑ��A�A�b�v���[�h���܂���"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(6, 11),
        (char*)"���������^�₪����ꍇ"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(6, 13),
        (char*)"�����N�ɋL�ڂ��ꂽ�\�[�X�R�[�h�̕��ɂ��m�F���肢���܂�"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(6, 17),
        (char*)"�ʐM�@�\�����܂����삳���邽�ߊe�v���[���[��"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(6, 19),
        (char*)"����̃f�[�^�x�[�X��ҏW���錠���������グ�܂���"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(6, 21),
        (char*)"���̃v���[���[�ɖ��f���|���Ȃ��悤�ɂ��Ă��肢���܂�"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(6, 25),
        (char*)"�K���ȏ�̓��e�����m�F�̏�ŃQ�[�������s���Ă�������"));
    GetUIObjByName("load-data")->
        AddBtn(UI_BUTTON(CLOSE_SAVE_DATA, POSITION_2D(37, 48),
            (char*)"����", BTN_DESIGN::LINE));

    CreateUIO("manual", POSITION_2D(50, 5), 80, 50,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(36, 1),
        (char*)"������@"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 5),
        (char*)"���I�����ꂽ�{�^���͂��������}�[�N���邢�́y�z�Ɋ���̌`�ŕ\�����Ă��܂�"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 7),
        (char*)"�h�i�j�k�L�[�ō��I�����ꂽ�{�^���̏�A���A���A�E�̃{�^����I���ł��܂�"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 9),
        (char*)"�r�o�`�b�d�L�[�������ƍ��I������Ă���{�^�������s����Ƃ����Ӗ��ł�"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 11),
        (char*)"�����Q�[����������Ȃ�A���ł��d�r�b�L�[�łł��܂�"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 15),
        (char*)"�o�[�`�������]�[�g�V�[���ɏ\�̓y�䂪����܂�"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 17),
        (char*)"�`�c�L�[�ō��E�̓y��Ɉړ��ł��܂�"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 19),
        (char*)"�������Ԃ͈ꕪ�ԁA���̓��K�؂Ȉʒu�ɓK�؂̎{�݂��쐬��"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 21),
        (char*)"���̒��g�̓��e�����肵����A�m��{�^���������Ă�������"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 23),
        (char*)"�{�ݎ��->�{�ݓ��e->�m�F����Ƃ�������Ői�܂Ȃ��Ƃ����܂���"));
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(2, 25),
        (char*)"�m�F���ꂽ�{�݂��ĕҏW���邱�Ƃ��ł��܂�"));
    GetUIObjByName("manual")->
        AddBtn(UI_BUTTON(CLOSE_MANUAL, POSITION_2D(37, 48),
            (char*)"����", BTN_DESIGN::LINE));

    CreateUIO("link", POSITION_2D(50, 35), 80, 20,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("link")->AddText(UI_TEXT(POSITION_2D(35, 1),
        (char*)"�֘A�����N"));
    GetUIObjByName("link")->AddText(UI_TEXT(POSITION_2D(2, 5),
        (char*)"ASCII���t�@�C���쐬�@https://cloudapps.herokuapp.com/imagetoascii/"));
    GetUIObjByName("link")->AddText(UI_TEXT(POSITION_2D(2, 8),
        (char*)"�f�[�^�x�[�X�@https://mariadb.com/"));
    GetUIObjByName("link")->AddText(UI_TEXT(POSITION_2D(2, 11),
        (char*)"�\�[�X�R�[�h�@https://github.com/HIBICUSbaka/HEW_GAME"));
    GetUIObjByName("link")->AddText(UI_TEXT(POSITION_2D(2, 14),
        (char*)"���ȒP�ȃR���\�[���G���W���@https://github.com/HIBICUSbaka/CLIG"));
    GetUIObjByName("link")->
        AddBtn(UI_BUTTON(CLOSE_LINK, POSITION_2D(37, 18),
            (char*)"����", BTN_DESIGN::LINE));
}

void CreateDialogUIObjs()
{
    CreateUIO("dialog", POSITION_2D(1, 40), 150, 19,
        UIO_DESIGN::NOTHING, NULL, NULL, 1);
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(2, 2),
        (char*)"�����Ă���l"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(2, 3),
        (char*)"------------"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 6),
        (char*)"���t���̈�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 8),
        (char*)"���t���̓�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 10),
        (char*)"���t���̎O�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 12),
        (char*)"���t���̎l�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 14),
        (char*)"���t���̌܁B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B�B"));
    GetUIObjByName("dialog")->
        AddBtn(UI_BUTTON(DIALOG_NEXT, POSITION_2D(50, 17),
            (char*)"", BTN_DESIGN::NONE));
    GetUIObjByName("dialog")->
        AddBtn(UI_BUTTON(TEMP_BTN_DIALOG_1, POSITION_2D(60, 17),
            (char*)"SKIP", BTN_DESIGN::LINE));
}

void CreateStageSelectUIObjs()
{
    CreateUIO("stage-select", POSITION_2D(1, 1), 178, 9,
        UIO_DESIGN::NOTHING, NULL, NULL, 1);
    GetUIObjByName("stage-select")->AddText(UI_TEXT(POSITION_2D(78, 3),
        (char*)"�X�e�[�W�I�����܂��傤�I"));
    GetUIObjByName("stage-select")->
        AddBtn(UI_BUTTON(BEGIN_STAGE_1, POSITION_2D(41, 7),
            (char*)"�f�t�H���g", BTN_DESIGN::LINE));
    GetUIObjByName("stage-select")->
        AddBtn(UI_BUTTON(BEGIN_STAGE_2, POSITION_2D(91, 7),
            (char*)"�C�l", BTN_DESIGN::LINE));
    GetUIObjByName("stage-select")->
        AddBtn(UI_BUTTON(BEGIN_STAGE_3, POSITION_2D(135, 7),
            (char*)"����", BTN_DESIGN::LINE));
}

void CreateNameSetUIObjs()
{
    CreateUIO("naming", POSITION_2D(1, 30), 178, 28,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(23, 5),
        (char*)"���q�l�̏��܂Ƃ߁F"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(23, 7),
        (char*)"�T�����[�}���F10�l"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(62, 7),
        (char*)"�T�����[�}���F10�l"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(101, 7),
        (char*)"�T�����[�}���F10�l"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(140, 7),
        (char*)"�T�����[�}���F10�l"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(23, 15),
        (char*)"���]�[�g�ɖ��O��t���܂��傤�I"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(72, 18),
        (char*)"  �w�w�w�w�w�w  "));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(92, 18),
        (char*)"  �w�w�w�w�w�w  "));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(72, 19),
        (char*)"----------------"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(92, 19),
        (char*)"----------------"));
    GetUIObjByName("naming")->
        AddBtn(UI_BUTTON(NAMING_SUB_1, POSITION_2D(78, 21),
            (char*)"�ҏW", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("naming")->
        AddBtn(UI_BUTTON(NAMING_SUB_2, POSITION_2D(98, 21),
            (char*)"�ҏW", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("naming")->
        AddBtn(UI_BUTTON(CONFIRM_NAME, POSITION_2D(120, 21),
            (char*)"����ŃI�b�P�[", BTN_DESIGN::LINE));

    CreateUIO("create-visitors", POSITION_2D(1, 13), 178, 5,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("create-visitors")->AddText(
        UI_TEXT(POSITION_2D(80, 2), (char*)"���q�l���I���D�D�D"));
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
            (char*)"     ���邢     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_1_3NAME, POSITION_2D(44, 7),
            (char*)"   �Î_���ς�   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_1_4NAME, POSITION_2D(64, 7),
            (char*)"      ����      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_1_5NAME, POSITION_2D(84, 7),
            (char*)"      �[��      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_1NAME, POSITION_2D(4, 14),
            (char*)"    �C�R�[��    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_2NAME, POSITION_2D(24, 14),
            (char*)"     �ꎞ�I     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_3NAME, POSITION_2D(44, 14),
            (char*)"      �ˋ�      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_4NAME, POSITION_2D(64, 14),
            (char*)"   �O���[�o��   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_2_5NAME, POSITION_2D(84, 14),
            (char*)"  ��C�ǂ߂Ȃ�  ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_1NAME, POSITION_2D(4, 21),
            (char*)"    �^�s�I�J    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_2NAME, POSITION_2D(24, 21),
            (char*)"    �킽����    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_3NAME, POSITION_2D(44, 21),
            (char*)"     �p���_     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_4NAME, POSITION_2D(64, 21),
            (char*)"      ���E      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(SUB1_3_5NAME, POSITION_2D(84, 21),
            (char*)"  �T�����[�}��  ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(BACK_TO_NAME_1, POSITION_2D(49, 27),
            (char*)"����", BTN_DESIGN::LINE));

    CreateUIO("subname2", POSITION_2D(38, 15), 104, 30,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_1NAME, POSITION_2D(4, 7),
            (char*)"      ��C      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_2NAME, POSITION_2D(24, 7),
            (char*)"    ���]�[�g    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_3NAME, POSITION_2D(44, 7),
            (char*)"       �X       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_4NAME, POSITION_2D(64, 7),
            (char*)"   ���[������   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_1_5NAME, POSITION_2D(84, 7),
            (char*)"      �p�Y      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_1NAME, POSITION_2D(4, 14),
            (char*)"     �i���X     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_2NAME, POSITION_2D(24, 14),
            (char*)"       �R       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_3NAME, POSITION_2D(44, 14),
            (char*)"       �C       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_4NAME, POSITION_2D(64, 14),
            (char*)"   �L�����v��   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_2_5NAME, POSITION_2D(84, 14),
            (char*)"     ������     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_1NAME, POSITION_2D(4, 21),
            (char*)"       ��       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_2NAME, POSITION_2D(24, 21),
            (char*)"       ��       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_3NAME, POSITION_2D(44, 21),
            (char*)"     �p���X     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_4NAME, POSITION_2D(64, 21),
            (char*)"       ��       ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(SUB2_3_5NAME, POSITION_2D(84, 21),
            (char*)"   �p���_�C�X   ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(BACK_TO_NAME_2, POSITION_2D(49, 27),
            (char*)"����", BTN_DESIGN::LINE));
}

void CreateBuildingUIObjs()
{
    CreateUIO("build", POSITION_2D(121, 1), 58, 59,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 3),
        (char*)"�c�莞�ԁF60"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 7),
        (char*)"���^�\��{�݂̏��F"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 9),
        (char*)"�{�݂̎�ށFxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 11),
        (char*)"�{�݂̓��e�Fxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(4, 14),
        (char*)"--------------------------------------------------"));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(SET_BUILDING_TYPE, POSITION_2D(24, 21),
            (char*)"�{�݂̎��", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(4, 28),
        (char*)"--------------------------------------------------"));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(SET_BUILDING_EVENT, POSITION_2D(24, 36),
            (char*)"�{�݂̓��e", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(4, 43),
        (char*)"--------------------------------------------------"));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(CONFIRM_BUILDING, POSITION_2D(27, 51),
            (char*)"�m��", BTN_DESIGN::LINE));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(BUILD_IS_END, POSITION_2D(27, 53),
            (char*)"����", BTN_DESIGN::LINE));

    CreateUIO("build-type", POSITION_2D(121, 1), 58, 59,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("build-type")->AddText(UI_TEXT(POSITION_2D(25, 1),
        (char*)"�{�ݎ��"));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_HOTSPRING, POSITION_2D(9, 8),
            (char*)"      ����      ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_FOOD, POSITION_2D(33, 8),
            (char*)"     �H���X     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_POOL, POSITION_2D(9, 15),
            (char*)"     �v�[��     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_DRINK, POSITION_2D(33, 15),
            (char*)"    ���ݕ��X    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_CINEMA, POSITION_2D(9, 22),
            (char*)"     �f���     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_KARAOKE, POSITION_2D(33, 22),
            (char*)"    �J���I�P    ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_RESTPLACE, POSITION_2D(9, 29),
            (char*)"     �h���n     ", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(TYPE_MAKEBYHAND, POSITION_2D(33, 29),
            (char*)"    ����X    ", BTN_DESIGN::STRAIGHT));
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
            (char*)"����", BTN_DESIGN::LINE));

    CreateUIO("build-event", POSITION_2D(121, 1), 58, 59,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("build-event")->AddText(UI_TEXT(POSITION_2D(25, 1),
        (char*)"�{�ݓ��e"));
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
    /*GetUIObjByName("build-event")->
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
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));*/
    GetUIObjByName("build-event")->
        AddBtn(UI_BUTTON(BACK_TO_BUILD_EVENT, POSITION_2D(38, 50),
            (char*)"����", BTN_DESIGN::LINE));
}

void CreateFinalResultUIObjs()
{
    CreateUIO("final-result", POSITION_2D(1, 40), 178, 19,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("final-result")->
        AddBtn(UI_BUTTON(SAVE_GAME_DATA, POSITION_2D(51, 9),
            (char*)"���̐l�́H", BTN_DESIGN::LINE));
    GetUIObjByName("final-result")->
        AddBtn(UI_BUTTON(BACK_TO_TITLE, POSITION_2D(111, 9),
            (char*)"�^�C�g���ɖ߂�", BTN_DESIGN::LINE));

    CreateUIO("save-data", POSITION_2D(60, 35), 60, 20,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("save-data")->AddText(UI_TEXT(POSITION_2D(5, 3),
        (char*)"���X�e�[�W�r�����N�@"));
    GetUIObjByName("save-data")->AddText(UI_TEXT(POSITION_2D(5, 5),
        (char*)"���X�e�[�W�`�����N�@"));
    GetUIObjByName("save-data")->AddText(UI_TEXT(POSITION_2D(5, 7),
        (char*)"���X�e�[�W�a�����N�@"));
    GetUIObjByName("save-data")->AddText(UI_TEXT(POSITION_2D(5, 9),
        (char*)"���X�e�[�W�b�����N�@"));
    GetUIObjByName("save-data")->AddText(UI_TEXT(POSITION_2D(5, 11),
        (char*)"�ł��g��ꂽ�{��"));
    /*GetUIObjByName("save-data")->
        AddBtn(UI_BUTTON(SAVE_AT_1, POSITION_2D(22, 3),
            (char*)"�f�[�^�P�ɃZ�[�u", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("save-data")->
        AddBtn(UI_BUTTON(SAVE_AT_2, POSITION_2D(22, 7),
            (char*)"�f�[�^�Q�ɃZ�[�u", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("save-data")->
        AddBtn(UI_BUTTON(SAVE_AT_3, POSITION_2D(22, 11),
            (char*)"�f�[�^�R�ɃZ�[�u", BTN_DESIGN::STRAIGHT));*/
    GetUIObjByName("save-data")->
        AddBtn(UI_BUTTON(BACK_TO_RESULT, POSITION_2D(27, 15),
            (char*)"����", BTN_DESIGN::LINE));
}
