#include "UIObjDeclarer.h"
#include "AppDeclared.h"

void CreateAllUIObjs()
{
    CreateTitleUIObjs();
    CreateDialogUIObjs();
    CreateStageSelectUIObjs();
    CreateNameSetUIObjs();
    CreateBuildingUIObjs();
    CreateFinalResultUIObjs();
}

void CreateTitleUIObjs()
{
    CreateUIO("title", POSITION_2D(60, 35), 60, 20,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(START_NEW_GAME, POSITION_2D(26, 3),
            (char*)"新規開始", BTN_DESIGN::LINE));
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(LOAD_GAME_DATA, POSITION_2D(27, 7),
            (char*)"ロード", BTN_DESIGN::LINE));
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(GAME_SIMPLY_MANUAL, POSITION_2D(26, 11),
            (char*)"操作方法", BTN_DESIGN::LINE));
    GetUIObjByName("title")->
        AddBtn(UI_BUTTON(THIS_GAME_LINK, POSITION_2D(27, 15),
            (char*)"リンク", BTN_DESIGN::LINE));

    CreateUIO("load-data", POSITION_2D(50, 5), 80, 50,
        UIO_DESIGN::STRAIGHT, NULL, NULL);
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(34, 1),
        (char*)"セーブデータ"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(2, 3),
        (char*)"----------------------------------------------------------------------------"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(1, 5),
        (char*)"データ１："));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 7),
        (char*)"セーブされた日付と時間：2021/01/25 11:58:25"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 9),
        (char*)"遊びましたステージ：ＤＥＦＡＵＬＴ"));
    GetUIObjByName("load-data")->
        AddBtn(UI_BUTTON(LOAD_DATA_1, POSITION_2D(37, 13),
            (char*)"ロード", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(2, 17),
        (char*)"----------------------------------------------------------------------------"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(1, 19),
        (char*)"データ２："));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 21),
        (char*)"セーブされた日付と時間：2021/01/25 11:58:25"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 23),
        (char*)"遊びましたステージ：ＤＥＦＡＵＬＴ１"));
    GetUIObjByName("load-data")->
        AddBtn(UI_BUTTON(LOAD_DATA_2, POSITION_2D(37, 27),
            (char*)"ロード", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(2, 31),
        (char*)"----------------------------------------------------------------------------"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(1, 33),
        (char*)"データ３："));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 35),
        (char*)"セーブされた日付と時間：2021/01/25 11:58:25"));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(3, 37),
        (char*)"遊びましたステージ：ＤＥＦＡＵＬＴ２"));
    GetUIObjByName("load-data")->
        AddBtn(UI_BUTTON(LOAD_DATA_3, POSITION_2D(37, 41),
            (char*)"ロード", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("load-data")->AddText(UI_TEXT(POSITION_2D(2, 45),
        (char*)"----------------------------------------------------------------------------"));
    GetUIObjByName("load-data")->
        AddBtn(UI_BUTTON(CLOSE_SAVE_DATA, POSITION_2D(37, 48),
            (char*)"閉じる", BTN_DESIGN::LINE));

    CreateUIO("manual", POSITION_2D(50, 5), 80, 50,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("manual")->AddText(UI_TEXT(POSITION_2D(36, 1),
        (char*)"操作方法"));
    GetUIObjByName("manual")->
        AddBtn(UI_BUTTON(CLOSE_MANUAL, POSITION_2D(37, 48),
            (char*)"閉じる", BTN_DESIGN::LINE));

    CreateUIO("link", POSITION_2D(50, 35), 80, 20,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("link")->AddText(UI_TEXT(POSITION_2D(35, 1),
        (char*)"関連リンク"));
    GetUIObjByName("link")->
        AddBtn(UI_BUTTON(CLOSE_LINK, POSITION_2D(37, 18),
            (char*)"閉じる", BTN_DESIGN::LINE));
}

void CreateDialogUIObjs()
{
    CreateUIO("dialog", POSITION_2D(1, 40), 178, 19,
        UIO_DESIGN::STAR, NULL, NULL, 1);
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(2, 2),
        (char*)"喋っている人"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(2, 3),
        (char*)"------------"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 6),
        (char*)"言葉その一。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 8),
        (char*)"言葉その二。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 10),
        (char*)"言葉その三。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 12),
        (char*)"言葉その四。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。"));
    GetUIObjByName("dialog")->AddText(UI_TEXT(POSITION_2D(6, 14),
        (char*)"言葉その五。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。"));
    GetUIObjByName("dialog")->
        AddBtn(UI_BUTTON(DIALOG_NEXT, POSITION_2D(175, 17),
            (char*)"", BTN_DESIGN::NONE));
}

void CreateStageSelectUIObjs()
{
    CreateUIO("stage-select", POSITION_2D(1, 1), 178, 9,
        UIO_DESIGN::NOTHING, NULL, NULL, 1);
    GetUIObjByName("stage-select")->AddText(UI_TEXT(POSITION_2D(78, 3),
        (char*)"ステージ選択しましょう！"));
    GetUIObjByName("stage-select")->
        AddBtn(UI_BUTTON(BEGIN_STAGE_1, POSITION_2D(41, 7),
            (char*)"デフォルト", BTN_DESIGN::LINE));
    GetUIObjByName("stage-select")->
        AddBtn(UI_BUTTON(BEGIN_STAGE_2, POSITION_2D(91, 7),
            (char*)"海浜", BTN_DESIGN::LINE));
    GetUIObjByName("stage-select")->
        AddBtn(UI_BUTTON(BEGIN_STAGE_3, POSITION_2D(135, 7),
            (char*)"砂漠", BTN_DESIGN::LINE));
}

