#pragma once
#ifndef LANG_KEYWORDS_H_INCLUDED
#define LANG_KEYWORDS_H_INCLUDED

#include <z/core/array.h>
#include <z/script/compiler/keyword.h>

enum KEYWORDS
{
    NONE = 0,
    IF,
    ELSE,

    FOR,
    EACH,   //19
    IN,     //20
    LOOP,   //22
    WHILE,  //23

    GOTO,   //24
    GOSUB,  //25
    LABEL,
    SUB,

    RUN,    //26
    STOP,
    INCLUDE,//27

    BREAK,  //28
    RETURN, //29

    DIM,

    WAIT,   //31
    UNTIL,  //32

    VAR,
    TYPE,   //33

    EXTERNAL,
    SHARED,
};

#define KWD z::script::compiler::keyword

z::core::array<KWD> genKeywords()
{
    z::core::array<KWD> kwds =
    {
        KWD("if",       IF),
        KWD("else",     ELSE),
        KWD("for",      FOR),
        KWD("each",     EACH),
        KWD("in",       IN),
        KWD("loop",     LOOP),
        KWD("while",    WHILE),
        KWD("goto",     GOTO),
        KWD("gosub",    GOSUB),
        KWD("label",    LABEL),
        KWD("sub",      SUB),
        KWD("run",      RUN),
        KWD("stop",     STOP),
        KWD("include",  INCLUDE),
        KWD("break",    BREAK),
        KWD("return",   RETURN),
        KWD("dim",      DIM),
        KWD("wait",     WAIT),
        KWD("until",    UNTIL),
        KWD("var",      VAR),
        KWD("type",     TYPE),
        KWD("external", EXTERNAL),
        KWD("shared",   SHARED)
    };

    return kwds;
}

#undef KWD

#endif // LANG_KEYWORDS_H_INCLUDED
