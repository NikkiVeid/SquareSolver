///@file interface.h
#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

///Constant for expressing of infinite amount of roots
static const int INF_AMOUNT = 3;

///Constant for accuracy of solving
static const int PRECISION  = 6;

/**
 * Function introduce options of program
 */
void intro();

/**
 * Function asks to press Enter to start.
 */
void ask_press_enter();

/**
 * Function enters coefficients of equation.
 * @param[in] coeffs, n_coef
 * @param[out] n_correct_values
 */
void print_results(int n_roots, const struct SquareRoots *roots);

/**
 * Function prints results of solving.
 * @param[in] n_roots, roots
 */
int input_coeffs(double coeffs[], int n_coef);

/**
 * Function removes extra symbols.
 */
bool line_cleaner();

#endif // INTERFACE_H_INCLUDED
