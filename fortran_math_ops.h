#ifndef __FORTRAN_MATH_OPS_H
#define __FORTRAN_MATH_OPS_H

#ifdef __cplusplus
extern "C"{
#endif
/**
 * @brief Fortran Addition (double + double = double)
 */
extern double fortran_add(double * a, double * b, double * c);
/**
 * @brief Fortran Division (double / double = double)
 */
extern double fortran_div(double * a, double * b, double * c);

#ifdef __cplusplus
}
#endif

#endif