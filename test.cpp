///@file test.cpp

#include <stdio.h>

#include "test.h"
#include "SquareEquationSolve.h"

const char CLOSING[] = "\033[0m\n";

int Test_Square(SquareTrinomialTest test)
{
    SquareRoots roots = {0, 0};
    int n_roots = full_equation_solve(test.coeffs, &roots);

    if ((roots.x1 != test.roots_true.x1) ||
        (roots.x2 != test.roots_true.x2) ||
        (n_roots != test.n_roots_true))
    {
        const char RED[] = "\033[31m";
        printf("%s Failed!%s"
               "%sOutput: x1 = %lg, x2 = %lg, n_roots = %d%s"
               "%sExpected: x1 = %lg, x2 = %lg, n_roots = %d%s",
               RED, CLOSING,
               RED, roots.x1, roots.x2, n_roots, CLOSING,
               RED, test.roots_true.x1, test.roots_true.x2, test.n_roots_true, CLOSING);
        return 0;
    }
    else
    {
        const char GREEN[] = "\033[32m";
        printf("%sOK%s", GREEN, CLOSING);
        return 1;
    }
}

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
    {
        n_succession += Test_Square(test[index]);
    }
    return n_succession;
}

int TestFile()
{
    FILE *test_file = NULL;
    char name_file[] = "test.txt";

    int n_succession_file = 0;
    if ((test_file = fopen(name_file, "r")) != NULL)
    {
        struct SquareTrinomialTest file_test = {};

        while (fgetc(test_file) != EOF)
        {
            fgetc(test_file);

            if (fscanf(test_file, "%lf%lf%lf%lf%lf%d\n", &(file_test.coeffs.a),
                                                         &(file_test.coeffs.b),
                                                         &(file_test.coeffs.c),
                                                         &(file_test.roots_true.x1),
                                                         &(file_test.roots_true.x2),
                                                         &(file_test.n_roots_true)) == 6)
            {
                n_succession_file += Test_Square(file_test);
            }
            else
            {
                printf("File input error.\n");
            }
        }

    }
    else
    {
        printf("File opening error.\n");
    }

    fclose(test_file);
    return n_succession_file;
}

