#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

void intro();
void ask_press_enter();
void print_results(int n_roots, const struct SquareRoots *roots);

int input_coeffs(double coeffs[], int n_coef);

bool line_cleaner();

#endif // INTERFACE_H_INCLUDED
