#include "VisitorThoughtManager.h"
#include "ThoughtListManager.h"
#include "AppDeclared.h"
#include "Tools.h"

void CreateStudentThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "イコールって素敵な言葉っすね");
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "ヤバい、なんか個性満々だねｗｗｗ");
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "いいね、但しタピオカ飲みたいになる");
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "ふわふわな感じもいいっすね");
        }
        else if (subName2 == 3)
        {
            strcpy_s(thought, sizeof(thought), "放課後ラーメンみたいな解放感ｗ");
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "この名前大人っぽいですね");
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "深いってなんか不快っすね");
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "一時的ってどういうことですよ");
        }
        else if (subName2 == 1)
        {
            strcpy_s(thought, sizeof(thought), "え？ちょっと地味な感じ．．．？");
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "この名前複数の場所に見たことがある．．．");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateCoupleThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "この名前って私たちのことを思い出せるね");
        }
        else if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "明るいね、ここのことも、私たちの未来もって感じ？");
        }
        else if (subName1 == 3)
        {
            strcpy_s(thought, sizeof(thought), "尊いってやばくない？ワクワクになるｗ");
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "あっ、ちょうどタピオカ飲みたい");
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "ふわふわな感じが好き！");
        }
        else if (subName2 == 5)
        {
            strcpy_s(thought, sizeof(thought), "喫茶店ね、のんびりの時間が欲しいね");
        }
        else if (subName2 == 6 || subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "ダイアモンドのような永遠な感じ");
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "あんたいつも使ってる深い理由とぴったりですよね");
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "一時的ってこういうわけないもん！");
        }
        else if (subName1 == 9 || subName2 == 0)
        {
            strcpy_s(thought, sizeof(thought), "なんか私たちのことを暗示する気？");
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "もう普段は仕事いっぱいだよ");
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "架空のものはちょっと好きになれないよ");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateProgrammerThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "いつも黒いUIに見るとしんどいよ、明るい方がいいね");
        }
        else if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "イコールってすばらしいよ、バグの検出も楽だし");
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "架空の想像力は私たちに必要だね");
        }
        else if (subName1 == 8)
        {
            strcpy_s(thought, sizeof(thought), "ここでグローバルのもの？いいじゃんどこも使えるｗ");
        }
        else if (subName2 == 2 || subName2 == 6 || subName2 == 7 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "いいよこの名前、無限のバグから解放された気がする");
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "深いところに隠してるバグが嫌いだよ");
        }
        else if (subName1 == 9 || subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "えっ、俺のことですか？");
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "せっかく仕事から逃れたのによ");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateArtistThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "明るいって、このリゾートにいい色を染まったね");
        }
        else if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "多様な醍醐味があるので深いでしょう");
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "架空のものこそ無限な可能性を生み出せるね");
        }
        else if (subName2 == 2 || subName2 == 6 ||
            subName2 == 7 || subName2 == 10 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "いい発想を生み出せるそう名前です");
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "一時的のものだからこそ特別な美感がありますね");
        }
        else if (subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "おおっ、ここで私のパラダイスですよ！");
        }

        if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "理性すぎる言葉から美を生み出すのは相当難しいよ");
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "サラリーマンって．．．ちょっとあれですよね");
        }
        else if (subName2 == 1 || subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "個性が少ないね、インパクトが少々足りません");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateOfficerThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 0)
        {
            strcpy_s(thought, sizeof(thought), "涼しいっていいですね、いつも正装で息苦しいよ");
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "空気読むのは飽きた、今日だけ読まない人になりたい");
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "このふわふわ感がさしぶりね、周りはいつも硬いし");
        }
        else if (subName2 == 1 || subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "いいよね、この落ち着くの感じ");
        }

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "いつも明るすぎ場所に働いてるのでちょっと飽きたね");
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "甘酸っぱいって何でちょっとイライラ気がする？");
        }
        else if (subName1 == 13 || subName2 == 4)
        {
            strcpy_s(thought, sizeof(thought), "何なんだこの生意気さ");
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "もうきた以上仕事の内容は考えたくないよ");
        }
        else if (subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "ちょっと落ち着かないねこの名前");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateFamilyThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "ほら、美味しい綿あめですよ～");
        }
        else if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "この前見に行ったパンダさんかわいいですね");
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "昔のことが思い出したねパパ");
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "お伽話にいるな感じですね～");
        }
        else if (subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "名前だけでも綺麗ところで断言できますね");
        }

        if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "え？これは小さい子に見させないものでしょう？");
        }
        else if (subName1 == 4 || subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "子供にはわかりずらいでしょう");
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "なんか変な場所を思いついた．．．");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateRabbitThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 8 || subName1 == 10 || subName1 == 14 ||
            subName2 == 5 || subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "なんか人間っぽいしワクワクするウギ！");
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "海は珍しいものウギ！経営者に感謝申し上げウギ！");
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "非人間動物同士としてちょっと嫌味ウギ．．．");
        }
        else if (subName2 == 13)
        {
            strcpy_s(thought, sizeof(thought), "村って危ういところじゃないウギ？");
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "嫌なことを思い出したウギ．．．");
        }
        else if (subName2 == 2 || subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "山とか森とかもう見飽きたウギ！");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateWhaleThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 8 || subName1 == 10 || subName1 == 14 ||
            subName2 == 5 || subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "なんか人間っぽいしワクワクするクジ！");
        }
        else if (subName2 == 2)
        {
            strcpy_s(thought, sizeof(thought), "森は珍しいものクジ！経営者に感謝申し上げクジ！");
        }
        else if (subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "山は珍しいものクジ！経営者に感謝申し上げクジ！");
        }

        if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "嫌なことを思い出したクジ．．．");
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "海はもう見飽きたクジ！");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateCamelThought(int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 8 || subName1 == 10 || subName1 == 14 ||
            subName2 == 5 || subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "なんか人間っぽいしワクワクするクダ！");
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "海は珍しいものクダ！経営者に感謝申し上げクダ！");
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "非人間動物同士としてちょっと嫌味クダ．．．");
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "嫌なことを思い出したクダ．．．");
        }
    }
    else
    {

    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateSingleVisitorThoughtByManager(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    switch (visitorType)
    {
    case VISITOR_TYPE::NONE:
        break;
    case VISITOR_TYPE::STUDENTS:
        CreateStudentThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::COUPLE:
        CreateCoupleThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::PROGRAMMER:
        CreateProgrammerThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::ARTIST:
        CreateArtistThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::OFFICER:
        CreateOfficerThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::FAMILY:
        CreateFamilyThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::RABBIT:
        CreateRabbitThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::WHALE:
        CreateWhaleThought(buildType, buildEvent);
        break;
    case VISITOR_TYPE::CAMEL:
        CreateCamelThought(buildType, buildEvent);
        break;
    default:
        break;
    }
}
