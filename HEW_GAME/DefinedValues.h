//------------------------------------------------------------------------
// ファイル名: DefinedValues.h
// 機能: 特殊な値を声明する
//------------------------------------------------------------------------

#pragma once

#define CONSOLE_WIDTH 180
#define CONSOLE_HEIGHT 60

#define ESC_VALUE 27
#define SPACE_VALUE 32
#define W_VALUE 119
#define A_VALUE 97
#define S_VALUE 115
#define D_VALUE 100
#define F_VALUE 102
#define J_VALUE 106
#define K_VALUE 107
#define L_VALUE 108
#define I_VALUE 105
#define O_VALUE 111
#define P_VALUE 112

#define BLACK_WHITE 0x0f
#define WHITE_BLACK 0xf0
#define BLACK_RED 0x0c
#define BLACK_DARKRED 0x04
#define BLACK_YELLOW 0x0e
#define BLACK_DARKYELLOW 0x06

#define TEST_OPENSUB 0x0001
#define TEST_CLOSETHIS 0x0002

#define MY_DEBUG_INFO

#define RUNCONTINUOUS

#ifdef RUNCONTINUOUS
#define LOCKFPS
#define MUTIPRINT
#endif // RUNCONTINUOUS

#define SOUNDBYHAL

enum class TYPEID
{
    UIObj,
    CollisionObj,
    ButtonObj,
    TextObj
};
