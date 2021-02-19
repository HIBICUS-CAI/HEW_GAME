#include "VisitorThoughtManager.h"
#include "ThoughtListManager.h"
#include "AppDeclared.h"
#include "Tools.h"
#include "ResultTips.h"
#include "FinalResult.h"

void CreateStudentThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "イコールって素敵な言葉っすね");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "ヤバい、なんか個性満々だねｗｗｗ");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "いいね、但しタピオカ飲みたいになる");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "ふわふわな感じもいいっすね");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 3)
        {
            strcpy_s(thought, sizeof(thought), "放課後ラーメンみたいな解放感ｗ");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "この名前大人っぽいですね");
            VisitorFeelGood(visitorType);
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "深いってなんか不快っすね");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "一時的ってどういうことですよ");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 1)
        {
            strcpy_s(thought, sizeof(thought), "え？ちょっと地味な感じ．．．？");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "この名前複数の場所に見たことがある．．．");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "バーベキューか、自分の手でご飯を作るのは楽しいね");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "おおこの圧倒的なラーメン感！おおこの圧倒的なラーメン感！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "何これめっちゃ面白い！普通のプールより楽しい！");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "タピオカこそこんな幸せが出来上がれるね");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "恋愛映画はいつも飽きになれないね");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "こんなかっこいい技術現実にも実現ほしいですね");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "おおこのカッコ良さ素晴らしい！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "やっぱり一緒に歌うのは楽しい！次の曲お願い～");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "テント出来上がりの達成感いいね");
            VisitorFeelGood(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "この匂いやばくない？");
            SetResultTipsTo("硫黄泉の匂いは若い人に対してちょっと強烈すぎるかもしれません");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "なんか普段の弁当を思い出した．．．美味しいけど");
            SetResultTipsTo("学生に対してカレーは日常すぎるかもしれません");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "え？子供っぽいっすか？");
            SetResultTipsTo("この時期の若い人は子供っぽいものが好きではありません");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "ホラーちょっと苦手よまじで");
            SetResultTipsTo("深い理由がないが、とある生徒はホラー映画にすごく苦手なので");
            VisitorFeelVeryBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateCoupleThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "この名前って私たちのことを思い出せるね");
            VisitorFeelVeryGood(visitorType);
        }
        else if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "明るいね、ここのことも、私たちの未来もって感じ？");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 3)
        {
            strcpy_s(thought, sizeof(thought), "尊いってやばくない？ワクワクになるｗ");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 10)
        {
            strcpy_s(thought, sizeof(thought), "あっ、ちょうどタピオカ飲みたい");
            VisitorFeelVeryGood(visitorType);
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "ふわふわな感じが好き！");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 5)
        {
            strcpy_s(thought, sizeof(thought), "喫茶店ね、のんびりの時間が欲しいね");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 6 || subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "ダイアモンドのような永遠な感じ");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "あんたいつも使ってる深い理由とぴったりですよね");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "一時的ってこういうわけないもん！");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 9 || subName2 == 0)
        {
            strcpy_s(thought, sizeof(thought), "なんか私たちのことを暗示する気？");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "もう普段は仕事いっぱいだよ");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "架空のものはちょっと好きになれないよ");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "この温泉肌に優しいと聞きましたわ");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "おおこの暖かさ、気持ちいいよね");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "普通のデート感もいいですよね");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "なんか祭りに楽しんでいるみたい！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "すごい！この無限な広さやばくない？");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNORMAL)
        {
            strcpy_s(thought, sizeof(thought),
                "普通のデート感もいいですよね");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "この幸せの甘さでめっちゃいい！心にしみれるわ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "普通のデート感もいいですよね");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "おしゃれの一品飲もうか？");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "なんかいろんな意味でワクワクするわ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "いいねこの物語、二人が一緒にいってくれてよかった");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "これ本当におもしろいですよね");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "一緒に記念のアクセサリーを作りましょう！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "友たちのお為に特別なお土産を作りましょう！");
            VisitorFeelGood(visitorType);
        }

        if (buildEvent == B_EVNT_EATBBQ ||
            buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "匂いが．．．ちょっとね．．．");
            SetResultTipsTo("強い匂いがあるところにデートしないでほうがいいですよ");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "もっとおしゃれな店がいいな");
            SetResultTipsTo("酒場のは少々騒がしい場所なので");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "えっ？何このカルピス放題って");
            SetResultTipsTo("カルピスはカップルにはちょっと微妙かも");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "もっといい選択があるはずじゃん");
            SetResultTipsTo("この主題は人によって好き嫌いがあります");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "え？二人で一緒に歌いたいよもう");
            SetResultTipsTo("カップルに対して普通のカラオケのほうがいいかもしれません");
            VisitorFeelVeryBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateProgrammerThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "いつも黒いUIに見るとしんどいよ、明るい方がいいね");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "イコールってすばらしいよ、バグの検出も楽だし");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "架空の想像力は私たちに必要だね");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 8)
        {
            strcpy_s(thought, sizeof(thought), "ここでグローバルのもの？いいじゃんどこも使えるｗ");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 2 || subName2 == 6 || subName2 == 7 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "いいよこの名前、無限のバグから解放された気がする");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "深いところに隠してるバグが嫌いだよ");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 9 || subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "えっ、俺のことですか？");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 9)
        {
            strcpy_s(thought, sizeof(thought), "せっかく仕事から逃れたのによ");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "暖かくになったね、もう冷房には何も怖くないよ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "体から力がどんどん現れている、いいよね");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "バーベキューのは超久しぶりだね、楽しみにしている");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "このうまさすごいね、どんなバグでも怖くないだ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "水流の中に泳ぐのは予想以上楽しいね");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKTEA ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "いいね、普段はこんな店あんまり来ないんだ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "技術はここまでできるか、やっぱり未来は期待できる");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "この熱血感ずいぶん久しぶりだ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "すごく面白いですね、このコメディ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "一人で歌うのは気楽なことだ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "ホテルの落ち着く感はいいね、パソコンも使えるし");
            VisitorFeelAlright(visitorType);
        }
        else if (buildType == B_TYPE_MAKEBYHAND)
        {
            strcpy_s(thought, sizeof(thought),
                "手作りのものに匠の精神も多少ありますね");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "仕事の時昼飯はもうラーメンいっぱいだね");
            SetResultTipsTo("どうやらプログラマーの昼飯は常にラーメンである");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "甘すぎくないタピオカって");
            SetResultTipsTo("深い理由がないがプログラマーはどうやらタピオカ好きではありません");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "嫌だ上司に飲まさせられた記憶が蘇った");
            SetResultTipsTo("遥か昔、とあるプログラマーは上司に無理矢理飲まさせられたことがある");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "せっかくのリゾートにもっと穏やかになりたいな");
            SetResultTipsTo("大したことないんが、このプログラマーはホラー苦手です");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "えっ？こんなこと言ったらおしまいじゃん？");
            SetResultTipsTo("このプログラマーはいつも合理的なものを追求しています");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "皆の前に歌うのは少し恥ずかしくなるな");
            SetResultTipsTo("どうやらこのプログラマーは人の前に歌う事が嫌いです");
            VisitorFeelBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateArtistThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "明るいって、このリゾートにいい色を染まったね");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "多様な醍醐味があるので深いでしょう");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "架空のものこそ無限な可能性を生み出せるね");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 2 || subName2 == 6 ||
            subName2 == 7 || subName2 == 10 || subName2 == 11)
        {
            strcpy_s(thought, sizeof(thought), "いい発想を生み出せるそう名前です");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "一時的のものだからこそ特別な美感がありますね");
            VisitorFeelAlright(visitorType);
        }
        else if (subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "おおっ、ここで私のパラダイスですよ！");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 5)
        {
            strcpy_s(thought, sizeof(thought), "理性すぎる言葉から美を生み出すのは相当難しいよ");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "サラリーマンって．．．ちょっとあれですよね");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 1 || subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "個性が少ないね、インパクトが少々足りません");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "温泉に沁みれたらアイデアがどんどん出ていきますね");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "ウナギ屋は良い技が持ってますね、美しいほどの旨い");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "日常感たっぷりですが、これも美感の起こりの一つね");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "無限に延べてるボーダーラインに色んな可能性がある");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "この香ばしいお茶はもう無敵だわ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "人々の気持ちや感情が全ての美しいものの根源だね");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "昔の人にいろんな知識や経験など得られますね");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "自然と話し合いと自分を納得できるようになった");
            VisitorFeelGood(visitorType);
        }

        if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "あ昔の祭りの時思い出した、楽しい思い出じゃないが");
            SetResultTipsTo("ここの話ですが、アーティストさんは昔ある祭りに彼氏にフラれたみたい");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "ああ歌うのは苦手ですよ．．．");
            SetResultTipsTo("キャラの個性なんですけど、アーティストさんは歌うことが嫌みたい");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "なんか出張してる気がする？");
            SetResultTipsTo("アーティストさんはいつも絶賛在宅勤務しているそうです");
            VisitorFeelBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateOfficerThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 0)
        {
            strcpy_s(thought, sizeof(thought), "涼しいっていいですね、いつも正装で息苦しいよ");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "空気読むのは飽きた、今日だけ読まない人になりたい");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "このふわふわ感がさしぶりね、周りはいつも硬いし");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 1 || subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "いいよね、この落ち着くの感じ");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 1)
        {
            strcpy_s(thought, sizeof(thought), "いつも明るすぎ場所に働いてるのでちょっと飽きたね");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "甘酸っぱいって何でちょっとイライラ気がする？");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 13 || subName2 == 4)
        {
            strcpy_s(thought, sizeof(thought), "何なんだこの生意気さ");
            VisitorFeelBad(visitorType);
        }
        else if (subName1 == 14)
        {
            strcpy_s(thought, sizeof(thought), "もうきた以上仕事の内容は考えたくないよ");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 12 || subName2 == 14)
        {
            strcpy_s(thought, sizeof(thought), "ちょっと落ち着かないねこの名前");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "これ肌にすごく効果的と聞きました！");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "いいね、祭りっぽくな感じ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "自分の手でご飯を作るのはたのたのしい～");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "おお～なんだなんだこの広さ、すごい！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "夜のプールこそ独特な面白さがあるとはな");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "タピオカの味に人を元気にさせる力がある！");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "ゆっくりと一杯飲もう？雰囲気いいし");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "やっぱ皆でカラオケしての方が楽しいね");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "凄い、これって「あたし～限定～」ということじゃん");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "普段はあんまりホラー見てないんがなんか新鮮な感じ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF ||
            buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "おお～これやばくない？本当にかっこいい！");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "うんん、単純な温泉ってなんかちょっとつまらん");
            SetResultTipsTo("どうやら事務員さんは日常と違う体験を探しています");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "もっと特別なものが欲しいね");
            SetResultTipsTo("どうやら事務員さんは日常と違う体験を探しています");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "これは仕事終わりの飲み会かい！");
            SetResultTipsTo("事務員さんに対して多分仕事後の飲み会はもう飽きたです");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "個人的にはインパクトが欲しいね");
            SetResultTipsTo("結果が見通しやすいなことは事務員さんが探しているものではありません");
            VisitorFeelBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateFamilyThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
{
    char thought[50] = "";
    if (buildType == -1 || buildEvent == -1)
    {
        int subName1 = GetConfirmedSubName1And2()[0];
        int subName2 = GetConfirmedSubName1And2()[1];

        if (subName1 == 11)
        {
            strcpy_s(thought, sizeof(thought), "ほら、美味しい綿あめですよ～");
            VisitorFeelAlright(visitorType);
        }
        else if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "この前見に行ったパンダさんかわいいですね");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 2)
        {
            strcpy_s(thought, sizeof(thought), "昔のことが思い出したねパパ");
            VisitorFeelGood(visitorType);
        }
        else if (subName1 == 7)
        {
            strcpy_s(thought, sizeof(thought), "お伽話にいるな感じですね～");
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 8 || subName2 == 10)
        {
            strcpy_s(thought, sizeof(thought), "名前だけでも綺麗ところで断言できますね");
            VisitorFeelAlright(visitorType);
        }

        if (subName1 == 9)
        {
            strcpy_s(thought, sizeof(thought), "え？これは小さい子に見させないものでしょう？");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 4 || subName1 == 6)
        {
            strcpy_s(thought, sizeof(thought), "子供にはわかりずらいでしょう");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 12)
        {
            strcpy_s(thought, sizeof(thought), "なんか変な場所を思いついた．．．");
            VisitorFeelVeryBad(visitorType);
        }
    }
    else
    {
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "次の家族旅行も温泉いきましょうよ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "どんな時でも来れるプールっていいよね");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "火傷注意して一緒に美味しいご飯作りましょう！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "同じ美味しいが母ちゃんのカレーとは違う風味がある");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "焼きそばからのいい香り！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "父ちゃん母ちゃんカルピス飲みたい！");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "家族の間でこんなゆっくりの時間が一番だね");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "ね太郎、このキャラかっこいいでしょう？");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "この映画面白いねママ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "花ちゃん、将来このような立派な人間になりたい！");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "家族で一緒にカラオケしてもなかなか楽しいじゃん");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "父ちゃん母ちゃんキャンプって凄く楽しい！");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "自分でお土産を作るのもいいね");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "一郎入るな、流水プールはまだ危険すぎるんだろう？");
            SetResultTipsTo("子供に対して流水プールはまだまだ早い");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "花ちゃんーーどこにいるのーーーー");
            SetResultTipsTo("子供を自分の周りに縛りたくないが広い場所に迷子になる可能性が非常に高い");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR ||
            buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "おいおい、未成年がいるでしょう？");
            SetResultTipsTo("未成年に対して酒はダメです");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "怖くない怖くない。ホラーってまじ有り得ないわ");
            SetResultTipsTo("ホラー映画は子供に対して不適切なものです");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "嫌だ血が出てる。。。");
            SetResultTipsTo("アクション映画の暴力内容は子供に対して不適切なものです");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "わざわざ私たち分けて必要ないじゃん");
            SetResultTipsTo("家族メンバーに一緒にいることが大切なのです");
            VisitorFeelVeryBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 80)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateRabbitThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
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
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "海は珍しいものウギ！経営者に感謝申し上げウギ！");
            VisitorFeelGood(visitorType);
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "非人間動物同士としてちょっと嫌味ウギ．．．");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName2 == 13)
        {
            strcpy_s(thought, sizeof(thought), "村って危ういところじゃないウギ？");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "嫌なことを思い出したウギ．．．");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 2 || subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "山とか森とかもう見飽きたウギ！");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "いいウギ、この暖かさ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "あ、これ本当に美味しいウギ！");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "この店凄くおしゃれウギ");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "賑やかにも嬉しいウギ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "感動されたウギ．．．");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "これ面白いウギ！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "こういうのも人間かウギ．．．");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "あ～森より良すぎるだウギ");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "友たちに何を作って上げるがいいウギ");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "この匂いもうダメウギ．．．");
            SetResultTipsTo("動物に対して硫黄泉の匂いがちょっと強烈すぎます");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "ひっ、ひどいウギ．．．");
            SetResultTipsTo("同じく人間に食べられる同士なので、そいつを食うのはちょっと残酷なことです");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "一生登れない気がするウギ．．．");
            SetResultTipsTo("流水プールから脱出のはウサギさん自分の力でできることではありません");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "あああ血だ血だっ！");
            SetResultTipsTo("かわいいうさぎさんに対してホラーは刺激すぎます");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "苦手なんだよこのタイプ．．．");
            SetResultTipsTo("かわいいうさぎさんに対してアクション映画は刺激すぎます");
            VisitorFeelBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateWhaleThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
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
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 2)
        {
            strcpy_s(thought, sizeof(thought), "森は珍しいものクジ！経営者に感謝申し上げクジ！");
            VisitorFeelVeryGood(visitorType);
        }
        else if (subName2 == 6)
        {
            strcpy_s(thought, sizeof(thought), "山は珍しいものクジ！経営者に感謝申し上げクジ！");
            VisitorFeelVeryGood(visitorType);
        }

        if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "嫌なことを思い出したクジ．．．");
            VisitorFeelBad(visitorType);
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "海はもう見飽きたクジ！");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "おお、体が完全に温まったぞクジ！");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "この肉本当に旨いクジ！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "魚ってこんな美味しいものだっけ？");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "美味しいクジ、このぬるぬるのめん");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "小さい海みたい！小さいクジけど");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "面白いクジこの酸っぱいな水！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "このなかなかのインパクトがあるクジ、面白い");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "いいよクジ、この甘酸っぱいな感じ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "ハハハハハこれ超面白いクジ！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "私たちくじらだもんね、一緒に歌うのは一番楽クジ");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "私もこんな綺麗なアクセサリー作れるクジ？");
            VisitorFeelAlright(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "ああ、この匂い本当にたまらないクジ");
            SetResultTipsTo("動物に対して硫黄泉の匂いがちょっと強烈すぎます");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_POLNORMAL ||
            buildEvent == B_EVNT_POLFLUSH ||
            buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "え？このプール小さすぎるでしょう？");
            SetResultTipsTo("いつも自由自在に泳いでいるくじらに対してプールはほぼ小さいすぎます");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "酒は少々苦手クジ．．．");
            SetResultTipsTo("もし高圧の海の中に酔っ払いになると頭はごちゃごちゃになります");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "ええ？歌うのは皆一緒でこそ楽しいでしょう？");
            SetResultTipsTo("くじらは社交意識がある動物なので、歌でコミュニケーションを行う必要があります");
            VisitorFeelVeryBad(visitorType);
        }
    }

    SetRandom();
    if (strcmp(thought, "") && CreateRandomNumIn(1, 100) < 90)
    {
        AddSingleThoughtToQueue(thought);
    }
}

