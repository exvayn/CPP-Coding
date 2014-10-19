#include <stdio.h>
#include <math.h>
#include <iostream>
void main(){
	int n,i,p;
	float r,l,x,y,a,b,g,h,pi=3.1415927;
	scanf("%d %f",&n,&r);
	r=2*pi*r;
	l=0;
	for (i=1;i<=n;i++){
		scanf("%f %f",&x,&y);
		if (i==1) {g=a=x; h=b=y;}
		else 
		{
		l=l+sqrt((a*a-2*a*x+x*x)+(b*b-2*b*y+y*y));
		a=x; b=y;
		}
	}
	l=l+sqrt((g*g-2*g*x+x*x)+(h*h-2*h*y+y*y))+r;
	printf("%.2f",l);
	system("pause");
}