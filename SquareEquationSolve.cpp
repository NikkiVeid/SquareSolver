///@file SquareEquationSolve.cpp

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "SquareEquationSolve.h"

const double EPSILON = 1e-6;

roots_amount full_equation_solve(SquareCoeffs coeffs, SquareRoots *roots)
{
  assert(isfinite(coeffs.a));
  assert(isfinite(coeffs.b));
  assert(isfinite(coeffs.c));
  assert(roots != NULL);

  if (is_not_zerod(coeffs.a))
           square_solve(coeffs, roots);
  else
           linear_solve(coeffs, roots);
}

roots_amount linear_solve(SquareCoeffs coeffs, SquareRoots *roots)
{
  assert(isfinite(coeffs.b));
  assert(isfinite(coeffs.c));
  assert(roots != NULL);

  if (is_not_zerod(coeffs.b))
  {
    roots->x1 = -coeffs.c/coeffs.b; ///<Root of linear equation
    return roots_1;
  }
  else if (is_not_zerod(coeffs.c))
    return roots_0;
  else
    return roots_INF_AMOUNT;
}

roots_amount square_solve(SquareCoeffs coeffs, SquareRoots *roots)
{
   assert(isfinite(coeffs.a));
   assert(isfinite(coeffs.b));
   assert(isfinite(coeffs.c));
   assert(roots != NULL);

   double discr = NAN, sqr = NAN;
   discr = (coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c);
   if (below_zerod(discr))
         return roots_0;
   sqr = sqrt(discr);
   roots->x1 = (-coeffs.b + sqr) / (2 * coeffs.a);
   roots->x2 = (-coeffs.b - sqr) / (2 * coeffs.a);
   if (is_not_zerod(discr))
         return roots_2;
   else
         return roots_1;
}

bool is_not_zerod(double n)
{
   if (fabs(n) > EPSILON)
    return 1;
   else
    return 0;
}

bool below_zerod(double n)
{
   const double EPSILON = 1e-6;
   if (n < -EPSILON)
    return 1;
   else
    return 0;
}


