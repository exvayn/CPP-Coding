//1. Написать функцию, которая вычисляет значение a^b. 
//Числа a и b могут быть любыми целыми положительными числами.
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
int function(int a, int b);
void main()
{ 
	setlocale(0,"RUS");
	int a,b,s;
	printf("Введите a b: ");
	scanf("%d %d", &a, &b);
	if (b>0) {
		s=function(a, b);
		printf("a^b = %d", s);	
	} else printf("b > 0 !!!");

    getch();
}
int function(int a, int b)
{
	int s;

	// s=a; for (int i=2;i<=b;i++) s=s*a;

	// float f=a; s = pow(f,b);

	int z; if (a<0 && b%2!=0) z=-1; else z=1; float f=abs(a);
	s = (int) exp(b*log(f)); s=s*z;

    return(s);
}
