/**
 * File:            negate.h
 * Namespace:       z::script::oper
 * Description:     unary '-' script operator.
 *
 *
 * Author:          Zachary Westerman
 * Email:           zacharywesterman@yahoo.com
 * Last modified:   3 Feb. 2017
**/

#pragma once
#ifndef NEGATE_H_INCLUDED
#define NEGATE_H_INCLUDED

#include "oper_t.h"

#include "../is_script_string.h"
#include "../destringify.h"

#include "../../core/string.h"

namespace z
{
    namespace script
    {
        namespace oper
        {
            template <typename CHAR>
            class negate : public oper_t<CHAR>
            {
            public:
                ///Negation uses '-' and has a priority of 7, is unary and comes before the operand.
                negate() : oper_t<CHAR>(core::string<char>("-"), 7, true, true) {}


                ///Perform subtraction
                error_flag operate(core::dynamic_stack< core::string<CHAR> >& operands) const
                {
                    error_flag operation_error = error::NONE;

                    core::string<CHAR> arg1;

                    if (operands.pop(arg1))
                    {
                        //strings cannot undergo negation
                        if (is_script_string(arg1))
                        {
                            operation_error |= error::INVALID_OPERATION;
                        }
                        //negate the given value
                        else
                        {
                            double val1 = core::value(arg1);

                            double result = (-val1); ///negate

                            operands.push(result);
                        }
                    }
                    else
                    {
                        operation_error |= error::MISSING_OPERAND;
                    }

                    return operation_error;
                }

            };
        }
    }
}

#endif // NEGATE_H_INCLUDED