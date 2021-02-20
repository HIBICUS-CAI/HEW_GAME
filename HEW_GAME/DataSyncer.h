//------------------------------------------------------------------------
// ファイル名: DataSyncer.h
// 機能: ゲームに使うデータベースのデータをまとめて管理する
//------------------------------------------------------------------------

#pragma once

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
