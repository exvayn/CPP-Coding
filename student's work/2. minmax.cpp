// Максимум среди элементов под нечетным номером
// и минимум среди элементов под четным номером
#include <stdio.h>
#include <locale.h>
#include <conio.h>

int main(void)
{
setlocale(0,"RUS");
int m, k, n, i, f;
printf ("Введите кол-во эл-тов: ");
scanf("%d",&n);
for (i=1;i<=n;i++) {
printf ("Введите %d-ый элемент: ", i);
scanf("%d",&f);
if (i<3) { if (i==1) m=f; else k=f;}
else{
if (i%2==0) {if (k>f) k=f;}
else {if (m<f) m=f;}
}
}

printf ("\n Максимум среди нечетных: %d ", m);
printf ("\n Минимум среди четных: %d", k);
getch();
return(0);
}
