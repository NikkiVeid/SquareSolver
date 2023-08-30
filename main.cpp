#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "interface.h"
#include "SquareEquationSolve.h"
#include "test.h"

int main(int argc, const char *argv[])
{
    const int N_COEF = 3;

    double coeffs[N_COEF] = {};

    if (argc - 1)
    {
        int n = TestFile();
        printf("Number of correct file tests: %d from 2\n", n);
    }
    intro();
    ask_press_enter();

    char ch = 0;
    while ((ch = getchar()) == '\n')
    {
        printf("Enter values of coefficients in decreasing order of powers:\n");
        if (input_coeffs(coeffs, N_COEF) == N_COEF)
        {
            SquareRoots roots = {NAN, NAN};
            SquareCoeffs coeffs1 = {coeffs[0], coeffs[1], coeffs[2]};

            int n_roots = full_equation_solve(&coeffs1, &roots);

            print_results(n_roots, &roots);
            ask_press_enter();
        }
        else
        {
            printf("Data entry error!\n");

            ask_press_enter();
            line_cleaner();
            ungetc(ch, stdin);

            continue;
        }
    }
    printf("Thanks for using!");
    return 0;
}

