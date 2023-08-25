#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

enum roots_amount {roots_0, roots_1, roots_2, roots_INF_AMOUNT};

struct SquareCoeffs
{
    double a;
    double b;
    double c;
};

struct SquareRoots
{
    double x1;
    double x2;
};

#endif // STRUCT_H_INCLUDED
