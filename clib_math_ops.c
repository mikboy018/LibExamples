#include "clib_math_ops.h"

double clib_add(double a, double b){
    return a + b;
}

double clib_div(double a, double b){
    if(fabs(b)<0.0000001)
        b = 0.0000001;

    return a/b;
}