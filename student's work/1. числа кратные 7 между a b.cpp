#include <stdio.h>
#include <locale.h>
#include <conio.h>

int main(void)
{
setlocale(0,"RUS");
int a, b, n, i;
do{
printf ("Введите 'а' b 'б': ");
scanf("%d %d",&a, &b);
if (a>b) printf ("a не может быть меньше b !!!!! \n \n");
} while (a>b);
n=0;
for (i=a;i<=b;i++) if (i%7==0) n++;

printf ("\n\nИскомое число равно: %d", n);
getch();
return(0);
}
