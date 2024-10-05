#include <stdio.h>
#include <pybind11/embed.h>
#include "rust_math_ops.h"
#include "c_math_ops.h"
#include "clib_math_ops.h"
#include "fortran_math_ops.h"

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

    printf("[C++]\n");
    printf("Rust (Lib):\n");
    printf("A %f + B %f = C %f\n",a,b,c);
    printf("A %f / B %f = D %f\n",a,b,d);
    printf("C (Header):\n");
    printf("A %f + B %f = C %f\n",a,b,e);
    printf("A %f / B %f = D %f\n",a,b,f);
    printf("C (Lib):\n");
    printf("A %f + B %f = C %f\n",a,b,g);
    printf("A %f / B %f = D %f\n",a,b,h);
    printf("Python:\n");
    printf("A %f + B %f = C %f\n",a,b,i);
    printf("A %f / B %f = c %f\n",a,b,j);
    printf("Fortran:\n");
    printf("A %f + B %f = C %f\n",a,b,k);
    printf("A %f / B %f = c %f\n",a,b,l);
    printf("-------------------------------------\n");

    return 0;
}