#ifndef __RUST_MATH_OPS_H
#define __RUST_MATH_OPS_H

/**
 * Example header for rust math functions. Just declaring extern seems to work nicely, here.
 */

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Add Operation in Rust (double + double = double) 
 * 
 * file://./rust_math_ops/src/lib.rs Line 2
 */
extern double rust_add(double a, double b); 
/**
 * @brief Add Operation in Rust (double / double = double) 
 * 
 * file://./rust_math_ops/src/lib.rs Line 7
 */
extern double rust_div(double a, double b);

#ifdef __cplusplus
}
#endif

#endif