#include <stdio.h>
#include <locale.h>
#include <conio.h>

int main(void)
{
setlocale(0,"RUS");
int a, b, n, i;
do{
printf ("������� '�' b '�': ");
scanf("%d %d",&a, &b);
if (a>b) printf ("a �� ����� ���� ������ b !!!!! \n \n");
} while (a>b);
n=0;
for (i=a;i<=b;i++) if (i%7==0) n++;

printf ("\n\n������� ����� �����: %d", n);
getch();
return(0);
}