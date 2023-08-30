///@file interface.cpp
#include <stdio.h>

#include "struct.h"
#include "test.h"
#include "interface.h"

void ask_press_enter()
{
    printf("Press Enter to start (or press any  other button to break).");
}

void intro()
{
   const double EPSILON = 1e-6;

   printf("Enter values with an accuracy less than %lg!\n", EPSILON);

   char test_agree = 0;
   char ch = 0;

   printf("Do you wanna test program? (Say \"+\", if you want)\n");
   int n = -1;
   test_agree = getchar();
   line_cleaner();
   if (test_agree == '+')
   {
        n = TestTool();
        printf("Number of correct tests: %d from 5\n", n);
   }

}

int input_coeffs(double coeffs[], int n_coef)
{
    int n_correct_values = 0;

    for (int i = 0; i < n_coef && n_correct_values == i; i++)
    {
        printf("coeffs_%d = ", i);
        n_correct_values += scanf("%lg", &coeffs[i]);
        if (line_cleaner() > 0)
        {
            printf("coeffs_%d = %lg\n", i, coeffs[i]);
        }
    }
    return n_correct_values;
}

void print_results(int n_roots, const struct SquareRoots *roots)
{
    switch (n_roots)
    {
        case roots_0: printf("No roots.\n");
                break;
        case roots_1: printf("x = %.*lg\n", PRECISION, roots->x1);
                break;
        case roots_2: printf("x1 = %.*lf\n", PRECISION, roots->x1);
                printf("x2 = %.*lf\n", PRECISION, roots->x2);
                break;
        case roots_INF_AMOUNT: printf("Infinite amount of roots.\n");
                         break;
        default: break;
    }
}

bool line_cleaner()
{
    char ch1 = 0;
    int n_extrasymbols = 0;
    while ((ch1 = getchar()) != '\n')
        n_extrasymbols++;
    return (n_extrasymbols > 0);
}
