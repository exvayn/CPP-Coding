#include <stdio.h>
#include <math.h>
#include <iostream>
//для EOF - <Enter> <Ctrl+Z> <Enter>
double i[131072];
void main(){
	int j=0;
	while (scanf("%lf", &i[j]) != EOF) j++;
	j--;
	while (j>=0) {printf("%.4f\n",sqrt(i[j])); j--;}
	system("pause");
}