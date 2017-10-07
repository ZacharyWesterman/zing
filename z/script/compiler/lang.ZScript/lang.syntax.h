#pragma once
#ifndef LANG_SYNTAX_H_INCLUDED
#define LANG_SYNTAX_H_INCLUDED

#include <z/core/array.h>
#include <z/script/compiler/syntaxRule.h>
//#include <z/zcript/compiler/identEnum.h>

enum SYNTAX
{
    IDENTIFIERLIST = z::script::compiler::ident::ID_COUNT,
    COMMAND,

    STATEMENTLIST,
    STATEMENT,
    IF_STATEMENT,
    FOR_STATEMENT,
    FOREACH_STATEMENT,
    LOOP_STATEMENT,
    WHILE_PRE_STMT,
    WHILE_POST_STMT,
    RUN_STATEMENT,
    STOP_STATEMENT,
    RETURN_STATEMENT,
    WAIT_STATEMENT,
    UNTIL_STATEMENT,
    LABEL_STATEMENT,
    GOTO_STATEMENT,
    GOSUB_STATEMENT,

    SUBROUTINE_DECL,

    VARIABLE_DECL,
    TYPEVAR_DECL,

    INT_DECLLIST,
    TYPEDECL,

    EXTERNALDECL,
    SHAREDDECL,

    FUNC_PROTOTYPE,
    FUNCTION_DECL,

    RANGE,
    RANGELIST,
    INDEX,
    INDEXLIST,

    EXPRLIST,
    LIST,

    FUNCCALL,
    TYPE_FUNCCALL,

    VARINDEX,
    TYPEVAR,
    VARIABLE,
    OPERAND,

    PARENTHEXPR,
    FACTORIALEXPR,
    ADD1EXPR,
    NEGATEXPR,
    POWEREXPR,
    MULTIPLYEXPR,
    ADDEXPR,
    BOOLEXPR,
    ASSIGNEXPR,
    DIMENSIONEXPR,
    SIZEOFEXPR,

    FORMALVARDECL,
    FORMALTYPEDECL,
    FORMALDECLLIST,

    PROGRAM,

    FUNCCALL_BUILTIN,

    LX_COUNT
};

#include "lang.syntax/program.h"

#include "lang.syntax/operand.h"
#include "lang.syntax/variable.h"


#define SYN_RULE_C z::script::compiler::syntaxRule<char>
#define SYN_RULE_W z::script::compiler::syntaxRule<wchar_t>
#define ARRAY_C z::core::array<SYN_RULE_C*>
#define ARRAY_W z::core::array<SYN_RULE_W*>


ARRAY_C* genSyntaxRulesC()
{
    ARRAY_C* rules = new ARRAY_C
    {
        new z::script::compiler::operand<char>,
        new z::script::compiler::variable<char>
    };

    return rules;
}

SYN_RULE_C* genProgramRuleC()
{
    return new z::script::compiler::program<char>;
}


ARRAY_W* genSyntaxRulesW()
{
    ARRAY_W* rules = new ARRAY_W
    {
        new z::script::compiler::operand<wchar_t>,
        new z::script::compiler::variable<wchar_t>
    };

    return rules;
}

SYN_RULE_W* genProgramRuleW()
{
    return new z::script::compiler::program<wchar_t>;
}

#undef SYN_RULE_C
#undef SYN_RULE_W
#undef ARRAY_C
#undef ARRAY_W

#endif // LANG_SYNTAX_H_INCLUDED
