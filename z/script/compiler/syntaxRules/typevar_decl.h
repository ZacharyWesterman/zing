/**
 * File:            typevar_decl.h
 * Namespace:       z::script
 * Description:     Implementation of the lexer's
 *                  syntax generating member functions.
 *                  This file should NOT be included
 *                  in a project. Include "lexer.h"
 *                  instead,and put this file in the
 *                  "syntaxRules" folder.
 *
 *
 * Author:          Zachary Westerman
 * Email:           zacharywesterman@yahoo.com
 * Last modified:   15 Jul. 2017
**/

#pragma once
#ifndef TYPEVAR_DECL_H_INCLUDED
#define TYPEVAR_DECL_H_INCLUDED

namespace z
{
namespace script
{
    namespace compiler
    {
        template <typename CHAR>
        bool lexer<CHAR>::typevar_decl()
        {
            if (phrase_nodes.is_valid(index+2) &&
                (phrase_nodes[index]->type == ident::IDENTIFIER) &&
                (phrase_nodes[index+1]->type == ident::IDENTIFIER) &&
                (phrase_nodes[index+2]->type == ident::SEMICOLON))
            {
                phrase_t<CHAR>* node = new phrase_t<CHAR>();

                    node->type = phrase::TYPEVAR_DECL;

                    node->line = phrase_nodes[index]->line;
                    node->column = phrase_nodes[index]->column;

                    phrase_nodes[index]->parent = node;
                    phrase_nodes[index+1]->parent = node;

                    node->children.add(phrase_nodes[index]);
                    node->children.add(phrase_nodes[index+1]);

                    node->file = phrase_nodes[index]->file;

                    delete phrase_nodes[index+2];
                    phrase_nodes.replace(index, index+2, node);

                    return true;
            }
            else if (phrase_nodes.is_valid(index+1) &&
                     phrase_nodes.is_valid(index-3) &&
                     (phrase_nodes[index-3]->type == ident::IDENTIFIER) &&
                     (phrase_nodes[index-2]->type == ident::IDENTIFIER) &&
                     (phrase_nodes[index-1]->type == ident::OPER_ASSIGN) &&
                     (phrase_nodes[index]->type == phrase::LIST) &&
                     (phrase_nodes[index+1]->type == ident::SEMICOLON))
                {
                    phrase_t<CHAR>* node = new phrase_t<CHAR>();

                    node->type = phrase::TYPEVAR_DECL;

                    node->line = phrase_nodes[index]->line;
                    node->column = phrase_nodes[index]->column;

                    phrase_nodes[index-3]->parent = node;
                    phrase_nodes[index-2]->parent = node;
                    phrase_nodes[index]->parent = node;

                    node->children.add(phrase_nodes[index-3]);
                    node->children.add(phrase_nodes[index-2]);
                    node->children.add(phrase_nodes[index]);

                    node->file = phrase_nodes[index]->file;

                    delete phrase_nodes[index-1];
                    delete phrase_nodes[index+1];
                    phrase_nodes.replace(index-3, index+1, node);

                    return true;
                }

            return false;
        }
    }
}
}

#endif // TYPEVAR_DECL_H_INCLUDED