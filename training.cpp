#include <stdio.h>
#include <TXLib.h>
int main()
{
   float x1, x2;       //����� ����������� ���������
   float a, b, c;      //������������ � ������� ��������� �������
   float discr;        //������������
   printf("������� ��� ������������ � ������� ��������� �������:\n");
   scanf("%f%f%f", &a, &b, &c);
   discr = b * b - 4 * a * c;
   if (discr < 0)
         printf("������ ���.\n");
   else
   {
      x1 = (-b + sqrt(discr)) / (2 * a);
      x2 = (-b - sqrt(discr)) / (2 * a);
      printf("%s ������� ���������:\n", (discr == 0) ? "������": "�����");
      if (discr == 0)
          printf("%.3f", x1);
      else
          printf("%.3f%7.3f", x1, x2);
   }
   return 0;
}
