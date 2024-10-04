#include <stdio.h>
#include "rust_math_ops.h"
#include "c_math_ops.h"
#include "clib_math_ops.h"

int main(int argc, char * argv[]){

    double a = 2.2;
    double b = 3.3;

    double c = rust_add(a,b);
    double d = rust_div(a,b);

    double e = c_add(a,b);
    double f = c_div(a,b);

    double g = clib_add(a,b);
    double h = clib_div(a,b);

    printf("RUST:\n");
    printf("A %f + B %f = C %f\n",a,b,c);
    printf("A %f / B %f = D %f\n",a,b,d);
    printf("C\n");
    printf("A %f + B %f = C %f\n",a,b,e);
    printf("A %f / B %f = D %f\n",a,b,f);
    printf("CLIB\n");
    printf("A %f + B %f = C %f\n",a,b,g);
    printf("A %f / B %f = D %f\n",a,b,h);

    return 0;
}