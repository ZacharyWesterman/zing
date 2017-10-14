/**
 * File:            addexpr.h
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
 * Last modified:   19 Jul. 2017
**/

#pragma once
#ifndef ADDEXPR_H_INCLUDED
#define ADDEXPR_H_INCLUDED

namespace z
{
namespace script
{
    namespace compiler
    {
        template <typename CHAR>
        class addexpr : public syntaxRule<CHAR>
        {
        public:
            ~addexpr() {}

            bool apply(core::array< phrase_t<CHAR>* >*,
                       int);
        };

        template <typename CHAR>
        bool addexpr<CHAR>::apply(core::array< phrase_t<CHAR>* >* phrase_nodes,
                                  int index)
        {
            //if no detected addition(or mul.) operators, continue to the next phase
            if ((phrase_nodes->at(index)->type == MULTIPLYEXPR) &&
                !(phrase_nodes->is_valid(index+1) &&
                  (phrase_nodes->at(index+1)->type >= ident::OPERATOR) &&
                  (phrase_nodes->at(index+1)->metaValue >= MUL) &&
                  (phrase_nodes->at(index+1)->metaValue <= MOD)
                  ) &&
                !(phrase_nodes->is_valid(index-1) &&
                  (phrase_nodes->at(index-1)->type >= ident::OPERATOR) &&
                  (phrase_nodes->at(index-1)->metaValue >= MUL) &&
                  (phrase_nodes->at(index-1)->metaValue <= MOD)
                  )
                )
            {
                if (phrase_nodes->at(index)->orig_type == ident::NONE)
                    phrase_nodes->at(index)->orig_type = phrase_nodes->at(index)->type;

                phrase_nodes->at(index)->type = ADDEXPR;

                return true;
            }
             //otherwise, if an addition operator is detected
            else if (phrase_nodes->is_valid(index+2) &&
                     ((phrase_nodes->at(index)->type == MULTIPLYEXPR) ||
                      (phrase_nodes->at(index)->type == ADDEXPR)
                      ) &&
                     ((phrase_nodes->at(index+1)->type == ADD) ||
                      (phrase_nodes->at(index+1)->type == SUB)
                      ) &&
                     ((phrase_nodes->at(index+2)->type == MULTIPLYEXPR) ||
                      (phrase_nodes->at(index+2)->type == ADDEXPR)
                      )
                     )
            {
                phrase_t<CHAR>* node = new phrase_t<CHAR>();

                node->type = ADDEXPR;

                node->line = phrase_nodes->at(index)->line;
                node->column = phrase_nodes->at(index)->column;

                phrase_nodes->at(index)->parent = node;
                phrase_nodes->at(index+1)->parent = node;
                phrase_nodes->at(index+2)->parent = node;

                node->children.add(phrase_nodes->at(index));
                node->children.add(phrase_nodes->at(index+1));
                node->children.add(phrase_nodes->at(index+2));

                node->file = phrase_nodes->at(index)->file;

                phrase_nodes->replace(index, index+2, node);

                return true;
            }
            else
                return false;
        }
    }
}
}

#endif // ADDEXPR_H_INCLUDED