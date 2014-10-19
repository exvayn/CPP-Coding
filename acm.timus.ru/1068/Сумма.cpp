#include <stdio.h>
#include <iostream>
void main(void)
{
	int  s,n;
	scanf ("%d",&n);
	if (n>1)
	{
		s=(n*(n+1))/2;		
	} 
	if (n<0) 
	{
		s=-(n*(n-1))/2+1;
	}
	if (n==0) s=1;
	if (n==1) s=1;
	printf("%d",s);
	system("pause");
}