///@file interface.cpp
#include <stdio.h>

#include "struct.h"
#include "test.h"

/**
 * Function asks to press Enter to start.
 */
void ask_press_enter()
{
    printf("Press Enter to start (or press any  other button to break).");
}

/**
 * Function introduce options of program
 */
void intro()
{
   const double EPSILON = 1e-6;
   printf("Enter values with an accuracy less than %lg!\n", EPSILON);
   char test_agree = 0;
   char ch = 0;
   printf("Do you wanna test program? (Say \"+\", if you want)\n");
   int n = -1;
   test_agree = getchar();
   while ((ch=getchar()) != '\n')
                continue;
   if (test_agree == '+')
   {
                n = TestTool();
                printf("Number of correct tests: %d from 5\n", n);
   }
}

/**
 * Function enters coefficients of equation.
 * @param[in] coeffs, n_coef
 * @param[out] n_correct_values
 */
int input_coeffs(double coeffs[], int n_coef)
{
    int n_correct_values = 0;

    for (int i = 0; i < n_coef; i++)
    {
        if (n_correct_values == i)
        {
            printf("coeffs_%d = ", i);
            n_correct_values += scanf("%lg", &coeffs[i]);
            if ((line_cleaner() > 0) && (coeffs[i] != 0))
            {
                printf("coeffs_%d = %lg\n", i, coeffs[i]);
            }
        }
        else
            break;
    }
    return n_correct_values;
}

/**
 * Function prints results of solving.
 * @param[in] n_roots, roots
 */
void print_results(int n_roots, const struct SquareRoots *roots)
{
    switch (n_roots)
    {
        case 0: printf("No roots.\n");
                break;
        case 1: printf("x = %.*lg\n", PRECISION, roots->x1);
                break;
        case 2: printf("x1 = %.*lf\n", PRECISION, roots->x1);
                printf("x2 = %.*lf\n", PRECISION, roots->x2);
                break;
        case INF_AMOUNT: printf("Infinite amount of roots.");
                         break;
        default: break;
    }
}

/**
 * Function removes extra symbols.
 */
bool line_cleaner()
{
    char ch1 = 0;
    int n_extrasymbols = 0;
    while ((ch1 = getchar()) != '\n')
                     n_extrasymbols += 1;
    if (n_extrasymbols > 0)
        return 1;
    else
        return 0;
}
