#include <stdio.h>
#include <TXLib.h>
int main()
{
   float x1, x2;       //Корни квадратного уравнения
   float a, b, c;      //Коэффициэнты в порядке понижения степени
   float discr;        //Дискриминант
   printf("Введите три коэффициэнта в порядке понижения степени:\n");
   scanf("%f%f%f", &a, &b, &c);
   discr = b * b - 4 * a * c;
   if (discr < 0)
         printf("Корней нет.\n");
   else
   {
      x1 = (-b + sqrt(discr)) / (2 * a);
      x2 = (-b - sqrt(discr)) / (2 * a);
      printf("%s данного уравнения:\n", (discr == 0) ? "Корень": "Корни");
      if (discr == 0)
          printf("%.3f", x1);
      else
          printf("%.3f%7.3f", x1, x2);
   }
   return 0;
}