void CreateNameSetUIObjs()
{
    CreateUIO("naming", POSITION_2D(1, 30), 178, 28,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(23, 5),
        (char*)"お客様の情報まとめ："));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(23, 7),
        (char*)"サラリーマン：10人"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(62, 7),
        (char*)"サラリーマン：10人"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(101, 7),
        (char*)"サラリーマン：10人"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(140, 7),
        (char*)"サラリーマン：10人"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(23, 15),
        (char*)"リゾートに名前を付けましょう！"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(72, 18),
        (char*)"  ＸＸＸＸＸＸ  "));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(92, 18),
        (char*)"  ＸＸＸＸＸＸ  "));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(72, 19),
        (char*)"----------------"));
    GetUIObjByName("naming")->AddText(UI_TEXT(POSITION_2D(92, 19),
        (char*)"----------------"));
    GetUIObjByName("naming")->
        AddBtn(UI_BUTTON(NAMING_SUB_1, POSITION_2D(78, 21),
            (char*)"編集", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("naming")->
        AddBtn(UI_BUTTON(NAMING_SUB_2, POSITION_2D(98, 21),
            (char*)"編集", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("naming")->
        AddBtn(UI_BUTTON(CONFIRM_NAME, POSITION_2D(120, 21),
            (char*)"これでオッケー", BTN_DESIGN::LINE));

    CreateUIO("subname1", POSITION_2D(38, 15), 104, 30,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(4, 7),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(24, 7),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(44, 7),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(64, 7),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(84, 7),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(4, 14),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(24, 14),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(44, 14),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(64, 14),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(84, 14),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(4, 21),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(24, 21),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(44, 21),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(64, 21),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(0, POSITION_2D(84, 21),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname1")->
        AddBtn(UI_BUTTON(BACK_TO_NAME_1, POSITION_2D(49, 27),
            (char*)"閉じる", BTN_DESIGN::LINE));

    CreateUIO("subname2", POSITION_2D(38, 15), 104, 30,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(4, 7),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(24, 7),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(44, 7),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(64, 7),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(84, 7),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(4, 14),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(24, 14),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(44, 14),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(64, 14),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(84, 14),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(4, 21),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(24, 21),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(44, 21),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(64, 21),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(0, POSITION_2D(84, 21),
            (char*)"oooooooooooooooo", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("subname2")->
        AddBtn(UI_BUTTON(BACK_TO_NAME_2, POSITION_2D(49, 27),
            (char*)"閉じる", BTN_DESIGN::LINE));
}

void CreateBuildingUIObjs()
{
    CreateUIO("build", POSITION_2D(121, 1), 58, 59,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 3),
        (char*)"残りの資金：999999999カラアゲ"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 7),
        (char*)"当／予定施設の情報："));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 9),
        (char*)"施設の種類：xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(5, 11),
        (char*)"施設の内容：xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(4, 14),
        (char*)"--------------------------------------------------"));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(SET_BUILDING_TYPE, POSITION_2D(24, 21),
            (char*)"施設の種類", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(4, 28),
        (char*)"--------------------------------------------------"));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(SET_BUILDING_EVENT, POSITION_2D(24, 36),
            (char*)"施設の内容", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build")->AddText(UI_TEXT(POSITION_2D(4, 43),
        (char*)"--------------------------------------------------"));
    GetUIObjByName("build")->
        AddBtn(UI_BUTTON(CONFIRM_BUILDING, POSITION_2D(27, 51),
            (char*)"確定", BTN_DESIGN::LINE));

    CreateUIO("build-type", POSITION_2D(121, 1), 58, 59,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("build-type")->AddText(UI_TEXT(POSITION_2D(25, 1),
        (char*)"施設種類"));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 8),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 8),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 15),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 15),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 22),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 22),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(9, 29),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(0, POSITION_2D(33, 29),
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
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
            (char*)"xxxxxxxxxxxxxxxx", BTN_DESIGN::STRAIGHT));
    GetUIObjByName("build-type")->
        AddBtn(UI_BUTTON(BACK_TO_BUILD_TYPE, POSITION_2D(38, 50),
            (char*)"閉じる", BTN_DESIGN::LINE));

    CreateUIO("build-event", POSITION_2D(121, 1), 58, 59,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 0);
    GetUIObjByName("build-event")->AddText(UI_TEXT(POSITION_2D(25, 1),
        (char*)"施設内容"));
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
            (char*)"閉じる", BTN_DESIGN::LINE));
}

void CreateFinalResultUIObjs()
{
    CreateUIO("final-result", POSITION_2D(1, 40), 178, 19,
        UIO_DESIGN::STRAIGHT, NULL, NULL, 1);
    GetUIObjByName("final-result")->
        AddBtn(UI_BUTTON(SAVE_GAME_DATA, POSITION_2D(51, 9),
            (char*)"セーブ", BTN_DESIGN::LINE));
    GetUIObjByName("final-result")->
        AddBtn(UI_BUTTON(BACK_TO_TITLE, POSITION_2D(111, 9),
            (char*)"タイトルに戻る", BTN_DESIGN::LINE));
}
