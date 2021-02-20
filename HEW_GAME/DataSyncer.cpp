#include "DataSyncer.h"
#include "DatabaseManager.h"
#include "LogsOutput.h"

MYSQL g_DatabaseHandle;
MYSQL* gp_ConnectHandle = NULL;
MYSQL_RES* gp_SqlResult = NULL;

void ConnectToHewDatabase()
{
    if (gp_ConnectHandle != NULL)
    {
        CloseConnectHandle(gp_ConnectHandle);
    }
    InitDatabaseHandle(&g_DatabaseHandle);
    gp_ConnectHandle = ConnectToDatabase(
        &g_DatabaseHandle,
        "106.53.96.176",
        "player", "player",
        "hew_game"
    );
}

void CloseConnectToHewDatabase()
{
    CloseConnectHandle(gp_ConnectHandle);
    InitDatabaseHandle(&g_DatabaseHandle);
    gp_ConnectHandle = NULL;
}

void TestHewDatabaseConnect()
{
    ConnectToHewDatabase();
    FreeResultPointer(gp_SqlResult);
    gp_SqlResult = RunQueryAndGetResult(&g_DatabaseHandle,
        "select * from stage_rank");
    DebugLogI1("row's count : ", GetResultRowCount(gp_SqlResult));
    FreeResultPointer(gp_SqlResult);
    RunQueryRequest(&g_DatabaseHandle,
        "update hew_game.stage_rank set STAGE_ID=45 where RESULT_ID=0;");
    gp_SqlResult = RunQueryAndGetResult(&g_DatabaseHandle,
        "select * from stage_rank");
    DebugLogI1("row's count : ", GetResultRowCount(gp_SqlResult));
    FreeResultPointer(gp_SqlResult);
    CloseConnectToHewDatabase();
}
