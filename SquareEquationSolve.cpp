///@file SquareEquationSolve.cpp

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "SquareEquationSolve.h"

RootsAmount full_equation_solve(const SquareCoeffs* coeffs, SquareRoots *roots)
{
  assert(isfinite(coeffs->a));
  assert(isfinite(coeffs->b));
  assert(isfinite(coeffs->c));
  assert(roots != NULL);

  if (is_not_zerod(coeffs->a))
           square_solve(coeffs, roots);
  else
           linear_solve(coeffs, roots);
}

RootsAmount linear_solve(const SquareCoeffs* coeffs, SquareRoots *roots)
{
  assert(isfinite(coeffs->b));
  assert(isfinite(coeffs->c));
  assert(roots != NULL);

  if (is_not_zerod(coeffs->b))
  {
    roots->x1 = -coeffs->c/coeffs->b;///<Root of linear equation
    return roots_1;
  }
  else if (is_not_zerod(coeffs->c))
    return roots_0;
  else
    return roots_INF_AMOUNT;
}

RootsAmount square_solve(const SquareCoeffs* coeffs, SquareRoots *roots)
{
   assert(isfinite(coeffs->a));
   assert(isfinite(coeffs->b));
   assert(isfinite(coeffs->c));
   assert(roots != NULL);
   double discr = NAN, sqr = NAN;

   discr = (coeffs->b * coeffs->b) - (4 * coeffs->a * coeffs->c);

   if (below_zerod(discr))
         return roots_0;

   sqr = sqrt(discr);
   roots->x1 = (-coeffs->b + sqr) / (2 * coeffs->a);
   roots->x2 = (-coeffs->b - sqr) / (2 * coeffs->a);

   if (is_not_zerod(discr))
         return roots_2;
   else
         return roots_1;
}

bool is_not_zerod(double n)
{
    return (fabs(n) > EPSILON);
}

bool below_zerod(double n)
{
    return (n < -EPSILON) ? 1:0;
}

