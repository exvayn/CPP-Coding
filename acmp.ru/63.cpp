// x+y=a    x*y=b
// y=a-x    (a-x)*x=b
//          x^2-ax+b=0
//          D=a^2-4b
//          x=(a-sqrt(a^2-4b))/2  для x знак -, для y знак +
#include <stdio.h>
#include <math.h>
FILE *f;
void main(){
	int a,b,x;
	f=fopen("input.txt","r");
	fscanf(f,"%d %d",&a,&b);
	fclose(f);
	x=(a-sqrt((float)(a*a-4*b)))/2;
	f=fopen("output.txt","w");
	fprintf(f,"%d %d",x,a-x);
	fclose(f);
}