#include "VisitorThoughtManager.h"
#include "ThoughtListManager.h"
#include "AppDeclared.h"
#include "Tools.h"
#include "ResultTips.h"

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
        if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "バーベキューか、自分の手でご飯を作るのは楽しいね");
        }
        else if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "おおこの圧倒的なラーメン感！おおこの圧倒的なラーメン感！");
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "何これめっちゃ面白い！普通のプールより楽しい！");
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "タピオカこそこんな幸せが出来上がれるね");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "恋愛映画はいつも飽きになれないね");
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "こんなかっこいい技術現実にも実現ほしいですね");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "おおこのカッコ良さ素晴らしい！");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "やっぱり一緒に歌うのは楽しい！次の曲お願い～");
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "テント出来上がりの達成感いいね");
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "この匂いやばくない？");
            SetResultTipsTo("硫黄泉の匂いは若い人に対してちょっと強烈すぎるかもしれません");
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "なんか普段の弁当を思い出した．．．美味しいけど");
            SetResultTipsTo("学生に対してカレーは日常すぎるかもしれません");
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "え？子供っぽいっすか？");
            SetResultTipsTo("この時期の若い人は子供っぽいものが好きではありません");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "ホラーちょっと苦手よまじで");
            SetResultTipsTo("深い理由がないが、とある生徒はホラー映画にすごく苦手なので");
        }
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
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "この温泉肌に優しいと聞きましたわ");
        }
        else if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "おおこの暖かさ、気持ちいいよね");
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "普通のデート感もいいですよね");
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "なんか祭りに楽しんでいるみたい！");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "すごい！この無限な広さやばくない？");
        }
        else if (buildEvent == B_EVNT_POLNORMAL)
        {
            strcpy_s(thought, sizeof(thought),
                "普通のデート感もいいですよね");
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "この幸せの甘さでめっちゃいい！心にしみれるわ");
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "普通のデート感もいいですよね");
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "おしゃれの一品飲もうか？");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "なんかいろんな意味でワクワクするわ");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "いいねこの物語、二人が一緒にいってくれてよかった");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "これ本当におもしろいですよね");
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "一緒に記念のアクセサリーを作りましょう！");
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "友たちのお為に特別なお土産を作りましょう！");
        }

        if (buildEvent == B_EVNT_EATBBQ ||
            buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "匂いが．．．ちょっとね．．．");
            SetResultTipsTo("強い匂いがあるところにデートしないでほうがいいですよ");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "もっとおしゃれな店がいいな");
            SetResultTipsTo("酒場のは少々騒がしい場所なので");
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "えっ？何このカルピス放題って");
            SetResultTipsTo("カルピスはカップルにはちょっと微妙かも");
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "もっといい選択があるはずじゃん");
            SetResultTipsTo("この主題は人によって好き嫌いがあります");
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "え？二人で一緒に歌いたいよもう");
            SetResultTipsTo("カップルに対して普通のカラオケのほうがいいかもしれません");
        }
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
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "暖かくになったね、もう冷房には何も怖くないよ");
        }
        else if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "体から力がどんどん現れている、いいよね");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "バーベキューのは超久しぶりだね、楽しみにしている");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "このうまさすごいね、どんなバグでも怖くないだ");
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "水流の中に泳ぐのは予想以上楽しいね");
        }
        else if (buildEvent == B_EVNT_DRKTEA ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "いいね、普段はこんな店あんまり来ないんだ");
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "技術はここまでできるか、やっぱり未来は期待できる");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "この熱血感ずいぶん久しぶりだ");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "すごく面白いですね、このコメディ");
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "一人で歌うのは気楽なことだ");
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "ホテルの落ち着く感はいいね、パソコンも使えるし");
        }
        else if (buildType == B_TYPE_MAKEBYHAND)
        {
            strcpy_s(thought, sizeof(thought),
                "手作りのものに匠の精神も多少ありますね");
        }

        if (buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "仕事の時昼飯はもうラーメンいっぱいだね");
            SetResultTipsTo("どうやらプログラマーの昼飯は常にラーメンである");
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "甘すぎくないタピオカって");
            SetResultTipsTo("深い理由がないがプログラマーはどうやらタピオカ好きではありません");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "嫌だ上司に飲まさせられた記憶が蘇った");
            SetResultTipsTo("遥か昔、とあるプログラマーは上司に無理矢理飲まさせられたことがある");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "せっかくのリゾートにもっと穏やかになりたいな");
            SetResultTipsTo("大したことないんが、このプログラマーはホラー苦手です");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "えっ？こんなこと言ったらおしまいじゃん？");
            SetResultTipsTo("このプログラマーはいつも合理的なものを追求しています");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "皆の前に歌うのは少し恥ずかしくなるな");
            SetResultTipsTo("どうやらこのプログラマーは人の前に歌う事が嫌いです");
        }
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
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "温泉に沁みれたらアイデアがどんどん出ていきますね");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "ウナギ屋は良い技が持ってますね、美しいほどの旨い");
        }
        else if (buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_EATRAMEN)
        {
            strcpy_s(thought, sizeof(thought),
                "日常感たっぷりですが、これも美感の起こりの一つね");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "無限に延べてるボーダーラインに色んな可能性がある");
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "この香ばしいお茶はもう無敵だわ");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "人々の気持ちや感情が全ての美しいものの根源だね");
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "昔の人にいろんな知識や経験など得られますね");
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "自然と話し合いと自分を納得できるようになった");
        }

        if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "あ昔の祭りの時思い出した、楽しい思い出じゃないが");
            SetResultTipsTo("ここの話ですが、アーティストさんは昔ある祭りに彼氏にフラれたみたい");
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "ああ歌うのは苦手ですよ．．．");
            SetResultTipsTo("キャラの個性なんですけど、アーティストさんは歌うことが嫌みたい");
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "なんか出張してる気がする？");
            SetResultTipsTo("アーティストさんはいつも絶賛在宅勤務しているそうです");
        }
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
        if (buildEvent == B_EVNT_SKINCARESPR)
        {
            strcpy_s(thought, sizeof(thought),
                "これ肌にすごく効果的と聞きました！");
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "いいね、祭りっぽくな感じ");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "自分の手でご飯を作るのはたのたのしい～");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "おお～なんだなんだこの広さ、すごい！");
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "夜のプールこそ独特な面白さがあるとはな");
        }
        else if (buildEvent == B_EVNT_DRKMILKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "タピオカの味に人を元気にさせる力がある！");
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "ゆっくりと一杯飲もう？雰囲気いいし");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "やっぱ皆でカラオケしての方が楽しいね");
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "凄い、これって「あたし～限定～」ということじゃん");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "普段はあんまりホラー見てないんがなんか新鮮な感じ");
        }
        else if (buildEvent == B_EVNT_MOVSF ||
            buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "おお～これやばくない？本当にかっこいい！");
        }

        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "うんん、単純な温泉ってなんかちょっとつまらん");
            SetResultTipsTo("どうやら事務員さんは日常と違う体験を探しています");
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "もっと特別なものが欲しいね");
            SetResultTipsTo("どうやら事務員さんは日常と違う体験を探しています");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "これは仕事終わりの飲み会かい！");
            SetResultTipsTo("事務員さんに対して多分仕事後の飲み会はもう飽きたです");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "個人的にはインパクトが欲しいね");
            SetResultTipsTo("結果が見通しやすいなことは事務員さんが探しているものではありません");
        }
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
        if (buildType == B_TYPE_HOTSPRING)
        {
            strcpy_s(thought, sizeof(thought),
                "次の家族旅行も温泉いきましょうよ");
        }
        else if (buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "どんな時でも来れるプールっていいよね");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "火傷注意して一緒に美味しいご飯作りましょう！");
        }
        else if (buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "同じ美味しいが母ちゃんのカレーとは違う風味がある");
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "焼きそばからのいい香り！");
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "父ちゃん母ちゃんカルピス飲みたい！");
        }
        else if (buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "家族の間でこんなゆっくりの時間が一番だね");
        }
        else if (buildEvent == B_EVNT_MOVSF)
        {
            strcpy_s(thought, sizeof(thought),
                "ね太郎、このキャラかっこいいでしょう？");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "この映画面白いねママ");
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "花ちゃん、将来このような立派な人間になりたい！");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "家族で一緒にカラオケしてもなかなか楽しいじゃん");
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "父ちゃん母ちゃんキャンプって凄く楽しい！");
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "自分でお土産を作るのもいいね");
        }

        if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "一郎入るな、流水プールはまだ危険すぎるんだろう？");
            SetResultTipsTo("子供に対して流水プールはまだまだ早い");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "花ちゃんーーどこにいるのーーーー");
            SetResultTipsTo("子供を自分の周りに縛りたくないが広い場所に迷子になる可能性が非常に高い");
        }
        else if (buildEvent == B_EVNT_DRKBAR ||
            buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "おいおい、未成年がいるでしょう？");
            SetResultTipsTo("未成年に対して酒はダメです");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "怖くない怖くない。ホラーってまじ有り得ないわ");
            SetResultTipsTo("ホラー映画は子供に対して不適切なものです");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "嫌だ血が出てる。。。");
            SetResultTipsTo("アクション映画の暴力内容は子供に対して不適切なものです");
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "わざわざ私たち分けて必要ないじゃん");
            SetResultTipsTo("家族メンバーに一緒にいることが大切なのです");
        }
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
        if (buildEvent == B_EVNT_NORMALSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "いいウギ、この暖かさ");
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "あ、これ本当に美味しいウギ！");
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD ||
            buildEvent == B_EVNT_DRKCAFE)
        {
            strcpy_s(thought, sizeof(thought),
                "この店凄くおしゃれウギ");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL)
        {
            strcpy_s(thought, sizeof(thought),
                "賑やかにも嬉しいウギ");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "感動されたウギ．．．");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "これ面白いウギ！");
        }
        else if (buildEvent == B_EVNT_MOVDOCUMENTARY)
        {
            strcpy_s(thought, sizeof(thought),
                "こういうのも人間かウギ．．．");
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "あ～森より良すぎるだウギ");
        }
        else if (buildEvent == B_EVNT_MAKEPRESENT)
        {
            strcpy_s(thought, sizeof(thought),
                "友たちに何を作って上げるがいいウギ");
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "この匂いもうダメウギ．．．");
            SetResultTipsTo("動物に対して硫黄泉の匂いがちょっと強烈すぎます");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "ひっ、ひどいウギ．．．");
            SetResultTipsTo("同じく人間に食べられる同士なので、そいつを食うのはちょっと残酷なことです");
        }
        else if (buildEvent == B_EVNT_POLFLUSH)
        {
            strcpy_s(thought, sizeof(thought),
                "一生登れない気がするウギ．．．");
            SetResultTipsTo("流水プールから脱出のはウサギさん自分の力でできることではありません");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "あああ血だ血だっ！");
            SetResultTipsTo("かわいいうさぎさんに対してホラーは刺激すぎます");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "苦手なんだよこのタイプ．．．");
            SetResultTipsTo("かわいいうさぎさんに対してアクション映画は刺激すぎます");
        }
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
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "おお、体が完全に温まったぞクジ！");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "この肉本当に旨いクジ！");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "魚ってこんな美味しいものだっけ？");
        }
        else if (buildEvent == B_EVNT_EATFRIEDNOODLE)
        {
            strcpy_s(thought, sizeof(thought),
                "美味しいクジ、このぬるぬるのめん");
        }
        else if (buildEvent == B_EVNT_POLINFINITY)
        {
            strcpy_s(thought, sizeof(thought),
                "小さい海みたい！小さいクジけど");
        }
        else if (buildEvent == B_EVNT_DRKKARUPISU)
        {
            strcpy_s(thought, sizeof(thought),
                "面白いクジこの酸っぱいな水！");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "このなかなかのインパクトがあるクジ、面白い");
        }
        else if (buildEvent == B_EVNT_MOVLOVE)
        {
            strcpy_s(thought, sizeof(thought),
                "いいよクジ、この甘酸っぱいな感じ");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "ハハハハハこれ超面白いクジ！");
        }
        else if (buildEvent == B_EVNT_KARAMUTLI)
        {
            strcpy_s(thought, sizeof(thought),
                "私たちくじらだもんね、一緒に歌うのは一番楽クジ");
        }
        else if (buildEvent == B_EVNT_MAKEACSY)
        {
            strcpy_s(thought, sizeof(thought),
                "私もこんな綺麗なアクセサリー作れるクジ？");
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "ああ、この匂い本当にたまらないクジ");
            SetResultTipsTo("動物に対して硫黄泉の匂いがちょっと強烈すぎます");
        }
        else if (buildEvent == B_EVNT_POLNORMAL ||
            buildEvent == B_EVNT_POLFLUSH ||
            buildEvent == B_EVNT_POLNIGHT)
        {
            strcpy_s(thought, sizeof(thought),
                "え？このプール小さすぎるでしょう？");
            SetResultTipsTo("いつも自由自在に泳いでいるくじらに対してプールはほぼ小さいすぎます");
        }
        else if (buildEvent == B_EVNT_DRKALCOHOL ||
            buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "酒は少々苦手クジ．．．");
            SetResultTipsTo("もし高圧の海の中に酔っ払いになると頭はごちゃごちゃになります");
        }
        else if (buildEvent == B_EVNT_KARASINGLE)
        {
            strcpy_s(thought, sizeof(thought),
                "ええ？歌うのは皆一緒でこそ楽しいでしょう？");
            SetResultTipsTo("くじらは社交意識がある動物なので、歌でコミュニケーションを行う必要があります");
        }
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
        if (buildEvent == B_EVNT_WARMSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "完全に温まったぞ、夜の砂漠でも怖くないクダ！");
        }
        else if (buildEvent == B_EVNT_EATLIGHTFOOD)
        {
            strcpy_s(thought, sizeof(thought),
                "この店凄くおしゃれクダ");
        }
        else if (buildEvent == B_EVNT_EATRAMEN ||
            buildEvent == B_EVNT_EATCURRY)
        {
            strcpy_s(thought, sizeof(thought),
                "あ、これ本当に美味しいクダ！");
        }
        else if (buildType == B_TYPE_POOL)
        {
            strcpy_s(thought, sizeof(thought),
                "水の中に泳ぐのは凄く楽しいクダ！");
        }
        else if (buildEvent == B_EVNT_DRKTEA)
        {
            strcpy_s(thought, sizeof(thought),
                "いいねこのお茶の香り");
        }
        else if (buildEvent == B_EVNT_DRKBAR)
        {
            strcpy_s(thought, sizeof(thought),
                "うん、おしゃれの店におしゃれの一品、いいクダ");
        }
        else if (buildEvent == B_EVNT_MOVACT)
        {
            strcpy_s(thought, sizeof(thought),
                "おお、凄いよこの映画");
        }
        else if (buildEvent == B_EVNT_MOVCOMEDY)
        {
            strcpy_s(thought, sizeof(thought),
                "これ面白いクダ！");
        }
        else if (buildEvent == B_EVNT_RESTHOTEL)
        {
            strcpy_s(thought, sizeof(thought),
                "あ～砂漠より良すぎるだクダ");
        }

        if (buildEvent == B_EVNT_HEALTHSPR)
        {
            strcpy_s(thought, sizeof(thought),
                "何なんだこの匂い");
            SetResultTipsTo("動物に対して硫黄泉の匂いがちょっと強烈すぎます");
        }
        else if (buildEvent == B_EVNT_EATUNAGI)
        {
            strcpy_s(thought, sizeof(thought),
                "ひっ、ひどいクダ．．．");
            SetResultTipsTo("植食動物に対して肉を食うのは残酷なことです");
        }
        else if (buildEvent == B_EVNT_EATBBQ)
        {
            strcpy_s(thought, sizeof(thought),
                "皆ほぼ肉を焼いてるクダ？");
            SetResultTipsTo("植食動物に対して肉を食うのは残酷なことです");
        }
        else if (buildEvent == B_EVNT_MOVHOR)
        {
            strcpy_s(thought, sizeof(thought),
                "砂漠はもう十分こわいのにぃ！");
            SetResultTipsTo("夜になると砂漠に色んな動物が出てしまい、駱駝さんに対してそれは十分ホラーでした");
        }
        else if (buildType == B_TYPE_KARAOKE)
        {
            strcpy_s(thought, sizeof(thought),
                "ぼく歌うのは苦手クダ．．．");
            SetResultTipsTo("深い理由がないがらくださんは歌えませんみたい");
        }
        else if (buildEvent == B_EVNT_RESTCAMP)
        {
            strcpy_s(thought, sizeof(thought),
                "なんかしんどいの砂漠生活を思い出したクダ");
            SetResultTipsTo("ほぼ全ての哺乳動物に対して砂漠は暮らしつらい場所である");
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
