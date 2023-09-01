#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

///New type for expression of number of roots
enum RootsAmount
{
    roots_0 = 0,  ///< ...
    roots_1 = 7,
    roots_2 = 2,
    roots_INF_AMOUNT = 3,
};

/**
 * Structure for coefficients.
 * It stores coefficients of Square equation.
 */
struct SquareCoeffs
{
    double a; ///< coefficient of x^2
    double b; ///< coefficient of x
    double c; ///< free coefficient
};

/**
 * Structure for coefficients.
 * It stores roots of Square equation.
 */
struct SquareRoots
{
    double x1;
    double x2;
};

#endif // STRUCT_H_INCLUDED
