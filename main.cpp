#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "interface.h"
#include "SquareEquationSolve.h"
#include "test.h"

const int N_COEF = 3;

int main()
{
   double coeffs[N_COEF] = {};
   intro();
   ask_press_enter();
   char ch = 0;
   while ((ch = getchar()) == '\n')
   {
     printf("Enter values of coefficients in decreasing order of powers:\n");
     if (input_coeffs(coeffs, N_COEF) == N_COEF)
     {
        int n_roots = -1;
        SquareRoots roots = {NAN, NAN};
        SquareCoeffs coeffs1 = {coeffs[0], coeffs[1], coeffs[2]};
        n_roots = full_equation_solve(coeffs1, &roots);
        print_results(n_roots, &roots);
        ask_press_enter();
     }
     else
     {
        printf("Data entry error!\n");
        ask_press_enter();
        while ((ch = getchar()) != '\n')
                 continue;
        ungetc(ch, stdin);
        continue;
     }
   }
   printf("Thanks for using!");
   return 0;
}

