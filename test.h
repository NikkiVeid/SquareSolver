#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "struct.h"

/**
 * Structure for testing.
 * It stores coefficients of Square equation, roots of this equation
 * and number of roots.
 */
struct SquareTrinomialTest
{
    SquareCoeffs coeffs; ///< Coefficients of Square equation
    SquareRoots roots_true; ///< Roots of Square equation
    roots_amount n_roots_true; ///< Number of roots
};

int TestTool();
int Test_Square(SquareTrinomialTest test);

#endif // TEST_H_INCLUDED
