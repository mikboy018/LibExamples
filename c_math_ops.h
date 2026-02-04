#ifndef __C_MATH_OPS_H
#define __C_MATH_OPS_H
#include <math.h>

/**
 * @brief C-Header Addition (double + double = double)
 */
double c_add(double a, double b)
{
    return a+b;
}

/**
 * @brief C-Header Division (double / double = double)
 */
double c_div(double a, double b)
{
    if(fabs(b)<0.0000001)
        b = 0.0000001;

    return a/b;
}

#endif