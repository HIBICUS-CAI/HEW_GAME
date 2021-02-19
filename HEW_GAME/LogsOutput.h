//------------------------------------------------------------------------
// ファイル名: LogsOutput.h
// 機能: 色んなログをアウトプット欄に出力する
//------------------------------------------------------------------------

#pragma once

#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

/// <summary>
/// 単純な文字ログを欄に出力する
/// </summary>
/// <param name="text">ログの内容</param>
void DebugLog(const char* text);

/// <summary>
/// ＩＮＴ型内容が付いているログを欄に出力する
/// </summary>
/// <param name="text">ログの文字内容</param>
/// <param name="value">ＩＮＴ型の内容</param>
void DebugLogI1(const char* text, const int value);

/// <summary>
/// ＩＮＴ型内容が付いているログを欄に出力する
/// </summary>
/// <param name="text">ログの文字内容</param>
/// <param name="value1">ＩＮＴ型の内容</param>
/// <param name="value2">ＩＮＴ型の内容</param>
void DebugLogI2(const char* text, const int value1, const int value2);

/// <summary>
/// ログをファイルに書き込む
/// </summary>
/// <param name="text">ログの内容</param>
void DebugLogToFile(const char* text);

/// <summary>
/// 単純なエラーログを欄に出力する
/// </summary>
/// <param name="text">ログの文字内容</param>
void ErrorLog(const char* text);

/// <summary>
/// ＩＮＴ型内容が付いているエラーログを欄に出力する
/// </summary>
/// <param name="text">ログの文字内容</param>
/// <param name="value">ＩＮＴ型の内容</param>
void ErrorLogI1(const char* text, const int value);

/// <summary>
/// ＩＮＴ型内容が付いているエラーログを欄に出力する
/// </summary>
/// <param name="text">ログの文字内容</param>
/// <param name="value1">ＩＮＴ型の内容</param>
/// <param name="value2">ＩＮＴ型の内容</param>
void ErrorLogI2(const char* text, const int value1, const int value2);
