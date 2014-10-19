#include <stdio.h>
#include <iostream>
void main(void)
{
	int k,h,d,s,i,j;
	scanf("%d",&k);
	int*A=new int[k];
	for (i=0;i<k;i++) scanf("%d",&A[i]);
	h=((int) k/2)+1;
	s=0;
	for (i=0;i<k;i++)
		for (j=i+1;j<k;j++)
			if (A[i]>A[j]) {d=A[i]; A[i]=A[j]; A[j]=d;}
	for (i=0;i<h;i++)
		s=s+((int) A[i]/2)+1;
	printf("%d",s);
		system("pause");
}