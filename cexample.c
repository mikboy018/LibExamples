#include <stdio.h>
#include <Python.h>
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

    double i=0, j=0;
    PyObject * name, * module, *py_add_func, * py_div_func;
    PyObject * args, * I, * J;

    Py_Initialize();
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("."));
    name = PyUnicode_DecodeFSDefault("py_math_ops");
    module = PyImport_Import(name);
    Py_DECREF(name);
    if(module != NULL){
        py_add_func = PyObject_GetAttrString(module,"py_add");
        py_div_func = PyObject_GetAttrString(module,"py_div");
        args = PyTuple_New(2);
        PyTuple_SetItem(args,0,PyFloat_FromDouble(a));
        PyTuple_SetItem(args,1,PyFloat_FromDouble(b));
        I = PyObject_CallObject(py_add_func,args);
        J = PyObject_CallObject(py_div_func,args);
        i = PyFloat_AsDouble(I);
        j = PyFloat_AsDouble(J);
    } else {
        printf("Python Module Not Found\n");
        exit(1);
    }

    printf("[C]\n");
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
    printf("-------------------------------------\n");

    return 0;
}