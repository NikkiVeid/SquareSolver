///@file test.cpp

#include <stdio.h>

#include "test.h"
#include "SquareEquationSolve.h"

/**
 * Function for single test of program
 * @param[in] test
 */
int Test_Square(SquareTrinomialTest test)
{
    SquareRoots roots = {0, 0};
    int n_roots = full_equation_solve(test.coeffs, &roots);

    if ((roots.x1 != test.roots_true.x1) ||
        (roots.x2 != test.roots_true.x2) ||
        (n_roots != test.n_roots_true))
    {
        printf("\033[31mFailed!\033[0m\n",
               "\033[31mOutput: x1 = %lg, x2 = %lg, n_roots = %lg\033[0m\n",
               "\033[31mExpected: x1 = %lg, x2 = %lg, n_roots = %lg\033[0m\n",
               roots.x1, roots.x2, n_roots, test.roots_true.x1, test.roots_true.x2, test.n_roots_true);
        return 0;
    }
    else
    {
        printf("\033[32mOK\033[0m\n");
        return 1;
    }

/**
 * Function for full test of program
 * @param[out] n_succesion
 */
int TestTool()
{
    const int N_TESTS = 5;

    int n_succession = 0;

    struct SquareTrinomialTest test[N_TESTS] = {
        {{1, 0, -4}, {+2, -2}, roots_2},
        {{0, 0,  3}, {0,   0}, roots_0},
        {{0, 0,  0}, {0,   0}, roots_INF_AMOUNT},
        {{0,-1,  1}, {1,   0}, roots_1},
        {{1, 1,  1}, {0,   0}, roots_0}
    };
    for (int index = 0; index < N_TESTS; index++)

    for (int index = 0; index < N_TESTS; index++)
    {
        n_succession += Test_Square(test[index]);
    }
    return n_succession;
}

    return n_succession;
}
