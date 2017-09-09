/**
 * File:            identity.h
 * Namespace:       z::script
 * Description:     Template for script identities. An example
 *                  identifier could be represented as <"+",OPERATOR>.
 *                  For error reporting purposes, all identities include
 *                  the line and column of their first character from
 *                  the input stream.
 *
 *
 * Author:          Zachary Westerman
 * Email:           zacharywesterman@yahoo.com
 * Last modified:   20 Aug. 2017
**/

#pragma once
#ifndef IDENTITY_H_INCLUDED
#define IDENTITY_H_INCLUDED

#include <z/core/string.h>

#include "../data_t.h"
#include "../errors.h"

namespace z
{
    namespace script
    {
        namespace ident
        {
            enum ident_enum
            {
                NONE = 0,

                LPARENTH,       //1
                RPARENTH,       //2

                LBRACE,         //3
                RBRACE,         //4

                LBRACKET,       //5
                RBRACKET,       //6

                COMMA,          //7
                SEMICOLON,      //8
                PERIOD,         //9

                STRING_LITERAL, //10

                NUMERIC_LITERAL,//11
                COMPLEX_LITERAL,//12

                LITERAL,

                IDENTIFIER,     //13

                KEYWORD_IF,     //16
                KEYWORD_ELSE,   //17

                KEYWORD_FOR,    //18
                KEYWORD_EACH,   //19
                KEYWORD_IN,     //20
                KEYWORD_LOOP,   //22
                KEYWORD_WHILE,  //23

                KEYWORD_GOTO,   //24
                KEYWORD_GOSUB,  //25
                KEYWORD_LABEL,
                KEYWORD_SUB,

                KEYWORD_RUN,    //26
                KEYWORD_STOP,
                KEYWORD_INCLUDE,//27

                KEYWORD_BREAK,  //28
                KEYWORD_RETURN, //29

                KEYWORD_DIM,

                KEYWORD_WAIT,   //31
                KEYWORD_UNTIL,  //32

                KEYWORD_VAR,
                KEYWORD_TYPE,   //33
                KEYWORD_FUNCTION,

                KEYWORD_GLOBAL, //34
                KEYWORD_EXTERNAL,//35
                KEYWORD_SHARED,

                OPER_ASSIGN,    //36

                OPER_ADD_ASSIGN,
                OPER_SUB_ASSIGN,

                OPER_MUL_ASSIGN,
                OPER_DIV_ASSIGN,
                OPER_IDIV_ASSIGN,
                OPER_MOD_ASSIGN,

                OPER_ADD1,      //39
                OPER_SUB1,      //40

                OPER_SIZEOF,

                OPER_POW,       //45
                OPER_FAC,       //46

                OPER_ADD,       //37
                OPER_SUB,       //38

                OPER_MUL,       //41
                OPER_DIV,       //42
                OPER_IDIV,      //43
                OPER_MOD,       //44

                OPER_AND_LGCL,  //47
                OPER_AND_BITW,  //48

                OPER_OR_LGCL,   //49
                OPER_OR_BITW,   //50

                OPER_XOR_LGCL,  //51
                OPER_XOR_BITW,  //52

                OPER_NAND_LGCL, //55
                OPER_NAND_BITW, //56

                OPER_NOR_LGCL,  //57
                OPER_NOR_BITW,  //58

                OPER_NXOR_LGCL, //59
                OPER_NXOR_BITW, //60

                OPER_EQ,        //61
                OPER_NOT_EQ,    //62
                OPER_GT,        //63
                OPER_GT_EQ,     //64
                OPER_LT,        //65
                OPER_LT_EQ,     //66

                OPER_NOT_LGCL,  //53
                OPER_NOT_BITW,  //54

                OPER_R_ARROW,   //67
                OPER_L_ARROW,   //68

                UNKNOWN,        //69

                ID_COUNT
            };

        }

        template <typename CHAR>
        class ident_t
        {
        public:
            int type;

            int line;
            int column;

            core::string<CHAR>* meta;

            data_t<CHAR> value;

            //keep track of the current file
            core::string<CHAR>* file;

            ///full constructor
            ident_t (ident::ident_enum t = ident::NONE, int lin = 0, int col = 0,
                     core::string<CHAR>* symbol_ptr = NULL, core::string<CHAR>* fileID = NULL)
            {
                type = t;

                line = lin;
                column = col;

                meta = symbol_ptr;

                //value = 0;

                file = fileID;
            }


            ///equality operators
            inline bool operator==(const ident_t& other) const
            {
                return (type == other.type);
            }

            inline bool operator!=(const ident_t& other) const
            {
                return (type != other.type);
            }

            inline bool operator>(const ident_t& other) const
            {
                return (type > other.type);
            }

            inline bool operator>=(const ident_t& other) const
            {
                return (type >= other.type);
            }

            inline bool operator<(const ident_t& other) const
            {
                return (type < other.type);
            }

            inline bool operator<=(const ident_t& other) const
            {
                return (type <= other.type);
            }
        };

    }
}

#endif // IDENTITY_H_INCLUDED