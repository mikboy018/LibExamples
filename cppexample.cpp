#include <stdio.h>
#include <pybind11/embed.h>
#include "rust_math_ops.h"
#include "c_math_ops.h"
#include "clib_math_ops.h"
#include "fortran_math_ops.h"

#define NRM  "\x1B[0m"
#define RED  "\033[0;31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define ORG  "\x1B[38;2;255;165;0m"
#define WHT  "\x1B[37m"

namespace py = pybind11;
using namespace py::literals;

int main(int argc, char * argv[]){

    double a = 2.2;
    double b = 3.3;

    double c = rust_add(a,b);
    double d = rust_div(a,b);

    double e = c_add(a,b);
    double f = c_div(a,b);

    double g = clib_add(a,b);
    double h = clib_div(a,b);

    py::scoped_interpreter guard{};
    py::module_ py_math = py::module_::import("py_math_ops");
    py::object I = py_math.attr("py_add")(a,b);
    double i = I.cast<double>();
    py::object J = py_math.attr("py_div")(a,b);
    double j = J.cast<double>();

    double k = 0, l = 0;
    fortran_add(&a,&b,&k);
    fortran_div(&a,&b,&l);

    printf(GRN "[C++]\n");
    printf(MAG "Rust (Lib):\n");
    printf(NRM "A %f + B %f = C %f\n",a,b,c);
    printf("A %f / B %f = D %f\n",a,b,d);
    printf(CYN "C (Header):\n");
    printf(NRM "A %f + B %f = C %f\n",a,b,e);
    printf("A %f / B %f = D %f\n",a,b,f);
    printf(YEL "C (Lib):\n");
    printf(NRM "A %f + B %f = C %f\n",a,b,g);
    printf("A %f / B %f = D %f\n",a,b,h);
    printf(RED "Python:\n");
    printf(NRM "A %f + B %f = C %f\n",a,b,i);
    printf("A %f / B %f = D %f\n",a,b,j);
    printf(ORG "Fortran:\n");
    printf(NRM "A %f + B %f = C %f\n",a,b,k);
    printf("A %f / B %f = D %f\n",a,b,l);
    printf("-------------------------------------\n");

    return 0;
}