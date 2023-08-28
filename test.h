///@file test.h
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
    SquareCoeffs coeffs;       ///< Coefficients of Square equation
    SquareRoots roots_true;    ///< Roots of Square equation
    roots_amount n_roots_true; ///< Number of roots
};

/**
 *Function for full test of program
 * @param[out] n_succesion
 */
int TestTool();

/**
 * Function for single test of program
 * @param[in] test
 */
int Test_Square(SquareTrinomialTest test);

#endif // TEST_H_INCLUDED
