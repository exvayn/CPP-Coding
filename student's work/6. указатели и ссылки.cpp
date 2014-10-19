#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>
#define N 10
void main()
{
	int *mass,*p,s,max,min,*max_i,*min_i,i,a,b;
	mass=(int*)malloc(N+sizeof(int));
	s=0; i=1;
	for (p=mass;p<mass+N;p++)
	{
		scanf("%d",p);
		if (!s) 
		{
			max=*mass;	max_i=mass;
			min=*mass;	min_i=mass;
			s=1;
		}
		if (abs(*p)>max) {max=abs(*p); max_i=p; a=i;}
		if (abs(*p)<min) {min=abs(*p); min_i=p; b=i;}
		i++;
	}
	if (b>a) {p=max_i; max_i=min_i; min_i=p;}
	for (p=min_i+1;p<max_i;p++)
	{
		s=s*(*p);
	}
	if (s==1) printf("HeTy"); else
	printf("proizv = %d",s);
	getch();
}