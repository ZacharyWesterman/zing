/**
 * File:            statementlist.h
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
#ifndef STATEMENTLIST_H_INCLUDED
#define STATEMENTLIST_H_INCLUDED

namespace z
{
    namespace script
    {
        template <typename CHAR>
        bool lexer<CHAR>::statementlist()
        {
            if (phrase_nodes.is_valid(index+1) &&
                ((phrase_nodes[index]->type == phrase::STATEMENT) ||
                 (phrase_nodes[index]->type == phrase::STATEMENTLIST)) &&
                (phrase_nodes[index+1]->type == phrase::STATEMENT))
            {
                phrase_t<CHAR>* node = new phrase_t<CHAR>();

                node->type = phrase::STATEMENTLIST;

                node->line = phrase_nodes[index]->line;
                node->column = phrase_nodes[index]->column;

                phrase_nodes[index]->parent = node;
                phrase_nodes[index+1]->parent = node;

                node->children.add(phrase_nodes[index]);
                node->children.add(phrase_nodes[index+1]);

                node->file = phrase_nodes[index]->file;

                phrase_nodes.replace(index, index+1, node);

                return true;
            }
            else
                return false;
        }
    }
}

#endif // STATEMENTLIST_H_INCLUDED