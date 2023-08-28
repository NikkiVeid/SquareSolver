///@file SquareEquationSolve.cpp

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "SquareEquationSolve.h"

/**
 * Function for solving of square  and linear equation
 * @param[in] coeffs, roots
 * @param[out] x1,x2
 */
roots_amount full_equation_solve(SquareCoeffs coeffs, SquareRoots *roots)
{
  assert(isfinite(coeffs.a));
  assert(isfinite(coeffs.b));
  assert(isfinite(coeffs.c));
  assert(roots != NULL);

  if (is_not_zerof(coeffs.a))
           square_solve(coeffs, roots);
  else
           linear_solve(coeffs, roots);
}

/**
 * Function for solving of linear equation
 * Formula x = -b/c
 * @param[in] coeffs, roots
 * @param[out] x1
 */
roots_amount linear_solve(SquareCoeffs coeffs, SquareRoots *roots)
{
  assert(isfinite(coeffs.b));
  assert(isfinite(coeffs.c));
  assert(roots != NULL);

  if (is_not_zerof(coeffs.b))
  {
    roots->x1 = -coeffs.c/coeffs.b; ///<Root of linear equation
    return roots_1;
  }
  else if (is_not_zerof(coeffs.c))
    return roots_0;
  else
    return roots_INF_AMOUNT;
}

/**
 * Function for solving of linear equation
 * Formula x1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a)
 * Formula x2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a)
 * @param[in] coeffs, roots
 * @param[out] x1
 */
roots_amount square_solve(SquareCoeffs coeffs, SquareRoots *roots)
{
   assert(isfinite(coeffs.a));
   assert(isfinite(coeffs.b));
   assert(isfinite(coeffs.c));
   assert(roots != NULL);

   double discr = NAN, sqr = NAN;
   discr = (coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c);
   if (below_zerof(discr))
         return roots_0;
   sqr = sqrt(discr);
   roots->x1 = (-coeffs.b + sqr) / (2 * coeffs.a);
   roots->x2 = (-coeffs.b - sqr) / (2 * coeffs.a);
   if (is_not_zerof(discr))
         return roots_2;
   else
         return roots_1;
}

/**
 * Function checks is number equal zero or not
 * Formula: |n|<EPSILON
 * @param[in] n
 */
bool is_not_zerof(double n)
{
   const double EPSILON = 1e-6;
   if (fabs(n) > EPSILON)
    return 1;
   else
    return 0;
}

/**
 * Function checks is the number less than zero or not
 * Formula: n< -EPSILON
 * @param[in] n
 */
bool below_zerof(double n)
{
   const double EPSILON = 1e-6;
   if (n < -EPSILON)
    return 1;
   else
    return 0;
}


