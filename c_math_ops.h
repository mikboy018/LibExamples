#ifndef __C_MATH_OPS_H
#define __C_MATH_OPS_H
#include <math.h>

double c_add(double a, double b){return a+b;}
double c_div(double a, double b){
    if(fabs(b)<0.0000001)
        b = 0.0000001;

    return a/b;
}

#endif