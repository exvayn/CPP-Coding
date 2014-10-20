#include <stdio.h>
#include <iostream>
void main (){
	int i,j,n,kol,z;
	scanf("%d",&n);
	int *A=new int[n];
	for (i=0;i<n; i++) A[i]=i+1;
	kol=1;
	do{
		for (i=0; i<n; i++) printf ("%d" , A[i]);
		printf ("\n");
		i=n-2;
		while (i>=0 && A[i+1]<A[i]) i--;
		if (i==-1) break;
		j=n-1;
		while (j>=0 && A[j]<A[i]) j--;
		z=A[i]; A[i]=A[j]; A[j]=z;
		for (j=i+1;j<(n+i+1)/2;j++) 
		{z=A[j]; A[j]=A[n-j+i]; A[n-j+i]=z;}
		kol++;
	}while (true);
	printf ("kol-vo kombinaciy - %d\n" , kol);
	system("pause");
}