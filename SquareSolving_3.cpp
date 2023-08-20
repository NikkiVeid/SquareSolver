#include <stdio.h>
#include <TXLib.h>
#include <math.h>
void lineal_solve(double coef_1, double coef_0);
void square_solve(double coef_2, double coef_1, double coef_0);
void find_squaresolution(double power_2, double power_1, double power_0);
int main()
{
   const double EPSILON = 0.000001;
   printf("Вводите значение с точностью не больше %lf!\n", EPSILON);
   double a = NAN, b = NAN, c = NAN; //Коэффициэнты в порядке понижения степени
   printf("Введите три коэффициэнта в порядке понижения степени:\n");
   if (scanf("%lf%lf%lf", &a, &b, &c) == 3)
   {
      if (a > EPSILON)
      {
          square_solve(a,b,c);
          find_squaresolution(a, b, c);
      }
      else
          lineal_solve(b,c);
   }
   else
      printf("Ошибка!\n");
   return 0;
}

void lineal_solve(double coef_1, double coef_0)  //Коэффициэнты в порядке уменьшения степени
{
  const double EPSILON = 0.000001;
  if ((coef_1 > EPSILON) and (coef_0 > EPSILON))
  {
     double x = NAN; //Корень данного уравнения
     x= -coef_0/coef_1;
     printf("Корень данного уравнения:\n%.6lf", x);
  }

  else if (coef_0 > EPSILON)
         printf("Корней нет.");
  else
    printf("Корнями являются все вещественные числа.");

}
void square_solve(double coef_2, double coef_1, double coef_0)
{
   const double EPSILON = 0.000001;
   double discr = NAN; //Дискриминант
   discr = (coef_1 * coef_1) - (4 * coef_2 * coef_0);
   if (discr < EPSILON)
         printf("Корней нет.\n");
   else
   {
      printf("%s данного уравнения:\n", ((discr > EPSILON) ? "Корни": "Корень"));
   }
}
void find_squaresolution(double power_2, double power_1, double power_0)
{
   const double EPSILON = 0.000001;
   double x1 = NAN, x2 = NAN; //Корни квадратного уравнения
   double sqr = NAN;
   sqr = sqrt((power_1 * power_1) - (4 * power_2 * power_0));
   x1 = (-power_1 + sqr) / (2 * power_2);
   x2 = (-power_1 - sqr) / (2 * power_2);
   if (sqr > sqrt(EPSILON))
         printf("%.6lf и %.6lf", x1, x2);
   else
         printf("%.6lf", x1);
}

