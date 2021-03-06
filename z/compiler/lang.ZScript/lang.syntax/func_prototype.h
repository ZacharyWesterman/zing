/**
 * File:            func_prototype.h
 * Namespace:       z::script::compiler
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
 * Last modified:   25 Sep. 2017
**/

#pragma once
#ifndef FUNC_PROTOTYPE_H_INCLUDED
#define FUNC_PROTOTYPE_H_INCLUDED

namespace z
{
namespace script
{
    namespace compiler
    {
        class func_prototype : public syntaxRule
        {
        public:
            ~func_prototype() {}

            bool apply(core::array< phrase_t* >*,
                       int,
                       core::array<error>*);
        };


        bool func_prototype::apply(core::array< phrase_t* >* phrase_nodes,
                                  int index,
                                  core::array<error>* error_buffer)
        {
            //function prototype must have an explicit return type.
            if (phrase_nodes->is_valid(index-1) &&
                (((phrase_nodes->at(index-1)->type == ident::KEYWORD) &&
                  (phrase_nodes->at(index-1)->metaValue == VAR)
                  ) ||
                 (phrase_nodes->at(index-1)->type == ident::IDENTIFIER)
                 )
                )
            {
                void* return_type;

                if (phrase_nodes->at(index-1)->type == ident::IDENTIFIER)
                    return_type = phrase_nodes->at(index-1)->meta;
                else
                    return_type = NULL;


                //returnType ( ... ) ;
                if (phrase_nodes->is_valid(index+4) &&
                    (phrase_nodes->at(index)->type == ident::IDENTIFIER) &&
                    (phrase_nodes->at(index+1)->type == ident::LPARENTH) &&
                    ((phrase_nodes->at(index+2)->type == FORMALVARDECL) ||
                     (phrase_nodes->at(index+2)->type == FORMALTYPEDECL) ||
                     (phrase_nodes->at(index+2)->type == FORMALDECLLIST)) &&
                    (phrase_nodes->at(index+3)->type == ident::RPARENTH) &&
                    (phrase_nodes->at(index+4)->type == ident::SEMICOLON))
                {
                    phrase_t* node =
                    new phrase_t(*(phrase_nodes->at(index)), FUNC_PROTOTYPE);

                    phrase_nodes->at(index)->parent = node;
                    phrase_nodes->at(index+2)->parent = node;

                    node->children.add(phrase_nodes->at(index));
                    node->children.add(phrase_nodes->at(index+2));

                    node->meta = return_type;

                    delete phrase_nodes->at(index-1);
                    delete phrase_nodes->at(index+1);
                    delete phrase_nodes->at(index+3);
                    delete phrase_nodes->at(index+4);
                    phrase_nodes->replace(index-1, index+4, node);

                    return true;
                }
                //returnType ( ) ;
                else if (phrase_nodes->is_valid(index+3) &&
                    (phrase_nodes->at(index)->type == ident::IDENTIFIER) &&
                    (phrase_nodes->at(index+1)->type == ident::LPARENTH) &&
                    (phrase_nodes->at(index+2)->type == ident::RPARENTH) &&
                    (phrase_nodes->at(index+3)->type == ident::SEMICOLON))
                {
                    phrase_t* node =
                    new phrase_t(*(phrase_nodes->at(index)), FUNC_PROTOTYPE);

                    phrase_nodes->at(index)->parent = node;

                    node->children.add(phrase_nodes->at(index));

                    node->meta = return_type;

                    delete phrase_nodes->at(index-1);
                    delete phrase_nodes->at(index+1);
                    delete phrase_nodes->at(index+2);
                    delete phrase_nodes->at(index+3);
                    phrase_nodes->replace(index-1, index+3, node);

                    return true;
                }
            }

            return false;
        }
    }
}
}

#endif // FUNC_PROTOTYPE_H_INCLUDED
