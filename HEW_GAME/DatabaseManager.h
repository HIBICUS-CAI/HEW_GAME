//------------------------------------------------------------------------
// ファイル名: DatabaseManager.h
// 機能: データベースとの操作を一括で管理する
//------------------------------------------------------------------------

#pragma once

#include "Assets/Libs/MariaDB Connector C/include/mysql.h"

/// <summary>
/// 必要なデータベースハンドルを初期化する
/// </summary>
/// <param name="dbHandle">データベースハンドル</param>
void InitDatabaseHandle(MYSQL* dbHandle);

/// <summary>
/// データベースに接続する
/// </summary>
/// <param name="dbHandle">データベースハンドル</param>
/// <param name="host">データベースIP</param>
/// <param name="user">ユーザー名</param>
/// <param name="passwd">暗証番号</param>
/// <param name="database">データベース名</param>
/// <returns>接続ハンドル</returns>
MYSQL* ConnectToDatabase(MYSQL* dbHandle,
    const char* host, const char* user,
    const char* passwd, const char* database);

/// <summary>
/// データベースへの接続を閉じる
/// </summary>
/// <param name="cnctHandle">接続ハンドル</param>
void CloseConnectHandle(MYSQL* cnctHandle);

/// <summary>
/// 一つのSQL文を実行する
/// </summary>
/// <param name="dbHandle">データベースハンドル</param>
/// <param name="requestStr">SQL文</param>
/// <returns>実行成功か否か</returns>
int RunQueryRequest(MYSQL* dbHandle, const char* requestStr);

/// <summary>
/// 実行結果を取り消す
/// </summary>
/// <param name="result">実行結果ポインタ</param>
void FreeResultPointer(MYSQL_RES* result);

/// <summary>
/// SQL文を実行後その結果を取得
/// </summary>
/// <param name="dbHandle">データベースハンドル</param>
/// <param name="requestStr">SQL文</param>
/// <returns>実行結果ポインタ</returns>
MYSQL_RES* RunQueryAndGetResult(MYSQL* dbHandle,
    const char* requestStr);

int GetResultRowCount(MYSQL_RES* resultPointer);
