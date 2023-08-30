///@file SquareEquationSolve.h
#ifndef SQUAREEQUATIONSOLVE_H_INCLUDED
#define SQUAREEQUATIONSOLVE_H_INCLUDED

#include "struct.h"

const double EPSILON = 1e-7;

/**
 * Function for solving of square  and linear equation
 * @param[in] coeffs, roots
 * @param[out] x1,x2
 */
RootsAmount full_equation_solve(const SquareCoeffs *coeffs, SquareRoots *roots);

/**
 * Function for solving of linear equation
 * Formula x = -b/c
 * @param[in] coeffs, roots
 * @param[out] x1
 */
RootsAmount linear_solve(const SquareCoeffs *coeffs, SquareRoots *roots);

/**
 * Function for solving of linear equation
 * Formula x1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a)
 * Formula x2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a)
 * @param[in] coeffs, roots
 * @param[out] x1
 */
RootsAmount square_solve(const SquareCoeffs *coeffs, SquareRoots *roots);

/**
 * Function checks is number equal zero or not
 * Formula: |n|<EPSILON
 * @param[in] n
 */
bool is_not_zerod(double n);

/**
 * Function checks is the number less than zero or not
 * Formula: n< -EPSILON
 * @param[in] n
 */
bool below_zerod(double n);

#endif // SQUAREEQUATIONSOLVE_H_INCLUDED
