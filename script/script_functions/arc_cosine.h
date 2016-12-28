#pragma once
#ifndef ARC_COSINE_H_INCLUDED
#define ARC_COSINE_H_INCLUDED

#include "../../core/array.h"
#include "../../core/string.h"
#include "../../core/stringUtils/eval_string.h"
#include "../script_errors.h"

#include <math.h>


namespace script
{
    namespace FUNCTION
    {
        //arc cosine function must take 1 parameter.
        //units are assumed to be in radians.
        template <typename CHAR>
        error_flag arc_cosine(const core::array< core::string<CHAR> >& params, core::string<CHAR>& output)
        {
            error_flag func_error = ERROR::NONE;

            if (params.size() > 1)
            {
                func_error |= ERROR::TOO_MANY_PARAMS;
            }
            else if (params.size() < 1)
            {
                func_error |= ERROR::TOO_FEW_PARAMS;
            }
            else
            {
                double angle = core::value(params.at(0));

                output = acos(angle);
            }

            return func_error;
        }
        //end of arc_cosine

    }
}

#endif // ARC_COSINE_H_INCLUDED
