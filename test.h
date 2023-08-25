#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "struct.h"

struct SquareTrinomialTest
{
    SquareCoeffs coeffs;
    SquareRoots roots_true;
    roots_amount n_roots_true;
};

int TestTool();
int Test_Square(SquareTrinomialTest test);

#endif // TEST_H_INCLUDED
