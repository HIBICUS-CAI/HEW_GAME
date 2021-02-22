//------------------------------------------------------------------------
// ファイル名: DataSyncer.h
// 機能: ゲームに使うデータベースのデータをまとめて管理する
//------------------------------------------------------------------------

#pragma once

/// <summary>
/// 結果テーブルを更新に使われる構造体
/// </summary>
struct DATA_UPDATE_RANK
{
    int StageID;
    int Rank;

    DATA_UPDATE_RANK()
    {
        StageID = -1;
        Rank = -1;
    }

    DATA_UPDATE_RANK(int _stage, int _rank)
    {
        StageID = _stage;
        Rank = _rank;
    }

    int IsMeanful()
    {
        if (StageID != -1 && Rank != -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

/// <summary>
/// 施設テーブルを更新に使われる構造体
/// </summary>
struct DATA_UPDATE_BUILD
{
    int StageID;
    int BuildTypeCount[8];

    DATA_UPDATE_BUILD()
    {
        StageID = -1;
        for (int i = 0; i < 8; i++)
        {
            BuildTypeCount[i] = 0;
        }
    }

    DATA_UPDATE_BUILD(int _stage, int* _count)
    {
        StageID = _stage;
        for (int i = 0; i < 8; i++)
        {
            BuildTypeCount[i] = _count[i];
        }
    }

    int IsMeanful()
    {
        if (StageID != -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

/// <summary>
/// HEW専用のデータベースに接続
/// </summary>
void ConnectToHewDatabase();

/// <summary>
/// HEW専用のデータベースにの接続を閉じる
/// </summary>
void CloseConnectToHewDatabase();

/// <summary>
/// うまく接続か否かを確認
/// </summary>
void TestHewDatabaseConnect();

/// <summary>
/// データベースからの値保存先を初期化する
/// </summary>
void InitDataSyncerCountArray();

/// <summary>
/// 結果テーブルを更新する
/// </summary>
/// <param name="data">今度の結果指向のポインタ</param>
void UpdateStageRankMT(DATA_UPDATE_RANK* data);

/// <summary>
/// 施設テーブルを更新する
/// </summary>
/// <param name="data">今度の施設情報指向のポインタ</param>
void UpdateStageBuildTypeMT(DATA_UPDATE_BUILD* data);

/// <summary>
/// 結果と施設テーブルから必要な情報を保存する
/// </summary>
/// <param name="stageID">今のステージ番号指向のポインタ</param>
void GetStageRankAndBuildCount(int* stageID);

/// <summary>
/// 結果テーブルを更新用のスレッドを作成する
/// </summary>
void CreateUpdateStageRankThread();

/// <summary>
/// 施設テーブルを更新用のスレッドを作成する
/// </summary>
void CreateUpdateStageBuildThread();

/// <summary>
/// 結果と施設テーブルから必要な情報を保存用のスレッドを作成する
/// </summary>
void CreateGetStageRankAndBuildThread();

/// <summary>
/// 結果テーブルを更新用のスレッドを閉じる
/// </summary>
void CloseUpdateStageRankThread();

/// <summary>
/// 施設テーブルを更新用のスレッドを閉じる
/// </summary>
void CloseUpdateStageBuildThread();

/// <summary>
/// 結果と施設テーブルから必要な情報を保存用のスレッドを閉じる
/// </summary>
void CloseGetStageRankAndBuildThread();

/// <summary>
/// ランクデータ指向のポインタを取得
/// </summary>
/// <returns>ランクデータ指向のポインタ</returns>
DATA_UPDATE_RANK* GetUpdateRankAddr();

/// <summary>
/// 施設データ指向のポインタを取得
/// </summary>
/// <returns>施設データ指向のポインタ</returns>
DATA_UPDATE_BUILD* GetUpdateBuildAddr();

/// <summary>
/// データベース使用できるか否かを取得
/// </summary>
/// <returns>使用フラグ</returns>
int CanUseDataBase();

/// <summary>
/// データベースから貰ったランクを取得
/// </summary>
/// <returns>ランク配列</returns>
int* GetDBRankArray();

/// <summary>
/// データベースから貰った施設を取得
/// </summary>
/// <returns>施設配列</returns>
int* GetDBBuildArray();

/// <summary>
/// データベースに接続する用のステージ番号を設定
/// </summary>
/// <param name="value">ステージ番号</param>
void SetDBStageArgument(int value);

/// <summary>
/// 今の結果は最新か否か
/// </summary>
/// <returns>最新結果フラグ</returns>
int IsDBResultNewest();
