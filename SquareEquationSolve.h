#ifndef SQUAREEQUATIONSOLVE_H_INCLUDED
#define SQUAREEQUATIONSOLVE_H_INCLUDED

#include "struct.h"

roots_amount full_equation_solve(SquareCoeffs coeffs, SquareRoots *roots);
roots_amount linear_solve(SquareCoeffs coeffs, SquareRoots *roots);
roots_amount square_solve(SquareCoeffs coeffs, SquareRoots *roots);

bool is_not_zerof(double n);
bool below_zerof(double n);

#endif // SQUAREEQUATIONSOLVE_H_INCLUDED
