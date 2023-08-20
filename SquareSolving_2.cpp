#include <stdio.h>
#include <TXLib.h>
#include <math.h>
void notsquare_solve(double coef_1, double coef_0);
void square_solve(double coef_2, double coef_1, double coef_0);
int main()
{
   double a = NAN, b = NAN, c =NAN; //Коэффициэнты в порядке понижения степени
   printf("Введите три коэффициэнта в порядке понижения степени:\n");
   scanf("%lf%lf%lf", &a, &b, &c);
   if ((a > 0) || (a < 0))
           square_solve(a,b,c);
   else
           notsquare_solve(b,c);
   return 0;
}

void notsquare_solve(double coef_1, double coef_0)  //Коэффициэнты в порядке уменьшения степени
{
  if (((coef_1 < 0) || (coef_1 > 0)) and ((coef_0 < 0) || (coef_1 > 0)))
  {
     double x = NAN; //Корень данного уравнения
     x= -coef_1/coef_0;
     printf("Корень данного уравнения:\n%lf", x);
  }

  else if ((coef_0 < 0) || (coef_0 > 0))
         printf("Корней нет.");
  else
    printf("Корнями являются все вещественные числа.");

}
void square_solve(double coef_2, double coef_1, double coef_0)
{
   double x1 = NAN, x2 = NAN; //Корни квадратного уравнения
   double discr = NAN; //Дискриминант
   discr = (coef_1 * coef_1) - (4 * coef_2 * coef_0);
   if (discr < 0)
         printf("Корней нет.\n");
   else
   {
      x1 = (-coef_1 + sqrt(discr)) / (2 * coef_2);
      x2 = (-coef_1 - sqrt(discr)) / (2 * coef_2);
      printf("%s данного уравнения:\n", ((discr < 0) || (discr > 0)) ? "Корни": "Корень");
      if ((discr < 0) || (discr > 0))
          printf("%.3lf%7.3lf", x1, x2);
      else
          printf("%.3lf", x1);
   }
}
