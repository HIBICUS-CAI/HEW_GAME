#include "DataSyncer.h"

int g_CanUseDatabase = 0;

void ConnectToHewDatabase()
{
}

void CloseConnectToHewDatabase()
{
}

void TestHewDatabaseConnect()
{
    //int databaseFlg = 1;
}

void InitDataSyncerCountArray()
{
}

void UpdateStageRankMT(DATA_UPDATE_RANK* data)
{
}

void UpdateStageBuildTypeMT(DATA_UPDATE_BUILD* data)
{
}

void GetStageRankAndBuildCount(int* stageID)
{
}

void CreateUpdateStageRankThread()
{
}

void CreateUpdateStageBuildThread()
{
}

void CreateGetStageRankAndBuildThread()
{
}

void CloseUpdateStageRankThread()
{
}

void CloseUpdateStageBuildThread()
{
}

void CloseGetStageRankAndBuildThread()
{
}

DATA_UPDATE_RANK* GetUpdateRankAddr()
{
    return nullptr;
}

DATA_UPDATE_BUILD* GetUpdateBuildAddr()
{
    return nullptr;
}

int CanUseDataBase()
{
    return g_CanUseDatabase;
}

int* GetDBRankArray()
{
    return nullptr;
}

int* GetDBBuildArray()
{
    return nullptr;
}

void SetDBStageArgument(int value)
{
}

int IsDBResultNewest()
{
    return 0;
}
