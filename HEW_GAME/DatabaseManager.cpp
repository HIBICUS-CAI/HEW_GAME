#include "DataBaseManager.h"
#include "LogsOutput.h"

void InitDatabaseHandle(MYSQL* dbHandle)
{
    mysql_init(dbHandle);
}

MYSQL* ConnectToDatabase(MYSQL* dbHandle,
    const char* host, const char* user,
    const char* passwd, const char* database)
{
    unsigned int port = 3306;
    const char* unix_socket = NULL;
    unsigned long client_flag = 0;

    MYSQL* cnctHandle;
    cnctHandle = mysql_real_connect(
        dbHandle, host, user, passwd, database,
        3306, NULL, 0
    );

    if (cnctHandle == NULL)
    {
        char errLog[128];
        sprintf_s(errLog, sizeof(errLog),
            "cannot connect to database : %s",
            mysql_error(dbHandle));
        ErrorLog(errLog);

        return NULL;
    }
    else
    {
        DebugLog("connect with database successfully");
    }

    return cnctHandle;
}

void CloseConnectHandle(MYSQL* cnctHandle)
{
    if (cnctHandle == NULL)
    {
        return;
    }
    else
    {
        mysql_close(cnctHandle);
        DebugLog("disconnect with database successfully");
    }
}

int RunQueryRequest(MYSQL* dbHandle, const char* requestStr)
{
    int status = mysql_query(dbHandle, requestStr);
    if (status)
    {
        ErrorLogI1("run query fail with code : ", status);
    }

    return status;
}

void FreeResultPointer(MYSQL_RES* result)
{
    mysql_free_result(result);
}

MYSQL_RES* RunQueryAndGetResult(MYSQL* dbHandle,
    const char* requestStr)
{
    if (!RunQueryRequest(dbHandle, requestStr))
    {
        return mysql_store_result(dbHandle);
    }
}

int GetResultRowCount(MYSQL_RES* resultPointer)
{
    if (resultPointer == NULL)
    {
        ErrorLog("result pointer is null");
        return -1;
    }
    else
    {
        return (int)mysql_num_rows(resultPointer);
    }
}