void CreateCamelThought(VISITOR_TYPE visitorType, int buildType, int buildEvent)
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
            VisitorFeelGood(visitorType);
        }
        else if (subName2 == 7)
        {
            strcpy_s(thought, sizeof(thought), "海は珍しいものクダ！経営者に感謝申し上げクダ！");
            VisitorFeelVeryGood(visitorType);
        }

        if (subName1 == 12)
        {
            strcpy_s(thought, sizeof(thought), "非人間動物同士としてちょっと嫌味クダ．．．");
            VisitorFeelVeryBad(visitorType);
        }
        else if (subName1 == 0 || subName1 == 4)
        {
            strcpy_s(thought, sizeof(thought), "嫌なことを思い出したクダ．．．");
            VisitorFeelBad(visitorType);
        }
    }
    else
    {
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "完全に温まったぞ、夜の砂漠でも怖くないクダ！");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "この店凄くおしゃれクダ");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "あ、これ本当に美味しいクダ！");
            VisitorFeelGood(visitorType);
        }
        else if (buildType == B_TYPE_POOL)
        {
            strcpy_s(thought, sizeof(thought),
                "水の中に泳ぐのは凄く楽しいクダ！");
            VisitorFeelVeryGood(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "いいねこのお茶の香り");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "うん、おしゃれの店におしゃれの一品、いいクダ");
            VisitorFeelAlright(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "おお、凄いよこの映画");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "これ面白いクダ！");
            VisitorFeelGood(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "あ～砂漠より良すぎるだクダ");
            VisitorFeelVeryGood(visitorType);
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "何なんだこの匂い");
            SetResultTipsTo("動物に対して硫黄泉の匂いがちょっと強烈すぎます");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "ひっ、ひどいクダ．．．");
            SetResultTipsTo("植食動物に対して肉を食うのは残酷なことです");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "皆ほぼ肉を焼いてるクダ？");
            SetResultTipsTo("植食動物に対して肉を食うのは残酷なことです");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "砂漠はもう十分こわいのにぃ！");
            SetResultTipsTo("夜になると砂漠に色んな動物が出てしまい、駱駝さんに対してそれは十分ホラーでした");
            VisitorFeelVeryBad(visitorType);
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "ぼく歌うのは苦手クダ．．．");
            SetResultTipsTo("深い理由がないがらくださんは歌えませんみたい");
            VisitorFeelBad(visitorType);
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "なんかしんどいの砂漠生活を思い出したクダ");
            SetResultTipsTo("ほぼ全ての哺乳動物に対して砂漠は暮らしつらい場所である");
            VisitorFeelVeryBad(visitorType);
        }
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
        CreateStudentThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::COUPLE:
        CreateCoupleThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::PROGRAMMER:
        CreateProgrammerThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::ARTIST:
        CreateArtistThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::OFFICER:
        CreateOfficerThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::FAMILY:
        CreateFamilyThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::RABBIT:
        CreateRabbitThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::WHALE:
        CreateWhaleThought(visitorType, buildType, buildEvent);
        break;
    case VISITOR_TYPE::CAMEL:
        CreateCamelThought(visitorType, buildType, buildEvent);
        break;
    default:
        break;
    }
}
