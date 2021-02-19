//------------------------------------------------------------------------
// ファイル名: DeclaredValues.h
// 機能: 特殊なグローバル変数を声明する
//------------------------------------------------------------------------

#pragma once

#include "DefinedValues.h"
#include "Structs.h"

/// <summary>
/// ゲームが続けるかどうかを設定
/// </summary>
/// <param name="value">０ならゲームが続けない</param>
void SetGameRunFlag(int value);

/// <summary>
/// ゲームが続けるかどうかを取得
/// </summary>
/// <returns>続けるのしるし</returns>
int GetGameRunFlag();

#define DELTATIME 16

/// <summary>
/// 設定されたフレーム時間を取得
/// </summary>
/// <returns>設定されたフレーム時間</returns>
int GetDeclaredDeltaTime();

/// <summary>
/// フレーム時間を設定する
/// </summary>
/// <param name="value">フレーム時間</param>
void SetDeclaredDeltaTime(int value);

/// <summary>
/// 出力ハンドルを取得
/// </summary>
/// <returns>出力制御ハンドル</returns>
HANDLE GetPrintHandle();

/// <summary>
/// 出力ハンドルを設定
/// </summary>
/// <param name="handle">出力制御ハンドル</param>
void SetPrintHandle(HANDLE handle);

/// <summary>
/// 更新用バッファと出力用バッファを交換
/// </summary>
void SwapPrintChain();

/// <summary>
/// 更新用バッファを取得
/// </summary>
/// <returns>更新用バッファに指向のポインタ</returns>
char* GetOutputBufferToUpdate();

/// <summary>
/// 出力用バッファを取得
/// </summary>
/// <returns>出力用バッファに指向のポインタ</returns>
char* GetOutputBufferToPrint();

#define UIOBJSIZE 32

/// <summary>
/// ＵＩアイテム配列を取得
/// </summary>
/// <returns>ＵＩアイテム配列のヘッドポインタ</returns>
UIOBJECT* GetUIObj();

/// <summary>
/// ＵＩアイテム配列の現在番号
/// </summary>
/// <returns>現在の番号</returns>
int* GetUIOIndex();

/// <summary>
/// ＵＩアイテム配列の現在番号を設定
/// </summary>
/// <param name="value">番号の値</param>
void SetUIOIndex(int value);

/// <summary>
/// ＵＩアイテム配列の現在番号を１を足す
/// </summary>
void AddUIOIndex();

/// <summary>
/// 現在最も上階なＵＩアイテムを取得
/// </summary>
/// <returns>最上階のＵＩアイテムに指向のポインタ</returns>
UIOBJECT* GetTopUIO();

/// <summary>
/// 最上階のＵＩアイテムを設定
/// </summary>
/// <param name="uiObj">ＵＩアイテム指向のポインタ</param>
void SetTopUIO(UIOBJECT* uiObj);

/// <summary>
/// バッファ交換用制御声明を取得
/// </summary>
/// <returns>制御用アイテム</returns>
CRITICAL_SECTION* GetSwapChainCS();

/// <summary>
/// 今選択されたボタンを取得
/// </summary>
/// <returns>選択されたボタンに指向のポインタ</returns>
UI_BUTTON* GetSelectedBtn();

/// <summary>
/// 選択されるボタンを設定
/// </summary>
/// <param name="btn">ボタンに指向のポインタ</param>
void SetSelectedBtn(UI_BUTTON* btn);

/// <summary>
/// 自動的にボタンを設定する記号を取得
/// </summary>
/// <returns>記号に指向のポインタ</returns>
int* GetAutoSelectBtnFlag();

/// <summary>
/// 自動的ボタンを設定するの記号を設定
/// </summary>
/// <param name="value">記号の値</param>
void SetAutoSelectBtnFlag(int value);

#define SOUNDFILE_SIZE 64

#ifdef SOUNDBYHAL
/// <summary>
/// 格納されたの音声ファイル配列を取得
/// </summary>
/// <returns>格納されたの音声ファイル配列指向のポインタ</returns>
SOUNDFILE_LOADED* GetSoundFilesInMemBitesArray();
#else
/// <summary>
/// 格納されたの音声ファイル配列を取得
/// </summary>
/// <returns>格納されたの音声ファイル配列指向のポインタ</returns>
SOUNDFILE_IN_MEMBITE* GetSoundFilesInMemBitesArray();
#endif // SOUNDBYHAL

#ifdef SOUNDBYHAL
/// <summary>
/// 名前によって格納されたの音声ファイルを取得
/// </summary>
/// <param name="fileName">格納された音声ファイルの名前</param>
/// <returns>格納された音声ファイル指向のポインタ</returns>
SOUNDFILE_LOADED* GetSoundFilesInMemBites(const char* soundName);
#else
/// <summary>
/// 名前によって格納されたの音声ファイルを取得
/// </summary>
/// <param name="fileName">格納された音声ファイルの名前</param>
/// <returns>格納された音声ファイル指向のポインタ</returns>
SOUNDFILE_IN_MEMBITE* GetSoundFilesInMemBites(const char* fileName);
#endif // SOUNDBYHAL

#ifndef SOUNDBYHAL

#define SOUNDHANDLE_SIZE 8

/// <summary>
/// 音声ハンドル配列を取得
/// </summary>
/// <returns>音声ハンドル配列に指向のポインタ</returns>
SOUND_THREAD_HANDLE* GetSoundHandleArray();

/// <summary>
/// 使っていない音声ハンドルを取得
/// </summary>
/// <returns>使っていない音声ハンドル構造体指向のポインタ</returns>
SOUND_THREAD_HANDLE* GetSoundHandleThatNotUsing();

#endif // !SOUNDBYHAL
