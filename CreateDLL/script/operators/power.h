#pragma once
#ifndef POWER_H_INCLUDED
#define POWER_H_INCLUDED

#include "oper_t.h"

#include "../is_script_string.h"
#include "../destringify.h"

#include "../../core/stringUtils/eval_string.h"

namespace script
{
    namespace oper
    {
        template <typename CHAR>
        class power : public oper_t<CHAR>
        {
        public:
            ///Power uses '^' and has a priority of 6.
            power() : oper_t<CHAR>(core::string<char>("^"), 6) {}


            ///Perform multiplication
            error_flag operate(core::dynamic_stack< core::string<CHAR> >& operands) const
            {
                error_flag operation_error = error::NONE;

                /** Stuff goes here **/

                return operation_error;
            }

        };
    }
}

#endif // POWER_H_INCLUDED
