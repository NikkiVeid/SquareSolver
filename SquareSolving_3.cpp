#include <assert.h>
#include <math.h>
#include <stdio.h>

const int INF_AMOUNT = -1;
const int PRECISION = 6;
const int N_COEF = 3;

struct SquareRoots
{
    double x1;
    double x2;
};

struct SquareTrinomialTest
{
    double coeffs[N_COEF];
    double x1_true;
    double x2_true;
    int n_roots_true;
};

void intro();
void press_enter();
void print_results(int n_roots, double x1, double x2);

int input_coeffs(double coeffs[], int n_coef);
int full_equation_solve(double coeffs[], double *x1, double *x2);
int linear_solve(double coeffs[], double *x1);
int square_solve(double coeffs[], double *x1, double *x2);

bool is_not_zerof(double n);
bool below_zerof(double n);

int TestTool();
int Test_Square(SquareTrinomialTest test);

int main()
{
   double coeffs[N_COEF] = {};
   intro();
   press_enter();
   char ch = 0;
   while ((ch = getchar()) == '\n')
   {
     printf("Enter values of coefficients in decreasing order of powers:\n");
     if (input_coeffs(coeffs, N_COEF) == N_COEF)
     {
        int n_roots = -1;
        double x1 = NAN, x2 = NAN;
        n_roots = full_equation_solve(coeffs, &x1, &x2);
        print_results(n_roots, x1, x2);
        press_enter();
     }
     else
     {
        printf("Data entry error!\n");
        press_enter();
        while ((ch = getchar()) != '\n')
                 continue;
        continue;
     }
   }
   printf("Thanks for using!");
   return 0;
}

void press_enter()
{
    printf("Press Enter to start (or press any  other button to break).");
}

void intro()
{
   const double EPSILON = 1e-6;
   printf("Enter values with an accuracy less than %lg!\n", EPSILON);
   char test_agree = 0;
   char ch = 0;
   printf("Do you wanna test program? (Say \"+\", if you want)");
   int n = -1;
   printf("\n");
   test_agree = getchar();
   while ((ch=getchar()) != '\n')
                continue;
   if (test_agree == '+')
   {
                n = TestTool();
                printf("Number of correct tests: %d from 5\n", n);
                if (n != 5)
                    printf("Program is fail");
   }
}

int Test_Square(SquareTrinomialTest test)
{
    double x1 = 0, x2 = 0;
    int n_roots = full_equation_solve(test.coeffs, &x1, &x2);
    if ((x1 != test.x1_true) || (x2 != test.x2_true) || (n_roots != test.n_roots_true))
    {
            printf("Output: x1 = %lg, x2 = %lg, n_roots = %lg\n",
                   "Expected: x1 = %lg, x2 = %lg, n_roots = %lg\n",
                   x1, x2, n_roots, test.x1_true, test.x2_true, test.n_roots_true);
            return 0;
    }
    else
    {
            printf("OK\n");
            return 1;
    }
}

int TestTool()
{
    const int N_TESTS = 5;
    int n_succession = 0;
    struct SquareTrinomialTest test[N_TESTS] = {
                                                {{1, 0, -4}, +2, -2, 2},
                                                {{0, 0,  3},  0,  0, 0},
                                                {{0, 0,  0},  0,  0, INF_AMOUNT},
                                                {{0,-1,  1},  1,  0, 1},
                                                {{1, 1,  1},  0,  0, 0}
                                               };

    for (int index = 0; index < N_TESTS; index++)
                  n_succession += Test_Square(test[index]);

    assert(n_succession != NULL);

    return n_succession;
}

int input_coeffs(double coeffs[], int n_coef)
{
    int n_correct_values = 0;

    for (int i = 0; i < n_coef; i++)
    {
        if (n_correct_values == i)
        {
          printf("coeffs_%d = ", i);
          n_correct_values += scanf("%lg", &coeffs[i]);
          char ch1 = 0;
          int n_extrasymbols = 0;
          while ((ch1 = getchar()) != '\n')
                     n_extrasymbols += 1;
          if (n_extrasymbols > 0)
               printf("coeffs_%d = %lg\n ", i, coeffs[i]);
        }
        else
           break;
    }
    return n_correct_values;
}

void print_results(int n_roots, double x1, double x2)
{
    switch (n_roots)
    {
         case 0: printf("No roots.\n");
                 break;
         case 1: printf("x = %.*lg\n", PRECISION, x1);
                 break;
         case 2: printf("x1 = %.*lf\n", PRECISION, x1);
                 printf("x2 = %.*lf\n", PRECISION, x2);
                 break;
         case INF_AMOUNT: printf("Infinite amount of roots.");
                          break;
         default: break;
    }
}

int full_equation_solve(double coeffs[], double *x1, double *x2)
{
  assert(x1 != NULL);
  assert(x2 != NULL);
  assert(x2 != x1);
  assert(isfinite(coeffs[0]));
  assert(isfinite(coeffs[1]));
  assert(isfinite(coeffs[2]));

  if (is_not_zerof(coeffs[0]))
           square_solve(coeffs, x1, x2);
  else
           linear_solve(coeffs, x1);
}

int linear_solve(double coeffs[], double *x1)
{
  assert(x1 != NULL);
  assert(isfinite(coeffs[1]));
  assert(isfinite(coeffs[2]));

  if (is_not_zerof(coeffs[1]))
  {
                 *x1 = -coeffs[2]/coeffs[1];
                 return 1;
  }
  else if (is_not_zerof(coeffs[2]))
                 return 0;
  else
                 return INF_AMOUNT;

}

int square_solve(double coeffs[], double *x1, double *x2)
{
   assert(x1 != NULL);
   assert(x2 != NULL);
   assert(x2 != x1);
   assert(isfinite(coeffs[0]));
   assert(isfinite(coeffs[1]));
   assert(isfinite(coeffs[2]));

   double discr = NAN, sqr = NAN;
   discr = (coeffs[1] * coeffs[1]) - (4 * coeffs[0] * coeffs[2]);
   if (below_zerof(discr))
         return 0;
   sqr = sqrt(discr);
   *x1 = (-coeffs[1] + sqr) / (2 * coeffs[0]);
   *x2 = (-coeffs[1] - sqr) / (2 * coeffs[0]);
   if (is_not_zerof(discr))
         return 2;
   else
         return 1;
}

bool is_not_zerof(double n)
{
   const double EPSILON = 1e-6;
   if (fabs(n) > EPSILON)
                   return 1;
   else
                   return 0;
}

bool below_zerof(double n)
{
   const double EPSILON = 1e-6;
   if (n < -EPSILON)
                   return 1;
   else
                   return 0;
}


